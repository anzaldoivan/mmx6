"""sizes.py -- per-system size: debt --files states and kinds + INCLUDE_ASM counts + untested drafts (2.6 planning, R2.6-002).

Run from the repo root (host):  PY tools/psxd_floor.py debt --files > .run/<phase>/debt-files.txt
                                PY tools/mmx6/systems/sizes.py .run/<phase>/debt-files.txt [system-prefix...]
"""
import re, sys, collections, pathlib
root = pathlib.Path('.')
debt_files = pathlib.Path(sys.argv[1])
rows = collections.defaultdict(lambda: collections.Counter())
def key(path):
    p = path.split('/')
    if p[1] == 'SLUS_013.95':
        return 'SLUS/' + (p[2] if len(p) > 3 else '(top)')
    if p[1] == 'shared':
        return 'shared/' + (p[2] if len(p) > 3 else '(top)')
    return p[1]
for line in debt_files.read_text().splitlines():
    m = re.match(r'DEBT FILE (\w+)\s+(\S+?):?\s(.*)$', line)
    if not m:
        continue
    st, path, kinds = m.groups()
    k = key(path)
    c = rows[k]
    c['files'] += 1
    c[st] += 1
    for part in kinds.split(','):
        part = part.strip()
        mm = re.match(r'([\w-]+) (\d+)$', part)
        if mm:
            c['d_' + mm.group(1)] += int(mm.group(2))
            c['debt'] += int(mm.group(2))
for f in (root / 'src').rglob('*.c'):
    n = f.read_text(errors='replace').count('INCLUDE_ASM(')
    if n:
        rows[key(str(f.relative_to(root)))]['asm'] += n
for line in (root / 'docs/ops/layout-test.untested.tsv').read_text().splitlines():
    if line.startswith('#') or ':' not in line:
        continue
    prog = line.split(':')[0]
    rows[prog if prog.startswith('rock') else 'SLUS/(top)']['untested'] += 1
want = sys.argv[2:] or None
for k in sorted(rows, key=lambda k: -rows[k]['files']):
    c = rows[k]
    if want and not any(k.startswith(w) for w in want):
        continue
    print(f"{k:22} files {c['files']:3} fin {c['finished']:2} mat {c['matched']:3} stubs {c['stubs']:2} asm {c['asm']:3} "
          f"ph {c['d_placeholder']:4} phu {c['d_placeholder-use']:5} off {c['d_offset']:5} ext {c['d_extern']:4} "
          f"pin {c['d_pin']:3} goto {c['d_goto']:3} debt {c['debt']:6} untested {c['untested']}")
