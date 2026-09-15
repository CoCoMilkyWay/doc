## 0. 边界

```
目标     给 RAW 下每篇研报各写一份 tag json, 全部过 tag stage 校验. 由 stage3 自己驱动: 阶段一补全缺失, 阶段二整体校验 (tag.hpp).
分工     agent loop 只负责 "生成 + 单篇闭环"; 判对错 / 格式化 / 跨文件规则 / 统计 全部归 tag stage (cpp), python 侧不复制任何规则.
路线     B: Cursor Cloud Agents API (https://api.cursor.com/v1, 公测). 一篇 = 一个 agent; 一轮 = 一个 run.
         无仓库代理 (省略 repos/env): 仓库 4GB, 每篇 clone 不可接受; report.md 正文直接随 prompt 发送 (中位 42KB, p90 73KB, 超上限截断).
         结果 json 从 run.result 文本里的 ```json 代码块取, 不走 git / artifacts. 回喂 = 对同一 agent POST /runs (保留对话与上一版).
代码     cpp/agent/tag_loop.py (标准库, 由 tag.cpp::fill_missing 用便携 python 调起, 参数全部来自 config.hpp)
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
          ┌────────▶ RUN       round += 1.  首轮 POST /v1/agents {prompt, model, name}  ;  回喂轮 POST /v1/agents/{id}/runs {prompt}
          │             │      轮询 GET /runs/{runId} 每 POLL_SEC 直到终态; 超 RUN_TIMEOUT_SEC 则 cancel
          │             ├── status != FINISHED ──▶ FAIL(run_error / run_cancelled / run_expired)   (不落文件, 该篇仍 "缺失", 下次再跑)
          │             ▼
          │          EXTRACT   run.result 里最后一个 ```json 块 → 写 TAG_STAGING_DIR/{folder}/{stem}.json
          │             │      没有 json 块 ⇒ 视作违规 "F3 回复中没有 json 代码块"
          │             ▼
          │          VERIFY    docpipe ROOT tag --one <staging json>  (F2 F3 S V K G; F3 顺手把文件格式化成规范形)
          │             ├── 无违规 ──▶ COMMIT   rename staging → TAG_REPORT_DIR/{folder}/{stem}.json
          │             ├── 有违规 ∧ round < TAG_AGENT_MAX_ROUND ──▶ prompt = FOLLOWUP(违规行) ──┐
          │             └── 有违规 ∧ round == TAG_AGENT_MAX_ROUND ──▶ QUARANTINE                 │
          └───────────────────────────────────────────────────────────────────────────────────────┘
                                 rename staging → TAG_QUARANTINE_DIR/{folder}/{stem}.json + {stem}.viol (各轮违规)

  收尾 (所有出口)   GET /usage 记 token; POST /archive 归档 agent; 追加一行 TAG_AGENT_LOG (jsonl)
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
并发    ThreadPoolExecutor(TAG_AGENT_WORKERS), 一篇一线程, 篇内串行. 只写自己 stem 的 staging/out/quarantine 文件, 无共享写.
顺序    missing.tsv 由 tag.cpp 按 raw 遍历序写出 ({券商}/{系列}/stem 字节序), 与报告同序.
幂等    缺失 := TAG_REPORT_DIR 下无该 json (tag.cpp::collect). 已提交的不再碰; quarantine 的跳过.
中断    staging 每次启动清空; out 只经 rename 落地, 无半截文件. Ctrl+C 由 docpipe 转给 python, 在跑的 run 留在 Cursor 侧自然结束.
失败    任一篇抛异常 (HTTP 4xx 非限速 / 模型 id 不存在 / docpipe --one 非 0/1 退出) ⇒ 整个 python 非 0 ⇒ tag.cpp 断言中止. 429/5xx 指数退避重试.
```

## 4. 常量 (config.hpp, 唯一出处; python 全部由命令行接收)

```
TAG_STAGING_DIR TAG_QUARANTINE_DIR TAG_AGENT_LOG   都在 TAG_REPORT_DIR 之外 (放进去被 F1 判多余)
TAG_AGENT_SCRIPT TAG_AGENT_MODEL TAG_AGENT_WORKERS TAG_AGENT_MAX_ROUND TAG_AGENT_MD_MAX_BYTES
python 内部: POLL_SEC=5 RUN_TIMEOUT_SEC=1800 HTTP_RETRY=5
环境: CURSOR_API_KEY (Cursor Dashboard → API Keys). 未设则阶段一整体跳过, 只做校验.
```

## 5. 监控

```
过程    stderr 每篇一行: [agent] 已完成/总数 结局 r轮数 stem
事后    TAG_AGENT_LOG 每篇一行 jsonl: stem folder model prompt_sha256 agent_id outcome round viol_history usage seconds
        看: 结局分布 (commit / quarantine / run_* / no_md), 各违规前缀出现次数 (某前缀持续高 = 改 INSTRUCTION, 不是加轮数), 平均轮数, token
分布    阶段二报告里的 X2 (primary / module / approach 占比) 抓 "默认填"
抽样    随机 5% 人看 findings 是否核心结论、approach 是否范式级 —— 校验器管不住的两项
```

## 6. 未定

```
- prompt.text 上限未在文档写明; tag.md ~40KB + 示例 ~8KB + 正文 ≤160KB. 首批跑几篇看有没有 4xx, 有则下调 TAG_AGENT_MD_MAX_BYTES 或改成 skeleton.
- 模型档: TAG_AGENT_MODEL 先 composer-2 (便宜档); quarantine 比例高再对那批换贵档重跑 (删 quarantine 里的 json + 改常量).
- 示例来源: 现在取 TAG_REPORT_DIR 下路径序前 2 篇, 随着提交增多会变 (hash 随之变). 稳定后可改成钉死两篇.
```
