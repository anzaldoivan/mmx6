#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002A47C(s32);
M2C_UNK func_800179A4(void*, M2C_UNK);
extern s16 D_800970AA;

#define SPAD20 (*(s32**)0x1F800020)
#define F_S8(o) M2C_FIELD(self, s8*, (o))
#define F_U8(o) M2C_FIELD(self, u8*, (o))
#define F_S16(o) M2C_FIELD(self, s16*, (o))
#define F_PTR(o) M2C_FIELD(self, void**, (o))

void func_800EFCDC(void* self) {
    s32 a;
    s32 b;
    s32 g;

    g = D_800970AA;
    if (F_S16(0xA) < g) {
        F_U8(0x15) = 0x40;
    } else {
        F_U8(0x15) = 0;
    }
    F_S16(0x40) = 0x140;
    a = func_8002A47C(F_S8(0x1));
    b = func_8002A47C(F_S8(0x1));
    F_S16(0x42) = ((a * 4 + 0x20) % 16) | ((((b + 8) / 4) + 0x1E0) << 6);
    F_PTR(0x3C) = (u8*)SPAD20 + SPAD20[func_8002A47C(F_S8(0x1))];
    ((void (*)(void*, s32))func_800179A4)(self, 3);
    F_S16(0x7C) = 0;
    F_U8(0x6)++;
}
