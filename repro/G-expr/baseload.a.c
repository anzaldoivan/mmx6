// tell: pointer-derived base `p->a` re-loaded (`lw $5,0($4)`) after each member store through it
// pass: cse
// expect: ^sw \$2,0\(\$3\)\nlw \$5,0\(\$4\)$
// dump: (set (mem/s:SI (plus:SI (reg:SI 84)
// diff: length -2
struct S2 { int x, y, z; };
struct S { struct S2 *a; };
void f(struct S *p)
{
    p->a->x = 1; p->a->y = 2; p->a->z = 3;
}
