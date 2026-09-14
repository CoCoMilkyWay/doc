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
static void print_pipeline_steps() {
  fprintf(stderr, "[convert] MinerU 处理流程 (device=%s, 每个PDF依次经过以下阶段):\n", MINERU_DEVICE);
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
  check_mineru_env(ctx.root); // E1-E3

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
  if (n_todo)
    print_pipeline_steps();

  // MinerU 通过环境变量取设备与模型来源; 子进程继承
  assert(setenv("MINERU_DEVICE_MODE", MINERU_DEVICE, 1) == 0);
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

  std::vector<size_t> failed;
  size_t gi = 0, done_pages = 0;
  double spent_ms = 0; // 已完成目录的 mineru 累计耗时, 与 done_pages 一起给出 s/页 与 ETA
  for (const auto &[folder, idxs] : pending) {
    std::string out_dir = folder == "." ? proc : proc + "/" + folder;
    mkdirs(out_dir);

    // 同目录待转 PDF 软链到临时目录, 一次调用, 模型只加载一次
    char tmp[] = "/tmp/docpipe-convert-XXXXXX";
    assert(mkdtemp(tmp) && "mkdtemp 失败");
    size_t dir_pages = 0;
    for (size_t i : idxs) {
      assert(symlink(pdfs[i].path.c_str(), (std::string(tmp) + "/" + pdfs[i].name).c_str()) == 0);
      dir_pages += pages[i];
    }

    fprintf(stderr, "[convert] (%zu/%zu) %s: %zu个PDF %zu页", ++gi, pending.size(),
            folder.c_str(), idxs.size(), dir_pages);
    if (done_pages)
      fprintf(stderr, "  [%.1fs/页, 剩余约%.0f分]", spent_ms / 1000 / done_pages,
              spent_ms / done_pages * (todo_pages - done_pages) / 60000);
    fprintf(stderr, "\n");
    double t0 = now_ms();

    // 等待期间每秒探测 MinerU 已落盘的 md, 逐篇打印完成 (MinerU 按批出结果, 一批 1~3 篇)
    std::vector<bool> seen(idxs.size(), false);
    auto tick = [&] {
      for (size_t k = 0; k < idxs.size(); ++k) {
        if (seen[k])
          continue;
        std::string s = stem(pdfs[idxs[k]].name);
        if (path_exists(staging + "/" + s + "/" + MINERU_METHOD + "/" + s + ".md")) {
          seen[k] = true;
          fprintf(stderr, "    ✓ %s (%d页, %.0fs)\n", pdfs[idxs[k]].name.c_str(), pages[idxs[k]],
                  (now_ms() - t0) / 1000);
        }
      }
    };
    int code = run_cmd({py, "-m", "mineru.cli.client", "-p", tmp, "-o", staging, "-b",
                        MINERU_BACKEND, "-m", MINERU_METHOD, "-l", MINERU_LANG, "-f",
                        MINERU_FORMULA ? "true" : "false", "-t", MINERU_TABLE ? "true" : "false"},
                       tick);
    double dt = now_ms() - t0;
    spent_ms += dt;
    done_pages += dir_pages;
    if (code != 0)
      fprintf(stderr, "    mineru 退出码 %d\n", code);

    for (size_t i : idxs)
      assert(unlink((std::string(tmp) + "/" + pdfs[i].name).c_str()) == 0);
    assert(rmdir(tmp) == 0);

    // 以产物为准判定成败, 不信退出码 (单个文件失败时 mineru 非 0 但其余已写出);
    // 成功的搬平+写 .stat+原子换入最终位置, 失败的清掉暂存, 暂存区每目录结束后必为空
    size_t n_fail = 0;
    for (size_t i : idxs) {
      std::string s = stem(pdfs[i].name);
      if (!finalize(staging + "/" + s, s, pdfs[i].size, out_dir + "/" + s)) {
        failed.push_back(i);
        ++n_fail;
        fprintf(stderr, "    ✗ %s\n", pdfs[i].name.c_str());
        remove_all(staging + "/" + s);
      }
    }
    fprintf(stderr, "    完成 %zu/%zu, %.0fs (%.1fs/页)\n", idxs.size() - n_fail, idxs.size(),
            dt / 1000, dt / 1000 / dir_pages);
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
