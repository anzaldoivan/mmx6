#include "common.h"
#define M2C_UNK s32

#define F(expr, type, offset) (*(type*)((u8*)(expr) + (offset)))
#define SPAD_20 (*(u8**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s16 D_800970AA;

void func_800EFFA4(void* self) {
    // !FAKE: first result scaled in place in its callee-saved register
    register s32 a asm("$16");
    s32 b;
    u8* base;
    s32 g;
    s32 c;

    g = D_800970AA;
    if (F(self, s16, 0xA) < g) {
        F(self, u8, 0x15) = 0x40;
    } else {
        F(self, u8, 0x15) = 0;
    }
    F(self, s16, 0x40) = 0x140;
    a = func_8002A47C(F(self, s8, 0x1));
    b = func_8002A47C(F(self, s8, 0x1));
    c = a * 4;
    F(self, s16, 0x42) = ((c + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    a = func_8002A47C(F(self, s8, 0x1));
    base = SPAD_20;
    F(self, u8*, 0x3C) = base + *(s32*)(base + a * 4);
    set_animation(self, 3);
    {
        // !FAKE: byte counter read into the first return register
        register s32 t asm("$2") = F(self, u8, 0x6);
        F(self, s16, 0x7C) = 0x5A;
        F(self, u8, 0x6) = t + 1;
    }
}

#undef SPAD_20
#undef F
