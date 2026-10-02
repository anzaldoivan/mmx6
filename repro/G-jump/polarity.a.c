// tell: if (a) then-arm g(1) is the fall-through: beqz to the else-arm h(2)
// pass: jump
// expect: ^beqz \$4,
// dump: (if_then_else (eq:SI (reg/v:SI 81)
// diff: branch
extern void g(int);
extern void h(int);
void f(int a)
{
    if (a) g(1); else h(2);
}
