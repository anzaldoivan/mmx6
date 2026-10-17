#include "common.h"

extern void (*D_800FCC60[])(void*);

#define G(type, off) (*(type*)((u8*)self + (off)))

void func_800F78AC(void* self) {
    if (G(s8, 2) != 0 && G(s8, 4) != 6) {
        if ((*(s8**)((u8*)self + 0x80))[5] == 9) {
            G(s8, 4) = 6;
            G(s8, 5) = 0;
        }
    }
    D_800FCC60[G(s8, 4)](self);
}

#undef G
