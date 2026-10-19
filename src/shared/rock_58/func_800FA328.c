#include "common.h"

extern s16 D_80090D5C;
extern s16 D_80097430;
extern s16 D_800CF854;

void func_800FA328(u8* arg0) {
    s32 t;

    t = (u16)D_800CF854 - 1;
    D_800CF854 = t;
    D_80097430 -= 0x20;
    D_80090D5C -= 0x400;
    if (!(t & 0xFFFF)) {
        *(s16*)(arg0 + 8) = 0x217;
        *(s16*)(arg0 + 0xA) = 6;
        arg0[1] += 1;
    }
}
