#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800ED360 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
M2C_UNK func_8002C9B0();
extern u32* D_80095098;
extern s8 D_800CCEED;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800ED360(void* self) {
    s32 a;
    s32 b;

    if (D_800CCEED >= 2) {
        func_8002C9B0();
        return;
    }
    F(u16, 0x40) = D_80095098[func_8002A47C(0x88)] >> 7;
    a = func_8002A47C(0x88);
    b = func_8002A47C(0x88);
    a = a * 4;
    F(s16, 0x42) = ((a + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    F(u8*, 0x3C) = (u8*)SPAD20_800ED360 + SPAD20_800ED360[func_8002A47C(0x88)];
    F(u8, 0x16) = 0x13;
    F(s8, 0x47) = 0;
    F(u8, 4)++;
}

#undef F
