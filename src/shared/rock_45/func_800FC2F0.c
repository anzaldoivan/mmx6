#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
extern s16 D_800970AA;
extern s32 D_800FCA84;

void func_800FC2F0(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x88) < 0xF) {
        M2C_FIELD(arg0, u8*, 0x88) = 0x1E;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        if (M2C_FIELD(arg0, s32*, 0x24) != 0) {
            func_80016C48(2, 0x42, arg0);
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        *(s32*)((u8*)&D_800FCA84 + 0x3D8) = 0;
        M2C_FIELD(arg0, u8*, 0x88) = 0x1E;
        {
            s32 g = D_800970AA;
            if (M2C_FIELD(arg0, s16*, 0xA) < g) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
        }
        ((void (*)(void*, s32))func_800179A4)(arg0, 1);
        M2C_FIELD(arg0, u8*, 0x5) = 4;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
}
