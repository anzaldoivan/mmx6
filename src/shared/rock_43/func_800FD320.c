#include "common.h"

extern s32 D_800FDE30;

void func_800FD320(u8* arg0) {
    if (arg0[0x84] < 15) {
        arg0[0x84] = 30;
    }
    ((void (**)(u8*))((u8*)&D_800FDE30 + 0x3B0))[(s8)arg0[6]](arg0);
}
