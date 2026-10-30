#include "common.h"

#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK reset_level();                         /* extern */
extern u16 D_800C4570;

void func_800EFF28(s8* arg0) {
    if (D_800C4570 & 0x40) {
        play_sound(0, 0x22, 0);
        ((void (*)())reset_level)();
        arg0[1] = 6;
        arg0[2] = 6;
        arg0[3] = 0;
    }
}
