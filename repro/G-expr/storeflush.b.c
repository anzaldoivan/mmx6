// tell: indexed store p[1] is MEM_IN_STRUCT_P: cse keeps G, no reload
// pass: cse
// expect: ^sll \$2,\$2,0x1$
// dump: (set (mem/s:SI (plus:SI (reg/v:SI 81)
extern int G;
int f(int *p)
{
    int a = G;
    p[1] = 1;
    return a + G;
}
