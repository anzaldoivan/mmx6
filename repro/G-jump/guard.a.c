// tell: while loop: jump copies the exit test `p<e` as the entry guard (sltu + beqz)
// pass: jump
// expect: ^sltu \$2,\$4,\$3\nbeqz \$2,
// dump: NOTE_INSN_LOOP_VTOP
// diff: length -2
void f(int *p, int n)
{
    int *e = p + n;
    while (p < e) { *p = 0; p++; }
}
