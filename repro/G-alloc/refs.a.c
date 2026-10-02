// tell: of two values live across a call and a branch, the one with more references gets $16
// pass: greg
// expect: ^addu \$16,\$2,\$4$
// dump: ;; 2 regs to allocate: 83 87
// diff: length 0
extern int g(int);
extern int h(int, int);
int f(int a, int b)
{
    int x = a * 3;
    int y = b * 5;
    if (g(a)) { x += 1; y += 2; }
    g(x);
    g(x);
    return h(x, y);
}
