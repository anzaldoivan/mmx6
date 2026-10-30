#include "common.h"
#include "mmx6/x4.h"

void* alloc_sprite_slot();
extern u8 D_80097427;
extern struct X4_EngineObj g_playthrough_state;
extern void* D_800E2F9C;
extern s16 D_800F0B30[];

static inline void spawn(u8 spr, s16 x, s16 y) {
    u8* obj = alloc_sprite_slot();
    if (obj != 0) {
        obj[0] = 1;
        obj[1] = 0x2D;
        obj[2] = spr;
        *(s16*)(obj + 0xA) = x;
        *(s16*)(obj + 0xE) = y;
        obj[0x58] = 1;
        obj[0x59] = g_playthrough_state.unk1;
        obj[0x5A] = D_80097427;
    }
}

void func_800EB15C(s32 a0, s32 a1) {
    s16 arg0 = a0;
    s16 arg1 = a1;
    s32 t;
    s32 h;
    s32 m;
    s32 d0;
    s32 d1;

    t = *(s32*)((u8*)D_800E2F9C + 0x40);
    spawn(0xB8, D_800F0B30[4] + arg0 + 5, D_800F0B30[5] + arg1 + 2);
    if (t > 0x14988EF) {
        spawn(0xB7, D_800F0B30[0] + arg0, D_800F0B30[1] + arg1);
        spawn(0xB7, D_800F0B30[2] + arg0, D_800F0B30[3] + arg1);
        spawn(0xB3, D_800F0B30[6] + arg0, D_800F0B30[7] + arg1);
        spawn(0xB7, D_800F0B30[8] + arg0, D_800F0B30[9] + arg1);
    } else if (t <= 0) {
        spawn(0xAE, D_800F0B30[0] + arg0, D_800F0B30[1] + arg1);
        spawn(0xAE, D_800F0B30[2] + arg0, D_800F0B30[3] + arg1);
        spawn(0xAE, D_800F0B30[6] + arg0, D_800F0B30[7] + arg1);
        spawn(0xAE, D_800F0B30[8] + arg0, D_800F0B30[9] + arg1);
    } else {
        h = t / 216000;
        m = (t % 216000) / 3600;
        if (h >= 100) {
            h = 99;
        }
        d0 = h / 10;
        d1 = h % 10;
        spawn(d0 - 0x52, D_800F0B30[0] + arg0, D_800F0B30[1] + arg1);
        spawn(d1 - 0x52, D_800F0B30[2] + arg0, D_800F0B30[3] + arg1);
        d0 = m / 10;
        d1 = m % 10;
        spawn(d0 - 0x52, D_800F0B30[6] + arg0, D_800F0B30[7] + arg1);
        spawn(d1 - 0x52, D_800F0B30[8] + arg0, D_800F0B30[9] + arg1);
    }
}
