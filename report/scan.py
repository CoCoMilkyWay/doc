#!/usr/bin/env python3
# -*- coding: utf-8 -*-
r"""校验脚本所在目录下所有 PDF 文件名是否严格符合命名格式。

命名格式 (固定五段, 缺失信息用占位):
    {日期}-{券商}-{系列}-{序号}-{标题}.pdf

逐文件检查:
  C1  整名结构   ^\d{8}-[汉]+-[a-z汉]+-\d{3}-[0-9a-z_汉]+\.pdf$
  C2  日期       00000000(占位) 或 2000-2030 间的合法日历日期
  C3  券商       无(占位) 或 2-8个汉字 (合法券商集合由一级目录自描述, 见 X1)
  C4  系列       无(占位) 或 纯[汉字+小写字母]且长度<=20 (结构由 C1 保证)
  C5  序号       000 当且仅当 系列为 无
  C6  标题       无(占位) 或 非空; 不含连续 __; 不以 _ 开头/结尾
  C7  长度       整名 utf-8 < 250 字节
跨文件/结构检查 (目录层次 = ROOT/{券商}/{系列}/):
  X1  PDF 必须恰好位于两级目录下, 且一级目录==券商段, 二级目录==系列段
  X2  同一系列目录内序号不得重复 (000 除外)
  X3  同一券商目录下的系列子目录名不得互为子串 (防止同一系列多种写法)
  X4  顶层券商目录名不得互为子串 (防止同一券商多种写法, 如 华泰/华泰期货)

输出: 树状打印所有 [违规:*] 与 [占位:*] 的文件; 存在违规时退出码 1。
用法: python3 scan.py
"""
import os, re, signal, sys
from datetime import datetime

signal.signal(signal.SIGPIPE, signal.SIG_DFL)   # 允许 | head 截断

ROOT = os.path.dirname(os.path.abspath(__file__))
CJK = r'\u4e00-\u9fff\u3400-\u4dbf'

RE_NAME = re.compile(
    r'(?P<date>\d{8})-(?P<broker>[%s]+)-(?P<series>[a-z%s]+)-(?P<num>\d{3})-(?P<title>[0-9a-z_%s]+)\.pdf'
    % (CJK, CJK, CJK))

YEAR_MIN, YEAR_MAX = 2000, 2030
BROKER_MINLEN, BROKER_MAXLEN = 2, 8
SERIES_MAXLEN = 20
MAX_NAME_BYTES = 250

def check_file(fname):
    """返回 (违规列表, 占位列表, 解析段 dict|None)。"""
    v, p = [], []
    if len(fname.encode('utf-8')) >= MAX_NAME_BYTES:
        v.append('违规:文件名超%d字节' % MAX_NAME_BYTES)
    m = RE_NAME.fullmatch(fname)
    if not m:
        v.append('违规:整名结构不符')
        return v, p, None
    g = m.groupdict()
    # C2 日期
    if g['date'] == '00000000':
        p.append('占位:日期')
    else:
        try:
            d = datetime.strptime(g['date'], '%Y%m%d')
            if not (YEAR_MIN <= d.year <= YEAR_MAX):
                v.append('违规:日期年份越界%s' % g['date'])
        except ValueError:
            v.append('违规:非法日期%s' % g['date'])
    # C3 券商
    if g['broker'] == '无':
        p.append('占位:券商')
    elif not (BROKER_MINLEN <= len(g['broker']) <= BROKER_MAXLEN):
        v.append('违规:券商名长度越界(%s)' % g['broker'])
    # C4/C5 系列与序号
    if g['series'] == '无':
        p.append('占位:系列')
        if g['num'] != '000':
            v.append('违规:系列为无但序号%s' % g['num'])
    else:
        if g['num'] == '000':
            v.append('违规:有系列但序号000')
        if len(g['series']) > SERIES_MAXLEN:
            v.append('违规:系列名超%d字符' % SERIES_MAXLEN)
    # C6 标题
    if g['title'] == '无':
        p.append('占位:标题')
    if '__' in g['title']:
        v.append('违规:标题含连续下划线')
    if g['title'].startswith('_') or g['title'].endswith('_'):
        v.append('违规:标题以下划线开头或结尾')
    return v, p, g

def main():
    records = []            # (相对文件夹, 文件名, 违规[], 占位[], 段dict|None)
    total = 0
    for dirpath, dirs, files in os.walk(ROOT):
        dirs.sort()
        folder = os.path.relpath(dirpath, ROOT)
        for f in sorted(files):
            if not f.lower().endswith('.pdf'):
                continue
            total += 1
            if not f.endswith('.pdf'):       # 扩展名必须小写
                records.append((folder, f, ['违规:扩展名非小写pdf'], [], None))
                continue
            v, p, g = check_file(f)
            records.append((folder, f, v, p, g))

    # ---- 结构与跨文件检查 ----
    # X1 路径两级且与文件名段一致
    for folder, f, v, p, g in records:
        if g is None:
            continue
        comps = folder.split(os.sep)
        if len(comps) != 2:
            v.append('违规:路径应为券商/系列两级(%s)' % folder)
            continue
        if comps[0] != g['broker']:
            v.append('违规:券商目录不符(%s)' % comps[0])
        if comps[1] != g['series']:
            v.append('违规:系列目录不符(%s)' % comps[1])
    # X2 同一系列目录内序号重复
    by_num = {}
    for idx, (folder, f, v, p, g) in enumerate(records):
        if g is not None and g['series'] != '无':
            by_num.setdefault((folder, g['num']), []).append(idx)
    for (folder, num), idxs in sorted(by_num.items()):
        if len(idxs) > 1:
            for idx in idxs:
                records[idx][2].append('违规:序号%s重复' % num)
    # X3 券商目录下系列子目录名互为子串
    dir_viol = []
    by_broker = {}
    for folder, f, v, p, g in records:
        comps = folder.split(os.sep)
        if len(comps) == 2:
            by_broker.setdefault(comps[0], set()).add(comps[1])
    for b, sers in sorted(by_broker.items()):
        ns = sorted(s for s in sers if s != '无')
        for i, a in enumerate(ns):
            for c in ns[i + 1:]:
                if a in c or c in a:
                    dir_viol.append('违规:券商%s下系列目录相近: %s / %s' % (b, a, c))
    # X4 顶层券商目录名互为子串
    bs = sorted(b for b in by_broker if b != '无')
    for i, a in enumerate(bs):
        for c in bs[i + 1:]:
            if a in c or c in a:
                dir_viol.append('违规:券商目录相近: %s / %s' % (a, c))

    # ---- 树状打印 ----
    tree = {}
    n_viol = n_place = 0
    for folder, f, v, p, g in records:
        if v or p:
            tree.setdefault(folder, []).append((f, v + p))
            n_viol += bool(v)
            n_place += bool(p)
    print('%s  (共%d个PDF: %d个违规, %d个含占位, %d个目录级违规)'
          % (os.path.basename(ROOT), total, n_viol, n_place, len(dir_viol)))
    for line in dir_viol:
        print('├── [%s]' % line)
    folders = sorted(tree)
    for fi, folder in enumerate(folders):
        last_folder = fi == len(folders) - 1
        print('%s── %s  (%d)' % ('└' if last_folder else '├', folder, len(tree[folder])))
        indent = '    ' if last_folder else '│   '
        items = tree[folder]
        for i, (f, tags) in enumerate(items):
            branch = '└' if i == len(items) - 1 else '├'
            print('%s%s── [%s] %s' % (indent, branch, ','.join(tags), f))
    sys.exit(1 if n_viol or dir_viol else 0)

if __name__ == '__main__':
    main()
