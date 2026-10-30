#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);

void func_800F374C(u8* arg0) {
    play_sound(2, 0x14, arg0);
    play_sound(2, 0x21, arg0);
    set_animation(arg0, 3);
    func_80029478(0x3C, 2, 2);
    ((void (*)(M2C_UNK, M2C_UNK, M2C_UNK))func_8002943C)(0x3C, 2, 2);
    *(s16*)(arg0 + 0x7C) = 0;
    arg0[6]++;
}
