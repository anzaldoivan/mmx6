#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800EA708(u8* arg0) {
    ((void (*)())func_80017A04)(arg0);
    if (arg0[0x47] == 0) {
        arg0[5] = 1;
        set_animation(arg0, 1);
        *(s16*)(arg0 + 0x7C) = 0;
    }
}
