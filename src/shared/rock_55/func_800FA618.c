#include "common.h"

s32 func_8002B2F8(s32);
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern s8 D_8009742C;
extern s16 D_80097430;
extern s8 D_800CCF08;
extern s8 D_800CF850;
extern s16 D_800CF854;

void func_800FA618(u8* arg0) {
    D_800CF854--;
    D_80097430 -= 0x20;
    D_80090D5C -= 0x400;
    if (!(D_800CF854 & 0xFFFF)) {
        D_80090D56 = 0;
        D_8009742C = 0;
        D_800CF850 = 0;
        ((void (*)(s32))func_8002B2F8)(0);
        if (D_800CCF08 == 0) {
            *(s16*)(arg0 + 8) = 0x1BB;
        } else {
            *(s16*)(arg0 + 8) = 0x1D0;
        }
        *(s16*)(arg0 + 0xA) = 4;
        arg0[1]++;
    }
}
