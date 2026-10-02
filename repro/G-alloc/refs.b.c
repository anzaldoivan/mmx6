// tell: the extra references moved to y: y now gets $16, x $17
// pass: greg
// expect: ^addu \$16,\$3,\$5$
// dump: ;; 2 regs to allocate: 87 83
extern int g(int);
extern int h(int, int);
int f(int a, int b)
{
    int x = a * 3;
    int y = b * 5;
    if (g(a)) { x += 1; y += 2; }
    g(y);
    g(y);
    return h(x, y);
}
