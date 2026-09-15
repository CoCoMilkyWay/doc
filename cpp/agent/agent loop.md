## 0. 边界

```
目标     给 RAW 下每篇研报各写一份 tag json, 全部过 tag stage 校验. 由 stage3 自己驱动: 阶段一补全缺失, 阶段二整体校验 (tag.hpp).
分工     agent loop 只负责 "生成 + 单篇闭环"; 判对错 / 格式化 / 跨文件规则 / 统计 全部归 tag stage (cpp), python 侧不复制任何规则.
路线     智谱 GLM 对话补全接口, 官方 zai-sdk (https://docs.bigmodel.cn/cn/api/introduction). 一篇 = 一段多轮对话 (messages 列表);
         一轮 = 一次 chat.completions.create(stream=True, response_format=json_object, thinking=enabled, reasoning_effort).
         report.md 正文随 user 消息发送 (中位 42KB, p90 73KB, 超 TAG_AGENT_MD_MAX_BYTES 截断); 结果 = content 整段 (JSON 模式,
         平台保证是一个可解析的 json 对象; 若模型仍包了 ```json 围栏也认). 回喂 = 把违规行作为下一条 user 消息追加到同一 messages 再问一轮.
         静态前缀 (指令 + tag.md + 示例) 放 system 消息且全库逐字节相同 => 吃平台隐式上下文缓存 (缓存命中 2 元/M vs 输入 8 元/M);
         带 stem/hash 的几行放 user 消息开头, system 里一个字都不能随篇变.
         流式是为了躲 300s 读超时 (首轮思考 1~1.3 万 reasoning tokens, 几分钟); reasoning_content 边收边落盘, content 拼起来.
代码     cpp/agent/tag_loop.py (由 tag.cpp::fill_missing 用内置便携 python 调起, 参数全部来自 config.hpp, 含单价表)
         cpp/src/stages/tag/env.cpp: T1 便携 python / T2 zai-sdk 及四条用法假设 (客户端类 / create 关键字 / 异常类 / httpx), 缺则打印 pip --target 安装指令后断言
         docpipe ROOT tag --one <json>: 单文件校验子命令, 违规一行一条到 stdout, 退出码 0/1 (tag.cpp::run_one)
未选     Cursor Python SDK 云端 agent (上一版): 每篇起一台 VM 分钟级, run "秒错" 无法取证, 无裸 completions, 无缓存. 已整体换掉.
         Batch API (5 折, 无并发限制): 官方支持表只有 GLM-4 系列 (docs.bigmodel.cn/cn/faq/batch-api-issues), GLM-5.x 用不上.
         对话补全(异步) (/async/chat/completions + 轮询): 支持 GLM-5.x, 速率限制页称可 "降低并发压力", 但是否不占并发权益文档未明说, 未验证.
```

## 1. 状态机 (单篇; python 里就是 Loop.one 的一个 while)

```
  missing.tsv 一行 ──▶ SELECT ── quarantine 已有该篮 ──▶ SKIP(quarantined_before)
  (folder stem date)    │  ───── 无 report.md (F4) ──▶ SKIP(no_md)
                        ▼
                     PREPARE   读 report.md (超 TAG_AGENT_MD_MAX_BYTES 截断并在 prompt 标明), messages = [system 静态前缀, user 本篇] (§2)
                        ▼      写 meta.json (开始时一次); request_id = "tag-" + sha1(stem)[:16] (和服务端对账的钥匙, 每轮再加 -rN)
          ┌────────▶ RUN       round += 1.  chat.completions.create(stream=True) 在线程里跑 (asyncio.to_thread);
          │             │      流里 reasoning_content → round-N.thinking.md, content 拼成 reply, 末 chunk 带 usage (记 token 与本轮费用)
          │             │      撞 429 且业务码 1302/1305 ⇒ 背压: 等 CAP_WAIT_SEC 再发, 最多 CAP_WAIT_MAX 次
          │             ├── finish_reason != stop ──▶ FAIL(run_length / run_sensitive / run_network_error / run_model_context_window_exceeded)
          │             │                              (不落文件, 该篇仍 "缺失", 下次再跑)
          │             ▼      messages += assistant(reply)
          │          EXTRACT   reply 整段 (JSON 模式) 或其中最后一个 ```json 块 → 写 TAG_STAGING_DIR/{folder}/{stem}.json
          │             │      取不出对象 ⇒ 视作违规 "F3 回复不是一个 json 对象"
          │             ▼
          │          VERIFY    docpipe ROOT tag --one <staging json>  (F2 F3 S V K G; F3 顺手把文件格式化成规范形)
          │             ├── 无违规 ──▶ COMMIT   rename staging → TAG_REPORT_DIR/{folder}/{stem}.json
          │             ├── 有违规 ∧ round < TAG_AGENT_MAX_ROUND ──▶ messages += user(FOLLOWUP(违规行)) ──┐
          │             └── 有违规 ∧ round == TAG_AGENT_MAX_ROUND ──▶ QUARANTINE                          │
          └────────────────────────────────────────────────────────────────────────────────────────────────┘
                                 rename staging → TAG_QUARANTINE_DIR/{folder}/{stem}.json + {stem}.viol (各轮违规)

  收尾 (所有出口)   写 meta.json (含 usage / cost_yuan / runs / outcome), 追加一行 agent.jsonl (TAG_AGENT_LOG_DIR), stderr 打一行
```

规则:
- 违规不分责任节点: 整份 json 由同一段对话一次出, 全部违规行原样回喂, 让它出修正后的完整 json (不接受差异).
- 解析失败 / S1 / S2 (结构性) 同样回喂 —— 没有 "代码 bug" 这一类, 因为 json 是模型直接写的.
- X 规则 (跨文件) 不在单篇 loop 内, 由阶段二整体跑; X 违规不自动回喂, 打印给人看.
- FAIL 不占 quarantine: 下一次 `run.py tag` 会把它当缺失重来. quarantine 要重试就删掉那个 json.

## 2. Prompt

```
system = SYSTEM 模板 (指令 + 自查) + tag.md 原文 + 示例 (TAG_REPORT_DIR 下按路径序取前 2 篇已过校验的 json)   —— 静态, 全库同一份
user   = 本篇固定值 (id / schema_version / gen 的字面值) + report.md 正文 (<<<REPORT_BEGIN/END>>> 包住, 截断时标明)
SYSTEM 指令: JSON 模式只出一个对象; 逐字抄 evidence; 枚举只用本字段的 code; 只写涉及的阶段; 流派选范式级; 例行 IC 检验不算 L2;
             高频信号归 L1_market; 正文可能截断不要臆测; 键序/数字写法/列表序由 F3 自动规范化不用管
       末尾附"出稿前自查"五条 = 实测首轮违规频次前五 (V1 串词表 / S1 缺键 / G1 evidence 漏抄括号内容或太短 / S2 stats 位序 / G4 findings 不贴合).
       G1 一条实测 8 篇 5 次打回全是漏抄括号里的中英对照 (如 "（Specific Return）"), 已点名. 原先有 S3 列表序, 已改由 F3 自动排序
回喂   = FOLLOWUP(违规行): "校验器报出以下违规 … 请修正后重新输出完整的 json 对象"
hash   = sha256(system 全文 + USER 模板 + FOLLOWUP 模板) → 写进 gen.prompt_sha256. 任一变 → hash 变.
         (增量重标 = 删掉 hash 不一致的 json 再跑; 目前不自动删, 由人决定; 校验器不查跨文件 hash 一致)
```

## 3. 并发与幂等

```
并发    asyncio: TAG_AGENT_WORKERS 个任务从队列取篇, 篇内串行到底 (首轮 → 校验 → 回喂 → commit/quarantine), 做完才取下一篇.
        zai-sdk 只有同步客户端 (无 Async*), 阻塞的一轮用 asyncio.to_thread 丢进线程; httpx.Client 线程安全, 各线程共用一个 (连接池默认 50).
        只写自己 stem 的 staging/out/quarantine/log 文件, 无共享写.
吞吐    = workers / 单篇耗时. 实测单篇 1.5~4.5 分钟 (首轮思考几分钟 + 回喂轮几十秒), 4 路约 70 篇/小时.
        TAG_AGENT_WORKERS = TAG_AGENT_PRICES[model].concurrency = 账户对该模型的并发上限 (控制台 → 速率限制, V0: glm-5.2 10 / glm-5.3 5 / glm-5.3-flash 50),
        开满: glm-5.2 10 路约 170 篇/小时, 1121 篇约 6.5 小时. 文档不公布各等级数字, 权益等级变了要手抄一次.
上限    429 且业务码 1302 (账户速率/并发上限) 或 1305 (平台过载) = 背压: 等 CAP_WAIT_SEC 再发同一轮, 最多 CAP_WAIT_MAX 次仍撞 ⇒ 抛出
        (说明 workers 开得比权益大得多). 其余 429 (1113 欠费 / 13xx 额度) 不是等得来的, 直接抛.
顺序    missing.tsv 由 tag.cpp 按 raw 遍历序写出 ({券商}/{系列}/stem 字节序), 与报告同序.
幂等    缺失 := TAG_REPORT_DIR 下无该 json (tag.cpp::collect). 已提交的不再碰; quarantine 的跳过.
中断    staging 每次启动清空; out 只经 rename 落地, 无半截文件. Ctrl+C 由 docpipe 转给 python (proc.cpp, 第二次升级为 SIGKILL):
        第一次只置 stop 旗标 —— 不再派发新篇, 在飞的几篇跑完当前这轮正常收尾 (写全 meta.json), 最多几分钟.
        不能让 KeyboardInterrupt 直接穿过去: 那会把 Loop.one 的 finally 一起取消, meta.json 缺 outcome; 而且阻塞在线程里的那一轮
        本来也取消不掉, 会继续读流到结束. 真等不及就再按一次, 交给 docpipe 硬杀.
重试    SDK 自带对 408/409/429/5xx 的 3 次指数退避 (0.5s~8s); 这之上只加 1302/1305 的背压等待. 不猜、不兜底、不自造超时 (默认 connect 8s / read 300s).
失败    分两类, 因为整批要跑十几个小时, 为一篇的服务端故障赔掉全批太贵 (server_fault()):
        · 服务端/网络 (zai.core.ZaiError, httpx.HTTPError) 及 400/1301 内容安全拦截 ⇒ 只坏这一篇, 记 outcome=sdk_error, 接着派下一篇
          (该篇仍 "缺失", 下次再跑). 连续 FAIL_STREAK 篇都栽在这 (中间没有一篇 commit/quarantine) ⇒ 不是偶发, 停止派发并非 0 退出
        · 鉴权 401 / 其余 400 (1211 模型不存在 / 1261 prompt 超长 / 1214 参数非法) / docpipe --one 非 0/1 退出 / 断言 = 我们自己的问题
          ⇒ 立刻停止派发新篇, 在飞的收尾
        ⇒ python 非 0 ⇒ tag.cpp 断言中止. 该篇 meta.json 记 outcome + 异常.
```

## 4. 常量 (config.hpp, 唯一出处; python 全部由命令行接收)

```
TAG_STAGING_DIR TAG_QUARANTINE_DIR TAG_AGENT_LOG_DIR   都在 TAG_REPORT_DIR 之外 (放进去被 F1 判多余)
TAG_AGENT_SCRIPT TAG_AGENT_MODEL TAG_AGENT_REASONING_EFFORT TAG_AGENT_WORKERS TAG_AGENT_MAX_ROUND TAG_AGENT_MD_MAX_BYTES
TAG_AGENT_PRICES  每型号一行: 单价 (元/百万 tokens: 输入 / 输出 / 缓存命中) + 本账户并发上限. TAG_AGENT_MODEL 必须在表里 (consteval 查表, 不在 ⇒ 编译失败);
                  tag.cpp 以 --price-in/--price-out/--price-hit 传给 python, 每轮费用 = (prompt-cached)*in + cached*hit + completion*out;
                  TAG_AGENT_WORKERS 直接取表里的并发上限
python 内部: FAIL_STREAK=10 TALLY_EVERY=25 CAP_WAIT_SEC=30 CAP_WAIT_MAX=20 CAP_CODES=(1302,1305) SENSITIVE_CODE=1301 (超时/重试归 SDK, 这里不设)
密钥: TAG_AGENT_KEY_FILE (cpp/agent/glm_api_key.txt, 一行 {id}.{secret}, 已 gitignore; bigmodel.cn 控制台 → API Keys). 文件不存在则阶段一整体跳过, 只做校验.
依赖: 内置便携 python (PYTHON_BIN) + zai-sdk 装在各 stage 共享的 PYTHON_DEPS_DIR (pip --target), 由 check_tag_env 检查并设 PYTHONNOUSERSITE/PYTHONPATH.
```

## 5. 交互记录与监控 (TAG_AGENT_LOG_DIR = resources-tag/agent-log)

```
布局    agent.jsonl                     每篇一行汇总: stem folder model prompt_sha256 request_id runs(每轮 id/request_id/finish_reason/usage/cost_yuan)
                                        outcome round viol_history usage(整篇 prompt/cached/completion) cost_yuan seconds md_bytes truncated.
                                        id/request_id 是和服务端对账的钥匙 (平台按 request_id 记日志)
        prefix-{hash12}.md              静态前缀只存一份: system 全文 + USER/FOLLOWUP 模板 (hash 变 = 新文件, 天然版本化)
        {folder}/{stem}/meta.json       同 agent.jsonl 那一行 (开始时写一次, 收尾覆盖)
        {folder}/{stem}/round-N.prompt.md    发出的 user 消息; 首轮里正文只留引用 (路径 + 字节数), 回喂轮全文
        {folder}/{stem}/round-N.thinking.md  流里的 reasoning_content, 边收边写 (首轮 40~50KB): 看模型怎么想, 判断是 prompt 没说清还是模型不行
        {folder}/{stem}/round-N.reply.md     content 原文 (从中取 json)
        {folder}/{stem}/round-N.viol.txt     docpipe --one 输出, 通过写 "(通过)"
清理    开跑前 clean_logs 把"这轮要重跑的篇" (= missing 里未进 quarantine 的) 的目录删掉, agent.jsonl 里对应行也去掉:
        否则新旧 round-N.* 混在一个目录里 (这轮轮数更少时旧文件会被当成本轮的), agent.jsonl 一篇好几行.
        已完成的篇不在 missing 里, 碰不到; quarantine 里的篇这轮跳过, 记录留着当迭代材料; prefix-*.md 按 hash 存, 不动
过程    stderr 每篇一行: [agent] 已完成/总数 结局 r轮数 秒数 输入k↑(缓存k) 输出k↓ 费用元 stem
        每 TALLY_EVERY 篇 (及收尾) 多一行汇总: 结局分布 | 输入/缓存命中率/输出 tokens | 累计费用·均价·预计全部 | 已用时与 ETA
        —— 分布决定改 prompt 还是换模型, 缓存命中率决定前缀有没有被弄乱, 费用与 ETA 决定换不换模型 / 调不调 workers
迭代    看: 结局分布 (commit / quarantine / run_* / no_md), 各违规前缀出现次数 (某前缀持续高 = 改 SYSTEM, 不是加轮数), 平均轮数, token, 费用;
        对 quarantine 的篇: viol.txt ↔ reply.md ↔ thinking.md 对着看, 判断是 prompt 没说清 / 模型不行 / 规则本身过严
分布    阶段二报告里的 X2 (primary / module / approach 占比) 抓 "默认填"
抽样    随机 5% 人看 findings 是否核心结论、approach 是否范式级 —— 校验器管不住的两项
```

## 6. 未定

```
- 上下文 1M, 正文 ≤160KB 远够; 超长会以 400/1261 或 finish_reason=model_context_window_exceeded 报出, 前者整批停 (我们的参数问题), 后者只坏该篇.
- 费用: 实测 glm-5.2 high 单篇 ≈ 45k 输入 (约半数缓存命中) + 15k 输出 (其中 1.1~1.3 万 reasoning) ≈ 0.6~0.8 元, 1121 篇约 700~900 元;
  大头是 reasoning tokens (28 元/M), glm-5.2 上 high 已是最低有效档 (low/medium 都映射成 high), 压不下去.
  glm-5.3-flash 单价 1/10 且支持 low/high/max, 同样 JSON 模式 + 缓存 —— 值得拿一小批比 commit 率与平均轮数, 再定全库用哪个
  (换模型 = 改 TAG_AGENT_MODEL, 单价表已有; quarantine 比例高就对那批换贵档重跑: 删 quarantine 里的 json + 改常量).
- JSON 模式与思考同开: bigmodel 结构化输出页示例即 glm-5.2 默认开思考, 但阿里云百炼的 GLM-5.2 页写 "结构化输出 仅非思考模式".
  若 bigmodel 也不支持, 首篇就会 400 (参数问题 ⇒ 整批立停, 零浪费), 那时去掉 response_format 退回围栏提取即可 (extract_json 两种都认).
- temperature 默认 1.0; 核心参数页建议事实性任务用较低值. 逐字抄写任务偏低温可能减少 G1 打回, 但对思考链的影响文档没说, 没动.
- 示例来源: 现在取 TAG_REPORT_DIR 下路径序前 2 篇, 随着提交增多会变 (hash 随之变). 稳定后可改成钉死两篇.
- 缓存: system 前缀 ~8.3k tokens 稳定命中 (cached_tokens 8192~8384), 回喂轮把首轮整段都命中 (2 万+). 同时起跑的前 workers 篇
  必然 miss (缓存还没建起来), 之后偶有 0 (平台侧时效性), 不处理.
```
