#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""用 clang-format 格式化本目录 (cpp/) 下所有 .cpp/.hpp, 风格见同目录 .clang-format。

用法: python3 format.py            就地格式化
      python3 format.py --check    只检查, 有未格式化的文件则退出码非 0
"""
import os, shutil, subprocess, sys

ROOT = os.path.dirname(os.path.abspath(__file__))
SKIP = {"build", "package"}  # 构建产物 / 第三方源码 (MinerU)

args = sys.argv[1:]
assert set(args) <= {"--check"}, "用法: format.py [--check]"
check = "--check" in args

fmt = shutil.which("clang-format")
assert fmt, "缺少 clang-format"
assert os.path.isfile(os.path.join(ROOT, ".clang-format")), (
    "缺少 %s/.clang-format" % ROOT
)

files = []
for dirpath, dirs, names in os.walk(ROOT):
    dirs[:] = sorted(d for d in dirs if d not in SKIP and not d.startswith("."))
    files += [
        os.path.join(dirpath, n) for n in sorted(names) if n.endswith((".cpp", ".hpp"))
    ]
assert files, "%s 下没有 .cpp/.hpp" % ROOT

# 逐个格式化到内存再比对: 只重写真正有变化的文件 (不打扰增量编译), 并能报出改了哪几个
changed = []
for path in files:
    with open(path, "rb") as fp:
        before = fp.read()
    after = subprocess.run(
        [fmt, "--style=file", path], stdout=subprocess.PIPE, check=True
    ).stdout
    if after == before:
        continue
    changed.append(os.path.relpath(path, ROOT))
    if not check:
        with open(path, "wb") as fp:
            fp.write(after)

for rel in changed:
    print("%s %s" % ("需要格式化" if check else "已格式化", rel))
print(
    "共 %d 个文件, %d 个%s"
    % (len(files), len(changed), "需要格式化" if check else "被改动"),
    file=sys.stderr,
)
sys.exit(1 if check and changed else 0)
