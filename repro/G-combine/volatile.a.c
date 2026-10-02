// tell: volatile `short` read: combine will not merge the load into the extend: lhu + sll 16 + sra 16
// pass: combine
// expect: ^lhu \$2,0\(\$4\)\nnop\nsll \$2,\$2,0x10\nsra \$2,\$2,0x10$
// dump: (mem/v:HI (reg/v:SI 81) 0)) 256 {movhi_internal2}
// diff: length -3
int f(volatile short *p)
{
    return *p + 1;
}
