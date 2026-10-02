// tell: store written after the if: the else-arm ends in a call, flow's nop vetoes cross-jump: two jal g
// pass: jump2
// expect: ^jal 0\nli \$4,2\nlui \$3,0x0$
// dump: (use (const_int 0 [0x0]))
// diff: isel
extern void g(int);
extern int G;
void f(int a)
{
    if (a) g(1); else g(2);
    G = 3;
}
