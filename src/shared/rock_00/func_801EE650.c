#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_801EE650(void* arg0) {
    void* temp_v1;

    temp_v1 = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(temp_v1, u8*, 0x98) = (u8)(M2C_FIELD(temp_v1, u8*, 0x98) - 1);
    clear_object_slot();
}
