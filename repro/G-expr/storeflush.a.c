// tell: global G reloaded after a bare-deref store *p (store has no /s, may alias G)
// pass: cse
// expect: ^lw \$2,0\(\$3\)$
// dump: (set (mem:SI (reg/v:SI 81) 0)
// diff: length -1
extern int G;
int f(int *p)
{
    int a = G;
    *p = 1;
    return a + G;
}
