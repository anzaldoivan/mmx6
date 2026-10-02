// tell: member store `p->a` (/s, in-struct) cannot alias scalar G: sched hoists the load above it
// pass: sched
// expect: ^lw \$2,0\(\$3\)\nsw \$5,0\(\$4\)$
// dump: (set (mem/s:SI (reg:SI 4 a0) 0)
struct S { int a; };
extern int G;
int f(struct S *p, int v)
{
    p->a = v;
    return G + 1;
}
