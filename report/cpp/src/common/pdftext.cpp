#include "common/pdftext.hpp"

#include <cassert>
#include <string>

#include <fcntl.h>
#include <spawn.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

int pdf_has_text(const std::string &path, int pages) {
  int pipefd[2];
  assert(pipe2(pipefd, O_CLOEXEC) == 0); // CLOEXEC: 避免并发 spawn 时管道端互相泄漏

  posix_spawn_file_actions_t fa;
  assert(posix_spawn_file_actions_init(&fa) == 0);
  posix_spawn_file_actions_adddup2(&fa, pipefd[1], STDOUT_FILENO);
  posix_spawn_file_actions_addopen(&fa, STDERR_FILENO, "/dev/null", O_WRONLY, 0);
  posix_spawn_file_actions_addclose(&fa, pipefd[0]);
  posix_spawn_file_actions_addclose(&fa, pipefd[1]);

  std::string npages = std::to_string(pages);
  char *argv[] = {
      (char *)"pdftotext", (char *)"-q", (char *)"-l", (char *)npages.c_str(),
      (char *)path.c_str(), (char *)"-", nullptr};
  pid_t pid;
  assert(posix_spawnp(&pid, "pdftotext", &fa, nullptr, argv, environ) == 0 &&
         "无法启动 pdftotext");
  posix_spawn_file_actions_destroy(&fa);
  close(pipefd[1]);

  bool any = false; // 去掉换页符与空白后是否还有内容
  char buf[1 << 16];
  for (;;) {
    ssize_t n = read(pipefd[0], buf, sizeof buf);
    assert(n >= 0 && "读取 pdftotext 输出失败");
    if (n == 0)
      break;
    for (ssize_t i = 0; i < n && !any; ++i) {
      unsigned char c = (unsigned char)buf[i];
      if (c != '\f' && c != ' ' && c != '\t' && c != '\n' && c != '\r' && c != '\v')
        any = true;
    }
  }
  close(pipefd[0]);

  int status = 0;
  assert(waitpid(pid, &status, 0) == pid);
  if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
    return -1;
  return any ? 1 : 0;
}
