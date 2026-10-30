#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800F7E0C;
extern s16 D_800F7E0E;

void func_800F4F58(struct X4_MainObj* arg0) {
    if (D_800F7E0C == 0) {
        set_animation(arg0, 0);
        play_sound(2, 0x27, arg0);
        D_800F7E0E = 5;
        arg0->unk7C = 0;
        *((u8*)arg0 + 6) = *((u8*)arg0 + 6) + 1;
    }
}
