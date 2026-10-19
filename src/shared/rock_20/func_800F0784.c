#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];
extern u8 D_800F366C[];

void func_800F0784(s32 arg0) {
    arg0 &= 0xFF;
    D_800971F8[1].unk4C = 1;
    D_800971F8[1].y_pos.i.hi = *(u16*)(D_800F366C + 0x734 + arg0 * 2);
}
