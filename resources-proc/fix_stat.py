#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""按 cpp/src/stages/convert/stat.cpp 的逻辑重算 resources-proc/report 下所有 .stat。

手动改过 report.md 后, .stat 清单里 "F <size> report.md" 的 size 与 hash 对不上,
check 阶段会判 [不完整:大小不符 report.md]. 本脚本现算目录清单 + sha256, 只重写
实际变化的 .stat (内容相同的不会动, 避免打扰增量编译/mtime).

用法: python3 fix_stat.py           就地重算并报告改了哪几篇
"""
import hashlib
import os
import stat as stat_mod
import sys

ROOT = os.path.dirname(os.path.abspath(__file__))
PROC = os.path.join(ROOT, "report")
STAT_NAME = ".stat"
MAGIC = "docpipe-stat 1"


def list_tree(doc_dir, rel=""):
    """复刻 cpp/src/common/fs.cpp list_tree_rec: dirs 先 (各自递归), files 后, 同级各自排序."""
    abs_dir = doc_dir if not rel else os.path.join(doc_dir, rel)
    dirs, files = [], []
    for name in os.listdir(abs_dir):
        if name in (".", ".."):
            continue
        st = os.lstat(os.path.join(abs_dir, name))
        r = name if not rel else rel + "/" + name
        if stat_mod.S_ISDIR(st.st_mode):
            dirs.append(name)
        else:
            files.append("F %d %s" % (st.st_size, r))
    dirs.sort()
    files.sort()
    out = []
    for d in dirs:
        r = d if not rel else rel + "/" + d
        out.append("D " + r)
        out.extend(list_tree(doc_dir, r))
    out.extend(files)
    return out


def entries(doc_dir):
    """剔除 .stat 自身及其写入临时文件 (复刻 stat.cpp entries())."""
    self_suffix = " " + STAT_NAME
    return [
        e
        for e in list_tree(doc_dir)
        if not e.endswith(self_suffix) and not e.endswith(self_suffix + ".tmp")
    ]


def hash_of(lines):
    h = hashlib.sha256()
    for l in lines:
        h.update(l.encode("utf-8"))
        h.update(b"\n")
    return h.hexdigest()


def main():
    assert os.path.isdir(PROC), "缺少 %s" % PROC
    changed = []
    for dirpath, dirs, _ in os.walk(PROC):
        if STAT_NAME not in os.listdir(dirpath):
            continue
        stat_path = os.path.join(dirpath, STAT_NAME)
        with open(stat_path, "r", encoding="utf-8") as fp:
            old = fp.read()
        lines = old.split("\n")
        if lines and lines[-1] == "":
            lines.pop()
        assert (
            len(lines) >= 3
            and lines[0] == MAGIC
            and lines[1].startswith("pdf ")
            and lines[2].startswith("hash ")
        ), ("%s 格式损坏" % stat_path)
        pdf_size = int(lines[1][4:])
        es = entries(dirpath)
        new = "%s\npdf %d\nhash %s\n" % (MAGIC, pdf_size, hash_of(es))
        for e in es:
            new += e + "\n"
        if new == old:
            continue
        with open(stat_path, "w", encoding="utf-8") as fp:
            fp.write(new)
        changed.append(os.path.relpath(dirpath, PROC))

    for rel in changed:
        print("已重算 %s/.stat" % rel)
    print("共 %d 篇 .stat 被改动" % len(changed), file=sys.stderr)


if __name__ == "__main__":
    main()
