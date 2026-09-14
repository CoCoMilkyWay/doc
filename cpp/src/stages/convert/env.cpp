#include "stages/convert/convert.hpp"

#include <cassert>
#include <cstdio>
#include <vector>

#include "common/fs.hpp"
#include "common/proc.hpp"
#include "config.hpp"

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

void check_mineru_env(const std::string &root) {
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
  if (run_cmd({py, "-c", "import mineru, torch, onnxruntime, transformers"}) != 0) {
    fprintf(stderr,
            "[环境] MINERU_DEPS_DIR 依赖不完整: %s\n"
            "解决办法 (必须一条命令装全: pip --target 不把目标目录当已装环境, 分两步先装 CPU torch\n"
            "  再装 [pipeline] 的话, 第二步会重新解析 torch 并从 PyPI 拉回 CUDA 版, 白占 4G;\n"
            "  torch 家族走 cpu 源, 其余走 PyPI, +cpu 本地版本号按 PEP 440 高于裸版本, 解析稳定胜出;\n"
            "  --target 装到相对目录, 不装进内置 python 自身, 保持其干净可复用;\n"
            "  PYTHONNOUSERSITE=1 必须带, 否则 pip 本身会先从 ~/.local 找, 装出来的东西不纯净):\n"
            "  PYTHONNOUSERSITE=1 %s -m pip install --target=%s \\\n"
            "    --index-url https://download.pytorch.org/whl/cpu \\\n"
            "    --extra-index-url https://pypi.org/simple \"%s[pipeline]\"\n",
            deps.c_str(), py.c_str(), deps.c_str(), src.c_str());
    assert(false && "E2 依赖缺失");
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
}
