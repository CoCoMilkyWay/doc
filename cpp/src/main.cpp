// 用法: docpipe <ROOT> [stage [--opt val ...]]...   不指定 stage 则按登记顺序全跑;
// 紧跟 stage 名之后的 "--opt val" 对归该 stage (Ctx::args), 由 stage 自行解释 (如 tag --one <json>)
#include <cassert>
#include <climits>
#include <cstdio>
#include <string>
#include <thread>
#include <unistd.h>
#include <vector>

#include "common/util.hpp"
#include "stage.hpp"

int main(int argc, char **argv) {
  assert(argc >= 2 && "用法: docpipe <ROOT> [stage [--opt val ...]]...");

  Ctx ctx;
  ctx.root = argv[1];
  while (ctx.root.size() > 1 && ctx.root.back() == '/')
    ctx.root.pop_back();
  ctx.workers = std::thread::hardware_concurrency();
  if (!ctx.workers)
    ctx.workers = 4;
  {
    char buf[PATH_MAX];
    ssize_t n = readlink("/proc/self/exe", buf, sizeof(buf) - 1);
    assert(n > 0 && "readlink /proc/self/exe 失败");
    ctx.self.assign(buf, (size_t)n);
  }

  std::vector<std::pair<Stage *, std::vector<std::string>>> todo;
  if (argc == 2) {
    for (Stage *s : all_stages())
      todo.emplace_back(s, std::vector<std::string>{});
  } else {
    for (int i = 2; i < argc; ++i) {
      std::string a = argv[i];
      if (a.starts_with("--")) { // 每个选项恰带一个值
        assert(!todo.empty() && "--选项须跟在 stage 名之后");
        assert(i + 1 < argc && "--选项缺值");
        todo.back().second.push_back(a);
        todo.back().second.push_back(argv[++i]);
        continue;
      }
      Stage *s = find_stage(a);
      assert(s && "未登记的 stage");
      todo.emplace_back(s, std::vector<std::string>{});
    }
  }

  for (auto &[s, args] : todo) {
    ctx.args = args;
    double t0 = now_ms();
    int code = s->run(ctx);
    fprintf(stderr, "[耗时] stage %s %.0fms (workers=%u)\n", s->name(), now_ms() - t0, ctx.workers);
    if (code)
      return code;
  }
  return 0;
}
