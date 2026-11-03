#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800EDBD4(u8* arg0) {
    animate_object();
    if ((s8)arg0[7] == 1) {
        arg0[7] = 0;
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 2);
        arg0[6]++;
    }
}
