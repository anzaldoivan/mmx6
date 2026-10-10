#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D2B0(void*);

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EAA18(void* self) {
    if (F(s8, 0x45) == 2) {
        ((void (*)(void*))func_8002D2B0)(self);
        if (F(u8, 0x70) & 8) {
            func_80016C48(2, 0x52, self);
            ((void (*)(s32))func_80012D9C)(5);
            F(s16, 0x7C) = 0xB4;
            F(s8, 5)++;
            if (F(s8, 3) != 0) {
                func_8002943C(0x5A, 2, 2);
            }
        }
    }
}

#undef F
