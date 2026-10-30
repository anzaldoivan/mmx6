#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)
#define W(p, o) M2C_FIELD(p, s32*, o)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(void*);
extern s16 D_8009721E;

void func_800F2C38(void* arg0) {
    s32 ang;
    s32 t;
    s32 a, b, c, d;

    a = H(arg0, 0x84);
    b = H(arg0, 0x86);
    ang = ratan2(H(arg0, 0xE) - b, a - H(arg0, 0xA));
    {
        s32 u;
        t = rcos(ang);
        u = t << 4;
        W(arg0, 0x20) = ((t << 5) + u) * 2;
    }
    t = rsin(ang);
    {
        s32 u = t << 4;
        t = (t << 5) + u;
    }
    W(arg0, 0x24) = t * 2;
    if (W(arg0, 0x20) >= 0) {
        B(arg0, 0x15) = 0x40;
    } else {
        B(arg0, 0x15) = 0;
    }
    move_object(arg0);
#define ABS(x) ((x) >= 0 ? (x) : -(x))
    if (ABS(H(arg0, 0x84) - H(arg0, 0xA)) < 7 &&
        ABS(H(arg0, 0x86) - H(arg0, 0xE)) < 7) {
        play_sound(2, 0x26, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 0x11);
        if (H(arg0, 0xA) >= D_8009721E + 0xB0) {
            B(arg0, 0x15) = 0;
        } else {
            B(arg0, 0x15) = 0x40;
        }
        B(arg0, 0x6)++;
    }
}
