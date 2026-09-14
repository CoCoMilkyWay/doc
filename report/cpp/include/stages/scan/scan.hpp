// stage1 scan: 校验 ROOT 下所有 PDF 的文件名与目录结构是否符合命名规范。
//
// 命名格式 (固定五段, 仅日期允许占位 00000000):
//     {日期}-{券商}-{系列}-{序号}-{标题}.pdf
//
// 逐文件检查 (naming.cpp / content.cpp):
//   C1  整名结构   ^\d{8}-[汉]+-[a-z汉]+-\d{3}[a-z]?-[0-9a-z_汉]+\.pdf$
//   C2  日期       00000000(占位) 或 2000-2030 间的合法日历日期
//   C3  券商       4个汉字的官方简称 (合法券商集合由一级目录自描述, 见 X1)
//   C4  系列       纯[汉字+小写字母]且长度<=20 (结构由 C1 保证); 不允许 无
//   C5  序号       3位数字(可带1个小写字母); 000 违规(单篇报告亦须归入某系列)
//   C6  标题       非空; 不含连续 __; 不以 _ 开头/结尾; 不允许 无
//   C7  长度       整名 utf-8 < 250 字节
//   C8  扫描件     前 SCAN_PAGES 页抽不出任何文字 => 标记 [扫描:无文字层]
//                  (有 OCR 文字层的不算扫描件; 无法解析的 PDF 记为违规)
// 跨文件/结构检查 (structure.cpp / content.cpp), 目录层次 = ROOT/{券商}/{系列}/,
// TOPIC_DIR 下为 ROOT/0主题研报/{主题}/:
//   X1  PDF 必须恰好位于两级目录下, 且一级目录==券商段, 二级目录==系列段
//       (TOPIC_DIR 下目录是主题而非券商/系列, 仅豁免这两个相等比较, 仍须两级)
//   X2  同一券商+系列(按文件名段)内序号不得重复 (000 除外)
//   X3  同一券商目录下的系列子目录名不得互为子串 (防止同一系列多种写法)
//   X4  顶层券商目录名不得互为子串 (防止同一券商多种写法, 如 华泰/华泰期货)
//   X5  内容重复  按文件字节 sha256 判定, 即使文件名不同也算重复
//
// 输出: 树状打印所有 [违规:*] / [占位:*] / [扫描:*] 的文件; 存在违规时退出码 1。
// 依赖: libpoppler-cpp (pkg-config poppler-cpp)
#pragma once

#include <cstddef>
#include <string>
#include <vector>

#include "stage.hpp"

inline constexpr int SCAN_PAGES = 3; // 扫描件判定只看前几页, 避免整本抽取
inline constexpr int YEAR_MIN = 2000;
inline constexpr int YEAR_MAX = 2030;
inline constexpr size_t BROKER_MINLEN = 4;
inline constexpr size_t BROKER_MAXLEN = 4;
inline constexpr size_t SERIES_MAXLEN = 20;
inline constexpr size_t MAX_NAME_BYTES = 250;
// 该目录下与普通研报同规检查, 仅豁免 X1 的目录==券商/系列比较
inline constexpr const char *TOPIC_DIR = "0主题研报";
inline constexpr const char *WU = "无";

// 文件名解析出的五段
struct Seg {
  std::string date, broker, series, num, title;
  size_t broker_len = 0, series_len = 0; // 码点数, 非字节数
};

// 单个 PDF 的检查记录
struct Rec {
  std::string folder; // 相对 ROOT 的目录, ROOT 自身为 "."
  std::string name, path;
  std::vector<std::string> viol, place, scan; // 违规 / 占位 / 扫描 标签
  bool parsed = false;                        // 文件名结构是否合法
  Seg g;
  std::string digest; // sha256; 仅大小有碰撞的文件才计算, 其余为空
  int text = -1;      // pdf_has_text 结果
};

struct ScanStage : Stage {
  const char *name() const override { return "scan"; }
  int run(const Ctx &ctx) override;
};

// walk.cpp: 递归收集 PDF 并逐个跑 C1-C7, 返回 PDF 总数
size_t collect_pdfs(const std::string &root, std::vector<Rec> &records);
// naming.cpp: C1-C7
void check_naming(const std::string &fname, Rec &r);
bool parse_name(const std::string &fname, Seg &g);
// structure.cpp: X1-X4, 目录级违规写入 dir_viol
void check_structure(std::vector<Rec> &records, std::vector<std::string> &dir_viol);
// content.cpp: 并行读一次文件, C8 + X5
void check_content(std::vector<Rec> &records, unsigned workers);
// report.cpp: 树状打印, 返回违规文件数
size_t print_report(const std::string &root, size_t total,
                    const std::vector<Rec> &records,
                    const std::vector<std::string> &dir_viol);
