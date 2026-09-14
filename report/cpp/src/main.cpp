// 用法: docpipe <ROOT> [stage...]   不指定 stage 则按登记顺序全跑
#include <cassert>
#include <string>
#include <thread>
#include <vector>

#include "stage.hpp"

int main(int argc, char **argv) {
  assert(argc >= 2 && "用法: docpipe <ROOT> [stage...]");

  Ctx ctx;
  ctx.root = argv[1];
  while (ctx.root.size() > 1 && ctx.root.back() == '/')
    ctx.root.pop_back();
  ctx.workers = std::thread::hardware_concurrency();
  if (!ctx.workers)
    ctx.workers = 4;

  std::vector<Stage *> todo;
  if (argc == 2) {
    todo = all_stages();
  } else {
    for (int i = 2; i < argc; ++i) {
      Stage *s = find_stage(argv[i]);
      assert(s && "未登记的 stage");
      todo.push_back(s);
    }
  }

  for (Stage *s : todo) {
    int code = s->run(ctx);
    if (code)
      return code;
  }
  return 0;
}
