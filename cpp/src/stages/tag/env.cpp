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
// T2 一次子进程把 tag_loop.py 真正要用到的 SDK 接口全查一遍 (只 import 与签名, 不联网, 不建 agent):
// 0=齐全 1=没装 其余=装了但与本项目用法不符 (原因由 python 自己打到 stderr)。
// 查的是 tag_loop.py 对 SDK 的三条假设, 与其说是"检查依赖", 不如说是把假设钉在这里 —— 万一某版 SDK
// 改了这些, 在环境检查就失败, 而不是跑到第一篇 (或第几百篇) 才炸:
//   1) 云端代理不需要 bridge: 按文档"显式实例化 AsyncClient", api_key 随 agents.create 传, 故构造器不能有必填参数
//   2) AsyncClient 是异步上下文管理器 (我们用 async with 管它的生命周期)
//   3) CloudAgentOptions 有 repos (给 [] = 无仓库) 和 metadata (打标记, 供清理上次泄漏的 agent)
static const char *SDK_PROBE_PY = R"PY(
import dataclasses, inspect, sys
try:
    import cursor_sdk
except ModuleNotFoundError:
    sys.exit(1)
missing = [n for n in ('AsyncClient', 'AsyncCursor', 'CloudAgentOptions', 'CursorAgentError')
           if not hasattr(cursor_sdk, n)]
if missing:
    print('[环境] cursor_sdk 缺少本项目用到的接口:', ' '.join(missing), file=sys.stderr)
    sys.exit(3)
req = [p.name for p in inspect.signature(cursor_sdk.AsyncClient.__init__).parameters.values()
       if p.name != 'self' and p.default is inspect.Parameter.empty
       and p.kind in (p.POSITIONAL_OR_KEYWORD, p.KEYWORD_ONLY)]
if req:
    print('[环境] cursor_sdk.AsyncClient 需要必填参数:', ' '.join(req), file=sys.stderr)
    sys.exit(4)
if not all(hasattr(cursor_sdk.AsyncClient, n) for n in ('__aenter__', '__aexit__')):
    print('[环境] cursor_sdk.AsyncClient 不是异步上下文管理器', file=sys.stderr)
    sys.exit(5)
opt = cursor_sdk.CloudAgentOptions
fields = {f.name for f in dataclasses.fields(opt)} if dataclasses.is_dataclass(opt) else set()
if not {'repos', 'metadata'} <= fields:
    print('[环境] cursor_sdk.CloudAgentOptions 字段不符:', ' '.join(sorted(fields)), file=sys.stderr)
    sys.exit(6)
print('[环境] cursor-sdk', getattr(cursor_sdk, '__version__', '?'), file=sys.stderr)
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
          "    --target=$PY_DEPS cursor-sdk\n",
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

  // T2 cursor-sdk. 这两个环境变量子进程 (探测与 tag_loop.py) 都继承, 所以这里探到的就是运行时会用到的那份
  assert(setenv("PYTHONNOUSERSITE", "1", 1) == 0);
  assert(setenv("PYTHONPATH", deps.c_str(), 1) == 0);
  int rc = run_cmd({py, "-c", SDK_PROBE_PY});
  if (rc != 0) {
    fprintf(stderr, "[环境] cursor-sdk %s (装在 %s)\n解决办法 (装/升到最新版):\n",
            rc == 1 ? "未安装" : "与本项目用法不符, 见上一行", deps.c_str());
    print_install_cmd(py, deps);
    assert(false && "T2 cursor-sdk 缺失或不合用");
  }
}
