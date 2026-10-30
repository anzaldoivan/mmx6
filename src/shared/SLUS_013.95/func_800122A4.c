#include "common.h"
#include "psyq/libgpu.h"
#include "mmx6/x4.h"

extern u8 D_8006D5FC[];
extern u16 g_screen_width;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800CF908[];
extern u8 D_800CF948[];

void func_800122A4(s8 arg0, s8 arg1) {
    s16 r[4];
    s16 t[4];
    u8* e;
    u8* e2;
    s16 v;

    ((s16*)D_8006D5FC)[0] = arg0;
    ((s16*)D_8006D5FC)[1] = arg1;
    e = (u8*)&g_playthrough_state;
    t[0] = (s8)e[0xD0];
    t[2] = (s8)e[0xD0];
    t[1] = (s8)e[0xD1];
    t[3] = (s8)e[0xD1] + 0xF0;
    SetDrawOffset(D_800CF908, &t[0]);
    SetDrawOffset(D_800CF908 + 0xC, &t[2]);
    if ((s8)e[0xD0] < 0) {
        r[0] = 0;
        r[2] = g_screen_width + (s8)e[0xD0];
    } else {
        r[0] = (s8)e[0xD0];
        r[2] = g_screen_width - (s8)e[0xD0];
    }
    e2 = (u8*)&g_playthrough_state;
    if ((s8)e2[0xD1] < 0) {
        v = (s8)e2[0xD1] + 0xF0;
        r[1] = 0;
    } else {
        v = 0xF0 - (s8)e2[0xD1];
        r[1] = (s8)e2[0xD1];
    }
    r[3] = v;
    do {
    } while (0);
    SetDrawArea(D_800CF948, r);
    r[1] += 0xF0;
    SetDrawArea(D_800CF948 + 0xC, r);
}
