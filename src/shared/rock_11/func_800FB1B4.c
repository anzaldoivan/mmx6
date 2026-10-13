#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];

void func_800FB1B4(u8* arg0) {
    s32 one = 1;

    *(s16*)(arg0 + 0x16) = one;
    *(s8*)(arg0 + 0x15) += arg0[0x16];
    if (*(s8*)(arg0 + 0x15) >= 0) {
        if (*(s8*)(arg0 + 0x15) < 0x10) {
            return;
        }
        if (++*(s8*)(arg0 + 0x14) >= 3) {
            *(s8*)(arg0 + 0x14) = 0;
        }
    } else {
        if (*(s8*)(arg0 + 0x15) >= -0xF) {
            return;
        }
        if (--*(s8*)(arg0 + 0x14) < 0) {
            *(s8*)(arg0 + 0x14) = 2;
        }
    }
    {
        s32 t = *(s8*)(arg0 + 0x14);
        D_800971F8[2].unk4C = one;
        D_800971F8[2].y_pos.u.hi = t << 8;
    }
    *(s8*)(arg0 + 0x15) = 0;
}
