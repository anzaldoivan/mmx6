#include "common.h"
#include "mmx6/x4.h"

void* func_8002C530();
extern u8 D_80097427;
extern struct X4_EngineObj D_800CCED0;
extern void* D_800E2F9C;
extern s16 D_800F0B30[];

static inline void spawn_bc8(u8 spr, s16 x, s16 y) {
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

void func_800EBBC8(s32 a0, s32 a1, s32 a2) {
    s16 arg0 = a0;
    s16 arg1 = a1;
    s32 t;
    s32 i;
    s32 d0;
    s32 d1;
    s32 d2;
    s32 d3;
    u16* p;

    i = a2 & 1;
    p = (u16*)((u8*)D_800E2F9C + 0xB8);
    i *= 2;
    t = (s16) * (u16*)((u8*)p + i);
    if (t >= 9999) {
        spawn_bc8(0xB7, D_800F0B30[0] + arg0, D_800F0B30[1] + arg1);
        spawn_bc8(0xB7, D_800F0B30[2] + arg0, D_800F0B30[3] + arg1);
        spawn_bc8(0xB7, D_800F0B30[4] + arg0, D_800F0B30[5] + arg1);
        spawn_bc8(0xB7, D_800F0B30[6] + arg0, D_800F0B30[7] + arg1);
    } else if (t <= 0) {
        spawn_bc8(0xAE, D_800F0B30[6] + arg0, D_800F0B30[7] + arg1);
    } else {
        d0 = t / 1000;
        d1 = t % 1000;
        d1 /= 100;
        d2 = t % 1000 - d1 * 100;
        d2 /= 10;
        d3 = t % 10;
        if (d0 != 0) {
            spawn_bc8(d0 - 0x52, D_800F0B30[0] + arg0, D_800F0B30[1] + arg1);
        }
        if (d1 != 0 || d0 != 0) {
            spawn_bc8(d1 - 0x52, D_800F0B30[2] + arg0, D_800F0B30[3] + arg1);
        }
        if (d2 != 0 || d1 != 0 || d0 != 0) {
            spawn_bc8(d2 - 0x52, D_800F0B30[4] + arg0, D_800F0B30[5] + arg1);
        }
        spawn_bc8(d3 - 0x52, D_800F0B30[6] + arg0, D_800F0B30[7] + arg1);
    }
}
