#include "common.h"
#include "mmx6/x4.h"

extern struct X4_AbcObj D_8008EAF0;

void func_8004B824(struct X4_UnkObj* arg0) {
    struct X4_AbcObj* abc = &D_8008EAF0;
    s32 d = abc->unkD;

    if (d == 4 && (s16)abc->unkA < 0x1E) {
        arg0->unk40 = d;
        arg0->unk42 = 0;
        arg0->unk5++;
    }
}
