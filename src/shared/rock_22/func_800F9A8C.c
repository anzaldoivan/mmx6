#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80017A04(); /* extern */

void func_800F9A8C(u8* arg0) {
    u16 t;

    ((void (*)())func_80017A04)();
    t = *(u16*)(arg0 + 0x7C);
    *(u16*)(arg0 + 0x7C) = t + 1;
    if ((s16)t >= 0x79) {
        if (*(s32*)(arg0 + 0x20) > 0) {
            *(s32*)(arg0 + 0x20) = -0x30000;
        } else if (*(s32*)(arg0 + 0x20) < 0) {
            *(s32*)(arg0 + 0x20) = 0x30000;
        } else if (*(s32*)(arg0 + 0x24) > 0) {
            *(s32*)(arg0 + 0x24) = -0x30000;
        } else if (*(s32*)(arg0 + 0x24) < 0) {
            *(s32*)(arg0 + 0x24) = 0x30000;
        }
        arg0[6]++;
    }
}
