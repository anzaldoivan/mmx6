#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern s8 D_800CCEF8;

void func_800EE438(void* arg0) {
    set_animation(arg0, D_800CCEF8 + 2);
}
