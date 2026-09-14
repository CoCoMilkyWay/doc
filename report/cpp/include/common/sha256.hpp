// 自带 sha256 实现, 避免引入 openssl 依赖。
#pragma once

#include <cstdint>
#include <string>

struct Sha256 {
  uint32_t h[8] = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
                   0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};
  uint64_t len = 0;
  uint8_t buf[64] = {};
  size_t fill = 0;

  void update(const uint8_t *p, size_t n);
  std::string hex(); // 收尾并输出 64 位十六进制串 (调用后对象作废)

private:
  void block(const uint8_t *p);
};

std::string file_sha256(const std::string &path);
