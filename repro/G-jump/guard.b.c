// tell: explicit guard `n > 0` around a do-while: the guard is the source's (blez), no copied test
// pass: jump
// expect: ^blez \$5,
void f(int *p, int n)
{
    int *e = p + n;
    if (n > 0) do { *p = 0; p++; } while (p < e);
}
