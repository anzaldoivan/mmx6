#include "common.h"
#include "mmx6/x4.h"

extern s16 D_800970AA;
extern struct X4_BackgroundObj D_800971F8[3];

void func_800E9B90(void) {
    if (D_800970AA > 0x800) {
        D_800971F8[1].unk4 = 2;
        D_800971F8[1].unk40 = 0;
        D_800971F8[1].unk42 = 0;
        D_800971F8[1].unk4C = 1;
        D_800971F8[2].unk4 = 2;
        D_800971F8[2].unk40 = 0;
        D_800971F8[2].unk42 = 0;
        D_800971F8[2].unk4C = 1;
        return;
    }
    if (D_800971F8[1].unk4 == 2) {
        D_800971F8[1].unk4 = 1;
        D_800971F8[1].unk40 = 0;
        D_800971F8[1].unk42 = 0x230;
        D_800971F8[1].unk4C = 1;
        D_800971F8[2].unk4 = 3;
        D_800971F8[2].unk40 = 0;
        D_800971F8[2].unk42 = 0x280;
        D_800971F8[2].unk4C = 1;
    }
}
