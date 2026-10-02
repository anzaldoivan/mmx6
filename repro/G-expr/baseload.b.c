// tell: base named in a local `q = p->a`: one load, all three stores through $5
// pass: cse
// expect: ^sw \$2,0\(\$5\)\nli \$2,3\nsw \$3,4\(\$5\)$
struct S2 { int x, y, z; };
struct S { struct S2 *a; };
void f(struct S *p)
{
    struct S2 *q = p->a;
    q->x = 1; q->y = 2; q->z = 3;
}
