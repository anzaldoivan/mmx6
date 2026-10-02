// tell: declaration order swapped: v3 is the lower pseudo and takes 52($sp), v2 56($sp)
// pass: greg
// expect: ^jal 0\nsw \$2,56\(\$29\)\naddiu \$4,\$16,4$
extern int g(int);
extern int h(int, int, int, int, int, int, int, int, int, int, int, int);
int f(int a)
{
    int v0, v1, v3, v2, v4, v5, v6, v7, v8, v9, v10, v11;
    v0 = g(a); v1 = g(a + 1); v2 = g(a + 2); v3 = g(a + 3); v4 = g(a + 4); v5 = g(a + 5);
    v6 = g(a + 6); v7 = g(a + 7); v8 = g(a + 8); v9 = g(a + 9); v10 = g(a + 10); v11 = g(a + 11);
    return h(v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) + v0 + v1;
}
