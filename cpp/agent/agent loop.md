## 0. 边界

```
目标     给 RAW 下每篇研报各写一份 tag json, 全部过 tag stage 校验. 由 stage3 自己驱动: 阶段一补全缺失, 阶段二整体校验 (tag.hpp).
分工     agent loop 只负责 "生成 + 单篇闭环"; 判对错 / 格式化 / 跨文件规则 / 统计 全部归 tag stage (cpp), python 侧不复制任何规则.
路线     B: Cursor Python SDK (cursor-sdk, https://cursor.com/cn/docs/sdk/python). 一篇 = 一个 agent; 一轮 = agent.send() 的一个 run.
         云端无仓库代理 (CloudAgentOptions(repos=[])): 仓库 4GB, 每篇 clone 不可接受; report.md 正文直接随 prompt 发送
         (中位 42KB, p90 73KB, 超 TAG_AGENT_MD_MAX_BYTES 截断). 结果 json 从 run.wait().result 文本里的 ```json 块取,
         不走 git / artifacts. 回喂 = 对同一 agent 再 send 一次 (对话与上一版都还在).
         不裸调 REST: POST /v1/agents 实测要等 ~62s 才返回 (返回时 run 早已结束), 而 SDK 的 create 立即给句柄, 生命周期/
         流式/重试/归档都是文档定义好的行为 —— 手搓 urllib 等于在未定义行为上重造轮子.
代码     cpp/agent/tag_loop.py (由 tag.cpp::fill_missing 用内置便携 python 调起, 参数全部来自 config.hpp)
         cpp/src/stages/tag/env.cpp: T1 便携 python / T2 cursor-sdk 及三条用法假设, 缺则打印 pip --target 安装指令后断言
         docpipe ROOT tag --one <json>: 单文件校验子命令, 违规一行一条到 stdout, 退出码 0/1 (tag.cpp::run_one)
未选     A: PydanticAI + GLM/Kimi API (Agent(output_type=ToolOutput) + output_validator/ModelRetry, 外层 pydantic_graph).
         更可控更便宜, 但要自己开 API key 与拆步 prompt. Cursor 账户没有裸 completions 接口, 接不上 A.
```

## 1. 状态机 (单篇; python 里就是 Loop.one 的一个 while)

```
  missing.tsv 一行 ──▶ SELECT ── quarantine 已有该篮 ──▶ SKIP(quarantined_before)
  (folder stem date)    │  ───── 无 report.md (F4) ──▶ SKIP(no_md)
                        ▼
                     PREPARE   读 report.md (超 TAG_AGENT_MD_MAX_BYTES 截断并在 prompt 标明), 拼首轮 prompt (§2)
                        ▼
                     CREATE    client.agents.create(model, api_key, name, cloud=CloudAgentOptions(repos=[], metadata))  → 立即得句柄
                        ▼      (建不出来就不落任何记录目录; 撞套餐并发上限当背压等待)
          ┌────────▶ RUN       round += 1.  run = agent.send(prompt);  async for msg in run.messages() → round-N.events.jsonl
          │             │      result = run.wait() → status / result / usage
          │             ├── status != finished ──▶ FAIL(run_error / run_cancelled / run_expired)   (不落文件, 该篇仍 "缺失", 下次再跑)
          │             ▼
          │          EXTRACT   result.result 里最后一个 ```json 块 → 写 TAG_STAGING_DIR/{folder}/{stem}.json
          │             │      没有 json 块 ⇒ 视作违规 "F3 回复中没有 json 代码块"
          │             ▼
          │          VERIFY    docpipe ROOT tag --one <staging json>  (F2 F3 S V K G; F3 顺手把文件格式化成规范形)
          │             ├── 无违规 ──▶ COMMIT   rename staging → TAG_REPORT_DIR/{folder}/{stem}.json
          │             ├── 有违规 ∧ round < TAG_AGENT_MAX_ROUND ──▶ prompt = FOLLOWUP(违规行) ──┐
          │             └── 有违规 ∧ round == TAG_AGENT_MAX_ROUND ──▶ QUARANTINE                 │
          └───────────────────────────────────────────────────────────────────────────────────────┘
                                 rename staging → TAG_QUARANTINE_DIR/{folder}/{stem}.json + {stem}.viol (各轮违规)

  收尾 (所有出口)   agent.get_usage() 记 token 与计费; agent.archive() 归档; 写 meta.json, 追加一行 agent.jsonl (TAG_AGENT_LOG_DIR)
```

规则:
- 违规不分责任节点: 整份 json 由同一个 agent 一次出, 全部违规行原样回喂, 让它出修正后的完整 json (不接受差异).
- 解析失败 / S1 / S2 (结构性) 同样回喂 —— 路线 B 里没有 "代码 bug" 这一类, 因为 json 是模型直接写的.
- X 规则 (跨文件) 不在单篇 loop 内, 由阶段二整体跑; X 违规不自动回喂, 打印给人看.
- FAIL 不占 quarantine: 下一次 `run.py tag` 会把它当缺失重来. quarantine 要重试就删掉那个 json.

## 2. Prompt

```
首轮 = INSTRUCTION + tag.md 原文 + 示例 (TAG_REPORT_DIR 下按路径序取前 2 篇已过校验的 json) + report.md 正文 (<<<REPORT_BEGIN/END>>> 包住)
INSTRUCTION 固定项: id / schema_version / gen.model / gen.prompt_sha256 的字面值; 研报日期; 逐字抄 evidence; 枚举只用 code; 列表序 / 键序;
                   只写涉及的阶段; 流派选范式级; 例行 IC 检验不算 L2; 高频信号归 L1_market; 正文可能截断不要臆测
回喂  = FOLLOWUP(违规行): "校验器报出以下违规 … 请修正后重新输出完整 json"
hash  = sha256(INSTRUCTION 模板 + FOLLOWUP 模板 + tag.md + 示例) → 写进 gen.prompt_sha256. 任一变 → hash 变.
        (增量重标 = 删掉 hash 不一致的 json 再跑; 目前不自动删, 由人决定)
```

## 3. 并发与幂等

```
并发    asyncio: TAG_AGENT_WORKERS 个任务从队列取篇, 篇内串行到底 (create → send/流 → 校验 → 回喂 → commit/quarantine), 做完才取下一篇.
        用 AsyncClient 而非同步 API: 文档把异步客户端定为并发编排的路子 (同步 API 没有并发约定, 也没有全局异步默认客户端, 故显式实例化).
        只写自己 stem 的 staging/out/quarantine/log 文件, 无共享写.
上限    套餐有 "同时在跑的 Cloud Agent 数" 上限 (报文里带 reached the limit): 当背压处理, 等 CAP_WAIT_SEC 再试, 最多 CAP_WAIT_MAX 次.
        agent 用完必须 archive (finally 里做), 否则一直占坑; 启动时 archive_leaked() 按 metadata={"docpipe":"tag"} 认领并归档上次泄漏的.
顺序    missing.tsv 由 tag.cpp 按 raw 遍历序写出 ({券商}/{系列}/stem 字节序), 与报告同序.
幂等    缺失 := TAG_REPORT_DIR 下无该 json (tag.cpp::collect). 已提交的不再碰; quarantine 的跳过.
中断    staging 每次启动清空; out 只经 rename 落地, 无半截文件. Ctrl+C 由 docpipe 转给 python, 在跑的 run 留在 Cursor 侧自然结束,
        其 agent 下次启动由 archive_leaked() 收拾.
重试    只认文档的约定: CursorAgentError.is_retryable 才重试 (退避照 retry_after), 最多 RETRY 次. 不猜、不兜底、不自造超时.
失败    任一篇抛异常 (不可重试的 SDK 错误 / 模型 id 不存在 / docpipe --one 非 0/1 退出) ⇒ 立刻停止派发新篇, 在飞的收尾 ⇒ python 非 0
        ⇒ tag.cpp 断言中止. 该篇 meta.json 记 outcome=error + 异常. 建 agent 失败的篇不留任何记录目录.
```

## 4. 常量 (config.hpp, 唯一出处; python 全部由命令行接收)

```
TAG_STAGING_DIR TAG_QUARANTINE_DIR TAG_AGENT_LOG_DIR   都在 TAG_REPORT_DIR 之外 (放进去被 F1 判多余)
TAG_AGENT_SCRIPT TAG_AGENT_MODEL TAG_AGENT_WORKERS TAG_AGENT_MAX_ROUND TAG_AGENT_MD_MAX_BYTES
python 内部: RETRY=5 CAP_WAIT_SEC=30 CAP_WAIT_MAX=20 (超时/轮询/流重连都归 SDK, 这里不设)
密钥: TAG_AGENT_KEY_FILE (cpp/agent/cursor_api_key.txt, 一行, 已 gitignore; Cursor Dashboard → API Keys). 文件不存在则阶段一整体跳过, 只做校验.
依赖: 内置便携 python (PYTHON_BIN) + cursor-sdk 装在各 stage 共享的 PYTHON_DEPS_DIR (pip --target), 由 check_tag_env 检查并设 PYTHONNOUSERSITE/PYTHONPATH.
```

## 5. 交互记录与监控 (TAG_AGENT_LOG_DIR = resources-tag/agent-log)

```
布局    agent.jsonl                     每篇一行汇总: stem folder model prompt_sha256 agent_id outcome round viol_history usage cost seconds md_bytes
        prefix-{hash12}.md              静态前缀只存一份: INSTRUCTION/FOLLOWUP 模板 + tag.md + 示例 (hash 变 = 新文件, 天然版本化)
        {folder}/{stem}/meta.json       同 agent.jsonl 那一行 (开始时写一次, 收尾覆盖)
        {folder}/{stem}/round-N.prompt.md    发出的 prompt; 首轮里 tag.md/示例/正文只留引用 (各有出处), 回喂轮全文
        {folder}/{stem}/round-N.events.jsonl run.messages() 的全部 SDKMessage (system/thinking/assistant/tool_call/status/usage), 边收边写
                                             → 能看模型怎么想、有没有乱调工具. 工具的 args/result schema 文档明说不稳定, 一律防御性序列化
        {folder}/{stem}/round-N.reply.md     result.result 原文 (从中扒 json)
        {folder}/{stem}/round-N.viol.txt     docpipe --one 输出, 通过写 "(通过)"
过程    stderr 每篇一行: [agent] 已完成/总数 结局 r轮数 stem
迭代    看: 结局分布 (commit / quarantine / run_* / no_md), 各违规前缀出现次数 (某前缀持续高 = 改 INSTRUCTION, 不是加轮数), 平均轮数, token;
        对 quarantine 的篇: viol.txt ↔ reply.md ↔ events.jsonl 的 thinking 对着看, 判断是 prompt 没说清 / 模型不行 / 规则本身过严
分布    阶段二报告里的 X2 (primary / module / approach 占比) 抓 "默认填"
抽样    随机 5% 人看 findings 是否核心结论、approach 是否范式级 —— 校验器管不住的两项
```

## 6. 未定

```
- prompt 上限未在文档写明; tag.md ~40KB + 示例 ~8KB + 正文 ≤160KB. 首批跑几篇看有没有 BadRequestError, 有则下调 TAG_AGENT_MD_MAX_BYTES 或改成 skeleton.
- 模型档: TAG_AGENT_MODEL 先 glm-5.2; 全库百美元量级, 决定性价比的是一次通过率不是单价, 故先跑一小批看 commit 率与平均轮数再定
  (quarantine 比例高就对那批换贵档重跑: 删 quarantine 里的 json + 改常量).
- 云端 agent 每篇起一台 VM, 单篇分钟级; 若整库耗时不可接受, 再考虑路线 A (原生 API + 结构化输出 + 显式缓存).
- 示例来源: 现在取 TAG_REPORT_DIR 下路径序前 2 篇, 随着提交增多会变 (hash 随之变). 稳定后可改成钉死两篇.
```
