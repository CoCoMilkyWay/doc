#include "stages/tag/tag.hpp"

#include <cassert>
#include <cstdio>
#include <cstdlib>

#include "common/fs.hpp"
#include "common/proc.hpp"
#include "config.hpp"

// stage3 阶段一 (agent loop) 的环境检查, 口径与 convert 的 E1/E2 一致: 用项目内置便携 python (PYTHON_BIN),
// 依赖装在各 stage 共享的 PYTHON_DEPS_DIR (pip --target, 为什么这么放见 config.hpp 那里的注释),
// 运行时用 PYTHONPATH 指过去; 缺什么就打印可直接粘的安装指令然后断言.
//
// T2 一次子进程把 tag_loop.py 真正要用到的 SDK 接口全查一遍 (只 import 与签名, 不联网, 不建客户端):
// 0=齐全 1=没装 其余=装了但与本项目用法不符 (原因由 python 自己打到 stderr)。
// 查的是 tag_loop.py 对 zai-sdk 的几条假设, 与其说是"检查依赖", 不如说是把假设钉在这里 —— 万一某版 SDK
// 改了这些, 在环境检查就失败, 而不是跑到第一篇 (或第几百篇) 才炸:
//   1) zai.ZhipuAiClient 存在 (国内 open.bigmodel.cn 端点的客户端; ZaiClient 是海外 api.z.ai 的)
//   2) chat.completions.create 收 model / messages / stream / response_format / thinking / reasoning_effort / request_id 关键字
//      (response_format=json_object 是平台 JSON 模式, 保证 content 可解析; thinking 显式 enabled, 强度靠 reasoning_effort;
//       stream 用于躲 300s 读超时; request_id 用于和服务端对账)
//   3) zai.core 暴露 tag_loop.py 用来分类异常的几个类 (ZaiError 基类, 401/400/429 各自的子类)
//   4) httpx 可 import (zai-sdk 的依赖, 流中途断连抛的是裸 httpx 异常)
static const char *SDK_PROBE_PY = R"PY(
import inspect, sys
try:
    import zai
except ModuleNotFoundError:
    sys.exit(1)
if not hasattr(zai, 'ZhipuAiClient'):
    print('[环境] zai 缺少 ZhipuAiClient', file=sys.stderr)
    sys.exit(3)
from zai.api_resource.chat.completions import Completions
params = set(inspect.signature(Completions.create).parameters)
need = {'model', 'messages', 'stream', 'response_format', 'thinking', 'reasoning_effort', 'request_id'}
if not need <= params:
    print('[环境] zai chat.completions.create 缺少关键字:', ' '.join(sorted(need - params)), file=sys.stderr)
    sys.exit(4)
import zai.core
missing = [n for n in ('ZaiError', 'APIAuthenticationError', 'APIRequestFailedError', 'APIReachLimitError')
           if not hasattr(zai.core, n)]
if missing:
    print('[环境] zai.core 缺少异常类:', ' '.join(missing), file=sys.stderr)
    sys.exit(5)
try:
    import httpx
except ModuleNotFoundError:
    print('[环境] 缺少 httpx (zai-sdk 的依赖, 装 zai-sdk 时应一并装上)', file=sys.stderr)
    sys.exit(6)
print('[环境] zai-sdk', zai.__version__, 'httpx', httpx.__version__, file=sys.stderr)
)PY";

// 与 MinerU 的安装指令同理: 长路径先落成 shell 变量, 每行压到 70 列以内 (这些指令是给人复制粘贴的,
// 长行被终端折行后若折在空格上, 粘出来就是粘连的错参数); PYTHONNOUSERSITE=1 必须带, 否则 pip 会先
// 从 ~/.local 找, 装出来的东西不纯净; --upgrade 必须带, 否则 pip 拒绝往已有别的包的 --target 目录里覆盖.
// 不 rm -rf 目标目录: 那是共享的, 会连 MinerU 那 1.6G 一起删
static void print_install_cmd(const std::string &py, const std::string &deps) {
  fprintf(stderr,
          "  PY_DEPS=%s\n"
          "  PY=%s\n"
          "  PYTHONNOUSERSITE=1 $PY -m pip install --upgrade \\\n"
          "    --target=$PY_DEPS zai-sdk\n",
          deps.c_str(), py.c_str());
}

void check_tag_env(const std::string &root) {
  std::string py = root + "/" + PYTHON_BIN;
  std::string deps = root + "/" + PYTHON_DEPS_DIR;

  // T1 内置便携 python (与 convert 的 E1 同一份, 缺失时的装法也一样)
  if (!path_exists(py)) {
    fprintf(stderr,
            "[环境] 缺少内置便携 python: %s\n"
            "解决办法 (python-build-standalone, install_only_stripped, x86_64-unknown-linux-gnu):\n"
            "  curl -L -o /tmp/cpython.tar.gz "
            "https://github.com/astral-sh/python-build-standalone/releases/download/"
            "20260310/cpython-3.12.13+20260310-x86_64-unknown-linux-gnu-install_only_stripped.tar.gz\n"
            "  tar -xzf /tmp/cpython.tar.gz -C /tmp && mv /tmp/python %s/%s\n",
            py.c_str(), root.c_str(), PYTHON_DIR);
    assert(false && "T1 缺少内置 python");
  }

  // T2 zai-sdk. 这两个环境变量子进程 (探测与 tag_loop.py) 都继承, 所以这里探到的就是运行时会用到的那份
  assert(setenv("PYTHONNOUSERSITE", "1", 1) == 0);
  assert(setenv("PYTHONPATH", deps.c_str(), 1) == 0);
  int rc = run_cmd({py, "-c", SDK_PROBE_PY});
  if (rc != 0) {
    fprintf(stderr, "[环境] zai-sdk %s (装在 %s)\n解决办法 (装/升到最新版):\n",
            rc == 1 ? "未安装" : "与本项目用法不符, 见上一行", deps.c_str());
    print_install_cmd(py, deps);
    assert(false && "T2 zai-sdk 缺失或不合用");
  }
}
