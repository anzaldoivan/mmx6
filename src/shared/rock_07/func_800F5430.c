#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D2B0(void*);
void func_800F6880(void*, s32, s16, s16);

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800F5430(void* arg0) {
    if (F(u8, 0x70) & 8) {
        func_80016C48(2, 0x5E, arg0);
        func_80012D9C(5);
        func_8002943C(0x32, 3, 2);
        func_800179A4(arg0, 0xC);
        func_800F6880(arg0, 0x10, F(s16, 0xA), F(s16, 0xE) + 0x20);
        func_800F6880(arg0, 0x10, F(s16, 0xA), F(s16, 0xE) + 0x20);
        func_800F6880(arg0, 0x11, F(s16, 0xA), F(s16, 0xE) + 0x20);
        func_800F6880(arg0, 0x12, F(s16, 0xA), F(s16, 0xE) + 0x20);
        F(u8, 6)++;
        return;
    }
    func_8002D2B0(arg0);
}

#undef F
