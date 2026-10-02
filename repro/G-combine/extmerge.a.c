// tell: word load whose only use is & 0xff merges into lbu
// pass: combine
// expect: ^lbu \$2,0\(\$4\)$
// dump: (zero_extend:SI (mem:QI (reg:SI 4 a0) 0)))
// diff: length 2
int f(int *p)
{
    return *p & 0xff;
}
