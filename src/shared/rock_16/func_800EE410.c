#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
extern s8 D_800CCF01;

void func_800EE410(void* arg0) {
    set_animation_frame(arg0, 1, D_800CCF01);
}
