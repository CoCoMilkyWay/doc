#include "common/proc.hpp"

#include <cassert>
#include <csignal>

#include <sys/wait.h>
#include <unistd.h>

// Ctrl+C 语义: 子进程自成进程组, SIGINT/SIGTERM 由本进程转发给整组 —— mineru 内部还会 fork
// worker, 只杀直接子进程会留下孤儿继续烧 CPU. 第二次 Ctrl+C 升级为 SIGKILL.
static volatile sig_atomic_t g_child_pgid = 0; // 运行中的子进程组, 0 表示无
static volatile sig_atomic_t g_got_sig = 0;    // 收到的信号编号, 0 表示未收到
static volatile sig_atomic_t g_n_sig = 0;

static void forward_sig(int sig) {
  g_got_sig = sig;
  if (g_child_pgid > 0) {
    sig_atomic_t n = g_n_sig + 1; // volatile 自增在 C++20 起弃用, 拆成读+写
    g_n_sig = n;
    kill(-g_child_pgid, n >= 2 ? SIGKILL : sig);
  }
}

int run_cmd(const std::vector<std::string> &argv, const std::function<void()> &on_tick) {
  assert(!argv.empty() && argv[0].starts_with('/'));
  std::vector<char *> av;
  for (const std::string &a : argv)
    av.push_back(const_cast<char *>(a.c_str()));
  av.push_back(nullptr);

  // glibc signal() 带 SA_RESTART: 转发完信号后 waitpid 自动续等, 保证给子进程收完尸再退出
  assert(signal(SIGINT, forward_sig) != SIG_ERR);
  assert(signal(SIGTERM, forward_sig) != SIG_ERR);

  pid_t pid = fork();
  assert(pid >= 0 && "fork 失败");
  if (pid == 0) {
    assert(setpgid(0, 0) == 0); // 自成进程组, 不再直接收终端的 Ctrl+C, 一律由父进程转发
    execv(av[0], av.data());
    _exit(127);
  }
  setpgid(pid, pid); // 父子各设一次消除竞态; 子进程已 exec 时返回 EACCES, 无妨
  g_child_pgid = pid;

  int st = 0;
  if (!on_tick) {
    assert(waitpid(pid, &st, 0) == pid);
  } else {
    for (;;) {
      pid_t r = waitpid(pid, &st, WNOHANG);
      if (r == pid)
        break;
      assert(r == 0);
      on_tick();
      sleep(1);
    }
  }
  g_child_pgid = 0;
  // 恢复默认处置, 否则两次 run_cmd 之间的 Ctrl+C 会被这个只管转发的处理函数吞掉
  assert(signal(SIGINT, SIG_DFL) != SIG_ERR);
  assert(signal(SIGTERM, SIG_DFL) != SIG_ERR);

  // 子进程已收尸, 本进程以同一信号自杀: 退出状态对上游 (shell/run.py) 正确, 且不会继续跑
  // 后面的目录与 stage
  if (g_got_sig)
    assert(raise(g_got_sig) == 0);

  if (WIFEXITED(st))
    return WEXITSTATUS(st);
  assert(WIFSIGNALED(st));
  return 128 + WTERMSIG(st);
}
