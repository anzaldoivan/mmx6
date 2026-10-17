#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_1C (*(u8**)0x1F80001C)

M2C_UNK func_800179A4(void*, M2C_UNK);
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
extern M2C_UNK D_800970A0;
extern s32 D_8007798C;
extern s32 D_801F3ABC;

void func_801F2A38(void* arg0) {
    u8* p;
    u8* player;
    s32 off;

    M2C_FIELD(arg0, s8*, 3) = 1;
    p = SCRATCH_1C;
    off = M2C_FIELD(p, s32*, 0x68);
    M2C_FIELD(arg0, s32*, 0x30) = (s32)&D_8007798C;
    M2C_FIELD(arg0, s16*, 0x40) = 0;
    M2C_FIELD(arg0, s16*, 0x42) = 0x7802;
    M2C_FIELD(arg0, s8*, 0x16) = 0x11;
    M2C_FIELD(arg0, s32*, 0x24) = 0x100000;
    M2C_FIELD(arg0, s8*, 0x64) = 1;
    M2C_FIELD(arg0, u8**, 0x3C) = p + off;
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        func_800179A4(arg0, 0xB);
        M2C_FIELD(arg0, s32*, 0x50) = (s32)&D_801F3ABC;
    } else {
        func_800179A4(arg0, 0xC);
    }
    player = (u8*)&D_800970A0;
    M2C_FIELD(arg0, u8*, 4)++;
    player[0x99]++;
    player[0x98]++;
}
#undef func_800179A4
#undef SCRATCH_1C
