#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */
extern s16 D_800CCED4;

void func_800EA270(void* arg0) {
    clear_object_slot();
    M2C_FIELD(arg0, s8*, 3) = 0;
    D_800CCED4 = 0;
}
