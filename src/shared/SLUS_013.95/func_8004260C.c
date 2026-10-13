#include "common.h"

void func_8004260C(u8* arg0) {
    if (*(u16*)(arg0 + 0x7C) & 1) {
        arg0[3] = 0;
    } else {
        arg0[3] = 1;
    }
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[3] = 0;
        arg0[4] = 2;
    }
}
