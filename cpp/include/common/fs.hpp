// 目录与路径小工具 (POSIX)。
#pragma once

#include <string>
#include <vector>

bool path_exists(const std::string &p);
bool is_dir(const std::string &p);

// 列出目录项: 不跟随也不收录符号链接, 目录与文件分开并按字节序排序保证输出稳定; 打不开则断言失败
void list_dir(const std::string &path, std::vector<std::string> &dirs,
              std::vector<std::string> &files);

// mkdir -p
void mkdirs(const std::string &path);

// 普通文件大小; 不存在或不是普通文件则断言失败
long long file_size(const std::string &path);

// 递归列出 dir 下全部条目 (不跟随符号链接), 每项一行, 顺序稳定 (目录先于文件, 同层按字节序):
//   "D <相对路径>"            目录
//   "F <字节数> <相对路径>"   文件
// 用作目录内容清单 / 完整性比对
void list_tree(const std::string &dir, std::vector<std::string> &out);

// rm -rf (path 不存在也算成功); 不跟随符号链接
void remove_all(const std::string &path);

// 整文件读入 / 整文件写出 (先写临时文件再 rename, 不留半截文件)
std::string read_file(const std::string &path);
void write_file(const std::string &path, const std::string &data);
