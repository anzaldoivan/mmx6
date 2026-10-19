#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern s8 D_8008EAB0;
extern struct X4_BackgroundObj D_800971F8[3];
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8003CCBC();

void func_80050EA0(u8* arg0, s32 arg1, u8* arg2) {
    *(s32*)(arg2 + 8) += *(s32*)(arg0 + 0x84);
    if (D_800971F8[0].x_pos.i.hi == D_800971F8[0].unk26) {
        *(s8*)(arg2 + 0xD4) = 0;
        func_8003CCBC(arg2);
        *(s8*)(arg0 + 5) = 4;
        func_800179A4(arg0, 1);
        func_80016C48(0, 0x11, arg0);
        if (*(s8*)(arg0 + 2) == 0x12) {
            D_8008EAB0 = 1;
            D_800971F8[0].unk26 = 0xD70;
        }
        D_800971F8[0].unk47 = *(u8*)(arg0 + 0x80);
        D_800971F8[0].unk34 &= 0xF;
    }
}
