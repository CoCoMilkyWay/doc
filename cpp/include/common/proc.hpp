// 子进程执行。
#pragma once

#include <functional>
#include <string>
#include <vector>

// fork+execv argv[0] (须为绝对路径), 继承 stdio 与环境变量, 阻塞到结束。
// on_tick 非空: 等待期间每秒回调一次 (用于打印进度)。
// 返回退出码; 被信号终止返回 128+signo; exec 失败子进程以 127 退出。
// Ctrl+C (SIGINT) / SIGTERM 会转发给子进程组并等其退出, 随后本进程以同一信号自杀, 不再返回。
int run_cmd(const std::vector<std::string> &argv, const std::function<void()> &on_tick = {});

// 非阻塞启动 (可同时挂多个子进程, 供 convert 并行跑 mineru): fork+execv, 子进程自成进程组,
// stderr_file 非空则子进程 stderr 重定向到该文件 (截断创建), 其余同 run_cmd. 返回 pid.
// Ctrl+C/SIGTERM 转发给所有在跑的子进程组。
pid_t spawn_cmd(const std::vector<std::string> &argv, const std::string &stderr_file = "");

// 阻塞等待任一 spawn_cmd 子进程退出, 返回其 pid, *code 填退出码 (口径同 run_cmd)。
// on_tick 非空: 等待期间每秒回调一次。收到过 Ctrl+C/SIGTERM 时: 等所有子进程退完,
// 本进程以同一信号自杀, 不再返回。
pid_t wait_any(int *code, const std::function<void()> &on_tick = {});
