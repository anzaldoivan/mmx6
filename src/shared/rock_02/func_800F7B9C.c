#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();

#define SPAD4C (*(u8**)0x1F80004C)

void func_800F7B9C(u8* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    if (*(s16*)(arg0 + 0x7C) == 0xA) {
        func_80016C48(2, 0x1D, arg0);
        func_80012D9C(7);
    }
    if ((*(s16*)(arg0 + 0x7C))++ >= 0x79) {
        func_800179A4(arg0, 8);
        {
            register s32 t asm("$2") = arg0[6] + 1;
            arg0[6] = t;
        }
        return;
    }
    if (SPAD4C[0x8A] != 0x11) {
        func_80016C48(2, 0x3D, arg0);
        func_800179A4(arg0, 2);
        {
            register s32 t asm("$2") = 5;
            arg0[6] = t;
        }
        *(s16*)(arg0 + 0x7C) = 0;
    }
}

#undef SPAD4C
