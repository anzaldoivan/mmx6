#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
extern M2C_UNK D_80074E7C;
extern s16 D_80097206;
extern M2C_UNK D_800FC740;
extern M2C_UNK D_800FC744;

void func_800F8DAC(void* arg0) {
    s8 st;

    st = M2C_FIELD(arg0, s8*, 0x45);
    if (st == 1) {
        if (M2C_FIELD(arg0, s16*, 0xE) == (D_80097206 + 0x30)) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 0x16);
            M2C_FIELD(arg0, u8*, 6)++;
            return;
        }
        if (func_8002D2D4() & 1) {
            func_80016C48(2, 0x22, arg0);
        } else {
            func_80016C48(2, 0x23, arg0);
        }
        func_80016C48(2, 0x54, arg0);
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x1D);
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_80074E7C;
        M2C_FIELD(arg0, s8*, 0x60) = 0xA;
        M2C_FIELD(arg0, s8*, 0x8E) = 0;
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC740;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC744;
        M2C_FIELD(arg0, s8*, 6) = 0xB;
    } else if (st == 2) {
        func_80016C48(2, 0x59, arg0);
    }
}
