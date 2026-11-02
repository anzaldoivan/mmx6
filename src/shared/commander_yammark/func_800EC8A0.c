#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002D230(void*);

void func_800EC8A0(u8* arg0) {
    ((void (*)(void*))func_8002D230)(arg0);
    ((void (*)(void*))func_80017A04)(arg0);
    if (*(s8*)(arg0 + 0x45) != 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        arg0[6] = 2;
        arg0[7] = 0;
    }
}
