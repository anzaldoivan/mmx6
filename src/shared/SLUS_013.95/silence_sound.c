#include "common.h"

extern s32* D_80097778[];
s32 SsUtKeyOffV(u8);
s32 SsUtSetVVol(u8, s32, s32);

// 0x8001750C silence_sound: zeroes the volume of and keys off a range of sound voices (all 24 for 0xFF).
// basis: code src/shared/SLUS_013.95/silence_sound.c:19 via=SsUtKeyOffV
// callers: exit_stage_from_menu, func_8001D0E4, func_8001D218
void silence_sound(u8 arg0, u8 arg1) {
    u8 i;
    u8 v;
    s8 n;
    s32* p;

    if (arg0 == 0xFF) {
        for (i = 0; i < 0x18; i++) {
            SsUtSetVVol(i, 0, 0);
            SsUtKeyOffV(i);
        }
        return;
    }
    p = D_80097778[arg0];
    p += arg1;
    v = ((u8*)p)[3];
    i = v & 0x1F;
    for (n = (v & 0x60) >> 5; n >= 0; n--) {
        SsUtSetVVol(i, 0, 0);
        SsUtKeyOffV(i);
        i++;
    }
}
