#include "common.h"
#include "mmx6/x4.h"

void* func_8002C530();
s32 func_800ED69C(u8 arg0);
extern u8 D_80097427;
extern struct X4_EngineObj D_800CCED0;
extern s16 D_800F0B30[];

static inline void spawn_7b8(u8 spr, s16 x, s16 y) {
    u8* obj = func_8002C530();
    if (obj != 0) {
        obj[0] = 1;
        obj[1] = 0x2D;
        obj[2] = spr;
        *(s16*)(obj + 0xA) = x;
        *(s16*)(obj + 0xE) = y;
        obj[0x58] = 1;
        obj[0x59] = D_800CCED0.unk1;
        obj[0x5A] = D_80097427;
    }
}

void func_800EB7B8(s32 a0, s32 a1) {
    s16 arg0 = a0;
    s16 arg1 = a1;
    s32 t;
    s32 i;
    s32 d0;
    s32 d1;
    s32 d2;

    t = 0;
    i = 0;
    do {
        if (func_800ED69C(i & 0xFF) != 0) {
            t++;
        }
        i++;
    } while (i < 0x80);
    if (t >= 999) {
        spawn_7b8(0xB7, D_800F0B30[0] + arg0, D_800F0B30[1] + arg1);
        spawn_7b8(0xB7, D_800F0B30[2] + arg0, D_800F0B30[3] + arg1);
        spawn_7b8(0xB7, D_800F0B30[4] + arg0, D_800F0B30[5] + arg1);
    } else if (t <= 0) {
        spawn_7b8(0xAE, D_800F0B30[4] + arg0, D_800F0B30[5] + arg1);
    } else {
        d0 = t / 100;
        d1 = t - d0 * 100;
        d2 = t % 10;
        d1 /= 10;
        if (d0 != 0) {
            spawn_7b8(d0 - 0x52, D_800F0B30[0] + arg0, D_800F0B30[1] + arg1);
        }
        if (d1 != 0 || d0 != 0) {
            spawn_7b8(d1 - 0x52, D_800F0B30[2] + arg0, D_800F0B30[3] + arg1);
        }
        spawn_7b8(d2 - 0x52, D_800F0B30[4] + arg0, D_800F0B30[5] + arg1);
    }
}
