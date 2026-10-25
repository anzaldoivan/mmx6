#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F7F6C(void* self) {
    ((M2C_UNK(*)())func_80017A04)();
    if (F(s16, 0x7C) == 0xA) {
        func_80016C48(2, 0x1D, self);
        func_80012D9C(7);
    }
    if (F(s16, 0x7C)++ >= 0x79) {
        func_80016C48(2, 0x3D, self);
        func_800179A4(self, 0x16);
        {
            // !FAKE: depin: dropping it breaks the match (51/54)
            register s32 v asm("$2") = F(u8, 0x6) + 1;
            F(u8, 0x6) = v;
        }
        return;
    }
    if (SPAD4C[0x8A] != 0x11) {
        func_80016C48(2, 0x3D, self);
        func_800179A4(self, 2);
        {
            // !FAKE: depin: dropping it breaks the match (52/54)
            register s32 v asm("$2") = 5;
            F(u8, 0x6) = v;
        }
        F(s16, 0x7C) = 0;
    }
}

#undef F
#undef SPAD4C
