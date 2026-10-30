#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8004F8A0(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}
