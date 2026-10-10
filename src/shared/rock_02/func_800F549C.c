#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8003D330();
M2C_UNK func_800F82C0();
extern u8 D_800CCF5C;
#define D_800CCF5C (*(s8*)&D_800CCF5C)

void func_800F549C(void* arg0) {
    ((void (*)(void))func_800F82C0)();
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_80016C48(0, 0xE, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 2;
    }
    if (++M2C_FIELD(arg0, s8*, 0x5C) == D_800CCF5C) {
        if (M2C_FIELD(arg0, s8*, 2) == 2) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 7);
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
            M2C_FIELD(arg0, u8*, 6)++;
            return;
        }
        func_8003D330();
        M2C_FIELD(arg0, u8*, 6) = 0xB;
        M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
        M2C_FIELD(arg0, s32*, 0x2C) = -0x1000;
    }
}
#undef D_800CCF5C
