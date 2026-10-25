#include "common.h"

#define M2C_UNK s32

#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;

void func_800F1CD8(s8* arg0) {
    struct X4_PlayerObj* pl = &g_Player;

    *(u8*)((s32)pl + 0xCA) = 0;
    func_8003D308(0x14, pl->unk15);
    arg0[5] = 1;
    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    func_800179A4(arg0, 5);
    *(s16*)(arg0 + 0x7C) = 0x7F;
    *(s16*)(arg0 + 0x7E) = 0x19;
    arg0[0x61] = 0x19;
    func_8002CCB0(arg0, 0x60, 0x60);
}
