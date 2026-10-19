#include "common.h"

extern s32 D_8006D674[];

s32 func_800F0724(u8 arg0, s32 arg1) {
    u8 i;
    u8 n;

    n = 0;
    i = 0;
    do {
        if (D_8006D674[i] & arg1) {
            n++;
        }
        i++;
    } while (i <= arg0);
    if (n >= 9) {
        n = 8;
    }
    return n;
}
