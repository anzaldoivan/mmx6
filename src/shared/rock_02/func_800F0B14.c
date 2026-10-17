#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 func_8002A47C(s32);
extern s8 D_80097244;
extern u8 D_800FB218[];

void func_800F0B14(void* arg0) {
    s32 base;
    s32 idx;
    s32 t;

    if ((s16)++M2C_FIELD(arg0, u16*, 0x7C) == 0xB4) {
        func_80027BA0(0, 0x17B0, 0xD0, D_800FB218);
        func_80027BA0(0, 0x1930, 0xD0, D_800FB218 + 0x10);
        D_80097244 = 1;
        idx = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
        base = SPAD20;
        t = *(s32*)(idx * 4 + base);
        M2C_FIELD(arg0, s32*, 0x3C) = base + t;
        ((void (*)(void*, s32))func_800179A4)(arg0, 1);
        M2C_FIELD(arg0, s32*, 0x24) = 0x10000;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
