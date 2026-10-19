#include "common.h"
#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800FA7CC(u8* arg0) {
    u8* p;

    func_80017A04();
    p = M2C_FIELD(arg0, u8**, 0x7C);
    M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(p, u16*, 0xA);
    {
        // !FAKE: copied halfword lands in the second argument register
        register s32 t asm("$5") = M2C_FIELD(p, u16*, 0xE);
        M2C_FIELD(arg0, u16*, 0xE) = t;
        func_80017A04(arg0, t);
    }
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x40, 0x40);
    if (M2C_FIELD(arg0, s16*, 0x8C) != 0) {
        M2C_FIELD(arg0, s16*, 0x8C) = M2C_FIELD(arg0, u16*, 0x8C) - 1;
        return;
    }
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = 2;
}
