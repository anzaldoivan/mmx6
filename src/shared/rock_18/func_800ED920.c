#include "common.h"

#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK reset_level();                         /* extern */
extern u16 D_800C4570;
extern s8 D_800CD3F9;

void func_800ED920(void) {
    if (D_800C4570 & 0x40) {
        play_sound(0, 0x22, 0);
        reset_level();
        D_800CD3F9 = 4;
    }
}
