#include "common.h"
#include "mmx6/x4.h"

extern s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern struct X4_PlayerObj g_Player;
extern s16 D_80097206;
extern s8 D_800CCEED;

void func_800E9A34(u8* arg0) {
    s16* p;
    s16 y;

    if (D_800CCEED == 1) {
        p = *(s16**)(arg0 + 0x18);
    } else {
        p = *(s16**)(arg0 + 0x18);
        y = p[7];
        if (D_80097206 < y) {
            return;
        }
        if (g_Player.x_pos.i.hi < p[6]) {
            return;
        }
        if (g_Player.y_pos.i.hi < y + 0x24) {
            return;
        }
    }
    ((void (*)(s32, s32, s32, u8*))func_80027BA0)(0, p[0], p[1], (u8*)(p + 2));
    arg0[4]++;
}
