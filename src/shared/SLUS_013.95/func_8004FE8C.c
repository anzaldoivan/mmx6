#include "common.h"

extern s32 D_800970A8;

s32 func_8004FE8C(void* arg0) {
    u8* p = (u8*)arg0;

    if (p[0x82] == 0) {
        s32 f = *(s32*)(p + 8);
        if (D_800970A8 < f) {
            p[0x82] = 0;
            return 0;
        }
        p[0x82] = 0x40;
        return 1;
    } else {
        s32 f = *(s32*)(p + 8);
        if (D_800970A8 < f) {
            p[0x82] = 0;
            return 1;
        }
        p[0x82] = 0x40;
        return 0;
    }
}
