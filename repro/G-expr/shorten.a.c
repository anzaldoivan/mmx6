// tell: `short` read masked in the expression: the & is shortened onto the raw HImode value, load is lhu
// pass: rtl
// expect: ^lhu \$2,0\(\$4\)$
// dump: (and:SI (subreg:SI (reg:HI 83) 0)
// diff: isel
int f(short *p)
{
    return (*p) & 0xFFF;
}
