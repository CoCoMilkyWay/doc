#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""stage3 阶段一: 用 Cursor Python SDK 给缺失的研报补标签 (设计见同目录 agent loop.md).

由 docpipe tag 调起 (tag.cpp::fill_missing), 全部参数来自 config.hpp, 这里不另存配置.
依赖 cursor-sdk (装法见 tag/env.cpp 的 T2), 环境由 check_tag_env 备好 (PYTHONNOUSERSITE / PYTHONPATH).

一篇 = 一个云端无仓库 agent (CloudAgentOptions(repos=[]), 仓库 4GB 不值得 clone, report.md 正文随 prompt 发送),
一轮 = agent.send() 的一个 run: 流里的 SDKMessage 落 events.jsonl (连续文本增量合并成一条), run.wait() 拿终态与最终文本, 从文本里取
```json 写 staging, 交 `docpipe ROOT tag --one` 校验; 有违规就把违规行回喂同一个 agent (对话与上一版都还在) 再问一轮,
通过则 rename 进 TAG_REPORT_DIR, 用完轮数进 quarantine. 收尾 agent.archive() (不归档会一直占套餐的并发坑).

按文档用 SDK: 并发编排用 AsyncClient (同步 API 没有并发约定), 重试只认 CursorAgentError.is_retryable/retry_after.
服务端的毛病 (CursorAgentError) 只坏它那一篇, 记成 sdk_error 接着跑下一篇, 连着坏 FAIL_STREAK 篇才停;
自己的 bug (断言失败等) 一律抛出 —— 越早失败越便宜, 由 docpipe 的断言接住.
"""
import argparse, asyncio, dataclasses, hashlib, json, os, re, shutil, signal, sys, time

from cursor_sdk import (  # pyright: ignore[reportMissingImports]
    AsyncClient,
    AsyncCursor,
    CloudAgentOptions,
    CursorAgentError,
)

RETRY = 5  # is_retryable 的错误最多重试几次 (指数退避, 服务端给了 retry_after 就照它等)
FAIL_STREAK = 10  # 连续这么多篇栽在服务端故障就停: 偶发只坏一篇, 连着坏就是系统性的, 别烧着钱空转
TALLY_EVERY = 25  # 每这么多篇打一行累计汇总 (结局分布 / 花费 / ETA)
CAP_WAIT_SEC = 30  # 撞到套餐的 "同时在跑 agent 数" 上限: 这是背压不是错误, 等别的篇收尾
CAP_WAIT_MAX = (
    20  # 最多等这么多次 (10 分钟) 仍撞上限 => 抛出 (说明有泄漏的 agent 占着坑)
)
CAP_MARK = "reached the limit"
META_MARK = {"docpipe": "tag"}  # 打在 agent 上, 供启动时识别并清理上次泄漏的

# ---------- prompt ----------

INSTRUCTION = """你是量化研报标注员. 任务: 为下面这篇研报写一份标签 json, 严格遵守随后给出的 schema 说明 (tag.md). 只输出一个 ```json 代码块, 不要任何解释.

硬性要求:
- "id" 必须是 "{stem}"; "schema_version" 必须是 {ver}; "gen" 必须是 {{"model": "{model}", "prompt_sha256": "{hash}"}}.
- 所有 evidence 与 Factor.name 必须逐字抄自下面的研报正文 (不改标点、不合并行、不缩写、不翻译); Factor.stats 里的每个数字必须是正文里出现的数字 (原文百分数写成小数, 如 16.5% -> 0.165; 不做任何换算), 正文没给的位置填 null.
- 枚举值只能用 tag.md §1/§2 列出的 code, 且每个字段只认它自己那张词表 (如 Factor.family 只能用 FactorFamily 的 code, 不能填 Approach 的).
- 只写研报实际涉及的阶段; 数字只在 L1 的 Factor.stats, 策略/组合的收益·超额·回撤只进 findings; findings 至少一条, 每条都要有 evidence.
- 每个 Factor 都要有 data_period (构造它用的原始数据周期)、horizon (它预测的收益期限) 和 formula (LaTeX 表达式, 无闭式的写 \\text{{...}} 描述).
- 流派 (approach) 选范式级的类别, 不要按具体实现名硬套; 例行的 IC/分组检验不算 L2, 高频/日内预测信号归 L1_market.
- 研报正文可能被截断 (见标记), 只根据看到的内容标注, 不要臆测.
- 键序、数字写法 (尾零/指数)、列表顺序都不用管, 校验器会自动规范化.

出稿前逐条自查 —— 下面五处是实测最常被校验器打回的, 每错一条就要多花一整轮:
1. V1 每个枚举字段只认它自己那张词表: primary 和 pipe 的键填 PipeStage (L0_data…L8_timing), module 填 Module (L8_rotation 是 Module 不是阶段), approach 填 Approach.
2. S1 每个出现的阶段, tag.md §2 给它列的键一个不少, 没内容的列表写 [] (L3_alpha 的 baseline 最常漏).
3. G1 每条 evidence 是正文里连续的一整句, 去掉空白与 markdown 符号后仍有 20 个以上码点.
4. S2 Factor.stats 恰好 4 项, 位序固定 [ic, rank_ic, icir, return_ls], 不确定的填 null 而不是猜.
5. G4 findings[i].text 用它 evidence 里的原词原句压缩而成, 不要换一套说法.

## schema 说明 (tag.md, 原文)
{spec}

## 示例 (已通过校验)
{examples}

## 研报正文 ({stem} 的 report.md{truncated})
<<<REPORT_BEGIN>>>
{md}
<<<REPORT_END>>>
"""

FOLLOWUP = """校验器对你上一版 json 报出以下违规 (规则编号见 tag.md §3, 每行一条):
{viol}
请修正后重新输出完整 json (仍然只输出一个 ```json 代码块, 其余要求不变; 不要只输出差异)."""

JSON_FENCE = re.compile(r"```json\s*\n(.*?)\n\s*```", re.S)
ANY_FENCE = re.compile(r"```\w*\s*\n(\{.*?\})\n\s*```", re.S)


def extract_json(text):
    m = JSON_FENCE.findall(text) or ANY_FENCE.findall(text)
    if m:
        return m[-1].strip()
    t = text.strip()
    return t if t.startswith("{") and t.endswith("}") else None


def load_examples(out_dir, n=2):
    found = []
    for dp, _, fs in sorted(os.walk(out_dir)):
        for f in sorted(fs):
            if f.endswith(".json"):
                found.append(os.path.join(dp, f))
    found = found[:n]
    if not found:
        return "(暂无)"
    return "\n".join(
        "```json\n%s\n```" % open(p, encoding="utf-8").read().rstrip("\n")
        for p in found
    )


# ---------- SDK 对象 → json ----------
# 工具调用的 args/result 负载 schema 文档明说不稳定, 一律防御性序列化: dataclass 摊平, 其余 repr


def plain(o):
    if dataclasses.is_dataclass(o) and not isinstance(o, type):
        return dataclasses.asdict(o)
    if isinstance(o, (set, frozenset, tuple)):
        return list(o)
    return repr(o)


def jsonable(o):
    return (
        json.loads(json.dumps(o, ensure_ascii=False, default=plain))
        if o is not None
        else None
    )


def event_row(ev, t0):
    """RunStreamEvent → 一行记录 (不记则返回 None).

    记 sdk_message (type/status/text/工具调用, 信封字段稳定) 与 result/done 两种终态信封。终态信封原样落盘:
    RunResult 只留规范化后的 status (服务端给的未知状态串会被归一成 "error"), 原始状态串与失败原因只在这里。
    step/interaction_update 是同一批内容的另一种切法, 与 sdk_message 重复, 不记。"""
    msg = ev.sdk_message
    if msg is not None:
        row = {"type": getattr(msg, "type", "?")}
        for k in (
            "subtype",
            "status",
            "message",
            "text",
            "call_id",
            "name",
            "args",
            "result",
            "truncated",
            "thinking_duration_ms",
            "usage",
            "request_id",
            "model",
            "tools",
        ):
            v = getattr(msg, k, None)
            if v is not None:
                row[k] = v
    elif ev.result is not None or ev.done is not None:
        row = {
            "kind": ev.kind,
            "payload": ev.result if ev.result is not None else ev.done,
        }
    else:
        return None
    row["t"] = round(time.time() - t0, 1)
    return json.dumps(row, ensure_ascii=False, default=plain)


class Delta:
    """把连续的同类文本增量 (thinking / assistant 的逐 token text) 并成一条再落盘.

    原样记一轮是 1500~1900 行, 其中 99% 是几个字的 delta: 人读不了, 文件也白占地方 (迭代 prompt 时
    要翻的恰恰是这些 thinking). 合并后一轮十几行, 每行带该段的 delta 条数与起始秒.
    非增量事件 (status / tool_call / usage / 终态信封) 仍原样一行一条, 交给 event_row."""

    MERGE = ("thinking", "assistant")

    def __init__(self):
        self.pend = None  # [type, 已拼接文本, 段起始秒, 段内 delta 条数]

    def feed(self, ev, t0):
        msg = ev.sdk_message
        typ = getattr(msg, "type", None) if msg is not None else None
        text = getattr(msg, "text", None) if typ in self.MERGE else None
        if text is None:
            out = self.tail()
            row = event_row(ev, t0)
            if row:
                out.append(row)
            return out
        if self.pend is not None and self.pend[0] == typ:
            self.pend[1] += text
            self.pend[3] += 1
            return []
        out = self.tail()
        self.pend = [typ, text, round(time.time() - t0, 1), 1]
        return out

    def tail(self):
        """收尾: 把还压着的那段吐出来 (流结束时必须调一次)."""
        if self.pend is None:
            return []
        typ, text, t, n = self.pend
        self.pend = None
        return [
            json.dumps(
                {"type": typ, "text": text, "deltas": n, "t": t}, ensure_ascii=False
            )
        ]


def hms(sec):
    return "%d:%02d:%02d" % (sec // 3600, sec // 60 % 60, sec % 60)


async def retrying(what, factory):
    """按文档的重试约定包一层: is_retryable 才重试, 服务端给了 retry_after 就照它等;
    套餐并发上限 (CAP_MARK) 当背压等待. 其余错误直接抛."""
    attempt = cap_wait = 0
    while True:
        try:
            return await factory()
        except CursorAgentError as err:
            if CAP_MARK in str(err) and cap_wait < CAP_WAIT_MAX:
                cap_wait += 1
                await asyncio.sleep(CAP_WAIT_SEC)
                continue
            if not err.is_retryable or attempt >= RETRY:
                raise
            attempt += 1
            delay = (
                float(err.retry_after)
                if (err.retry_after or "").isdigit()
                else 2**attempt
            )
            print(
                "[agent] %s 可重试错误 (%s), %.0fs 后第 %d 次重试"
                % (what, err.code or err.status, delay, attempt),
                file=sys.stderr,
                flush=True,
            )
            await asyncio.sleep(delay)


# ---------- 单篇 ----------


class Loop:
    def __init__(self, a, client, spec, examples, prompt_hash):
        self.a, self.client = a, client
        self.spec, self.examples, self.hash = spec, examples, prompt_hash
        self.lock = asyncio.Lock()
        self.done = 0
        self.total = 0
        self.tally = {}  # outcome -> 篇数
        self.streak = 0  # 连续栽在服务端故障的篇数, 见 FAIL_STREAK
        self.cents = 0.0
        self.t_start = time.time()

    async def validate(self, path):
        """本机校验器是唯一判官 (F2-F4 S V K G), python 侧不复制任何规则."""
        p = await asyncio.create_subprocess_exec(
            self.a.docpipe,
            self.a.root,
            "tag",
            "--one",
            path,
            stdout=asyncio.subprocess.PIPE,
            stderr=asyncio.subprocess.PIPE,
        )
        out, err = await p.communicate()
        assert p.returncode in (0, 1), "docpipe --one 异常退出 %d: %s" % (
            p.returncode,
            err.decode()[-2000:],
        )
        return [l for l in out.decode().splitlines() if l]

    async def log(self, rec):
        async with self.lock:
            with open(
                os.path.join(self.a.log_dir, "agent.jsonl"), "a", encoding="utf-8"
            ) as f:
                f.write(json.dumps(rec, ensure_ascii=False) + "\n")
            self.done += 1
            cost = (rec.get("cost") or {}).get("charged_cents", 0.0)
            self.cents += cost
            self.tally[rec["outcome"]] = self.tally.get(rec["outcome"], 0) + 1
            if rec["outcome"] in ("commit", "quarantine"):  # 模型答错不算故障
                self.streak = 0
            elif rec["outcome"].startswith(("run_", "sdk_")):
                self.streak += 1
            print(
                "[agent] %d/%d %-10s r%d %6.1fs %5.1f¢ %s"
                % (
                    self.done,
                    self.total,
                    rec["outcome"],
                    rec.get("round", 0),
                    rec.get("seconds", 0.0),
                    cost,
                    rec["stem"],
                ),
                file=sys.stderr,
                flush=True,
            )
            if self.done % TALLY_EVERY == 0:
                print(self.summary(), file=sys.stderr, flush=True)

    def summary(self):
        """一行看清这批跑成什么样: 结局分布决定下一步改 prompt 还是换模型, ETA 决定要不要调 workers."""
        el = time.time() - self.t_start
        return (
            "[agent] ---- %d/%d (%.0f%%)  %s | $%.2f 共, %.1f¢/篇 | 已用 %s, 余 %s"
            % (
                self.done,
                self.total,
                100.0 * self.done / max(self.total, 1),
                " ".join("%s %d" % kv for kv in sorted(self.tally.items())),
                self.cents / 100,
                self.cents / max(self.done, 1),
                hms(el),
                hms(el / max(self.done, 1) * (self.total - self.done)),
            )
        )

    @staticmethod
    def dump(path, text):
        with open(path, "w", encoding="utf-8") as f:
            f.write(text if text.endswith("\n") else text + "\n")

    async def one(self, folder, stem, date):
        a = self.a
        sub = "" if folder == "." else folder + "/"
        md_path = os.path.join(a.proc, sub + stem, a.md_name)
        stg_path = os.path.join(a.staging, sub + stem + ".json")
        out_path = os.path.join(a.out, sub + stem + ".json")
        q_path = os.path.join(a.quarantine, sub + stem + ".json")
        ldir = os.path.join(a.log_dir, sub + stem)  # 本篇交互全记录
        rec = {
            "stem": stem,
            "folder": folder,
            "model": a.model,
            "prompt_sha256": self.hash,
            "t0": time.time(),
        }
        if os.path.exists(q_path):
            rec["outcome"] = "quarantined_before"
            return await self.log(rec)
        if not os.path.exists(md_path):
            rec["outcome"] = "no_md"
            return await self.log(rec)

        md = open(md_path, "rb").read()
        md_bytes = len(md)
        truncated = ""
        if md_bytes > a.md_max:
            md = md[: a.md_max]
            truncated = ", 只含前 %d 字节, 已截断" % a.md_max
        md = md.decode("utf-8", errors="ignore")
        fill = dict(
            stem=stem,
            ver=a.schema_version,
            model=a.model,
            hash=self.hash,
            date=date,
            truncated=truncated,
        )
        prompt = INSTRUCTION.format(
            spec=self.spec, examples=self.examples, md=md, **fill
        )
        # 首轮 prompt 的静态前缀 (prefix-{hash}.md) 和正文 (report.md) 都另有出处, 记录里只留引用, 避免每篇复制 100KB
        prompt_log = INSTRUCTION.format(
            spec="<<见 %s/prefix-%s.md>>" % (a.log_dir, self.hash[:12]),
            examples="<<同上>>",
            md="<<%s, %d 字节%s>>" % (md_path, md_bytes, truncated),
            **fill
        )
        rec.update(md_bytes=md_bytes, truncated=bool(truncated))

        # create 会校验选项并立即返回句柄 (agent_id 当场可用), 不等 VM; 建不出来就不该留下半篮子记录目录
        agent = await retrying(
            "create " + stem,
            lambda: self.client.agents.create(
                model=a.model,
                name="tag " + stem,
                cloud=CloudAgentOptions(repos=[], metadata=dict(META_MARK, stem=stem)),
            ),
        )
        rec["agent_id"] = agent.agent_id
        os.makedirs(ldir, exist_ok=True)
        self.dump(
            os.path.join(ldir, "meta.json"),
            json.dumps(rec, ensure_ascii=False, indent=2),
        )
        async with agent:
            try:
                await self.rounds(
                    rec, agent, prompt, prompt_log, ldir, stg_path, out_path, q_path
                )
            except BaseException as e:
                # CursorAgentError 是服务端/网络的毛病, 只坏这一篇; 别的 (断言、KeyError…) 是我们自己的 bug
                rec.update(
                    outcome="sdk_error" if isinstance(e, CursorAgentError) else "error",
                    error=repr(e),
                )
                raise
            finally:
                billed = await agent.get_usage()
                rec["usage"] = jsonable(billed.usage)
                rec["cost"] = jsonable(billed.cost)
                await agent.archive()  # 不归档会一直占套餐的并发坑
                rec["seconds"] = round(time.time() - rec["t0"], 1)
                self.dump(
                    os.path.join(ldir, "meta.json"),
                    json.dumps(rec, ensure_ascii=False, indent=2),
                )
                await self.log(rec)

    async def send_round(self, rec, agent, prompt, ldir, rnd):
        """发一轮, 流边收边落盘, 返回 (RunResult, 本轮文件名前缀).

        服务端偶发"秒错": run 建出来后流里一条 sdk_message 都没有, 当场收到 error 信封就 done, 计费全 0.
        别重发 —— 实测重发要么再建一个照样秒错的 run, 要么撞 AgentBusyError("Agent already has an active run"):
        服务端那边这个 run 其实还占着 agent, 是我们这条流提前断了. 秒错就让这篇按 run_error 收场, 反正它
        没花钱, 下一次 pass 会把它当缺失重来."""
        rp = os.path.join(ldir, "round-%d." % rnd)
        run = await retrying("send " + rec["stem"], lambda: agent.send(prompt))
        t0 = time.time()
        delta = Delta()
        with open(rp + "events.jsonl", "w", encoding="utf-8") as ef:
            async for ev in run.events():  # 流只能消费一次; 剩余事件由 wait() 读完
                for row in delta.feed(ev, t0):
                    ef.write(row + "\n")
                ef.flush()
            for row in delta.tail():
                ef.write(row + "\n")
        result = await run.wait()
        # 每轮的 run 身份存档: 服务端只按 run_id 记账, 出问题时要能把本地这一轮和服务端那条对上
        rec.setdefault("runs", []).append(
            {
                "round": rnd,
                "run_id": result.id,
                "status": result.status,
                "ms": result.duration_ms,
            }
        )
        return result, rp

    async def rounds(
        self, rec, agent, prompt, prompt_log, ldir, stg_path, out_path, q_path
    ):
        a = self.a
        viol_history = []
        rnd = 0
        while True:
            rnd += 1
            self.dump(
                os.path.join(ldir, "round-%d.prompt.md" % rnd),
                prompt_log if rnd == 1 else prompt,
            )
            result, rp = await self.send_round(rec, agent, prompt, ldir, rnd)
            reply = result.result or ""
            self.dump(rp + "reply.md", reply)
            if result.status != "finished":
                rec["outcome"] = "run_" + result.status
                rec.update(round=rnd, viol_history=viol_history)
                return
            js = extract_json(reply)
            if js is None:
                viol = ["违规:F3 回复中没有 json 代码块"]
            else:
                os.makedirs(os.path.dirname(stg_path), exist_ok=True)
                self.dump(stg_path, js)
                viol = await self.validate(stg_path)
            viol_history.append(viol)
            self.dump(rp + "viol.txt", "\n".join(viol) if viol else "(通过)")
            if not viol:
                os.makedirs(os.path.dirname(out_path), exist_ok=True)
                os.replace(stg_path, out_path)
                rec["outcome"] = "commit"
                break
            if rnd >= a.max_round:
                os.makedirs(os.path.dirname(q_path), exist_ok=True)
                if os.path.exists(stg_path):
                    os.replace(stg_path, q_path)
                with open(q_path[:-5] + ".viol", "w", encoding="utf-8") as f:
                    for k, v in enumerate(viol_history, 1):
                        f.write("# round %d\n%s\n" % (k, "\n".join(v)))
                rec["outcome"] = "quarantine"
                break
            prompt = FOLLOWUP.format(viol="\n".join(viol))
        rec.update(round=rnd, viol_history=viol_history)


# ---------- 库级驱动 ----------


def clean_logs(a, missing):
    """清掉这轮要重跑那些篇的旧记录, 返回清掉的篇数.

    不清的话新旧 round-N.* 会混在同一个目录里 (这轮轮数更少时, 上一轮多出来的文件会被当成本轮的),
    agent.jsonl 也会一篇好几行. 已完成的篇不在 missing 里, 本来就碰不到; quarantine 里的篇这轮直接跳过
    (见 Loop.one), 它们的记录是迭代 prompt 的材料, 一并留着. prefix-*.md 按 hash 存, 留着不碍事."""
    redo = {}
    for folder, stem, _ in missing:
        sub = "" if folder == "." else folder + "/"
        if not os.path.exists(os.path.join(a.quarantine, sub + stem + ".json")):
            redo[stem] = os.path.join(a.log_dir, sub + stem)
    n = 0
    for d in redo.values():
        if os.path.isdir(d):
            shutil.rmtree(d)
            n += 1
    jl = os.path.join(a.log_dir, "agent.jsonl")
    if os.path.exists(jl):
        keep = [
            l
            for l in open(jl, encoding="utf-8").read().splitlines()
            if l and json.loads(l)["stem"] not in redo
        ]
        with open(jl, "w", encoding="utf-8") as f:
            for l in keep:
                f.write(l + "\n")
    return n


async def archive_leaked(client):
    """上次进程被 kill 留下的未归档 agent 会一直占套餐的并发坑. 按创建时打的 metadata 认领, 归档是幂等的."""
    n = 0
    page = await client.agents.list(runtime="cloud", include_archived=False)
    async for info in page.auto_paging_iter():
        if info.metadata.get("docpipe") == META_MARK["docpipe"] and not info.archived:
            await client.agents.archive(info.agent_id)
            n += 1
    return n


async def main():
    ap = argparse.ArgumentParser()
    for k in (
        "root",
        "docpipe",
        "key_file",
        "missing",
        "staging",
        "out",
        "proc",
        "md_name",
        "quarantine",
        "log_dir",
        "spec",
        "model",
    ):
        ap.add_argument("--" + k.replace("_", "-"), required=True)
    ap.add_argument("--workers", type=int, required=True)
    ap.add_argument("--max-round", type=int, required=True)
    ap.add_argument("--md-max", type=int, required=True)
    ap.add_argument("--schema-version", type=int, required=True)
    a = ap.parse_args()

    key = open(a.key_file, encoding="utf-8").read().strip()
    assert key.startswith("crsr_"), "%s 内容不是 Cursor API key" % a.key_file
    # bridge 子进程继承本环境, 用 CURSOR_API_KEY 鉴权 (账户级 models.list/agents.list 与云端 agent RPC 都走它;
    # launch_bridge 默认开 allow_api_key_env_fallback, 故无需每次调用再传 api_key)
    os.environ["CURSOR_API_KEY"] = key
    spec = open(a.spec, encoding="utf-8").read()
    examples = load_examples(a.out)
    prompt_hash = hashlib.sha256(
        (INSTRUCTION + FOLLOWUP + spec + examples).encode()
    ).hexdigest()
    missing = [
        l.split("\t")
        for l in open(a.missing, encoding="utf-8").read().splitlines()
        if l
    ]
    os.makedirs(a.log_dir, exist_ok=True)
    cleaned = clean_logs(a, missing)
    prefix = os.path.join(
        a.log_dir, "prefix-%s.md" % prompt_hash[:12]
    )  # 静态前缀只存一份, 各篇 round-1.prompt.md 引用它
    if not os.path.exists(prefix):
        Loop.dump(
            prefix,
            "# INSTRUCTION 模板\n%s\n# FOLLOWUP 模板\n%s\n# tag.md\n%s\n# 示例\n%s"
            % (INSTRUCTION, FOLLOWUP, spec, examples),
        )

    # 云端 agent 也得先起本地 bridge (cursor-sdk-bridge, 随 wheel 自带): 它是本地中介, 替我们把 RPC 转发到云端.
    # 按文档显式 launch_bridge (无全局异步默认 client), workspace 给项目根 (与同步默认 client 用 cwd 同义)
    async with await AsyncClient.launch_bridge(workspace=a.root) as client:
        ids = {m.id for m in await AsyncCursor.models.list(client=client)}
        assert a.model in ids, "TAG_AGENT_MODEL=%s 不在 models.list() 里: %s" % (
            a.model,
            sorted(ids),
        )
        leaked = await archive_leaked(client)

        loop = Loop(a, client, spec, examples, prompt_hash)
        loop.total = len(missing)
        print(
            "[agent] %d 篇, model=%s, workers=%d, prompt_sha256=%s, 清理旧记录 %d 篇, 归档上次泄漏 agent %d 个"
            % (len(missing), a.model, a.workers, prompt_hash[:12], cleaned, leaked),
            file=sys.stderr,
            flush=True,
        )

        # 一篇一个任务, 篇内串行到底 (建 agent → 跟 run → 校验 → 回喂 … → commit/quarantine), 做完才取下一篇.
        # 服务端的毛病只坏那一篇, 接着往下派; 自己的 bug 立刻停止派发新篇 (在飞的跑完自己那篇),
        # 两种情况最后都整体非 0 退出 (docpipe 断言接住)
        todo = asyncio.Queue()
        for item in missing:
            todo.put_nowait(item)
        stop = asyncio.Event()

        async def worker():
            while not stop.is_set():
                try:
                    folder, stem, date = todo.get_nowait()
                except asyncio.QueueEmpty:
                    return
                try:
                    await loop.one(folder, stem, date)
                except CursorAgentError:
                    # 服务端偶发故障只坏这一篇: 已按 sdk_error 记完账 (log 也打了行), 下次 pass 当缺失重来.
                    # 一篇的毛病不该赔上整批 —— 1121 篇跑一趟十来个小时, 为第 4 篇中止太贵了.
                    if loop.streak < FAIL_STREAK:
                        continue
                    stop.set()
                    print(
                        "[agent] 连续 %d 篇栽在服务端故障, 停止派发新篇 (在飞的跑完自己那篇再收尾)"
                        % loop.streak,
                        file=sys.stderr,
                        flush=True,
                    )
                    raise
                except BaseException as e:
                    if (
                        not stop.is_set()
                    ):  # 只有第一个出事的报, 别的任务做完手上这篇就收工
                        stop.set()
                        print(
                            "[agent] %s 出错, 停止派发新篇 (在飞的跑完自己那篇再收尾): %r"
                            % (stem, e),
                            file=sys.stderr,
                            flush=True,
                        )
                    raise

        # Ctrl+C 只停派发, 不打断在飞的篇: 默认的 KeyboardInterrupt 会连 Loop.one 的 finally 一起取消,
        # 于是 get_usage/archive 没跑成 —— agent 留在云端占着套餐的并发坑, meta.json 也缺 outcome (实测如此).
        # 这里改成收到信号就置 stop, 在飞的几篇跑完当前这轮正常收尾 (最多两三分钟).
        # 真等不及就再按一次: docpipe (proc.cpp) 第二次会把整个子进程组 SIGKILL 掉.
        def on_sigint():
            if not stop.is_set():
                stop.set()
                print(
                    "[agent] 收到中断: 不再派发新篇, 在飞的篇跑完当前这轮就收尾 (再按一次 Ctrl+C 立即杀掉)",
                    file=sys.stderr,
                    flush=True,
                )

        asyncio.get_running_loop().add_signal_handler(signal.SIGINT, on_sigint)

        # return_exceptions: 先等所有在飞的篇收尾 (归档 agent、写完记录), 再把第一个异常抛出去
        done = await asyncio.gather(
            *[worker() for _ in range(a.workers)], return_exceptions=True
        )
        print(loop.summary(), file=sys.stderr, flush=True)
        for r in done:
            if isinstance(r, BaseException):
                raise r


if __name__ == "__main__":
    asyncio.run(main())
