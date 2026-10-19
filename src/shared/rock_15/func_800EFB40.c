#include "common.h"

extern void (*D_800F67B4[])(void*);

void func_800EFB40(u8* arg0) {
    u16 v;

    D_800F67B4[((s8*)arg0)[6]](arg0);
    v = *(u16*)(arg0 + 0x54);
    *(u16*)(arg0 + 0x54) = v - 1;
    if (v & 1) {
        arg0[3] = 0;
    } else {
        arg0[3] = 1;
    }
}
