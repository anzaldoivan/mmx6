// tell: a byte offset cast through char *: no shift, one addu
// pass: rtl
// expect: ^addu \$4,\$4,\$5$
int f(int *p, int i)
{
    return *(int *)((char *)p + i);
}
