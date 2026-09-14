#include "common/fs.hpp"

#include <algorithm>
#include <cassert>
#include <cerrno>
#include <cstdio>

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

bool path_exists(const std::string &p) {
  struct stat st;
  return stat(p.c_str(), &st) == 0;
}

bool is_dir(const std::string &p) {
  struct stat st;
  return stat(p.c_str(), &st) == 0 && S_ISDIR(st.st_mode);
}

void list_dir(const std::string &path, std::vector<std::string> &dirs,
              std::vector<std::string> &files) {
  DIR *dp = opendir(path.c_str());
  assert(dp && "无法打开目录");
  while (struct dirent *e = readdir(dp)) {
    std::string n = e->d_name;
    if (n == "." || n == "..")
      continue;
    struct stat st;
    assert(lstat((path + "/" + n).c_str(), &st) == 0);
    if (S_ISLNK(st.st_mode))
      continue;
    (S_ISDIR(st.st_mode) ? dirs : files).push_back(n);
  }
  closedir(dp);
  std::sort(dirs.begin(), dirs.end());
  std::sort(files.begin(), files.end());
}

void mkdirs(const std::string &path) {
  for (size_t i = 1; i <= path.size(); ++i) {
    if (i != path.size() && path[i] != '/')
      continue;
    std::string prefix = path.substr(0, i);
    if (mkdir(prefix.c_str(), 0755) != 0)
      assert(errno == EEXIST && "mkdir 失败");
  }
  assert(is_dir(path));
}

long long file_size(const std::string &path) {
  struct stat st;
  assert(stat(path.c_str(), &st) == 0 && S_ISREG(st.st_mode) && "不是普通文件");
  return (long long)st.st_size;
}

static void list_tree_rec(const std::string &dir, const std::string &rel,
                          std::vector<std::string> &out) {
  std::string abs = rel.empty() ? dir : dir + "/" + rel;
  DIR *dp = opendir(abs.c_str());
  assert(dp && "无法打开目录");
  std::vector<std::string> dirs, files; // files 直接存成整行
  while (struct dirent *e = readdir(dp)) {
    std::string n = e->d_name;
    if (n == "." || n == "..")
      continue;
    struct stat st;
    assert(lstat((abs + "/" + n).c_str(), &st) == 0);
    std::string r = rel.empty() ? n : rel + "/" + n;
    if (S_ISDIR(st.st_mode))
      dirs.push_back(n);
    else // 符号链接/设备等一律按文件计入, 让清单比对能发现它们
      files.push_back("F " + std::to_string((long long)st.st_size) + " " + r);
  }
  closedir(dp);
  std::sort(dirs.begin(), dirs.end());
  std::sort(files.begin(), files.end());
  for (const std::string &d : dirs) {
    std::string r = rel.empty() ? d : rel + "/" + d;
    out.push_back("D " + r);
    list_tree_rec(dir, r, out);
  }
  for (std::string &f : files)
    out.push_back(std::move(f));
}

void list_tree(const std::string &dir, std::vector<std::string> &out) { list_tree_rec(dir, "", out); }

void remove_all(const std::string &path) {
  struct stat st;
  if (lstat(path.c_str(), &st) != 0) {
    assert(errno == ENOENT);
    return;
  }
  if (S_ISDIR(st.st_mode)) {
    DIR *dp = opendir(path.c_str());
    assert(dp && "无法打开目录");
    std::vector<std::string> names;
    while (struct dirent *e = readdir(dp)) {
      std::string n = e->d_name;
      if (n != "." && n != "..")
        names.push_back(n);
    }
    closedir(dp);
    for (const std::string &n : names)
      remove_all(path + "/" + n);
    assert(rmdir(path.c_str()) == 0 && "rmdir 失败");
  } else {
    assert(unlink(path.c_str()) == 0 && "unlink 失败");
  }
}

std::string read_file(const std::string &path) {
  FILE *f = fopen(path.c_str(), "rb");
  assert(f && "文件打不开");
  std::string s;
  char buf[65536];
  for (size_t n; (n = fread(buf, 1, sizeof buf, f)) > 0;)
    s.append(buf, n);
  assert(!ferror(f));
  fclose(f);
  return s;
}

void write_file(const std::string &path, const std::string &data) {
  std::string tmp = path + ".tmp";
  FILE *f = fopen(tmp.c_str(), "wb");
  assert(f && "文件无法创建");
  assert(fwrite(data.data(), 1, data.size(), f) == data.size());
  assert(fclose(f) == 0);
  assert(rename(tmp.c_str(), path.c_str()) == 0);
}
