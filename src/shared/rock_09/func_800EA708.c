#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800EA708(u8* arg0) {
    ((void (*)())animate_object)(arg0);
    if (arg0[0x47] == 0) {
        arg0[5] = 1;
        set_animation(arg0, 1);
        *(s16*)(arg0 + 0x7C) = 0;
    }
}
