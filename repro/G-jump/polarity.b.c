// tell: condition inverted and arms swapped: h(2) is the fall-through, bnez to g(1)
// pass: jump
// expect: ^bnez \$4,
extern void g(int);
extern void h(int);
void f(int a)
{
    if (!a) h(2); else g(1);
}
