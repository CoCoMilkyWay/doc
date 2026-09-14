# doc — 研报/论文文档库 + docpipe 流水线

```
入口: run.py ──► CMake(cpp/) ──► docpipe (C++可执行文件) ──► stage 按序执行: scan ──► convert
```

`python3 run.py [stage...]`：按需 cmake 配置 + 增量编译，然后以本目录为 ROOT 执行 `docpipe`。
不指定 stage 则全跑；任一 stage 退出码非 0 即中止（不在不合规的库上跑后续阶段）。
错误处理只用断言，Release 也保留（CMakeLists 里剔掉了 `-DNDEBUG`）。

```
doc/
├── run.py                     # 🚀 主入口 → cmake 配置/编译 → exec docpipe <ROOT> [stage...]
│                              #    启动前校验: cmake / pkg-config / libpoppler-cpp / clang++ (缺则断言失败并给出安装命令)
├── resources-raw/             # 📥 原始输入 (只读)
│   ├── report/                # 📥 研报 PDF, 层次 {券商}/{系列}/{日期}-{券商}-{系列}-{序号}-{标题}.pdf
│   │   └── 0主题研报/{主题}/  # 📥 跨券商主题目录: 同规命名检查, 仅豁免"目录名==券商/系列"的比较
│   └── paper/{主题}/          # 📥 英文论文/书籍, 主题分类 (AlphaMining/HFT/Factors/...); 暂未纳入流水线
├── resources-proc/            # 📤 转换产物 (与输入同层次)
│   └── report/
│       ├── {券商}/{系列}/{stem}/
│       │   ├── report.md      # 📤 markdown 正文 (文件名统一, stem 信息已在目录名里)
│       │   ├── images/        # 📤 插图, md 内以 ![](images/..) 相对引用
│       │   └── .stat          # 📤 "已完成"的唯一凭据: 源PDF字节数 + 目录内容清单 + 清单sha256
│       └── .staging/          # 📤 MinerU 中间产物暂存区: 整篇就绪后 rename 原子换入; 启动无条件清空
├── cpp/
│   ├── CMakeLists.txt         # 🏗️ C++23 / Clang / Release 保留断言; 链 Threads + pkg-config poppler-cpp
│   ├── .clang-format          # 🏗️ LLVM 风格, IndentWidth 2, 不限行宽
│   ├── format.py              # 🏗️ 格式化 cpp/ 下全部 .cpp/.hpp (跳过 build/package); --check 只检查
│   ├── include/
│   │   ├── config.hpp         # ⚙️ 全部可调参数的唯一出处: 目录布局 / scan 阈值 / MinerU 后端与环境变量
│   │   │                      #    路径一律相对 ROOT, 项目整体搬迁/换机器直接可用
│   │   ├── stage.hpp          # 🔗 stage 抽象: Ctx{root, workers} + Stage{name, run→退出码}; 新增 stage 只需实现接口 + 在 registry.cpp 登记
│   │   ├── stages/scan/scan.hpp       # 🔍 stage1 规范校验: 逐文件 C1-C8 + 跨文件 X1-X5 规则表 / Seg / Rec
│   │   ├── stages/convert/convert.hpp # 📝 stage2 MinerU 转换: 环境校验 E1-E3 / .stat 格式 / 增量扫描 / 分批转换协议
│   │   └── common/
│   │       ├── fs.hpp         # 🔧 目录与路径 (POSIX): list_dir / list_tree 内容清单 / mkdirs / remove_all / 读写整文件(先写临时再 rename)
│   │       ├── proc.hpp       # 🔧 子进程: fork+execv 阻塞执行, 每秒 on_tick 回调; SIGINT/SIGTERM 转发给整个子进程组 (mineru 内部还会 fork worker)
│   │       ├── pdftext.hpp    # 🔧 libpoppler-cpp 进程内解析: pdf_has_text (有无文字层) / pdf_pages
│   │       ├── sha256.hpp     # 🔧 自带 sha256 (不引 openssl): 流式 update/hex + file_sha256
│   │       └── util.hpp       # 🔧 printf 风格 F() / now_ms / split / UTF-8 解码 / 文件名字符类 (数字·小写·汉字)
│   ├── src/
│   │   ├── main.cpp           # 💾 入口: 解析 ROOT 与 stage 列表, workers=硬件线程数, 逐 stage 跑并打印耗时
│   │   ├── stages/registry.cpp        # 💾 stage 登记表, 顺序即默认执行顺序 {scan, convert}
│   │   ├── stages/scan/
│   │   │   ├── scan.cpp       # 🔍 编排: 收集 → 命名 → 结构 → 内容 → 报告
│   │   │   ├── walk.cpp       # 🔍 递归收集 PDF (不跟随符号链接, 按字节序保证输出稳定)
│   │   │   ├── naming.cpp     # 🔍 C1-C7: 整名五段结构 / 日期 / 券商 / 系列 / 序号 / 标题 / 长度
│   │   │   ├── structure.cpp  # 🔍 X1-X4: 两级目录且目录名==文件名段 / 序号重复 / 系列名互为子串 / 券商名互为子串
│   │   │   ├── content.cpp    # 🔍 C8 + X5: 并行读一次文件, 判扫描件 (前 SCAN_PAGES 页无文字层) + sha256 内容重复 (仅大小碰撞者才算)
│   │   │   └── report.cpp     # 🔍 树状打印 [违规:*]/[占位:*]/[扫描:*], 返回违规文件数 (>0 → 退出码 1)
│   │   └── stages/convert/
│   │       ├── env.cpp        # 📝 E1-E3: 内置 python 存在 / 依赖可 import (mineru·torch·onnxruntime·transformers) / pipeline 模型齐备; 不满足即打印解决办法
│   │       ├── check.cpp      # 📝 增量扫描: raw 与 proc 一一对应, 列出 [多余文件]/[多余目录]/[不完整:*]/[源PDF已变], 问 "删除后继续? [y/N]"; 产出待转清单
│   │       ├── convert.cpp    # 📝 按目录分批 (软链到临时目录, 一次 mineru 调用 → 模型每目录只加载一次); 每篇 搬平→写.stat→rename 换入; 进度: 每目录一行(PDF数/页数/s每页/ETA) + 每篇 ✓
│   │       └── stat.cpp       # 📝 .stat 读写与校验: 只 readdir/stat 不读内容, 千篇量级 100ms 内
│   ├── package/               # 📚 内置第三方 (随项目搬迁, 不依赖系统环境)
│   │   ├── python/            # 📚 便携版 CPython 3.12 (python-build-standalone, 自带 pip)
│   │   └── MinerU/            # 📚 MinerU 剪裁版源码 (cli/client.py 关掉了 middle/model/content_list json 与调试 pdf)
│   │       ├── deps/          # 📚 pip --target 装的依赖 (~1.6G, 不用 venv: venv 会把绝对路径写死, 搬迁即失效)
│   │       ├── models/        # 📚 模型缓存 (~2.5G, MODELSCOPE_CACHE 重定向到此)
│   │       └── mineru.json    # 📚 由 mineru-models-download 生成 (MINERU_TOOLS_CONFIG_JSON 重定向到此)
│   └── build/                 # 🎯 构建目录, 产物 cpp/build/docpipe
└── Win10-VM/                  # 🖥️ 独立的 QEMU/KVM Win10 虚拟机 (与流水线无关, 跑 Windows 版行情/研报客户端)
    ├── start.sh               # 🖥️ 一键启动: 依赖自检 → virtiofsd 共享 → OVMF UEFI 启动; 首次自动建 80G 稀疏盘, 空盘光驱优先
    ├── shared/                # 🖥️ 与客机共享目录 (virtio-fs, 客机需装 WinFSP)
    └── *.iso / *.fd / disk.qcow2  # 🖥️ 安装盘 / virtio 驱动 / WinFSP / OVMF 固件 / 磁盘镜像
```

## stage1 scan — 命名与结构校验

命名格式固定五段（仅日期允许占位 `00000000`）：`{日期}-{券商}-{系列}-{序号}-{标题}.pdf`

| 规则 | 检查                                                                    |
| ---- | ----------------------------------------------------------------------- |
| C1   | 整名结构 `^\d{8}-[汉]+-[a-z汉]+-\d{3}[a-z]?-[0-9a-z_汉]+\.pdf$`         |
| C2   | 日期为 `00000000` 或 `YEAR_MIN`~`YEAR_MAX` 间的合法日历日               |
| C3   | 券商 = 4 个汉字的官方简称（合法券商集合由一级目录自描述）               |
| C4   | 系列纯「汉字+小写字母」且 ≤ `SERIES_MAXLEN`，不允许「无」               |
| C5   | 序号 3 位数字（可带 1 个小写字母），`000` 违规（单篇也须归入某系列）    |
| C6   | 标题非空、不含连续 `__`、不以 `_` 起止，不允许「无」                    |
| C7   | 整名 UTF-8 < `MAX_NAME_BYTES` 字节                                      |
| C8   | 前 `SCAN_PAGES` 页抽不出文字 → `[扫描:无文字层]`；无法解析的 PDF 记违规 |
| X1   | PDF 恰好位于两级目录下，且一级目录==券商段、二级目录==系列段            |
| X2   | 同券商+系列内序号不得重复（`000` 除外）                                 |
| X3   | 同券商目录下系列子目录名不得互为子串                                    |
| X4   | 顶层券商目录名不得互为子串（如 华泰/华泰期货）                          |
| X5   | 按文件字节 sha256 判内容重复，文件名不同也算                            |

## stage2 convert — MinerU 转 markdown

CPU-only（`pipeline` 后端），关键取舍都在 `config.hpp` 注释里：
`MINERU_API_CONCURRENCY=1`（CPU 上每任务的 torch 已吃满全核，多并发只会互抢更慢）、
`MINERU_LOG_LEVEL=WARNING`（只留各模型 tqdm 与 docpipe 自己的进度行）。

python 环境不用 venv，改用「内置便携 CPython + `pip --target` + 运行时 `PYTHONPATH`」，
且 `PYTHONPATH` 必须 `MinerU/` 在前、`deps/` 在后，否则跑的是 pip 复制进 `deps/mineru` 的陈旧拷贝。

随时被 kill 也不留半成品：中间产物一律落在 `.staging/`（同一文件系统），
整篇就绪才 `rename` 换入最终位置；`.staging` 启动时无条件清空。
