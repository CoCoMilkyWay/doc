#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""cpp/ 下 docpipe 流水线的启动器: 按需 cmake 配置 + 增量编译, 然后以本目录为 ROOT 执行。

用法: python3 run.py [stage...]     不指定 stage 则按序全跑: scan -> convert -> tag
目录布局与全部参数见 cpp/include/config.hpp; 各 stage 的规则与输出格式见
cpp/include/stages/{scan/scan.hpp, convert/convert.hpp, tag/tag.hpp} 头部注释。
"""
import os, shutil, subprocess, sys

ROOT = os.path.dirname(os.path.abspath(__file__))
CPP = os.path.join(ROOT, "cpp")
BUILD = os.path.join(CPP, "build")
BIN = os.path.join(BUILD, "docpipe")

assert os.path.isfile(os.path.join(CPP, "CMakeLists.txt")), (
    "缺少 %s/CMakeLists.txt" % CPP
)
assert shutil.which("cmake"), "缺少 cmake"
assert shutil.which("pkg-config"), "缺少 pkg-config"
assert (
    subprocess.run(["pkg-config", "--exists", "poppler-cpp"]).returncode == 0
), "缺少 libpoppler-cpp, 请安装: sudo apt install libpoppler-cpp-dev"

if not os.path.isfile(os.path.join(BUILD, "CMakeCache.txt")):
    cxx = shutil.which("clang++")
    assert cxx, "缺少 clang++"
    cfg = [
        "cmake",
        "-S",
        CPP,
        "-B",
        BUILD,
        "-DCMAKE_BUILD_TYPE=Release",
        "-DCMAKE_CXX_COMPILER=" + cxx,
    ]
    if shutil.which("ninja"):
        cfg += ["-G", "Ninja"]
    subprocess.run(cfg, check=True, stdout=sys.stderr)

subprocess.run(["cmake", "--build", BUILD], check=True, stdout=sys.stderr)
os.execv(BIN, [BIN, ROOT] + sys.argv[1:])
