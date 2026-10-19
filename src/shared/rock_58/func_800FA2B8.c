#include "common.h"
#include "mmx6/x4.h"

extern s16 D_80090D5C;
extern struct X4_BackgroundObj D_800971F8[3];
extern s16 D_80097430;
extern s16 D_800CF854;

void func_800FA2B8(u8* arg0) {
    s32 temp_a1;

    temp_a1 = (u16)D_800CF854 + 1;
    D_800CF854 = temp_a1;
    D_80097430 += 0x20;
    D_80090D5C += 0x400;
    if ((temp_a1 & 0xFFFF) == 0x1F) {
        D_800971F8[2].y_pos.u.hi = 0x100;
        D_800971F8[2].unk4C = 1;
        arg0[1]++;
    }
}
