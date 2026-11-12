# tools/mmx6/systems/props_check.py -- check a naming-proposal TSV against its token list (C0368; 2.6 T14, kept by T12.1).
# Run from the repo root: PY tools/mmx6/systems/props_check.py PROPS.tsv TOKENS.tsv -> 'PROPS OK n' rc 0, else 'PROPS FAIL' lines rc 1.
import re, sys, os, subprocess
root = os.getcwd() + '/'
props, toks = sys.argv[1], sys.argv[2]
want = [l.split('\t')[0] for l in open(toks) if l.strip()]
rows = [l.rstrip('\n').split('\t') for l in open(props) if l.strip()][1:]
err = []
seen, names = {}, {}
for i, r in enumerate(rows, 2):
    if len(r) != 10:
        err.append(f'{i}: {len(r)} columns'); continue
    tok, verd, name, kind, ref = r[:5]
    if tok in seen: err.append(f'{i}: {tok} twice')
    seen[tok] = 1
    if verd not in ('admit', 'hold'): err.append(f'{i}: verdict {verd}')
    if verd == 'admit':
        if not re.fullmatch(r'[a-z][a-z0-9_]*', name): err.append(f'{i}: name {name}')
        if name in names: err.append(f'{i}: name {name} also row {names[name]}')
        names[name] = i
        if kind in ('-', '') or ref in ('-', ''): err.append(f'{i}: admit without basis')
        for m in re.finditer(r'code:([^:\s]+):(\d+) via=(\w+)', ref):
            p, n, a = m.group(1), int(m.group(2)), m.group(3)
            try:
                line = open(root + p).read().split('\n')[n - 1]
            except Exception:
                err.append(f'{i}: ref {p}:{n} unreadable'); continue
            if not re.search(r'\b' + re.escape(a) + r'\b', line): err.append(f'{i}: anchor {a} not on {p}:{n}')
        if kind in ('code', 'xref') and 'code:' not in ref: err.append(f'{i}: {kind} without code: ref')
        hit = subprocess.run(['grep', '-rlw', '--include=*.c', '--include=*.h', name, root + 'src', root + 'include'], capture_output=True, text=True).stdout.strip()
        if hit: err.append(f'{i}: name {name} already used in {hit.splitlines()[0]}')
    elif not r[8] or r[8] == '-':
        err.append(f'{i}: hold without clause')
for t in want:
    if t not in seen: err.append(f'missing {t}')
for e in err: print('PROPS FAIL', e)
print(f'PROPS OK {len(rows)}' if not err else f'PROPS FAIL {len(err)}')
sys.exit(1 if err else 0)
