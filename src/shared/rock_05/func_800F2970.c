#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_800F2B4C();
extern s32 D_800F4148;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F2970(void* self) {
    ((void (*)())func_800F2B4C)();
    ((void (*)(void*))func_80017A04)(self);
    if (--F(s16, 0x7C) == 0) {
        if (F(s16, 0x7E) != 0) {
            F(s16, 0x7E)--;
            func_800179A4(self, 4);
            F(s32, 0x20) = 0;
            F(s32, 0x24) = 0xFFFB0000;
            F(void*, 0x68) = 0;
            F(u8, 6) = 1;
            return;
        }
        F(void*, 0x68) = &D_800F4148;
        F(u8, 5) = 7;
        F(u8, 6) = 0;
    }
}

#undef F
