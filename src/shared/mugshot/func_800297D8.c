#include "common.h"

extern u16 D_80097202;

void func_800297D8(u8* arg0) {
    s32 t = (s16)D_80097202 >> 1;
    t += *(u16*)(arg0 + 0x40);
    *(s16*)(arg0 + 0xA) = t;
}
