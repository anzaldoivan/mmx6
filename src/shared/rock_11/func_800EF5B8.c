#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_800F1A90(void* self, u8 arg1);
M2C_UNK func_800F4534(void*, M2C_UNK);
extern s32 D_80097420;
extern u8 D_800E9884[];
extern u8 D_800E9894[];
extern s16 D_800FD516;
extern s16 D_800FD518;
extern s8 D_800FD51B;

#define F(type, off) M2C_FIELD(arg0, type*, off)

// str 0x800E9884 sha1=cc02398329fa039d76fae5aa30b17ad91bc6c29c = "rising byte ramp: a table, not text"
// str 0x800E9894 sha1=2d16eed36913e36e5b0f303d1c288f5e234839b2 = "tail of the same byte ramp"
void func_800EF5B8(void* arg0) {
    s8 a[16];
    s8 b[16];
    u16 ang;
    s16 y;
    s32 t;
    s16 px;
    s16 py;

    __builtin_memcpy(a, D_800E9884, 16);
    __builtin_memcpy(b, D_800E9894, 16);
    px = D_800FD516;
    py = D_800FD518;
    ang = ratan2(F(s16, 0xE) - py, px - F(s16, 0xA)) & 0xFFF;
    F(s16, 0x88) = ang;
    ((void (*)(void*, s32, s32))set_animation_frame)(arg0, a[ang >> 8],
                                               D_80097420 & 1);
    t = F(u8, 0x2) & 0xF;
    switch (t) {
    case 1:
        y = ((-rsin(F(s16, 0x7E)) * 8) >> 12) + 0x60;
        F(s16, 0xE) = y;
        break;
    case 2:
        y = ((-rsin(F(s16, 0x7E)) * 8) >> 12) + 0x20;
        F(s16, 0xE) = y;
        break;
    case 3:
        y = ((-rsin(F(s16, 0x7E)) * 8) >> 12) + 0xB0;
        F(s16, 0xE) = y;
        break;
    }
    F(s16, 0x7E) += 0x1E;
    if (D_800FD51B == 2) {
        set_animation(arg0, b[F(s16, 0x88) >> 8]);
        func_800F1A90(arg0, 0x10);
        func_800F4534(arg0, 0x10);
        func_800F4534(arg0, 0x11);
        func_800F4534(arg0, 0x12);
        func_800F4534(arg0, 0x13);
        {
            // !FAKE: depin: dropping it breaks the match (140/145)
            register s32 n asm("$2") = F(u8, 0x6);
            F(s16, 0x7C) = 0x32;
            F(u8, 0x6) = n + 1;
        }
    }
}
