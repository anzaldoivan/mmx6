// tell: &local held in a named pointer: one addu into callee-saved $16, move $4,$16 per call
// pass: rtl
// expect: ^move \$4,\$16$
// dump: (reg/v:SI 81)) -1 (nil)
// diff: length -2
extern void h(void *);
void f(void)
{
    int buf[4];
    void *q = buf;
    h(q);
    h(q);
}
