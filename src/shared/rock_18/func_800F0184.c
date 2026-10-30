#include "common.h"
#include "mmx6/x4.h"

extern u8 D_80097427;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F0F88[][3];

void func_800F0184(u8* arg0) {
    u8 v;
    u8 w;

    v = arg0[0x57];
    arg0[3] = 1;
    if (v != 0) {
        if ((v - 1) == D_80097427) {
            *(s16*)(arg0 + 0x42) = 0x784C;
        } else {
            w = D_800F0F88[arg0[2]][1];
            *(s16*)(arg0 + 0x42) = (w & 0xF) | (((w >> 4) + 0x1E0) << 6);
        }
    }
    if (arg0[0x47] != g_playthrough_state.unk3) {
        arg0[3] = 0;
    }
    arg0[0x47] = g_playthrough_state.unk3;
}
