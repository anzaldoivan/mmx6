// tell: the full word has a second use: lw kept, separate andi 0xff
// pass: combine
// expect: ^andi \$2,\$3,0xff$
int f(int *p)
{
    return (*p & 0xff) + *p;
}
