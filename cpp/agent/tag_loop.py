#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""stage3 阶段一: 用 Cursor Cloud Agents API 给缺失的研报补标签 (设计见 cpp/include/stages/tag/agent loop.md).

由 docpipe tag 调起 (tag.cpp::fill_missing), 全部参数来自 config.hpp, 这里不另存配置. 只用标准库.
每篇一个无仓库 agent: prompt = 指令 + tag.md + 两篇已过校验的示例 + report.md 正文; 回复里的 ```json 落 staging,
用 `docpipe ROOT tag --one <json>` 校验, 违规原样回喂同一 agent (保留对话) 重问; 通过 rename 进 TAG_REPORT_DIR,
用完轮数进 quarantine. 任何 API/环境异常直接抛出 (越早失败越便宜), 由 docpipe 断言接住.
"""
import argparse, base64, hashlib, json, os, re, subprocess, sys, threading, time, urllib.error, urllib.request
from concurrent.futures import ThreadPoolExecutor

API = "https://api.cursor.com"
POLL_SEC = 5          # 轮询 run 状态间隔
RUN_TIMEOUT_SEC = 1800  # 单次 run 上限, 超时 cancel 并按失败处理
HTTP_RETRY = 5        # 429/5xx 重试次数 (指数退避)
TERMINAL = {"FINISHED", "ERROR", "CANCELLED", "EXPIRED"}

# ---------- Cursor API ----------

class Api:
    def __init__(self, key):
        self.auth = "Basic " + base64.b64encode((key + ":").encode()).decode()

    def call(self, method, path, body=None):
        data = json.dumps(body).encode() if body is not None else None
        for attempt in range(HTTP_RETRY + 1):
            req = urllib.request.Request(API + path, data=data, method=method)
            req.add_header("Authorization", self.auth)
            req.add_header("Accept", "application/json")
            if data is not None:
                req.add_header("Content-Type", "application/json")
            try:
                with urllib.request.urlopen(req, timeout=60) as resp:
                    raw = resp.read()
                    return json.loads(raw) if raw else {}
            except urllib.error.HTTPError as e:
                text = e.read().decode(errors="replace")
                if (e.code == 429 or e.code >= 500) and attempt < HTTP_RETRY:
                    time.sleep(2 ** attempt)
                    continue
                raise RuntimeError("%s %s -> HTTP %d: %s" % (method, path, e.code, text[:500]))
            except urllib.error.URLError as e:
                if attempt < HTTP_RETRY:
                    time.sleep(2 ** attempt)
                    continue
                raise
        raise AssertionError("unreachable")

    def models(self):
        return self.call("GET", "/v1/models")["items"]

    def create_agent(self, prompt, model, name):
        r = self.call("POST", "/v1/agents", {"prompt": {"text": prompt}, "model": {"id": model}, "name": name[:100]})
        return r["agent"]["id"], r["run"]["id"]

    def followup(self, agent_id, prompt):
        return self.call("POST", "/v1/agents/%s/runs" % agent_id, {"prompt": {"text": prompt}})["run"]["id"]

    def run(self, agent_id, run_id):
        return self.call("GET", "/v1/agents/%s/runs/%s" % (agent_id, run_id))

    def cancel(self, agent_id, run_id):
        self.call("POST", "/v1/agents/%s/runs/%s/cancel" % (agent_id, run_id))

    def usage(self, agent_id):
        return self.call("GET", "/v1/agents/%s/usage" % agent_id).get("totalUsage", {})

    def archive(self, agent_id):
        self.call("POST", "/v1/agents/%s/archive" % agent_id)

    def wait_run(self, agent_id, run_id):
        t0 = time.time()
        while True:
            r = self.run(agent_id, run_id)
            if r["status"] in TERMINAL:
                return r
            if time.time() - t0 > RUN_TIMEOUT_SEC:
                self.cancel(agent_id, run_id)
                return self.run(agent_id, run_id)
            time.sleep(POLL_SEC)

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

# ---------- 单篇 ----------

class Loop:
    def __init__(self, a, api, spec, examples, prompt_hash):
        self.a, self.api, self.spec, self.examples, self.hash = a, api, spec, examples, prompt_hash
        self.lock = threading.Lock()
        self.done = 0
        self.total = 0

    def validate(self, path):
        p = subprocess.run([self.a.docpipe, self.a.root, "tag", "--one", path], capture_output=True, text=True)
        assert p.returncode in (0, 1), "docpipe --one 异常退出 %d: %s" % (p.returncode, p.stderr[-2000:])
        return [l for l in p.stdout.splitlines() if l]

    def log(self, rec):
        with self.lock:
            with open(self.a.log, "a", encoding="utf-8") as f:
                f.write(json.dumps(rec, ensure_ascii=False) + "\n")
            self.done += 1
            print("[agent] %d/%d %-10s r%d %s" % (self.done, self.total, rec["outcome"], rec.get("round", 0), rec["stem"]),
                  file=sys.stderr, flush=True)

    def one(self, folder, stem, date):
        a = self.a
        sub = "" if folder == "." else folder + "/"
        md_path = os.path.join(a.proc, sub + stem, a.md_name)
        stg_path = os.path.join(a.staging, sub + stem + ".json")
        out_path = os.path.join(a.out, sub + stem + ".json")
        q_path = os.path.join(a.quarantine, sub + stem + ".json")
        rec = {"stem": stem, "folder": folder, "model": a.model, "prompt_sha256": self.hash, "t0": time.time()}
        if os.path.exists(q_path):
            rec["outcome"] = "quarantined_before"
            return self.log(rec)
        if not os.path.exists(md_path):
            rec["outcome"] = "no_md"
            return self.log(rec)

        md = open(md_path, "rb").read()
        truncated = ""
        if len(md) > a.md_max:
            md = md[:a.md_max]
            truncated = ", 只含前 %d 字节, 已截断" % a.md_max
        md = md.decode("utf-8", errors="ignore")
        prompt = INSTRUCTION.format(stem=stem, ver=a.schema_version, model=a.model, hash=self.hash, date=date,
                                    spec=self.spec, examples=self.examples, truncated=truncated, md=md)
        agent_id = None
        viol_history = []
        rnd = 0
        outcome = None
        while True:
            rnd += 1
            if agent_id is None:
                agent_id, run_id = self.api.create_agent(prompt, a.model, "tag " + stem)
                rec["agent_id"] = agent_id
            else:
                run_id = self.api.followup(agent_id, prompt)
            run = self.api.wait_run(agent_id, run_id)
            if run["status"] != "FINISHED":
                outcome = "run_" + run["status"].lower()
                break
            js = extract_json(run.get("result") or "")
            if js is None:
                viol = ["违规:F3 回复中没有 json 代码块"]
            else:
                os.makedirs(os.path.dirname(stg_path), exist_ok=True)
                with open(stg_path, "w", encoding="utf-8") as f:
                    f.write(js + "\n")
                viol = self.validate(stg_path)
            viol_history.append(viol)
            if not viol:
                os.makedirs(os.path.dirname(out_path), exist_ok=True)
                os.replace(stg_path, out_path)
                outcome = "commit"
                break
            if rnd >= a.max_round:
                os.makedirs(os.path.dirname(q_path), exist_ok=True)
                if os.path.exists(stg_path):
                    os.replace(stg_path, q_path)
                with open(q_path[:-5] + ".viol", "w", encoding="utf-8") as f:
                    for k, v in enumerate(viol_history, 1):
                        f.write("# round %d\n%s\n" % (k, "\n".join(v)))
                outcome = "quarantine"
                break
            prompt = FOLLOWUP.format(viol="\n".join(viol))
        rec.update(outcome=outcome, round=rnd, viol_history=viol_history, usage=self.api.usage(agent_id),
                   seconds=round(time.time() - rec["t0"], 1))
        self.api.archive(agent_id)
        self.log(rec)


def main():
    ap = argparse.ArgumentParser()
    for k in ("root", "docpipe", "key_file", "missing", "staging", "out", "proc", "md_name", "quarantine", "log", "spec", "model"):
        ap.add_argument("--" + k.replace("_", "-"), required=True)
    ap.add_argument("--workers", type=int, required=True)
    ap.add_argument("--max-round", type=int, required=True)
    ap.add_argument("--md-max", type=int, required=True)
    ap.add_argument("--schema-version", type=int, required=True)
    a = ap.parse_args()

    key = open(a.key_file, encoding="utf-8").read().strip()
    assert key.startswith("crsr_"), "%s 内容不是 Cursor API key" % a.key_file
    api = Api(key)
    ids = set()
    for m in api.models():
        ids.add(m["id"])
        ids.update(m.get("aliases") or [])
    assert a.model in ids, "TAG_AGENT_MODEL=%s 不在 GET /v1/models 里: %s" % (a.model, sorted(ids))

    spec = open(a.spec, encoding="utf-8").read()
    examples = load_examples(a.out)
    prompt_hash = hashlib.sha256((INSTRUCTION + FOLLOWUP + spec + examples).encode()).hexdigest()
    missing = [l.split("\t") for l in open(a.missing, encoding="utf-8").read().splitlines() if l]

    loop = Loop(a, api, spec, examples, prompt_hash)
    loop.total = len(missing)
    print("[agent] %d 篇, model=%s, workers=%d, prompt_sha256=%s" % (len(missing), a.model, a.workers, prompt_hash[:12]),
          file=sys.stderr, flush=True)
    with ThreadPoolExecutor(max_workers=a.workers) as ex:
        futs = [ex.submit(loop.one, folder, stem, date) for folder, stem, date in missing]
        for f in futs:
            f.result()  # 任一篇抛异常 => 整体失败 (docpipe 断言接住)


if __name__ == "__main__":
    main()
