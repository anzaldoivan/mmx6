#include "common.h"

extern s16 D_800EA2C8[];
extern s8 D_800EAACC;

void func_800E9F7C(u8* arg0) {
    ((void (**)(u8*)) & D_800EA2C8[0x154])[(s8)arg0[5]](arg0);
    arg0[3] = D_800EAACC;
}
