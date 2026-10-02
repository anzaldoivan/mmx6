// tell: global load held below a bare `*p` store (no /s: may alias G)
// pass: sched
// expect: ^sw \$5,0\(\$4\)\nlw \$2,0\(\$3\)$
// dump: (insn 12 19 14 (set (mem:SI (reg:SI 4 a0) 0)
// diff: order
extern int G;
int f(int *p, int v)
{
    *p = v;
    return G + 1;
}
