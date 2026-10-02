// tell: store written in both arms: jump2 cross-jumps the store and the call: one shared jal g
// pass: jump2
// expect: ^j 18\nli \$4,1\nli \$4,2\njal 0$
extern void g(int);
extern int G;
void f(int a)
{
    if (a) { g(1); G = 3; } else { g(2); G = 3; }
}
