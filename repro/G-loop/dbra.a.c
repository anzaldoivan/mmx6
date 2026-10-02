// tell: up-count loop 0..9 with the counter otherwise unused is reversed: li 9, addu -1, bgez
// pass: loop
// expect: ^bgez \$3,
// dump: Reversed loop and added reg_nonneg
// diff: isel
extern int A[];
void f(void)
{
    int i;
    for (i = 0; i < 10; i++)
        A[5] += 3;
}
