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
