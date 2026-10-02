// tell: widening temp `int t = *p`: sign-extending lh, then the mask
// pass: rtl
// expect: ^lh \$2,0\(\$4\)$
int f(short *p)
{
    int t = *p;
    return t & 0xFFF;
}
