#!/usr/bin/env python3
"""thshard.py -- split the tools-health-full propagate dry-run into shards that fit a CI job (container, stdlib).

  <keys> | thshard.py count                 -> number of propagate shards n (shards 1..n; shard 0 is the other rungs)
  <keys> | thshard.py keys K                -> shard K's keys, one per line, in stdin order
  <keys> | thshard.py check                 -> per shard `SHARD k keys n first..last est Ns`, then
                                               `SHARDS CHECK OK <n> shards` rc 0, else `SHARDS CHECK FAIL <why>` rc 1
  thshard.py --self-test                    -> planted shard lists (gap, overlap, over budget) must fail
  [--registry config/dedup_registry.txt]

<keys> is $(PROPAGATE_KEYS_CMD) (mk/tools-health.mk): sorted registry keys. Cost model (refit 3.0 T6 on the timed
shard 1 after T4's red-R5 bisect, `.run/3.0/logs/t6-shard1.log`: 387 keys, wall 1662 s vs 7644 s estimated by the
2.7 T4 constants): per (key, prog), prog = the col2 and col4 program prefixes of the key's rows (NF >= 5, col6 !=
family). Each rate is the measured rate +20%, rounded up. SLUS_013.95: 20 s per unit (its 101-unit group, 19
re-isolated, took 1622 s = 16.1 s/unit). Other programs: 17 s per unit, 36 s when the key has a refused row there
(least-squares over shard 1's 48 rock groups, 374 units: 14.1 s grouped, 29.5 s isolated). Shard est = 300 +
max(max_P chain_P, sum_P chain_P / 8) (8 workers; one program's group runs serially in one worker). Shards are
greedy contiguous slices of the stdin order, closed before a key would push est over SPLIT_AT (15% headroom under
BUDGET) or the SLUS units over SLUS_MAX: per-unit cost grows with group size (cookbook C0414), so the SLUS rate is
never extrapolated past the group size it was measured on.
"""
import sys

BUDGET = 9000  # s per shard
BASE = 300  # s, fixed cost per shard (corpus, census, worker trees)
SPLIT_AT = 7650  # s, greedy split threshold: 15% headroom under BUDGET
UNIT = 17  # s per (key, prog), grouped, non-SLUS; was 20 (2.7 T4 fit 16.4 +20%)
UNIT_REFUSED = 36  # s per (key, prog) with a refused row, non-SLUS; was 28 (2.7 T4 fit 22.6 +20%)
UNIT_SLUS = 20  # s per (key, SLUS_013.95) unit, grouped or isolated; was 72 (pre-bisect, >= 52 s measured)
SLUS_MAX = 101  # SLUS units per shard at most: the calibrated group size (3.0 T6 shard 1)
WORKERS = 8  # container nproc
SHARD0_EST = 1474  # s, shard 0 (every other rung), measured 2.7 T4 (t4-shard0); was 6200 placeholder


def prog_of(ref):
    return ref.split(":", 1)[0]


def rate(key, prog, refused):
    if prog == "SLUS_013.95":
        return UNIT_SLUS
    return UNIT_REFUSED if (key, prog) in refused else UNIT


def load_weights(lines):
    """key -> {prog: seconds} from registry lines."""
    progs, refused = {}, set()
    for line in lines:
        if line.startswith("#"):
            continue
        f = line.split()
        if len(f) < 5 or (len(f) >= 6 and f[5] == "family"):
            continue
        key = f[0]
        ps = progs.setdefault(key, set())
        ps.add(prog_of(f[1]))
        ps.add(prog_of(f[3]))
        if f[4] == "refused":
            refused.add((key, prog_of(f[3])))
    return {k: {p: rate(k, p, refused) for p in sorted(ps)} for k, ps in progs.items()}


def estimate(keys, weights):
    chain = {}
    for k in keys:
        for p, s in weights.get(k, {}).items():
            chain[p] = chain.get(p, 0) + s
    if not chain:
        return BASE
    return BASE + max(max(chain.values()), sum(chain.values()) / WORKERS)


def slus_units(keys, weights):
    return sum(1 for k in keys if "SLUS_013.95" in weights.get(k, {}))


def split(keys, weights):
    shards, cur = [], []
    for k in keys:
        if cur and (estimate(cur + [k], weights) > SPLIT_AT or slus_units(cur + [k], weights) > SLUS_MAX):
            shards.append(cur)
            cur = []
        cur.append(k)
    if cur:
        shards.append(cur)
    return shards


def check(keys, shards, weights):
    """Return (lines, failure or None)."""
    out = []
    flat = [k for s in shards for k in s]
    if len(set(flat)) != len(flat):
        return out, "overlap: a key is in more than one shard"
    if flat != keys:
        return out, "shards do not cover the key list in order (gap or reorder)"
    for i, s in enumerate(shards, 1):
        est = estimate(s, weights)
        out.append("SHARD %d keys %d %s..%s est %ds" % (i, len(s), s[0][:12], s[-1][:12], est))
        if est > BUDGET:
            return out, "shard %d est %ds over budget %ds" % (i, est, BUDGET)
        if not s:
            return out, "shard %d empty" % i
    out.append("SHARD 0 est %ds (measured)" % SHARD0_EST)
    if SHARD0_EST > BUDGET:
        return out, "shard 0 est %ds over budget %ds" % (SHARD0_EST, BUDGET)
    return out, None


def self_test():
    w = {k: {"SLUS_013.95": UNIT} for k in "abcdef"}
    w["f"] = {"SLUS_013.95": BUDGET}
    keys = list("abcde")
    good = [["a", "b"], ["c", "d", "e"]]
    planted = {
        "gap": [["a", "b"], ["d", "e"]],
        "overlap": [["a", "b", "c"], ["c", "d", "e"]],
        "over-budget": [["a", "b"], ["c", "d", "e", "f"]],
    }
    ok = check(keys, good, w)[1] is None
    lw = load_weights(["# c", "k S:1 s S:1 gated", "k S:1 s T:2 refused", "k S:1 s U:3 gated family"])
    ok &= lw == {"k": {"S": UNIT, "T": UNIT_REFUSED}}
    ok &= split(keys, w) == [keys]
    cap = [str(i) for i in range(SLUS_MAX + 1)]  # cheap SLUS keys: the SLUS_MAX cap alone must close a shard
    capped = split(cap, {k: {"SLUS_013.95": 1} for k in cap})
    print("thshard self-test slus-cap: %s" % ("split" if len(capped) == 2 else "NOT SPLIT"))
    ok &= len(capped) == 2
    for name, sh in planted.items():
        ks = keys + ["f"] if name == "over-budget" else keys
        failed = check(ks, sh, w)[1] is not None
        print("thshard self-test %s: %s" % (name, "refused" if failed else "ACCEPTED"))
        ok &= failed
    print("THSHARD SELF-TEST %s" % ("OK" if ok else "FAIL"))
    return 0 if ok else 1


def main(argv):
    registry = "config/dedup_registry.txt"
    if "--registry" in argv:
        i = argv.index("--registry")
        registry = argv[i + 1]
        argv = argv[:i] + argv[i + 2 :]
    if argv == ["--self-test"]:
        return self_test()
    if not argv or argv[0] not in ("count", "keys", "check") or (argv[0] == "keys") != (len(argv) == 2):
        print(__doc__, file=sys.stderr)
        return 2
    keys = [line.strip() for line in sys.stdin if line.strip()]
    with open(registry) as fh:
        weights = load_weights(fh)
    shards = split(keys, weights)
    if argv[0] == "count":
        print(len(shards))
        return 0
    if argv[0] == "keys":
        try:
            k = int(argv[1])
        except ValueError:
            k = 0
        if not 1 <= k <= len(shards):
            print("thshard: shard %s out of range 1..%d" % (argv[1], len(shards)), file=sys.stderr)
            return 2
        sys.stdout.write("".join(x + "\n" for x in shards[k - 1]))
        return 0
    lines, why = check(keys, shards, weights)
    for line in lines:
        print(line)
    if why:
        print("SHARDS CHECK FAIL %s" % why)
        return 1
    print("SHARDS CHECK OK %d shards" % len(shards))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
