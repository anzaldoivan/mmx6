// tell: &local passed directly: per-site addu $4,$sp,16, no callee-saved register
// pass: rtl
// expect: ^addiu \$4,\$29,16$
extern void h(void *);
void f(void)
{
    int buf[4];
    h(buf);
    h(buf);
}
