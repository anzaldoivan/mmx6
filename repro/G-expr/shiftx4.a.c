// tell: p[i] on int *p: the index is scaled by sll 2 before the addu
// pass: rtl
// expect: ^sll \$5,\$5,0x2$
// dump: (ashift:SI (reg:SI 84)
// diff: length -1
int f(int *p, int i)
{
    return p[i];
}
