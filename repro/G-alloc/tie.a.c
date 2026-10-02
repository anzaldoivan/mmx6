// tell: equal priority: the lower pseudo (first-created value, x) gets $16
// pass: greg
// expect: ^addu \$16,\$2,\$4$
// dump: 83 in 16  84 in 17
// diff: regs $16 $17
extern int g(int);
extern int h(int, int, int);
int f(int a, int b)
{
    int x, y;
    x = a * 3;
    y = b * 5;
    if (g(a)) { x += 1; y += 1; }
    return h(x, 0, y);
}
