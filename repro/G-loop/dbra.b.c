// tell: written as a down-count to 0: li 10, addu -1, bgtz (loop has nothing to reverse)
// pass: loop
// expect: ^bgtz \$3,
extern int A[];
void f(void)
{
    int i;
    for (i = 10; i > 0; i--)
        A[5] += 3;
}
