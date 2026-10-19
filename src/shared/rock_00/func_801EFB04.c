#include "common.h"

void func_801EFB04(u8* arg0) {
    if (*(s16*)(arg0 + 0x88) < 0x1E) {
        if (*(u16*)(arg0 + 0x88) & 1) {
            arg0[3] = 0;
        } else {
            arg0[3] = 1;
        }
    }
    if (--*(s16*)(arg0 + 0x88) == 0) {
        arg0[0x75] = 0;
        arg0[3] = 0;
        arg0[4] = 3;
    }
}
