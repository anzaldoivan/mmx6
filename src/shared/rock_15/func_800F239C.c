#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800F0A78(void* arg0);
extern u8 D_8008EAFC;

void func_800F239C(void* arg0) {
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x60, 0x60);
    if (--M2C_FIELD(arg0, s32*, 0x8C) == 0) {
        func_800F0A78(arg0);
        M2C_FIELD(arg0, s32*, 0x8C) = 3;
    }
    if (M2C_FIELD(arg0, s32*, 0x90) == 0) {
        func_80029478(0xA, 4, 2);
        {
            // !FAKE: keep the constant in the first return register for the store
            register s32 k asm("$2") = 0xA;
            M2C_FIELD(arg0, s32*, 0x90) = k;
        }
    }
    M2C_FIELD(arg0, s32*, 0x90)--;
    if (D_8008EAFC == 0) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0x7F;
        M2C_FIELD(arg0, s16*, 0x7E) = 0x19;
        M2C_FIELD(arg0, s8*, 0x61) = 0x19;
        M2C_FIELD(arg0, u8*, 5)++;
        func_80012D9C(9);
    }
}
