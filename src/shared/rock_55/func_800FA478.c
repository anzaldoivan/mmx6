#include "common.h"

extern s16 D_80090D5C;
extern s16 D_80097430;
extern s8 D_800CCF08;
extern s16 D_800CF854;

void func_800FA478(u8* arg0) {
    s16 v;
    s32 t;

    t = (u16)D_800CF854 - 1;
    D_800CF854 = t;
    D_80097430 -= 0x20;
    D_80090D5C -= 0x400;
    if (!(t & 0xFFFF)) {
        v = 0x1CF;
        if (D_800CCF08 == 0) {
            v = 0x1BA;
        }
        *(s16*)(arg0 + 8) = v;
        *(s16*)(arg0 + 0xA) = 1;
        do {
        } while (0);
        arg0[1]++;
    }
}
