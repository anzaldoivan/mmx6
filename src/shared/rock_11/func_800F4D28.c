#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK silence_sound(M2C_UNK, M2C_UNK); /* extern */
M2C_UNK clear_object_slot(void*);            /* extern */

void func_800F4D28(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        silence_sound(2, 0x17);
    }
    clear_object_slot(arg0);
}
