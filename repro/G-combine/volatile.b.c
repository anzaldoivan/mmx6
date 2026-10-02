// tell: plain `short` read: the sign extend merges into the load, one lh
// pass: combine
// expect: ^lh \$2,0\(\$4\)$
int f(short *p)
{
    return *p + 1;
}
