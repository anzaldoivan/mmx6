#include "common.h"

#define M2C_UNK s32

#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj D_800970A0;

void func_800EDEC4(s8* arg0) {
    u8 temp;

    func_80016C48(2, 0x20, arg0);
    temp = D_800970A0.unk15;
    *(u8*)((s32)&D_800970A0 + 0xCA) = 0;
    func_8003D308(0x14, temp);
    func_800179A4(arg0, 6);
    arg0[5] = 1;
    *(s16*)(arg0 + 0x7C) = 0x7F;
    *(s16*)(arg0 + 0x7E) = 0x19;
    arg0[0x61] = 0x19;
    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    func_8002CCB0(arg0, 0x60, 0x60);
}
