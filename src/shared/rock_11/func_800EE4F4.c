#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
extern s16 D_80090D5C;
extern s32 D_80097420;
extern s16 D_80097430;
extern u8 D_800C4560;
extern s16 D_800CF854;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EE4F4(void* self) {
    s32 t;

    if (--F(s16, 0x7E) == 0) {
        F(u16, 0x7E) = 0x3C;
    }
    if (--F(s16, 0x7C) == -1) {
        F(u16, 0x7C) = 3;
        t = (u16)D_800CF854 + 1;
        D_800CF854 = t;
        D_80097430 += 0x20;
        D_80090D5C += 0x400;
        D_800C4560 |= 1;
        if ((u16)t >= 0x1F) {
            F(u8, 0x6)++;
        }
    }
    if (!(D_80097420 & 3)) {
        func_8002943C(2, 5, 2);
    }
    if (!(D_80097420 & 0x1F)) {
        func_80012D9C(3);
    }
}

#undef F
