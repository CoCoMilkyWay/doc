#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""stage3 阶段一: 用 Cursor Python SDK 给缺失的研报补标签 (设计见同目录 agent loop.md).

由 docpipe tag 调起 (tag.cpp::fill_missing), 全部参数来自 config.hpp, 这里不另存配置.
依赖 cursor-sdk (装法见 tag/env.cpp 的 T2), 环境由 check_tag_env 备好 (PYTHONNOUSERSITE / PYTHONPATH).

一篇 = 一个云端无仓库 agent (CloudAgentOptions(repos=[]), 仓库 4GB 不值得 clone, report.md 正文随 prompt 发送),
一轮 = agent.send() 的一个 run: 流里每条 SDKMessage 落 events.jsonl, run.wait() 拿终态与最终文本, 从文本里取
```json 写 staging, 交 `docpipe ROOT tag --one` 校验; 有违规就把违规行回喂同一个 agent (对话与上一版都还在) 再问一轮,
通过则 rename 进 TAG_REPORT_DIR, 用完轮数进 quarantine. 收尾 agent.archive() (不归档会一直占套餐的并发坑).

按文档用 SDK: 并发编排用 AsyncClient (同步 API 没有并发约定), 重试只认 CursorAgentError.is_retryable/retry_after,
其余异常一律抛出 —— 越早失败越便宜, 由 docpipe 的断言接住.
"""
import argparse, asyncio, dataclasses, hashlib, json, os, re, sys, time

from cursor_sdk import AsyncClient, AsyncCursor, CloudAgentOptions, CursorAgentError

RETRY = 5  # is_retryable 的错误最多重试几次 (指数退避, 服务端给了 retry_after 就照它等)
CAP_WAIT_SEC = 30  # 撞到套餐的 "同时在跑 agent 数" 上限: 这是背压不是错误, 等别的篇收尾
CAP_WAIT_MAX = 20  # 最多等这么多次 (10 分钟) 仍撞上限 => 抛出 (说明有泄漏的 agent 占着坑)
CAP_MARK = "reached the limit"
META_MARK = {"docpipe": "tag"}  # 打在 agent 上, 供启动时识别并清理上次泄漏的

# ---------- prompt ----------

INSTRUCTION = """你是量化研报标注员. 任务: 为下面这篇研报写一份标签 json, 严格遵守随后给出的 schema 说明 (tag.md). 只输出一个 ```json 代码块, 不要任何解释.

硬性要求:
- "id" 必须是 "{stem}"; "schema_version" 必须是 {ver}; "gen" 必须是 {{"model": "{model}", "prompt_sha256": "{hash}"}}.
- 研报日期 {date} (来自文件名); Metric.period 若给出, 不得晚于该月.
- 所有 evidence 与 Factor.name 必须逐字抄自下面的研报正文 (不改标点、不合并行、不缩写、不翻译); Metric.value 必须是它自己 evidence 里出现的数字 (原文百分数可写成小数, 如 16.5% -> 0.165).
- 枚举值只能用 tag.md §1/§2 列出的 code; 枚举列表按词表顺序、字符串列表按字节序排列; 键按 tag.md §2 的 struct 字段顺序写.
- 只写研报实际涉及的阶段; result 里没有可逐字抄的数字就给空列表; findings 至少一条, 每条都要有 evidence.
- 流派 (approach) 选范式级的类别, 不要按具体实现名硬套; 例行的 IC/分组检验不算 L2, 高频/日内预测信号归 L1_market.
- 研报正文可能被截断 (见标记), 只根据看到的内容标注, 不要臆测.

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
    return "\n".join("```json\n%s\n```" % open(p, encoding="utf-8").read().rstrip("\n") for p in found)


# ---------- SDK 对象 → json ----------
# 工具调用的 args/result 负载 schema 文档明说不稳定, 一律防御性序列化: dataclass 摊平, 其余 repr


def plain(o):
    if dataclasses.is_dataclass(o) and not isinstance(o, type):
        return dataclasses.asdict(o)
    if isinstance(o, (set, frozenset, tuple)):
        return list(o)
    return repr(o)


def jsonable(o):
    return json.loads(json.dumps(o, ensure_ascii=False, default=plain)) if o is not None else None


def event_row(msg, t0):
    """SDKMessage → 一行记录. 信封 (type/call_id/name/status) 是稳定的, 其余字段有则记."""
    if isinstance(msg, dict):
        row = dict(msg)
    else:
        row = {"type": getattr(msg, "type", "?")}
        for k in ("subtype", "status", "message", "text", "call_id", "name", "args", "result", "truncated",
                  "thinking_duration_ms", "usage", "request_id", "model", "tools"):
            v = getattr(msg, k, None)
            if v is not None:
                row[k] = v
    row["t"] = round(time.time() - t0, 1)
    return json.dumps(row, ensure_ascii=False, default=plain)


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
            delay = float(err.retry_after) if (err.retry_after or "").isdigit() else 2**attempt
            print("[agent] %s 可重试错误 (%s), %.0fs 后第 %d 次重试" % (what, err.code or err.status, delay, attempt),
                  file=sys.stderr, flush=True)
            await asyncio.sleep(delay)


# ---------- 单篇 ----------


class Loop:
    def __init__(self, a, client, key, spec, examples, prompt_hash):
        self.a, self.client, self.key = a, client, key
        self.spec, self.examples, self.hash = spec, examples, prompt_hash
        self.lock = asyncio.Lock()
        self.done = 0
        self.total = 0

    async def validate(self, path):
        """本机校验器是唯一判官 (F2-F4 S V K G), python 侧不复制任何规则."""
        p = await asyncio.create_subprocess_exec(
            self.a.docpipe, self.a.root, "tag", "--one", path,
            stdout=asyncio.subprocess.PIPE, stderr=asyncio.subprocess.PIPE,
        )
        out, err = await p.communicate()
        assert p.returncode in (0, 1), "docpipe --one 异常退出 %d: %s" % (p.returncode, err.decode()[-2000:])
        return [l for l in out.decode().splitlines() if l]

    async def log(self, rec):
        async with self.lock:
            with open(os.path.join(self.a.log_dir, "agent.jsonl"), "a", encoding="utf-8") as f:
                f.write(json.dumps(rec, ensure_ascii=False) + "\n")
            self.done += 1
            print("[agent] %d/%d %-10s r%d %s" % (self.done, self.total, rec["outcome"], rec.get("round", 0), rec["stem"]),
                  file=sys.stderr, flush=True)

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
        rec = {"stem": stem, "folder": folder, "model": a.model, "prompt_sha256": self.hash, "t0": time.time()}
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
        fill = dict(stem=stem, ver=a.schema_version, model=a.model, hash=self.hash, date=date, truncated=truncated)
        prompt = INSTRUCTION.format(spec=self.spec, examples=self.examples, md=md, **fill)
        # 首轮 prompt 的静态前缀 (prefix-{hash}.md) 和正文 (report.md) 都另有出处, 记录里只留引用, 避免每篇复制 100KB
        prompt_log = INSTRUCTION.format(spec="<<见 %s/prefix-%s.md>>" % (a.log_dir, self.hash[:12]), examples="<<同上>>",
                                        md="<<%s, %d 字节%s>>" % (md_path, md_bytes, truncated), **fill)
        rec.update(md_bytes=md_bytes, truncated=bool(truncated))

        # create 会校验选项并立即返回句柄 (agent_id 当场可用), 不等 VM; 建不出来就不该留下半篮子记录目录
        agent = await retrying("create " + stem, lambda: self.client.agents.create(
            model=a.model, api_key=self.key, name="tag " + stem,
            cloud=CloudAgentOptions(repos=[], metadata=dict(META_MARK, stem=stem)),
        ))
        rec["agent_id"] = agent.agent_id
        os.makedirs(ldir, exist_ok=True)
        self.dump(os.path.join(ldir, "meta.json"), json.dumps(rec, ensure_ascii=False, indent=2))
        async with agent:
            try:
                await self.rounds(rec, agent, prompt, prompt_log, ldir, stg_path, out_path, q_path)
            except BaseException as e:
                rec.update(outcome="error", error=repr(e))
                raise
            finally:
                billed = await agent.get_usage()
                rec["usage"] = jsonable(billed.usage)
                rec["cost"] = jsonable(billed.cost)
                await agent.archive()  # 不归档会一直占套餐的并发坑
                rec["seconds"] = round(time.time() - rec["t0"], 1)
                self.dump(os.path.join(ldir, "meta.json"), json.dumps(rec, ensure_ascii=False, indent=2))
                await self.log(rec)

    async def rounds(self, rec, agent, prompt, prompt_log, ldir, stg_path, out_path, q_path):
        a = self.a
        viol_history = []
        rnd = 0
        while True:
            rnd += 1
            rp = os.path.join(ldir, "round-%d." % rnd)
            self.dump(rp + "prompt.md", prompt_log if rnd == 1 else prompt)
            run = await retrying("send " + rec["stem"], lambda: agent.send(prompt))
            t0 = time.time()
            with open(rp + "events.jsonl", "w", encoding="utf-8") as ef:
                async for msg in run.messages():  # 流只能消费一次; 剩余事件由 wait() 读完
                    ef.write(event_row(msg, t0) + "\n")
                    ef.flush()
            result = await run.wait()
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
    for k in ("root", "docpipe", "key_file", "missing", "staging", "out", "proc", "md_name", "quarantine", "log_dir",
              "spec", "model"):
        ap.add_argument("--" + k.replace("_", "-"), required=True)
    ap.add_argument("--workers", type=int, required=True)
    ap.add_argument("--max-round", type=int, required=True)
    ap.add_argument("--md-max", type=int, required=True)
    ap.add_argument("--schema-version", type=int, required=True)
    a = ap.parse_args()

    key = open(a.key_file, encoding="utf-8").read().strip()
    assert key.startswith("crsr_"), "%s 内容不是 Cursor API key" % a.key_file
    spec = open(a.spec, encoding="utf-8").read()
    examples = load_examples(a.out)
    prompt_hash = hashlib.sha256((INSTRUCTION + FOLLOWUP + spec + examples).encode()).hexdigest()
    missing = [l.split("\t") for l in open(a.missing, encoding="utf-8").read().splitlines() if l]
    os.makedirs(a.log_dir, exist_ok=True)
    prefix = os.path.join(a.log_dir, "prefix-%s.md" % prompt_hash[:12])  # 静态前缀只存一份, 各篇 round-1.prompt.md 引用它
    if not os.path.exists(prefix):
        Loop.dump(prefix, "# INSTRUCTION 模板\n%s\n# FOLLOWUP 模板\n%s\n# tag.md\n%s\n# 示例\n%s"
                  % (INSTRUCTION, FOLLOWUP, spec, examples))

    # 没有全局异步默认客户端, 按文档显式实例化 (云端代理不需要 bridge; api_key 随 agents.create 传)
    async with AsyncClient() as client:
        ids = {m.id for m in await AsyncCursor.models.list(client=client)}
        assert a.model in ids, "TAG_AGENT_MODEL=%s 不在 models.list() 里: %s" % (a.model, sorted(ids))
        leaked = await archive_leaked(client)

        loop = Loop(a, client, key, spec, examples, prompt_hash)
        loop.total = len(missing)
        print("[agent] %d 篇, model=%s, workers=%d, prompt_sha256=%s, 清理上次泄漏 agent %d 个"
              % (len(missing), a.model, a.workers, prompt_hash[:12], leaked), file=sys.stderr, flush=True)

        # 一篇一个任务, 篇内串行到底 (建 agent → 跟 run → 校验 → 回喂 … → commit/quarantine), 做完才取下一篇.
        # 任一篇抛异常: 立刻停止派发新篇 (在飞的跑完自己那篇), 最后整体非 0 退出 (docpipe 断言接住)
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
                except BaseException:
                    stop.set()  # 别的任务做完手上这篇就收工
                    print("[agent] 中止于 %s" % stem, file=sys.stderr, flush=True)
                    raise

        # return_exceptions: 先等所有在飞的篇收尾 (归档 agent、写完记录), 再把第一个异常抛出去
        for r in await asyncio.gather(*[worker() for _ in range(a.workers)], return_exceptions=True):
            if isinstance(r, BaseException):
                raise r


if __name__ == "__main__":
    asyncio.run(main())
