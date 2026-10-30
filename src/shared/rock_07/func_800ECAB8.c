#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800ECAB8(u8* arg0) {
    s8 t = *(s8*)(*(u8**)(arg0 + 0x80) + 7);

    if (t == 0) {
        return;
    }
    switch (t) {
    case 5:
        if (*(s8*)(arg0 + 2) == 0x10) {
            ((void (*)(void*, s32))set_animation)(arg0, 6);
            arg0[6]++;
        }
        break;
    case 6:
        if (*(s8*)(arg0 + 2) == 0x11) {
            ((void (*)(void*, s32))set_animation)(arg0, 6);
            arg0[6]++;
        }
        break;
    case 7:
        if (*(s8*)(arg0 + 2) == 0x12) {
            ((void (*)(void*, s32))set_animation)(arg0, 6);
            arg0[6]++;
        }
        break;
    }
}
