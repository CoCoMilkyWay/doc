#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""stage3 阶段一: 用智谱官方 Python SDK (zai-sdk, GLM 对话补全接口) 给缺失的研报补标签 (设计见同目录 agent loop.md).

由 docpipe tag 调起 (tag.cpp::fill_missing), 全部参数来自 config.hpp, 这里不另存配置.
依赖 zai-sdk (装法见 tag/env.cpp 的 T2), 环境由 check_tag_env 备好 (PYTHONNOUSERSITE / PYTHONPATH).
接口文档: https://docs.bigmodel.cn/cn/api/introduction (对话补全 / 错误码 / 速率限制 / 上下文缓存).

一篇 = 一段多轮对话 (messages: system 静态前缀 + user 本篇正文 + assistant 回复 + user 回喂 ...),
一轮 = 一次 chat.completions.create(stream=True, response_format=json_object): 流里的 reasoning_content 边收边落 round-N.thinking.md,
content 拼成 round-N.reply.md (JSON 模式下整段 content 就是一个 json 对象, 平台保证可解析; 见 docs.bigmodel.cn/cn/guide/capabilities/struct-output),
写 staging 交 `docpipe ROOT tag --one` 校验; 有违规就把违规行作为下一条 user 消息追加到同一段对话再问一轮
(上一版回复也在上下文里), 通过则 rename 进 TAG_REPORT_DIR, 用完轮数进 quarantine.

静态前缀 (指令 + tag.md + 示例, ~50KB) 放 system 消息且逐字节一致, 吃平台的隐式上下文缓存 (命中数见 usage.prompt_tokens_details.cached_tokens).
zai-sdk 只有同步客户端 (没有 Async*), 阻塞的一轮用 asyncio.to_thread 丢进线程, 编排仍是 asyncio (每篇一个任务, 篇内串行).
SDK 自带对 408/409/429/5xx 的 3 次退避重试 (0.5s~8s); 这之上只把 429 限速/过载 (业务码 1302/1305) 当背压再等, 其余不再兜底.
服务端/网络的毛病 (zai.core.ZaiError, httpx.HTTPError) 只坏它那一篇, 记成 sdk_error 接着跑下一篇, 连着坏 FAIL_STREAK 篇才停;
鉴权 401 / 参数 400 (模型不存在、prompt 超长…) 与自己的 bug (断言失败等) 一律抛出 —— 越早失败越便宜, 由 docpipe 的断言接住.
"""
import argparse, asyncio, hashlib, json, os, re, shutil, signal, sys, time

import httpx  # pyright: ignore[reportMissingImports]
from zai import ZhipuAiClient  # pyright: ignore[reportMissingImports]
from zai.core import (  # pyright: ignore[reportMissingImports]
    APIAuthenticationError,
    APIReachLimitError,
    APIRequestFailedError,
    ZaiError,
)

FAIL_STREAK = (
    10  # 连续这么多篇栽在服务端故障就停: 偶发只坏一篇, 连着坏就是系统性的, 别烧着钱空转
)
TALLY_EVERY = 25  # 每这么多篇打一行累计汇总 (结局分布 / token / ETA)
CAP_WAIT_SEC = 30  # 撞到账户并发/速率上限或平台过载: 这是背压不是错误, 等别的篇收尾再试
CAP_WAIT_MAX = 20  # 最多等这么多次 (10 分钟) 仍撞上限 => 抛出 (说明 TAG_AGENT_WORKERS 开得比账户并发权益大得多)
CAP_CODES = (
    "1302",
    "1305",
)  # 429 里只有这两个业务码是背压 (速率限制 / 访问量过大); 1113 欠费、13xx 套餐额度到顶都不是等得来的
SENSITIVE_CODE = "1301"  # 400 里唯一算 "这一篇正文的事" 的码 (内容安全拦截), 其余 400 都是我们的参数问题

# ---------- prompt ----------
# 分成 system (静态, 全库逐字节相同 => 上下文缓存命中) 和 user (本篇: 固定值 + 正文) 两条消息.
# 缓存按前缀匹配, 所以带 stem/hash 的几行必须放到 user 里, system 里一个字都不能随篇变.

SYSTEM = """你是量化研报标注员. 任务: 为用户消息里给出的研报写一份标签 json, 严格遵守随后给出的 schema 说明 (tag.md). 接口已开 JSON 模式: 整个回复就是那一个 json 对象, 不要代码块围栏, 不要任何解释.

硬性要求:
- "id"、"schema_version"、"gen" 三个字段的字面值在用户消息开头给出, 原样照抄.
- 所有 evidence 与 Factor.name 必须逐字抄自研报正文 (不改标点、不合并行、不缩写、不翻译); Factor.stats 里的每个数字必须是正文里出现的数字 (原文百分数写成小数, 如 16.5% -> 0.165; 不做任何换算), 正文没给的位置填 null.
- 枚举值只能用 tag.md §1/§2 列出的 code, 且每个字段只认它自己那张词表 (如 Factor.family 只能用 FactorFamily 的 code, 不能填 Approach 的).
- 只写研报实际涉及的阶段; 数字只在 L1 的 Factor.stats, 策略/组合的收益·超额·回撤只进 findings; findings 至少一条, 每条都要有 evidence.
- 每个 Factor 都要有 data_period (构造它用的原始数据周期)、horizon (它预测的收益期限) 和 formula (LaTeX 表达式, 无闭式的写 \\text{{...}} 描述).
- 流派 (approach) 选范式级的类别, 不要按具体实现名硬套; 例行的 IC/分组检验不算 L2, 高频/日内预测信号归 L1_market.
- 研报正文可能被截断 (见标记), 只根据看到的内容标注, 不要臆测.
- 键序、数字写法 (尾零/指数)、列表顺序都不用管, 校验器会自动规范化.

出稿前逐条自查 —— 下面五处是实测最常被校验器打回的, 每错一条就要多花一整轮:
1. V1 每个枚举字段只认它自己那张词表: primary 和 pipe 的键填 PipeStage (L0_data…L8_timing), module 填 Module (L8_rotation 是 Module 不是阶段), approach 填 Approach.
2. S1 每个出现的阶段, tag.md §2 给它列的键一个不少, 没内容的列表写 [] (L3_alpha 的 baseline 最常漏).
3. G1 每条 evidence 是正文里连续的一整句, 去掉空白与 markdown 符号后仍有 20 个以上码点; 括号及括号里的内容 (中英对照如 "（Specific Return）")、脚注角标、单位、引号一个都不能省 —— 实测打回最多的就是漏抄了括号里的英文. 写完回到原文逐字核对一遍.
4. S2 Factor.stats 恰好 4 项, 位序固定 [ic, rank_ic, icir, return_ls], 不确定的填 null 而不是猜.
5. G4 findings[i].text 用它 evidence 里的原词原句压缩而成, 不要换一套说法.

## schema 说明 (tag.md, 原文)
{spec}

## 示例 (已通过校验)
{examples}
"""

USER = """本篇固定值: "id" 必须是 "{stem}"; "schema_version" 必须是 {ver}; "gen" 必须是 {{"model": "{model}", "prompt_sha256": "{hash}"}}.

## 研报正文 ({stem} 的 report.md{truncated})
<<<REPORT_BEGIN>>>
{md}
<<<REPORT_END>>>
"""

FOLLOWUP = """校验器对你上一版 json 报出以下违规 (规则编号见 tag.md §3, 每行一条):
{viol}
请修正后重新输出完整的 json 对象 (其余要求不变; 不要只输出差异, 不要解释)."""

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


def hms(sec):
    return "%d:%02d:%02d" % (sec // 3600, sec // 60 % 60, sec % 60)


# ---------- GLM 对话补全 ----------


def api_code(err):
    """APIStatusError 响应体里的业务错误码 (HTTP 状态码之内那层, 见 docs.bigmodel.cn/cn/api/api-code), 形如 {"error": {"code": "1302", ...}}."""
    body = err.response.json()
    assert isinstance(body, dict) and "error" in body, (
        "错误响应体不是 {error: {code, message}}: %r" % body
    )
    return str(body["error"]["code"])


def server_fault(e):
    """异常分类: True = 服务端/网络的毛病, 只坏这一篇 (sdk_error, 下次 pass 当缺失重来); False = 我们自己的问题, 整批立停.
    鉴权 401 与参数 400 (1211 模型不存在 / 1261 prompt 超长 / 1214 参数非法 …) 是后者; 400 里只有 1301 内容安全拦截算这一篇正文的事.
    """
    if isinstance(e, APIAuthenticationError):
        return False
    if isinstance(e, APIRequestFailedError):
        return api_code(e) == SENSITIVE_CODE
    return isinstance(e, (ZaiError, httpx.HTTPError))


def complete(client, a, messages, request_id, think_path):
    """一轮对话补全 (同步, 由 asyncio.to_thread 跑在线程里). 流式: reasoning_content 边收边写 think_path, content 拼起来返回.
    返回 (content, finish_reason, usage, id). 429 限速/过载当背压等待 —— SDK 自己的 3 次退避重试用完后才会抛到这里.

    stream=True 是为了不吃 300s 读超时: 开思考且 reasoning_effort 高时一篇想几分钟很正常 (实测首轮 1~1.3 万 reasoning tokens), 非流式会整段静默.
    response_format=json_object 是平台的 JSON 模式 (GLM-5.2 支持), content 保证是一个可解析的 json 对象 —— 少一类 F3 "缺逗号" 的回喂轮.
    流里的错误不走 HTTP 状态码, 而是 finish_reason (sensitive / network_error / length / model_context_window_exceeded), 由调用方按 run_* 收场.
    """
    cap_wait = 0
    while True:
        try:
            stream = client.chat.completions.create(
                model=a.model,
                messages=messages,
                stream=True,
                response_format={"type": "json_object"},
                # thinking.type 默认就是 enabled (GLM-5.3 系列强制开, GLM-5.2 由模型自判), 这里显式写死不留歧义;
                # 思考强度由 reasoning_effort 定, 各型号可取档位见 config.hpp TAG_AGENT_REASONING_EFFORT
                thinking={"type": "enabled"},
                reasoning_effort=a.reasoning_effort,
                request_id=request_id,
            )
            break
        except APIReachLimitError as err:
            if api_code(err) not in CAP_CODES or cap_wait >= CAP_WAIT_MAX:
                raise
            cap_wait += 1
            print(
                "[agent] %s 撞限速 (%s), %ds 后再试 (%d/%d)"
                % (request_id, api_code(err), CAP_WAIT_SEC, cap_wait, CAP_WAIT_MAX),
                file=sys.stderr,
                flush=True,
            )
            time.sleep(CAP_WAIT_SEC)
    parts, finish, usage, rid = [], None, None, None
    with open(think_path, "w", encoding="utf-8") as tf:
        for chunk in stream:
            rid = chunk.id or rid
            if chunk.usage is not None:  # 最后一个 chunk 带整轮用量
                usage = chunk.usage
            for ch in chunk.choices:
                if ch.delta.reasoning_content:
                    tf.write(ch.delta.reasoning_content)
                if ch.delta.content:
                    parts.append(ch.delta.content)
                if ch.finish_reason:
                    finish = ch.finish_reason
    assert finish is not None, "%s: 流到 [DONE] 却没有 finish_reason" % request_id
    if usage is None:
        # 流完成了 (有 finish_reason) 但服务端没在末 chunk 附 usage —— 服务端偶发, 当 sdk_error 只坏这一篇, 不整批停
        raise ZaiError("%s: 流到 [DONE] 却没有 usage" % request_id)
    return "".join(parts), finish, usage, rid


# ---------- 单篇 ----------


class Loop:
    def __init__(self, a, client, system, prompt_hash):
        self.a, self.client = a, client
        self.system, self.hash = (
            system,
            prompt_hash,
        )  # system 消息全库同一份 (静态前缀, 见 SYSTEM)
        self.lock = asyncio.Lock()
        self.done = 0
        self.total = 0
        self.tally = {}  # outcome -> 篇数
        self.streak = 0  # 连续栽在服务端故障的篇数, 见 FAIL_STREAK
        self.tok = {
            "prompt": 0,
            "cached": 0,
            "completion": 0,
        }  # 累计 token
        self.cost = 0.0  # 累计费用 (元), 本地按 config.hpp 单价估算 (平台不回传金额)
        self.t_start = time.time()

    def price(self, usage):
        """一轮的费用 (元): 未命中缓存的输入 + 缓存命中 + 输出 (含 reasoning), 单价 元/百万 tokens. 所有型号同一公式."""
        cached = (
            usage.prompt_tokens_details.cached_tokens
            if usage.prompt_tokens_details
            else 0
        )
        a = self.a
        return (
            (usage.prompt_tokens - cached) * a.price_in
            + cached * a.price_hit
            + usage.completion_tokens * a.price_out
        ) / 1e6

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
            u = rec.get("usage") or {}
            for k in self.tok:
                self.tok[k] += u.get(k, 0)
            self.cost += rec.get("cost_yuan", 0.0)
            self.tally[rec["outcome"]] = self.tally.get(rec["outcome"], 0) + 1
            if rec["outcome"] in ("commit", "quarantine"):  # 模型答错不算故障
                self.streak = 0
            elif rec["outcome"].startswith(("run_", "sdk_")):
                self.streak += 1
            print(
                "[agent] %d/%d %-10s r%d %6.1fs %4dk↑(%3dk缓存) %3dk↓ %5.2f元 %s"
                % (
                    self.done,
                    self.total,
                    rec["outcome"],
                    rec.get("round", 0),
                    rec.get("seconds", 0.0),
                    u.get("prompt", 0) // 1000,
                    u.get("cached", 0) // 1000,
                    u.get("completion", 0) // 1000,
                    rec.get("cost_yuan", 0.0),
                    rec["stem"],
                ),
                file=sys.stderr,
                flush=True,
            )
            if self.done % TALLY_EVERY == 0:
                print(self.summary(), file=sys.stderr, flush=True)

    def summary(self):
        """一行看清这批跑成什么样: 结局分布决定下一步改 prompt 还是换模型, 缓存命中率决定前缀有没有被弄乱, 费用/ETA 决定要不要换模型或调 workers."""
        el = time.time() - self.t_start
        return (
            "[agent] ---- %d/%d (%.0f%%)  %s | 输入 %.1fM (缓存命中 %.0f%%) 输出 %.1fM tokens | 费用 %.2f元 (均 %.3f元/篇, 预计全部 %.0f元) | 已用 %s, 余 %s"
            % (
                self.done,
                self.total,
                100.0 * self.done / max(self.total, 1),
                " ".join("%s %d" % kv for kv in sorted(self.tally.items())),
                self.tok["prompt"] / 1e6,
                100.0 * self.tok["cached"] / max(self.tok["prompt"], 1),
                self.tok["completion"] / 1e6,
                self.cost,
                self.cost / max(self.done, 1),
                self.cost / max(self.done, 1) * self.total,
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
        prompt = USER.format(md=md, **fill)
        # system 前缀 (prefix-{hash}.md) 和正文 (report.md) 都另有出处, 记录里只留引用, 避免每篇复制 100KB
        prompt_log = USER.format(
            md="<<%s, %d 字节%s>>" % (md_path, md_bytes, truncated), **fill
        )
        rec.update(md_bytes=md_bytes, truncated=bool(truncated))
        # request_id 是和服务端对账的钥匙 (平台按它记日志; 6~64 字符, stem 是长中文名故取其 sha1 前 16 位)
        rec["request_id"] = "tag-" + hashlib.sha1(stem.encode()).hexdigest()[:16]

        os.makedirs(ldir, exist_ok=True)
        self.dump(
            os.path.join(ldir, "meta.json"),
            json.dumps(rec, ensure_ascii=False, indent=2),
        )
        messages = [
            {"role": "system", "content": self.system},
            {"role": "user", "content": prompt},
        ]
        try:
            await self.rounds(
                rec, messages, prompt_log, ldir, stg_path, out_path, q_path
            )
        except BaseException as e:
            rec.update(
                outcome="sdk_error" if server_fault(e) else "error", error=repr(e)
            )
            raise
        finally:
            rec["seconds"] = round(time.time() - rec["t0"], 1)
            self.dump(
                os.path.join(ldir, "meta.json"),
                json.dumps(rec, ensure_ascii=False, indent=2),
            )
            await self.log(rec)

    async def send_round(self, rec, messages, ldir, rnd):
        """发一轮 (阻塞的流式调用丢进线程), 返回 (content, finish_reason, 本轮文件名前缀). 思考过程已落 round-N.thinking.md."""
        rp = os.path.join(ldir, "round-%d." % rnd)
        req_id = "%s-r%d" % (rec["request_id"], rnd)
        content, finish, usage, rid = await asyncio.to_thread(
            complete, self.client, self.a, messages, req_id, rp + "thinking.md"
        )
        u = rec.setdefault(
            "usage", {"prompt": 0, "cached": 0, "completion": 0}
        )  # 整篇累计, 供 log() 汇总
        u["prompt"] += usage.prompt_tokens
        u["cached"] += (
            usage.prompt_tokens_details.cached_tokens
            if usage.prompt_tokens_details
            else 0
        )
        u["completion"] += usage.completion_tokens
        cost = self.price(usage)
        rec["cost_yuan"] = round(rec.get("cost_yuan", 0.0) + cost, 4)  # 整篇累计 (元)
        # 每轮的身份存档: 服务端按 id/request_id 记账, 出问题时要能把本地这一轮和服务端那条对上
        rec.setdefault("runs", []).append(
            {
                "round": rnd,
                "id": rid,
                "request_id": req_id,
                "finish_reason": finish,
                "usage": usage.model_dump(),
                "cost_yuan": round(cost, 4),
            }
        )
        return content, finish, rp

    async def rounds(self, rec, messages, prompt_log, ldir, stg_path, out_path, q_path):
        a = self.a
        viol_history = []
        rnd = 0
        while True:
            rnd += 1
            self.dump(
                os.path.join(ldir, "round-%d.prompt.md" % rnd),
                prompt_log if rnd == 1 else messages[-1]["content"],
            )
            reply, finish, rp = await self.send_round(rec, messages, ldir, rnd)
            self.dump(rp + "reply.md", reply)
            if finish != "stop":
                # length / sensitive / network_error / model_context_window_exceeded: 这一轮没成, 不落文件, 该篇仍 "缺失" 下次重来
                rec["outcome"] = "run_" + finish
                rec.update(round=rnd, viol_history=viol_history)
                return
            messages.append({"role": "assistant", "content": reply})
            js = extract_json(reply)
            if js is None:
                viol = ["违规:F3 回复不是一个 json 对象"]
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
            messages.append(
                {"role": "user", "content": FOLLOWUP.format(viol="\n".join(viol))}
            )
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
        "reasoning_effort",
    ):
        ap.add_argument("--" + k.replace("_", "-"), required=True)
    for k in ("price_in", "price_out", "price_hit"):  # 元/百万 tokens, 见 config.hpp TAG_AGENT_PRICES
        ap.add_argument("--" + k.replace("_", "-"), type=float, required=True)
    ap.add_argument("--workers", type=int, required=True)
    ap.add_argument("--max-round", type=int, required=True)
    ap.add_argument("--md-max", type=int, required=True)
    ap.add_argument("--schema-version", type=int, required=True)
    a = ap.parse_args()

    key = open(a.key_file, encoding="utf-8").read().strip()
    # 智谱 API key 形如 {id}.{secret} (SDK 的 _jwt_token 也只按这一个点拆), 两段都是字母数字
    assert re.fullmatch(r"[0-9A-Za-z]+\.[0-9A-Za-z]+", key), (
        "%s 内容不像智谱 API key ({id}.{secret})" % a.key_file
    )
    spec = open(a.spec, encoding="utf-8").read()
    examples = load_examples(a.out)
    system = SYSTEM.format(spec=spec, examples=examples)
    prompt_hash = hashlib.sha256((system + USER + FOLLOWUP).encode()).hexdigest()
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
            "# system 消息 (SYSTEM 模板 + tag.md + 示例, 逐字节即发出去的内容)\n%s\n# USER 模板\n%s\n# FOLLOWUP 模板\n%s"
            % (system, USER, FOLLOWUP),
        )

    # 同步客户端, httpx.Client 线程安全, 各 worker 线程共用一个 (连接池默认 50). 默认 base_url 即 open.bigmodel.cn/api/paas/v4,
    # 默认超时 connect 8s / read 300s, 默认对 408/409/429/5xx 重试 3 次. 模型 id 不做预检 (平台没有 models.list 接口):
    # 写错了首篇就 400/1211 => server_fault 判 False => 整批立停
    client = ZhipuAiClient(api_key=key)
    loop = Loop(a, client, system, prompt_hash)
    loop.total = len(missing)
    print(
        "[agent] %d 篇, model=%s (reasoning_effort=%s, 单价 输入%g/输出%g/缓存命中%g 元/M), workers=%d, prompt_sha256=%s, 清理旧记录 %d 篇"
        % (
            len(missing),
            a.model,
            a.reasoning_effort,
            a.price_in,
            a.price_out,
            a.price_hit,
            a.workers,
            prompt_hash[:12],
            cleaned,
        ),
        file=sys.stderr,
        flush=True,
    )

    # 一篇一个任务, 篇内串行到底 (首轮 → 校验 → 回喂 … → commit/quarantine), 做完才取下一篇.
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
            except BaseException as e:
                if server_fault(e):
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
                if not stop.is_set():  # 只有第一个出事的报, 别的任务做完手上这篇就收工
                    stop.set()
                    print(
                        "[agent] %s 出错, 停止派发新篇 (在飞的跑完自己那篇再收尾): %r"
                        % (stem, e),
                        file=sys.stderr,
                        flush=True,
                    )
                raise

    # Ctrl+C 只停派发, 不打断在飞的篇: 默认的 KeyboardInterrupt 会连 Loop.one 的 finally 一起取消, meta.json 就缺 outcome;
    # 而且阻塞在线程里的那一轮 (asyncio.to_thread) 本来也取消不掉, 还会继续读流到结束.
    # 这里改成收到信号就置 stop, 在飞的几篇跑完当前这轮正常收尾 (最多几分钟).
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

    # return_exceptions: 先等所有在飞的篇收尾 (写完记录), 再把第一个异常抛出去
    done = await asyncio.gather(
        *[worker() for _ in range(a.workers)], return_exceptions=True
    )
    print(loop.summary(), file=sys.stderr, flush=True)
    for r in done:
        if isinstance(r, BaseException):
            raise r


if __name__ == "__main__":
    asyncio.run(main())
