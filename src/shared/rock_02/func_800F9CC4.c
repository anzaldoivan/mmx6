#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);

void func_800F9CC4(u8* arg0) {
    s32 t;

    t = arg0[6] - 1;
    arg0[6] = t;
    if ((t << 0x18) == 0) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0xA, arg0);
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0xFFF80000;
        arg0[5] = arg0[5] + 1;
    }
}
