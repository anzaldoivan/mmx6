#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F9754 (*(s32*)0x1F800020)

s32 func_8002A47C(s32);
M2C_UNK clear_object_slot();
extern u32* D_80095098;
extern s8 D_800CCEED;

void func_800F9754(void* arg0) {
    s32 a;
    s32 base;
    s32 c;

    if (D_800CCEED >= 2) {
        ((M2C_UNK(*)())clear_object_slot)();
        return;
    }
    M2C_FIELD(arg0, u16*, 0x40) = D_80095098[func_8002A47C(0x92)] >> 7;
    M2C_FIELD(arg0, u16*, 0x42) =
        ((func_8002A47C(0x92) * 4 + 0x20) % 16) |
        (((func_8002A47C(0x92) + 8) / 4 + 0x1E0) << 6);
    a = func_8002A47C(0x92);
    base = SPAD20_800F9754;
    c = *(s32*)(a * 4 + base);
    M2C_FIELD(arg0, u8*, 0x16) = 0x13;
    M2C_FIELD(arg0, u8*, 0x47) = 0;
    M2C_FIELD(arg0, u8*, 0x4)++;
    M2C_FIELD(arg0, s32*, 0x3C) = base + c;
}

#undef SPAD20_800F9754
