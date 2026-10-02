#!/usr/bin/env python3
"""cookbook_check.py -- the cookbook index check: entry files vs INDEX rows, titles, idiom symptom tags, the
triage table's TODOs (container, stdlib only; reads only, tools/cookbook_add.sh stays the only adder of rows).

  cookbook_check.py [--check] [--dir D]   (D default <repo>/cookbook; --check = this default check)
      entry = D/C<nnnn>.md, line 1 `# C<nnnn> — <title>`, line 2 `tags: <t,t,...> · date: … · …`;
      row = a D/INDEX.md line `C<nnnn> | <title> | <tags> | <date> | <phase/task> | <origin>` (`<!--` lines are
      comments, not rows).
        every entry has exactly one row with its id (none -> ORPHAN, more -> DUP);
        every row resolves to D/<id>.md (else DANGLING);
        row title == the entry's line-1 title (else TITLE);
        an entry whose tags (row field 3 or line 2) include `idiom` has >= 1 `sym-<slug>` tag of the vocabulary
        (the slugs ending the tell cells of D/C0002.md's table) (else NOSYMPTOM);
        D/C0002.md holds no `TODO` (else TODO C0002).
      -> per defect `COOKBOOK ORPHAN|DANGLING|DUP|TITLE|NOSYMPTOM|TODO <id>` rc 1;
         else `COOKBOOK OK <e> entries, <r> rows, 0 orphans, 0 dangling` rc 0.
  cookbook_check.py --self-test
      scratch copies of D under .run/cookbook-selftest/<plant>/ (C0054; never the real cookbook/): the unplanted
      copy must pass first (C0066), then plants orphan file, dangling row, title mismatch, idiom entry without a
      symptom tag, duplicate row, TODO in C0002, each refused with its token.
      Ends `COOKBOOK CONTROL OK`, else `COOKBOOK CONTROL FAIL <why>` rc 1.
Firewall G12: our own docs only; prints ids and counts, never retail bytes.
"""
import argparse
import glob
import os
import re
import shutil
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ROW_RE = re.compile(r'^(C\d{4}) \| ')
HEAD_RE = re.compile(r'^# (C\d{4}) — (.*)$')
SYM_RE = re.compile(r'`(sym-[a-z0-9-]+)`\s*$')


def _read(path):
    with open(path, encoding='utf-8') as f:
        return f.read().splitlines()


def _tags(field):
    return {t.strip() for t in field.split(',') if t.strip()}


def check(d):
    """Return (defect lines, entries, rows)."""
    defects = []
    entries = {}
    for p in sorted(glob.glob(os.path.join(d, 'C[0-9][0-9][0-9][0-9].md'))):
        eid = os.path.basename(p)[:-3]
        lines = _read(p)
        m = HEAD_RE.match(lines[0]) if lines else None
        title = m.group(2).strip() if m and m.group(1) == eid else None
        tags = set()
        if len(lines) > 1 and lines[1].startswith('tags:'):
            tags = _tags(lines[1][len('tags:'):].split(' · ')[0])
        entries[eid] = (title, tags)
    rows = {}
    nrows = 0
    for line in _read(os.path.join(d, 'INDEX.md')):
        if line.startswith('<!--') or not ROW_RE.match(line):
            continue
        nrows += 1
        f = [x.strip() for x in line.split(' | ')]
        rows.setdefault(f[0], []).append(f)
    vocab = set()
    c2 = os.path.join(d, 'C0002.md')
    c2lines = _read(c2) if os.path.exists(c2) else []
    for line in c2lines:
        if line.startswith('|'):
            cells = line.strip().strip('|').split('|')
            m = SYM_RE.search(cells[0].strip()) if cells else None
            if m:
                vocab.add(m.group(1))
    for eid, (title, tags) in sorted(entries.items()):
        rs = rows.get(eid, [])
        if not rs:
            defects.append('COOKBOOK ORPHAN ' + eid)
            continue
        if len(rs) > 1:
            defects.append('COOKBOOK DUP ' + eid)
        r = rs[0]
        if title is None or len(r) < 2 or r[1] != title:
            defects.append('COOKBOOK TITLE ' + eid)
        alltags = tags | (_tags(r[2]) if len(r) > 2 else set())
        if 'idiom' in alltags and not (alltags & vocab):
            defects.append('COOKBOOK NOSYMPTOM ' + eid)
    for rid in sorted(rows):
        if rid not in entries:
            defects.append('COOKBOOK DANGLING ' + rid)
    if any('TODO' in line for line in c2lines):
        defects.append('COOKBOOK TODO C0002')
    return defects, len(entries), nrows


def run_check(d):
    defects, e, r = check(d)
    for x in defects:
        print(x)
    if defects:
        return 1
    print('COOKBOOK OK %d entries, %d rows, 0 orphans, 0 dangling' % (e, r))
    return 0


def _append(path, text):
    with open(path, 'a', encoding='utf-8') as f:
        f.write(text)


def _sub(path, old, new):
    lines = _read(path)
    s = '\n'.join(lines) + '\n'
    assert old in s, (path, old)
    with open(path, 'w', encoding='utf-8') as f:
        f.write(s.replace(old, new, 1))


def self_test(src):
    base = os.path.join(ROOT, '.run', 'cookbook-selftest')
    idx = lambda d: os.path.join(d, 'INDEX.md')
    c75 = 'idiom,sym-global-reload,'

    def p_orphan(d):
        _append(os.path.join(d, 'C9999.md'), '# C9999 — planted orphan\ntags: plant · date: - · phase/task: - · origin: -\n')

    def p_dangling(d):
        _append(idx(d), 'C9998 | planted dangling | plant | - | - | -\n')

    def p_title(d):
        lines = _read(os.path.join(d, 'C0003.md'))
        _sub(os.path.join(d, 'C0003.md'), lines[0], lines[0] + ' (planted)')

    def p_nosym(d):
        _sub(os.path.join(d, 'C0075.md'), c75, 'idiom,sym-planted-none,')
        _sub(idx(d), c75, 'idiom,sym-planted-none,')

    def p_dup(d):
        row = [l for l in _read(idx(d)) if l.startswith('C0003 | ')][0]
        _append(idx(d), row + '\n')

    def p_todo(d):
        _append(os.path.join(d, 'C0002.md'), '\nTODO planted\n')

    plants = [('clean', None, None), ('orphan', p_orphan, 'COOKBOOK ORPHAN C9999'),
              ('dangling', p_dangling, 'COOKBOOK DANGLING C9998'), ('title', p_title, 'COOKBOOK TITLE C0003'),
              ('nosymptom', p_nosym, 'COOKBOOK NOSYMPTOM C0075'), ('dup', p_dup, 'COOKBOOK DUP C0003'),
              ('todo', p_todo, 'COOKBOOK TODO C0002')]
    for name, plant, token in plants:
        d = os.path.join(base, name)
        if os.path.exists(d):
            shutil.rmtree(d)
        shutil.copytree(src, d)
        if plant:
            plant(d)
        defects, _, _ = check(d)
        if plant is None and defects:
            print('COOKBOOK CONTROL FAIL clean copy refused: ' + defects[0])
            return 1
        if plant and token not in defects:
            print('COOKBOOK CONTROL FAIL %s plant not refused (%s)' % (name, ', '.join(defects) or 'no defect'))
            return 1
    print('COOKBOOK CONTROL OK')
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--check', action='store_true')
    ap.add_argument('--dir', default=os.path.join(ROOT, 'cookbook'))
    ap.add_argument('--self-test', action='store_true')
    a = ap.parse_args()
    if a.self_test:
        return self_test(a.dir)
    return run_check(a.dir)


if __name__ == '__main__':
    sys.exit(main())
