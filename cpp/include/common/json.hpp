// 自带的严格 JSON 解析/规范序列化 (不引第三方库)。
//
// 解析比 RFC 8259 更严: 对象键重复 / 非法 UTF-8 / 非法转义 / 尾随内容 都判失败。
// 数字不转成 double 而保留原文 (lexeme), 校验与序列化都用原文, 避免浮点格式往返不一致。
// 规范序列化 (canonical): 键按 (rank, 字节序) 排, 2 空格缩进, 非 ASCII 原样 (不 \u 转义), 数字原文, 末尾一个换行;
// 空数组/空对象写成 [] / {}; 非空的数组/对象单行能放下 (含缩进 <= 100 字符) 就写单行 (逗号+空格分隔), 放不下才逐行展开
// (展开后每个子项各自再判断能否单行, 所以大列表里的小 dict 元素还是会单行). rank 为空时纯字节序;
// 给 rank 则同 rank 内字节序 (调用方用它让键按 schema 字段序而不是字母序输出).
#pragma once

#include <string>
#include <string_view>
#include <utility>
#include <vector>

struct Json {
  enum Kind { Null,
              Bool,
              Number,
              String,
              Array,
              Object };
  Kind kind = Null;
  bool b = false;
  std::string num; // Number: 原文
  std::string str; // String: 已解转义的 UTF-8
  std::vector<Json> arr;
  // Object: 键值并行数组, 保持文件内顺序
  std::vector<std::string> keys;
  std::vector<Json> vals;

  // Object 取键, 无则 nullptr; 非 Object 调用即断言失败
  const Json *get(std::string_view key) const;
  // 同上, 供解析后就地改写用 (如 tag 的 F3 规范化)
  Json *get(std::string_view key) { return const_cast<Json *>(std::as_const(*this).get(key)); }
};

// 失败返回 false, err 为 "行:列 原因"
bool json_parse(const std::string &text, Json &out, std::string &err);
// 键排序权重: 返回值越小越靠前; 未知键返回同一大值即可 (退化为字节序)
using KeyRank = int (*)(std::string_view);
std::string json_canonical(const Json &j, KeyRank rank = nullptr);
