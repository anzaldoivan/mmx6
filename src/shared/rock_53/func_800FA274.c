#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800FA274(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        D_800971F8[2].unk3 = 1;
        D_800971F8[2].y_pos.i.hi = 0x200;
        D_800971F8[2].unk4C = 1;
        *(s16*)(arg0 + 8) = 0x15C;
        *(s16*)(arg0 + 0xA) = 0xE;
        arg0[1]++;
    }
}
