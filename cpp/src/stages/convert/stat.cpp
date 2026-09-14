#include "stages/convert/convert.hpp"

#include <algorithm>
#include <cassert>
#include <cstdlib>

#include "common/fs.hpp"
#include "common/sha256.hpp"
#include "common/util.hpp"
#include "config.hpp"

static const char *MAGIC = "docpipe-stat 1";

// 现算 doc_dir 的清单行 (剔除 .stat 自身及其写入时的临时文件)
static std::vector<std::string> entries(const std::string &doc_dir) {
  std::vector<std::string> all, out;
  list_tree(doc_dir, all);
  std::string self = std::string(" ") + PROC_STAT_NAME;
  for (std::string &e : all)
    if (!e.ends_with(self) && !e.ends_with(self + ".tmp"))
      out.push_back(std::move(e));
  return out;
}

// 清单行 -> 相对路径: "D rel" / "F size rel"
static std::string rel_of(const std::string &line) {
  size_t p = line[0] == 'D' ? 1 : line.find(' ', 2);
  return line.substr(p + 1);
}

static std::string hash_of(const std::vector<std::string> &lines) {
  Sha256 h;
  for (const std::string &l : lines) {
    h.update((const uint8_t *)l.data(), l.size());
    h.update((const uint8_t *)"\n", 1);
  }
  return h.hex();
}

void write_stat(const std::string &doc_dir, long long pdf_size) {
  std::vector<std::string> es = entries(doc_dir);
  assert(!es.empty() && "空目录不该写 .stat");
  std::string s = F("%s\npdf %lld\nhash %s\n", MAGIC, pdf_size, hash_of(es).c_str());
  for (const std::string &e : es)
    s += e + "\n";
  write_file(doc_dir + "/" + PROC_STAT_NAME, s);
}

std::string verify_stat(const std::string &doc_dir, long long pdf_size) {
  std::string stat_path = doc_dir + "/" + PROC_STAT_NAME;
  if (!path_exists(stat_path))
    return F("不完整:无%s", PROC_STAT_NAME);
  std::vector<std::string> lines = split(read_file(stat_path), '\n');
  if (!lines.empty() && lines.back().empty())
    lines.pop_back();
  if (lines.size() < 3 || lines[0] != MAGIC || !lines[1].starts_with("pdf ") ||
      !lines[2].starts_with("hash "))
    return F("不完整:%s格式损坏", PROC_STAT_NAME);
  long long recorded = atoll(lines[1].c_str() + 4);
  if (recorded != pdf_size)
    return F("源PDF已变:大小 %lld -> %lld", recorded, pdf_size);
  std::vector<std::string> want(lines.begin() + 3, lines.end());
  if (lines[2].substr(5) != hash_of(want))
    return F("不完整:%s清单与其hash不符", PROC_STAT_NAME);

  // 按相对路径归并, 找出第一处差异
  std::vector<std::string> have = entries(doc_dir);
  std::sort(want.begin(), want.end(), [](const std::string &a, const std::string &b) {
    return rel_of(a) < rel_of(b);
  });
  std::sort(have.begin(), have.end(), [](const std::string &a, const std::string &b) {
    return rel_of(a) < rel_of(b);
  });
  size_t i = 0, j = 0;
  while (i < want.size() || j < have.size()) {
    if (j == have.size() || (i < want.size() && rel_of(want[i]) < rel_of(have[j])))
      return "不完整:缺 " + rel_of(want[i]);
    if (i == want.size() || rel_of(have[j]) < rel_of(want[i]))
      return "不完整:多余 " + rel_of(have[j]);
    if (want[i] != have[j])
      return "不完整:大小不符 " + rel_of(have[j]);
    ++i, ++j;
  }
  return "";
}
