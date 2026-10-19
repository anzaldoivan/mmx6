#include "common.h"

#define SLOT_PTR (*(u8**)0x801F8300)

void func_800134D8(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        s32 t = i * 2;
        *(u16*)(SLOT_PTR + t + 0x60) = 0;
    }
    for (i = 0; i < 0x10; i++) {
        *(SLOT_PTR + i + 0x71) = 0;
    }
}

#undef SLOT_PTR
