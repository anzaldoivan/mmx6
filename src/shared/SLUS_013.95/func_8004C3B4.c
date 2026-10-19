#include "common.h"

#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800328B0();

void func_8004C3B4(void* arg0) {
    s32 t;

    t = FU8(arg0, 0x3B) - 1;
    FU8(arg0, 0x3B) = t;
    if ((t & 0xFF) == 0xFF) {
        FU8(arg0, 4) = FU8(arg0, 4) + 1;
        func_800328B0(arg0);
    }
}

#undef FU8
