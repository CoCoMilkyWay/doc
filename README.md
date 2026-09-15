# doc — 研报/论文文档库 + docpipe 流水线

```
入口: run.py ──► CMake(cpp/) ──► docpipe (C++可执行文件) ──► stage 按序执行: scan ──► convert ──► tag
```

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
├── resources-tag/             # 🏷️ 研报标签 (stage3 校验对象, 由 agent 逐篇填写), 与 raw 同层次但独立成树
│   └── report/{券商}/{系列}/{stem}.json   # 🏷️ 不能放进 proc 的 {stem}/: .stat 清单逐行相等, 多一个文件即判不完整
├── multi_factor_model.md      # 🏷️ 现代多因子系统模块拆分 (L0~L8), 标签词表 Module 的叶子即照此编制
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
│   │   ├── stages/tag/tag.hpp         # 🏷️ stage3 标签校验: 规则表 F1-F4 / S1-S4 / V1-V3 / K1-K8 / G1-G4 / X1-X4, 按券商统计输出
│   │   ├── stages/tag/schema.hpp      # 🏷️ 标签 schema 唯一出处: Stage(派生) > Module(partition) > Approach(流派) 三层 + 正交轴 (体裁/资产/数据), NAMED_ENUM X-宏词表
│   │   └── common/
│   │       ├── fs.hpp         # 🔧 目录与路径 (POSIX): list_dir / list_tree 内容清单 / mkdirs / remove_all / 读写整文件(先写临时再 rename)
│   │       ├── proc.hpp       # 🔧 子进程: fork+execv 阻塞执行, 每秒 on_tick 回调; SIGINT/SIGTERM 转发给整个子进程组 (mineru 内部还会 fork worker)
│   │       ├── pdftext.hpp    # 🔧 libpoppler-cpp 进程内解析: pdf_has_text (有无文字层) / pdf_pages
│   │       ├── sha256.hpp     # 🔧 自带 sha256 (不引 openssl): 流式 update/hex + file_sha256
│   │       ├── json.hpp       # 🔧 自带严格 JSON (不引第三方): 拒绝重复键/非法 UTF-8, 数字保留原文; canonical 序列化 (键字节序·2空格·非ASCII原样)
│   │       └── util.hpp       # 🔧 printf 风格 F() / now_ms / split / UTF-8 编解码 / 文件名字符类 (数字·小写·汉字)
│   ├── src/
│   │   ├── main.cpp           # 💾 入口: 解析 ROOT 与 stage 列表, workers=硬件线程数, 逐 stage 跑并打印耗时
│   │   ├── stages/registry.cpp        # 💾 stage 登记表, 顺序即默认执行顺序 {scan, convert, tag}
│   │   ├── stages/scan/
│   │   │   ├── scan.cpp       # 🔍 编排: 收集 → 命名 → 结构 → 内容 → 报告
│   │   │   ├── walk.cpp       # 🔍 递归收集 PDF (不跟随符号链接, 按字节序保证输出稳定)
│   │   │   ├── naming.cpp     # 🔍 C1-C7: 整名五段结构 / 日期 / 券商 / 系列 / 序号 / 标题 / 长度
│   │   │   ├── structure.cpp  # 🔍 X1-X4: 两级目录且目录名==文件名段 / 序号重复 / 系列名互为子串 / 券商名互为子串
│   │   │   ├── content.cpp    # 🔍 C8 + X5: 并行读一次文件, 判扫描件 (前 SCAN_PAGES 页无文字层) + sha256 内容重复 (仅大小碰撞者才算)
│   │   │   └── report.cpp     # 🔍 树状打印 [违规:*]/[占位:*]/[扫描:*], 返回违规文件数 (>0 → 退出码 1)
│   │   ├── stages/convert/
│   │   │   ├── env.cpp        # 📝 E1-E3: 内置 python 存在 / 依赖可 import (mineru·torch·onnxruntime·transformers) / pipeline 模型齐备; 不满足即打印解决办法
│   │   │   ├── check.cpp      # 📝 增量扫描: raw 与 proc 一一对应, 列出 [多余文件]/[多余目录]/[不完整:*]/[源PDF已变], 问 "删除后继续? [y/N]"; 产出待转清单
│   │   │   ├── convert.cpp    # 📝 按目录分批 (软链到临时目录, 一次 mineru 调用 → 模型每目录只加载一次); 每篇 搬平→写.stat→rename 换入; 进度: 每目录一行(PDF数/页数/s每页/ETA) + 每篇 ✓
│   │   │   └── stat.cpp       # 📝 .stat 读写与校验: 只 readdir/stat 不读内容, 千篇量级 100ms 内
│   │   └── stages/tag/
│   │       ├── tag.cpp        # 🏷️ 编排: 收集 raw 全部 PDF 为期望集合 → 遍历标签树 (对不上的记 [多余]) → 并行逐篇 parse→K→G → 跨文件 X → 报告
│   │       ├── parse.cpp      # 🏷️ F2 F3 S1-S4 V1: json 解析 / canonical 字节比对 / 键集合恰好相等 / 类型·规范数字 / 列表序 / 长度 / 词表
│   │       ├── rules.cpp      # 🏷️ V2 V3 K1-K8 字段间一致性; G1-G4 接地: evidence 归一化后必须是 report.md 逐字子串, 数字须在 evidence 里
│   │       ├── cross.cpp      # 🏷️ X1-X4: builds_on 存在·不倒置·无环 / 枚举取值分布 (防 LLM 默认填) / 死词表提示 / findings 串写
│   │       └── report.cpp     # 🏷️ 按券商目录统计 (总数/已标注/缺失/违规/多余), 违规项树状列出
│   ├── agent/                 # 🏷️ stage3 阶段一: tag_loop.py (Cursor Python SDK 补标签) + agent loop.md 设计 + cursor_api_key.txt (gitignore)
│   ├── package/               # 📚 内置第三方 (随项目搬迁, 不依赖系统环境)
│   │   ├── python/            # 📚 便携版 CPython 3.12 (python-build-standalone, 自带 pip), 各 stage 共用
│   │   │   └── deps/          # 📚 pip --target 装的依赖 (~1.6G: MinerU 全家 + cursor-sdk). 共享一份, 不按 stage 分;
│   │   │                      #     不用 venv (绝对路径写死, 搬迁即失效), 也不进 site-packages (那是 git 跟踪的)
│   │   └── MinerU/            # 📚 MinerU 剪裁版源码 (cli/client.py 关掉了 middle/model/content_list json 与调试 pdf)
│   │       ├── models/        # 📚 模型缓存 (~2.5G, MODELSCOPE_CACHE 重定向到此)
│   │       └── mineru.json    # 📚 由 mineru-models-download 生成 (MINERU_TOOLS_CONFIG_JSON 重定向到此)
│   └── build/                 # 🎯 构建目录, 产物 cpp/build/docpipe
└── Win10-VM/                  # 🖥️ 独立的 QEMU/KVM Win10 虚拟机 (与流水线无关, 跑 Windows 版行情/研报客户端)
    ├── start.sh               # 🖥️ 一键启动: 依赖自检 → virtiofsd 共享 → OVMF UEFI 启动; 首次自动建 80G 稀疏盘, 空盘光驱优先
    ├── shared/                # 🖥️ 与客机共享目录 (virtio-fs, 客机需装 WinFSP)
    └── *.iso / *.fd / disk.qcow2  # 🖥️ 安装盘 / virtio 驱动 / WinFSP / OVMF 固件 / 磁盘镜像
```
