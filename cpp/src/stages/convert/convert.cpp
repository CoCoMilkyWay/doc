#include "stages/convert/convert.hpp"

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>

#include <unistd.h>

#include "common/fs.hpp"
#include "common/pdftext.hpp"
#include "common/proc.hpp"
#include "common/util.hpp"
#include "config.hpp"

// 递归收集 PDF (扩展名大小写不限, 与 scan 同口径), 顺序稳定
static void walk(const std::string &root, const std::string &rel, std::vector<Pdf> &out) {
  std::string dirpath = rel == "." ? root : root + "/" + rel;
  std::vector<std::string> dirs, files;
  list_dir(dirpath, dirs, files);
  for (const std::string &f : files)
    if (lower_ascii(f).ends_with(".pdf"))
      out.push_back({rel, f, dirpath + "/" + f, file_size(dirpath + "/" + f)});
  for (const std::string &d : dirs)
    walk(root, rel == "." ? d : rel + "/" + d, out);
}

static std::string stem(const std::string &name) { return name.substr(0, name.size() - 4); }

// 按 MinerU 实际执行顺序打印各阶段作用, 帮用户理解进度条里那些 "Layout Predict" /
// "MFR Predict" 之类的输出分别在干什么; MINERU_FORMULA/MINERU_TABLE 关闭时对应行不会
// 真的跑, 这里同步跳过, 避免误导.
static void print_pipeline_steps(const std::string &device) {
  fprintf(stderr, "[convert] MinerU 处理流程 (device=%s, 每个PDF依次经过以下阶段):\n",
          device.c_str());
  fprintf(stderr, "  Layout Predict        版面检测: 分割标题/正文/表格/公式/图片等区域框\n");
  if (MINERU_FORMULA)
    fprintf(stderr, "  MFR Predict           公式识别: 公式区域图片 -> LaTeX\n");
  if (MINERU_TABLE) {
    fprintf(stderr, "  Table orientation     表格方向判断: 检测表格是否被旋转 90°/270°\n");
    fprintf(stderr, "  Table-ocr det/rec     表格内文字检测+识别 (供表格结构还原用)\n");
    fprintf(stderr, "  Table-wireless Predict 无线表(无框线)结构识别 -> 还原成 HTML\n");
    fprintf(stderr, "  Table-wired Predict   有线表(有框线)结构识别 -> 还原成 HTML\n");
  }
  fprintf(stderr, "  OCR-det/rec           正文文字检测+识别\n");
  fprintf(stderr, "  Seal Predict          印章检测识别 (没有印章时为 0it)\n");
  fprintf(stderr, "  Processing pages      汇总以上结果, 拼成最终页面结构\n");
}

// 暂存区内的 MinerU 输出 <stage_dir>/<MINERU_METHOD>/{<stem>.md, images/} 搬平为 <stage_dir>/{PROC_MD_NAME,
// images/}, 写 .stat, 最后 rename 整个目录到最终位置 (同一文件系统, 原子: 要么完整出现, 要么不出现).
// 返回 false 表示 MinerU 没产出 md (暂存目录留给调用方清理). 中间目录 rmdir 非空即断言失败 =>
// 顺带校验 client.py 的剪裁生效, 没有多余产物.
static bool finalize(const std::string &stage_dir, const std::string &s, long long pdf_size,
                     const std::string &final_dir) {
  std::string mineru_dir = stage_dir + "/" + MINERU_METHOD;
  std::string src_md = mineru_dir + "/" + s + ".md";
  if (!path_exists(src_md))
    return false;
  std::string src_img = mineru_dir + "/images";
  if (is_dir(src_img))
    assert(rename(src_img.c_str(), (stage_dir + "/images").c_str()) == 0);
  assert(rename(src_md.c_str(), (stage_dir + "/" + PROC_MD_NAME).c_str()) == 0);
  assert(rmdir(mineru_dir.c_str()) == 0 && "MinerU 输出目录有多余产物, 检查 client.py 剪裁");
  write_stat(stage_dir, pdf_size);
  assert(!path_exists(final_dir) && "最终位置已存在, check 应已处理");
  assert(rename(stage_dir.c_str(), final_dir.c_str()) == 0);
  return true;
}

int ConvertStage::run(const Ctx &ctx) {
  std::string raw = ctx.root + "/" + RAW_REPORT_DIR;
  std::string proc = ctx.root + "/" + PROC_REPORT_DIR;
  assert(is_dir(raw) && "缺少研报输入目录 RAW_REPORT_DIR");
  int vram_gb = 0;                                          // cuda 时为显存 GB, cpu 时 0
  std::string device = check_mineru_env(ctx.root, vram_gb); // E1-E3, 顺带定下本次用 cuda 还是 cpu

  std::vector<Pdf> pdfs;
  walk(raw, ".", pdfs);

  // 增量扫描: raw <-> proc 一一对应 + 每篇完整性; 问题项须经用户同意删除, 否则退出
  std::vector<size_t> todo;
  if (!check_proc(proc, pdfs, ctx.workers, todo))
    return 1;
  std::string staging = proc + "/" + PROC_STAGING_DIR;
  mkdirs(staging);

  // 待转换按目录分组 (map 保证目录按字节序), 顺带数页 (进度/ETA 按页算)
  std::map<std::string, std::vector<size_t>> pending;
  std::vector<int> pages(pdfs.size(), 0);
  size_t todo_pages = 0;
  for (size_t i : todo) {
    pending[pdfs[i].folder].push_back(i);
    pages[i] = pdf_pages(pdfs[i].path);
    assert(pages[i] > 0 && "PDF 无法解析, scan 应已拦下");
    todo_pages += pages[i];
  }
  size_t n_todo = todo.size(), n_done = pdfs.size() - n_todo;
  fprintf(stderr, "[convert] 共%zu个PDF: 已完成%zu, 待转换%zu (%zu个目录, %zu页)\n", pdfs.size(),
          n_done, n_todo, pending.size(), todo_pages);

  // MinerU 通过环境变量取设备与模型来源; 子进程继承. 显式写入探测结果而不是留空让 MinerU 自己
  // 判 (mineru/utils/config_reader.py get_device()), 是为了让这里打印的和实际跑的一定是同一个
  assert(setenv("MINERU_DEVICE_MODE", device.c_str(), 1) == 0);
  assert(setenv("MINERU_MODEL_SOURCE", MINERU_MODEL_SOURCE, 1) == 0);
  assert(setenv("MINERU_FORMULA_CH_SUPPORT", MINERU_FORMULA_CH_SUPPORT, 1) == 0);
  assert(setenv("MINERU_API_MAX_CONCURRENT_REQUESTS", MINERU_API_CONCURRENCY, 1) == 0);
  assert(setenv("MINERU_LOG_LEVEL", MINERU_LOG_LEVEL, 1) == 0);
  assert(setenv("DOCPIPE_IMG_MAX_WIDTH", IMG_MAX_WIDTH, 1) == 0);
  assert(setenv("DOCPIPE_IMG_QUALITY", IMG_QUALITY, 1) == 0);
  assert(setenv("DOCPIPE_IMG_MIN_SIDE_PT", IMG_MIN_SIDE_PT, 1) == 0);
  // 内置便携 python + PYTHONPATH = MINERU_DIR 源码 : MINERU_DEPS_DIR (见 config.hpp 注释, 顺序不能反),
  // 不用 venv/入口脚本, 全部路径均由 ctx.root 运行时拼出, 项目搬迁/换机器不受影响
  assert(setenv("PYTHONNOUSERSITE", "1", 1) == 0);
  assert(setenv("PYTHONPATH",
                (ctx.root + "/" + MINERU_DIR + ":" + ctx.root + "/" + MINERU_DEPS_DIR).c_str(),
                1) == 0);
  // 防御性加固: 禁止 huggingface/transformers 联网 (本地模型已齐备, 实测本就不联网, 这里加一层保险)
  assert(setenv("HF_HUB_OFFLINE", "1", 1) == 0);
  assert(setenv("TRANSFORMERS_OFFLINE", "1", 1) == 0);
  assert(setenv("HF_HUB_DISABLE_TELEMETRY", "1", 1) == 0);
  std::string py = ctx.root + "/" + MINERU_PYTHON_BIN;

  // ---- 并行度与批量: 按显存自动 (MINERU_WORKERS 非 0 则写死并行数) ----
  // 实测 (RTX 2060 6GB, batch_ratio=2): 单进程峰值显存 ~2.5GB ≈ 权重 1.5GB + 激活 0.5GB×ratio,
  // GPU 利用率仅 20%~80% 波动 (纯 CPU 阶段 GPU 干等), CPU 也只用 ~3 核 —— 并行 2 个进程错峰互补.
  // 批量: MinerU 按 get_vram 阶梯定 batch_ratio (pipeline_analyze.py: ≥32GB→16, ≥16→8, ≥8→4,
  // ≥6→2, 否则 1), 那是按独占整卡设计的; 这里按 "峰值估算 1.5+0.5×ratio ≤ 每进程显存份额
  // (总显存-1GB 桌面预留)/进程数" 取允许的最大档, 用 MINERU_VIRTUAL_VRAM_SIZE 报给每个进程
  int workers = MINERU_WORKERS;
  if (workers == 0)
    workers = (device == "cuda" && vram_gb >= 6) ? 2 : 1;
  if ((size_t)workers > pending.size() && !pending.empty())
    workers = (int)pending.size();
  if (device == "cuda") {
    double share = double(vram_gb - 1) / workers;
    int vvram = 1;
    constexpr int LADDER[][2] = {{16, 32}, {8, 16}, {4, 8}, {2, 6}}; // {batch_ratio, 虚拟显存GB}
    for (auto [r, v] : LADDER)
      if (1.5 + 0.5 * r <= share) {
        vvram = v;
        break;
      }
    assert(setenv("MINERU_VIRTUAL_VRAM_SIZE", std::to_string(vvram).c_str(), 1) == 0);
    if (n_todo)
      fprintf(stderr, "[convert] 显存%dGB: 并行%d个mineru, 每个按虚拟显存%dGB定批量\n", vram_gb,
              workers, vvram);
  }
  bool quiet = workers > 1; // 多进程时 tqdm 进度条交错刷屏, mineru stderr 改重定向到临时日志
  if (n_todo && !quiet)
    print_pipeline_steps(device);

  // 每个在跑的 mineru 子进程领一个目录; 各用独立暂存子目录 staging/j<gi> 防 stem 撞名
  struct Job {
    std::string folder;
    std::vector<size_t> idxs;
    std::string tmp;      // 软链临时目录
    std::string jstaging; // 本目录专属暂存子目录
    std::string log;      // quiet 时 mineru stderr 重定向文件 (tmp 内), 否则空
    std::vector<bool> seen;
    size_t dir_pages = 0;
    double t0 = 0;
    pid_t pid = -1;
  };

  std::vector<size_t> failed;
  std::vector<Job> running;
  size_t gi = 0, done_pages = 0;
  double t_start = now_ms(); // 并行下 s/页 与 ETA 按墙钟算
  auto next = pending.begin();

  auto spawn_job = [&](const std::string &folder, const std::vector<size_t> &idxs) {
    mkdirs(folder == "." ? proc : proc + "/" + folder);

    Job j;
    j.folder = folder;
    j.idxs = idxs;
    // 同目录待转 PDF 软链到临时目录, 一次调用, 模型只加载一次
    char tmp[] = "/tmp/docpipe-convert-XXXXXX";
    assert(mkdtemp(tmp) && "mkdtemp 失败");
    j.tmp = tmp;
    for (size_t i : idxs) {
      assert(symlink(pdfs[i].path.c_str(), (j.tmp + "/" + pdfs[i].name).c_str()) == 0);
      j.dir_pages += pages[i];
    }
    j.jstaging = staging + "/j" + std::to_string(++gi);
    j.seen.assign(idxs.size(), false);

    fprintf(stderr, "[convert] (%zu/%zu) %s: %zu个PDF %zu页", gi, pending.size(), folder.c_str(),
            idxs.size(), j.dir_pages);
    if (done_pages) {
      double sp = (now_ms() - t_start) / done_pages; // ms/页, 墙钟
      fprintf(stderr, "  [%.1fs/页, 剩余约%.0f分]", sp / 1000,
              sp * (todo_pages - done_pages) / 60000);
    }
    fprintf(stderr, "\n");
    j.t0 = now_ms();
    if (quiet)
      j.log = j.tmp + "/mineru.log";
    j.pid = spawn_cmd({py, "-m", "mineru.cli.client", "-p", j.tmp, "-o", j.jstaging, "-b",
                       MINERU_BACKEND, "-m", MINERU_METHOD, "-l", MINERU_LANG, "-f",
                       MINERU_FORMULA ? "true" : "false", "-t", MINERU_TABLE ? "true" : "false"},
                      j.log);
    running.push_back(std::move(j));
  };

  // 每秒探测各在跑目录已落盘的 md, 逐篇打印完成 (MinerU 按批出结果, 一批 1~3 篇)
  auto tick = [&] {
    for (Job &j : running)
      for (size_t k = 0; k < j.idxs.size(); ++k) {
        if (j.seen[k])
          continue;
        std::string s = stem(pdfs[j.idxs[k]].name);
        if (path_exists(j.jstaging + "/" + s + "/" + MINERU_METHOD + "/" + s + ".md")) {
          j.seen[k] = true;
          fprintf(stderr, "    ✓ %s (%d页, %.0fs)\n", pdfs[j.idxs[k]].name.c_str(),
                  pages[j.idxs[k]], (now_ms() - j.t0) / 1000);
        }
      }
  };

  while (next != pending.end() || !running.empty()) {
    while ((int)running.size() < workers && next != pending.end()) {
      spawn_job(next->first, next->second);
      ++next;
    }
    int code = 0;
    pid_t pid = wait_any(&code, tick);
    size_t ji = 0;
    while (ji < running.size() && running[ji].pid != pid)
      ++ji;
    assert(ji < running.size() && "wait_any 返回未知 pid");
    Job &j = running[ji];
    double dt = now_ms() - j.t0;
    done_pages += j.dir_pages;
    if (code != 0) {
      fprintf(stderr, "    mineru 退出码 %d (%s)\n", code, j.folder.c_str());
      if (quiet) { // stderr 进了日志文件, 打印尾部供排查 (日志随 tmp 一起删, 不留)
        std::string s = read_file(j.log);
        size_t pos = s.size() > 4096 ? s.find('\n', s.size() - 4096) + 1 : 0; // npos+1==0, 整读
        fprintf(stderr, "    ---- mineru 日志尾部 ----\n%s    ----\n", s.substr(pos).c_str());
      }
    }

    for (size_t i : j.idxs)
      assert(unlink((j.tmp + "/" + pdfs[i].name).c_str()) == 0);
    if (!j.log.empty())
      assert(unlink(j.log.c_str()) == 0);
    assert(rmdir(j.tmp.c_str()) == 0);

    // 以产物为准判定成败, 不信退出码 (单个文件失败时 mineru 非 0 但其余已写出);
    // 成功的搬平+写 .stat+原子换入最终位置, 失败的清掉暂存, 暂存子目录每目录结束后必空
    std::string out_dir = j.folder == "." ? proc : proc + "/" + j.folder;
    size_t n_fail = 0;
    for (size_t i : j.idxs) {
      std::string s = stem(pdfs[i].name);
      if (!finalize(j.jstaging + "/" + s, s, pdfs[i].size, out_dir + "/" + s)) {
        failed.push_back(i);
        ++n_fail;
        fprintf(stderr, "    ✗ %s\n", pdfs[i].name.c_str());
        remove_all(j.jstaging + "/" + s);
      }
    }
    if (path_exists(j.jstaging)) // mineru 启动即挂时可能根本没建过
      assert(rmdir(j.jstaging.c_str()) == 0 && "暂存子目录应已清空");
    fprintf(stderr, "    完成 %zu/%zu (%s), %.0fs (%.1fs/页)\n", j.idxs.size() - n_fail,
            j.idxs.size(), j.folder.c_str(), dt / 1000, dt / 1000 / j.dir_pages);
    running.erase(running.begin() + ji);
  }
  assert(rmdir(staging.c_str()) == 0 && "暂存区应为空");

  // 汇总: 与 scan 同风格的树状输出
  std::map<std::string, std::vector<std::string>> tree;
  for (size_t i : failed)
    tree[pdfs[i].folder].push_back(pdfs[i].name);
  printf("%s  (共%zu个PDF: 已完成%zu, 本次转换%zu, 失败%zu)\n", PROC_REPORT_DIR, pdfs.size(), n_done,
         n_todo - failed.size(), failed.size());
  size_t fi = 0;
  for (const auto &[folder, names] : tree) {
    bool last_folder = ++fi == tree.size();
    printf("%s── %s  (%zu)\n", last_folder ? "└" : "├", folder.c_str(), names.size());
    const char *indent = last_folder ? "    " : "│   ";
    for (size_t i = 0; i < names.size(); ++i)
      printf("%s%s── [失败:无md产物] %s\n", indent, i + 1 == names.size() ? "└" : "├",
             names[i].c_str());
  }
  return failed.empty() ? 0 : 1;
}
