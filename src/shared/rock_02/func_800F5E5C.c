#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800F5E5C(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (25/35)
    register u16 t asm("$2");

    if (M2C_FIELD(arg0, s16*, 0x7C) == 0xA) {
        func_80012D9C(7);
        func_80016C48(2, 0x1D, arg0);
    }
    func_80017A04(arg0);
    t = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, s16*, 0x7C) = t + 1;
    if ((s16)t > 0x28) {
        func_800179A4(arg0, 8);
        t = M2C_FIELD(arg0, u8*, 6);
        M2C_FIELD(arg0, u8*, 6) = t + 1;
    }
}
