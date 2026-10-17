#include "common.h"

void func_80027FA4(s32, s32, s32);

void func_80027C98(s32 arg0, s16 arg1, s16 arg2, u16* arg3) {
    s32 i;
    s32 j;
    s32 x;
    s32 y;

    y = arg2;
    i = 0;
    while (i < arg3[3]) {
        x = arg1;
        j = 0;
        while (j < arg3[2]) {
            func_80027FA4(arg0, x, y);
            j++;
            x += 0x10;
        }
        i++;
        y += 0x10;
    }
}
