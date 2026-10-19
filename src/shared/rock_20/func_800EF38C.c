#include "common.h"

s32 func_800F0668(void);
extern u8 D_800F366C[];

void func_800EF38C(u8* arg0) {
    s32 t = func_800F0668();
    D_800F366C[0x128D] = t;
    if (t & 0xFF) {
        arg0[2] = arg0[2] + 1;
    } else {
        arg0[2] = 8;
    }
}
