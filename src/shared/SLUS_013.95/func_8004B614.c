#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8004B614(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}
