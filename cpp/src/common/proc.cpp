#include "common/proc.hpp"

#include <cassert>
#include <csignal>

#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

// Ctrl+C 语义: 每个子进程自成进程组, SIGINT/SIGTERM 由本进程转发给所有在跑的组 —— mineru 内部
// 还会 fork worker, 只杀直接子进程会留下孤儿继续烧 CPU. 第二次 Ctrl+C 升级为 SIGKILL.
static const int MAX_CHILDREN = 8;
static volatile sig_atomic_t g_pgids[MAX_CHILDREN]; // 在跑子进程组, 0 表示空槽
static volatile sig_atomic_t g_got_sig = 0;         // 收到的信号编号, 0 表示未收到
static volatile sig_atomic_t g_n_sig = 0;
static int g_n_children = 0; // 非空槽数 (只在主流程读写, 不进信号处理函数)

static void forward_sig(int sig) {
  g_got_sig = sig;
  sig_atomic_t n = g_n_sig + 1; // volatile 自增在 C++20 起弃用, 拆成读+写
  g_n_sig = n;
  for (int i = 0; i < MAX_CHILDREN; ++i)
    if (g_pgids[i] > 0)
      kill(-g_pgids[i], n >= 2 ? SIGKILL : sig);
}

pid_t spawn_cmd(const std::vector<std::string> &argv, const std::string &stderr_file) {
  assert(!argv.empty() && argv[0].starts_with('/'));
  int slot = -1;
  for (int i = 0; i < MAX_CHILDREN && slot < 0; ++i)
    if (g_pgids[i] == 0)
      slot = i;
  assert(slot >= 0 && "子进程槽位用尽");
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
    if (!stderr_file.empty()) {
      int fd = open(stderr_file.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
      assert(fd >= 0 && "stderr 日志文件创建失败");
      assert(dup2(fd, 2) == 2);
      close(fd);
    }
    execv(av[0], av.data());
    _exit(127);
  }
  setpgid(pid, pid); // 父子各设一次消除竞态; 子进程已 exec 时返回 EACCES, 无妨
  g_pgids[slot] = pid;
  ++g_n_children;
  return pid;
}

static void clear_slot(pid_t pid) {
  for (int i = 0; i < MAX_CHILDREN; ++i)
    if (g_pgids[i] == pid) {
      g_pgids[i] = 0;
      --g_n_children;
      return;
    }
  assert(false && "waitpid 收到未知子进程");
}

static int exit_code_of(int st) {
  if (WIFEXITED(st))
    return WEXITSTATUS(st);
  assert(WIFSIGNALED(st));
  return 128 + WTERMSIG(st);
}

pid_t wait_any(int *code, const std::function<void()> &on_tick) {
  assert(g_n_children > 0);
  int st = 0;
  pid_t pid;
  if (!on_tick) {
    pid = waitpid(-1, &st, 0);
    assert(pid > 0);
  } else {
    for (;;) {
      pid = waitpid(-1, &st, WNOHANG);
      assert(pid >= 0);
      if (pid > 0)
        break;
      on_tick();
      sleep(1);
    }
  }
  clear_slot(pid);

  // 收到过信号: 把其余子进程也收完尸, 然后以同一信号自杀 —— 不再返回调用方, 调用方不会
  // 继续 spawn 后面的目录与 stage; 退出状态对上游 (shell/run.py) 正确
  if (g_got_sig) {
    while (g_n_children > 0) {
      pid_t r = waitpid(-1, &st, 0);
      assert(r > 0);
      clear_slot(r);
    }
    assert(signal(SIGINT, SIG_DFL) != SIG_ERR);
    assert(signal(SIGTERM, SIG_DFL) != SIG_ERR);
    assert(raise(g_got_sig) == 0);
  }
  // 恢复默认处置, 否则两次调用之间的 Ctrl+C 会被这个只管转发的处理函数吞掉
  if (g_n_children == 0) {
    assert(signal(SIGINT, SIG_DFL) != SIG_ERR);
    assert(signal(SIGTERM, SIG_DFL) != SIG_ERR);
  }
  *code = exit_code_of(st);
  return pid;
}

int run_cmd(const std::vector<std::string> &argv, const std::function<void()> &on_tick) {
  pid_t pid = spawn_cmd(argv);
  int code = 0;
  pid_t r = wait_any(&code, on_tick);
  assert(r == pid);
  return code;
}
