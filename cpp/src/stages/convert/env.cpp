#include "stages/convert/convert.hpp"

#include <cassert>
#include <cstdio>
#include <vector>

#include "common/fs.hpp"
#include "common/proc.hpp"
#include "config.hpp"

// 本机有没有 NVIDIA 卡. E2 之前就要用它决定给哪套安装指令, 那时 torch 还没装, 只能看驱动:
// /proc/driver/nvidia/version 由内核模块创建, 驱动一加载就有, 不依赖 PATH 里是否有 nvidia-smi
static bool has_nvidia_gpu() { return path_exists("/proc/driver/nvidia/version"); }

// E2 一次子进程同时回答两件事, 省掉重复 import torch 的几秒:
// 退出码 0=依赖齐全且 CUDA 可用, 3=依赖齐全但只能 CPU, 其余(python 自身的 1)=import 失败,
// 缺什么由 python 自己的 traceback 打到 stderr. 判据与 mineru/utils/config_reader.py
// get_device() 一致, 所以这里探到什么, MinerU 实际就会用什么
static const char *DEPS_PROBE_PY =
    "import sys, mineru, torch, onnxruntime, transformers\n"
    "sys.exit(0 if torch.cuda.is_available() else 3)\n";

// E2 的安装指令. CPU/GPU 两套只差 --index-url 与 extra 名, 其余道理相同:
//   必须一条命令装全: pip --target 不把目标目录当已装环境, 分两步先装 torch 再装 extra 的话,
//     第二步会重新解析 torch 并从 PyPI 拉回另一个版本, 白占几个 G;
//   torch 家族走 pytorch 源, 其余走 PyPI, +cpu/+cu130 本地版本号按 PEP 440 高于裸版本, 解析稳定胜出;
//   --target 装到相对目录, 不装进内置 python 自身, 保持其干净可复用;
//   PYTHONNOUSERSITE=1 必须带, 否则 pip 本身会先从 ~/.local 找, 装出来的东西不纯净;
//   先 rm -rf: pip --target 只覆盖同名文件、不卸载旧包, 而 onnxruntime 与 onnxruntime-gpu 是两个包
//     却共用同一个 onnxruntime/ 模块目录, CPU/GPU 之间来回切时不清空就会新旧文件混在一起
static void print_install_cmd(const std::string &py, const std::string &deps,
                              const std::string &src, bool gpu) {
  fprintf(stderr,
          "  rm -rf %s && PYTHONNOUSERSITE=1 %s -m pip install --target=%s \\\n"
          "    --index-url https://download.pytorch.org/whl/%s \\\n"
          "    --extra-index-url https://pypi.org/simple \"%s[%s]\"\n",
          deps.c_str(), py.c_str(), deps.c_str(), gpu ? "cu130" : "cpu", src.c_str(),
          gpu ? "pipeline-gpu" : "pipeline");
}

// argv: <config.json 绝对路径> <必须存在的模型子路径>...
// 退出码 2=配置文件不存在 3=未配置 models-dir.pipeline 4=有模型缺失
static const char *MODEL_CHECK_PY = R"PY(
import json, os, sys
cfg = sys.argv[1]
if not os.path.isfile(cfg):
    sys.exit(2)
root = (json.load(open(cfg, encoding='utf-8')).get('models-dir') or {}).get('pipeline') or ''
if not root:
    sys.exit(3)
root = os.path.expanduser(root)
missing = [p for p in sys.argv[2:] if not os.path.exists(os.path.join(root, p))]
for p in missing:
    print('[环境] 缺少模型:', os.path.join(root, p), file=sys.stderr)
sys.exit(4 if missing else 0)
)PY";

std::string check_mineru_env(const std::string &root) {
  std::string src = root + "/" + MINERU_DIR;
  std::string py = root + "/" + MINERU_PYTHON_BIN;
  std::string deps = root + "/" + MINERU_DEPS_DIR;
  std::string config_json = root + "/" + MINERU_CONFIG_JSON;
  std::string models_cache = root + "/" + MINERU_MODELS_CACHE_DIR;

  // 配置文件与模型缓存改到项目内相对路径 (MinerU 原版默认写 ~), 全部由 ctx.root 现算, 随项目搬迁/
  // 换机器可用; 子进程 (pip install/mineru-models-download/mineru) 均继承这两个环境变量
  assert(setenv("MINERU_TOOLS_CONFIG_JSON", config_json.c_str(), 1) == 0);
  assert(setenv("MODELSCOPE_CACHE", models_cache.c_str(), 1) == 0);

  // E1 内置便携 python (自带 pip, 不依赖系统 python; 与项目路径无关的部分只在系统 glibc, 整目录搬迁/换机器可用)
  if (!path_exists(py)) {
    fprintf(stderr,
            "[环境] 缺少内置便携 python: %s\n"
            "解决办法 (python-build-standalone, install_only_stripped, x86_64-unknown-linux-gnu):\n"
            "  curl -L -o /tmp/cpython.tar.gz "
            "https://github.com/astral-sh/python-build-standalone/releases/download/"
            "20260310/cpython-3.12.13+20260310-x86_64-unknown-linux-gnu-install_only_stripped.tar.gz\n"
            "  tar -xzf /tmp/cpython.tar.gz -C /tmp && mv /tmp/python %s/%s\n",
            py.c_str(), root.c_str(), MINERU_PYTHON_DIR);
    assert(false && "E1 缺少内置 python");
  }

  // E2 依赖 (装在项目内相对目录 MINERU_DEPS_DIR, 不用 venv: venv 会把创建时的绝对路径写死进
  // pyvenv.cfg/activate, 项目搬迁即失效. PYTHONNOUSERSITE=1 保证不会误捡系统/用户目录里的包,
  // 确保这里检测到的就是真正会在运行时用到的依赖). MINERU_DIR 源码在前, 压过 deps 里的 mineru 拷贝
  assert(setenv("PYTHONNOUSERSITE", "1", 1) == 0);
  assert(setenv("PYTHONPATH", (src + ":" + deps).c_str(), 1) == 0);
  bool gpu = has_nvidia_gpu();
  int rc = run_cmd({py, "-c", DEPS_PROBE_PY});
  if (rc != 0 && rc != 3) {
    fprintf(stderr, "[环境] MINERU_DEPS_DIR 依赖不完整: %s\n解决办法 (本机%s, 装%s版):\n",
            deps.c_str(), gpu ? "有 NVIDIA 卡" : "无 NVIDIA 卡", gpu ? " GPU " : " CPU ");
    print_install_cmd(py, deps, src, gpu);
    assert(false && "E2 依赖缺失");
  }
  bool cuda_ok = rc == 0;

  // 定下这次实际用的设备. MINERU_DEVICE 写死 "cpu"/"cuda" 时照用 (写死 cuda 就必须真能用),
  // "auto" 则按探测结果走 —— 这就是 CPU/GPU 通用的地方: 同一份代码, 有卡的机器自动 cuda
  std::string device = MINERU_DEVICE;
  if (device == "auto") {
    // 有卡却装了 CPU 版: import 全过, 但 torch.cuda.is_available() 为假, 真跑起来仍是 CPU,
    // 慢几十倍且毫无提示. 与其静默慢, 不如在这里失败并给出 GPU 版指令
    if (gpu && !cuda_ok) {
      fprintf(stderr,
              "[环境] 本机有 NVIDIA 卡, 但 %s 里的 torch 不带 CUDA (装成 CPU 版了), 再跑也只会用 "
              "CPU\n解决办法 (重装成 GPU 版; 若确实就想用 CPU 跑, 把 config.hpp 的 MINERU_DEVICE "
              "写死 \"cpu\" 可跳过本检查):\n",
              deps.c_str());
      print_install_cmd(py, deps, src, true);
      assert(false && "E2 有 GPU 却装了 CPU 版 torch");
    }
    device = cuda_ok ? "cuda" : "cpu";
  } else {
    assert((device != "cuda" || cuda_ok) && "MINERU_DEVICE 写死 cuda, 但 torch 报告 CUDA 不可用");
  }

  // E3 模型
  std::vector<std::string> cmd = {py, "-c", MODEL_CHECK_PY, config_json};
  for (const char *m : MINERU_PIPELINE_MODELS)
    cmd.push_back(m);
  if (run_cmd(cmd) != 0) {
    fprintf(stderr,
            "[环境] pipeline 模型未就绪 (%s 不存在, 或其 models-dir.pipeline 下模型不全)\n"
            "解决办法 (约 1~2GB, 走 modelscope 国内快; 下载完会自动写 %s;\n"
            "  PYTHONNOUSERSITE=1 必须带, 否则会误捡 ~/.local 下无关/不全的包导致 import 报错):\n"
            "  PYTHONNOUSERSITE=1 PYTHONPATH=%s:%s MODELSCOPE_CACHE=%s MINERU_TOOLS_CONFIG_JSON=%s "
            "%s -m mineru.cli.models_download -s modelscope -m pipeline\n",
            config_json.c_str(), config_json.c_str(), src.c_str(), deps.c_str(),
            models_cache.c_str(), config_json.c_str(), py.c_str());
    assert(false && "E3 模型缺失");
  }

  return device;
}
