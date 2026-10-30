#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define S8(o) M2C_FIELD(arg0, s8*, o)
#define U8(o) M2C_FIELD(arg0, u8*, o)
#define U16(o) M2C_FIELD(arg0, u16*, o)
#define S16(o) M2C_FIELD(arg0, s16*, o)
#define S32(o) M2C_FIELD(arg0, s32*, o)
#define PTR(o) M2C_FIELD(arg0, void**, o)
#define SCRATCH_PTR (*(u8**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

void func_800EF95C(void* arg0) {
    s32 x;
    s32 y;
    s32 t;
    u8* p;

    if (S16(0xE) >= 0x458) {
        S32(0x68) = 0;
        S16(0x40) = 0x140;
        x = func_8002A47C(S8(1));
        y = func_8002A47C(S8(1));
        x *= 4;
        S16(0x42) = ((x + 0x20) % 16) | (((y + 8) / 4 + 0x1E0) << 6);
        t = func_8002A47C(S8(1));
        p = SCRATCH_PTR;
        {
            // !FAKE: depin: dropping it breaks the match (42/63)
            register s32 u asm("$6") = *(s32*)(p + t * 4);
            PTR(0x3C) = p + u;
            ((void (*)(void*, s32, s32))set_animation)(arg0, 1, u);
        }
        S32(0x24) = 0;
        U8(6)++;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
}
