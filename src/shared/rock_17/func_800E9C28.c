#include "common.h"

void func_800EA278(u8* arg0, s32 arg1);

void func_800E9C28(u8* arg0) {
    s32 t;
    s16 i;

    t = *(u16*)(arg0 + 4) - 1;
    *(u16*)(arg0 + 4) = t;
    if ((t << 16) == 0) {
        for (i = 0; i < 0x18; i++) {
            func_800EA278(arg0, (u8)(i - 0x80));
        }
        arg0[1]++;
    }
}
