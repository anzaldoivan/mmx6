#!/usr/bin/env python3
"""thshard.py -- split the tools-health-full propagate dry-run into shards that fit a CI job (container, stdlib).

  <keys> | thshard.py count                 -> number of propagate shards n (shards 1..n; shard 0 is the other rungs)
  <keys> | thshard.py keys K                -> shard K's keys, one per line, in stdin order
  <keys> | thshard.py check                 -> per shard `SHARD k keys n first..last est Ns`, then
                                               `SHARDS CHECK OK <n> shards` rc 0, else `SHARDS CHECK FAIL <why>` rc 1
  thshard.py --self-test                    -> planted shard lists (gap, overlap, over budget) must fail
  [--registry config/us/dedup_registry.txt]

<keys> is $(PROPAGATE_KEYS_CMD) (mk/tools-health.mk): sorted registry keys. Cost model (refit 3.0 T6 on the timed
shard 1 after T4's red-R5 bisect, `.run/3.0/logs/t6-shard1.log`: 387 keys, wall 1662 s vs 7644 s estimated by the
2.7 T4 constants): per (key, prog), prog = the col2 and col4 program prefixes of the key's rows (NF >= 5, col6 !=
family). Each rate is the measured rate +20%, rounded up. main: 20 s per unit (its 101-unit group, 19
re-isolated, took 1622 s = 16.1 s/unit). Other programs: 17 s per unit, 36 s when the key has a refused row there
(least-squares over shard 1's 48 rock groups, 374 units: 14.1 s grouped, 29.5 s isolated). Shard est = 300 +
max(max_P chain_P, sum_P chain_P / 8) (8 workers; one program's group runs serially in one worker). Shards are
greedy contiguous slices of the stdin order, closed before a key would push est over SPLIT_AT (15% headroom under
BUDGET) or the SLUS units over SLUS_MAX: per-unit cost grows with group size (cookbook C0414), so the SLUS rate is
never extrapolated past the group size it was measured on.

Refit 3.2 T11 (budget 50 min per step, developer): the flat SLUS rate hid where the cost is. T1's 11 shards (stamp
4c3539f89463, `.run/3.2/logs/t1-shard<k>.log`) ran 59-3434 s at an equal 2320 s estimate; shard 2 ran 3434 s and
3156 s on rerun (7 R5 rounds, 40 cross-key bisects, cookbook C0422), and key count does not predict cost. So the SLUS
rate is now per key range: SLUS_CAL holds each T1 shard's first key, grouped wall and SLUS units, and a key costs
its range's wall / units (sorted-key bisect, so a new key takes its neighbours' rate). Shard est = 300 + wall for an
unsplit T1 shard (BASE 300 s covers the 1-3 min step overhead measured). SPLIT_AT 2500 keeps ~17% headroom under
the 3000 s budget: 12 shards, max est 2499 s (2550 re-flows into 11 shards packed near the budget).
"""
import bisect
import sys

from paths import CONFIG_V  # the version axis (3.3 T37)

BUDGET = 3000  # s per shard: 50 min per step (3.2 T11); was 9000 (3 h cap)
BASE = 300  # s, fixed cost per shard (corpus, census, worker trees)
SPLIT_AT = 2500  # s, greedy split threshold: ~17% headroom under BUDGET; was 7650
UNIT = 17  # s per (key, prog), grouped, non-SLUS; was 20 (2.7 T4 fit 16.4 +20%)
UNIT_REFUSED = 36  # s per (key, prog) with a refused row, non-SLUS; was 28 (2.7 T4 fit 22.6 +20%)
# main rate per key range (3.2 T11): (first key prefix, grouped wall s, SLUS units) of T1's shards 1..11;
# replaces UNIT_SLUS = 20 (one rate for every key; was 72 pre-bisect). Shard 2's wall is the larger of its two runs.
SLUS_CAL = (
    ("00006b8a5815", 1975, 100),
    ("1a993fe21b1b", 3434, 101),
    ("352cf890412f", 2197, 101),
    ("506fd071bf40", 1782, 101),
    ("6ae6ba2676fb", 2087, 100),
    ("815174a61947", 2634, 100),
    ("95cf5435ad21", 2183, 101),
    ("b31bd5bef82a", 2002, 100),
    ("ce7bdf7311dd", 2259, 101),
    ("eb3a6db008dc", 2428, 100),
    ("fffe1e9b0361", 59, 1),
)
SLUS_MAX = 101  # SLUS units per shard at most: the calibrated group size (3.0 T6 shard 1)
WORKERS = 8  # container nproc
SHARD0_EST = 1474  # s, shard 0 (every other rung), measured 2.7 T4 (t4-shard0); was 6200 placeholder


def prog_of(ref):
    return ref.split(":", 1)[0]


def slus_rate(key, cal=SLUS_CAL):
    """s per SLUS unit for key: the rate of the calibrated range it sorts into (keys before the first take range 1)."""
    i = max(0, bisect.bisect_right([c[0] for c in cal], key[: len(cal[0][0])]) - 1)
    return cal[i][1] / cal[i][2]


def rate(key, prog, refused):
    if prog == "main":
        return slus_rate(key)
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
    return sum(1 for k in keys if "main" in weights.get(k, {}))


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
    w = {k: {"main": UNIT} for k in "abcdef"}
    w["f"] = {"main": BUDGET}
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
    capped = split(cap, {k: {"main": 1} for k in cap})
    print("thshard self-test slus-cap: %s" % ("split" if len(capped) == 2 else "NOT SPLIT"))
    ok &= len(capped) == 2
    cal = (("10", 100, 10), ("80", 300, 10))  # range rates 10 and 30 s/unit
    ranged = [slus_rate(k, cal) for k in ("0f", "10", "7f", "80", "ff")] == [10, 10, 10, 30, 30]
    print("thshard self-test slus-range: %s" % ("ranged" if ranged else "NOT RANGED"))
    ok &= ranged
    for name, sh in planted.items():
        ks = keys + ["f"] if name == "over-budget" else keys
        failed = check(ks, sh, w)[1] is not None
        print("thshard self-test %s: %s" % (name, "refused" if failed else "ACCEPTED"))
        ok &= failed
    print("THSHARD SELF-TEST %s" % ("OK" if ok else "FAIL"))
    return 0 if ok else 1


def main(argv):
    registry = CONFIG_V + "/dedup_registry.txt"
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
