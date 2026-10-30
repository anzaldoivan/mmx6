#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */
extern s8 D_800CCEDF;

void func_800F53C8(void) {
    D_800CCEDF = 1;
    clear_object_slot();
}
