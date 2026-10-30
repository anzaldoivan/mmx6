#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EF2E4(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}
