#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */
extern M2C_UNK D_800FF668;

void func_800FCB64(void* arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 2) & 0xF0;
    if (temp_v1 == 0) {
        M2C_FIELD(&D_800FF668, u16*, 0x7B8) =
            (u16)(M2C_FIELD(&D_800FF668, u16*, 0x7B8) - 1);
    } else if (temp_v1 == 0x10) {
        M2C_FIELD(&D_800FF668, u16*, 0x7BA) =
            (u16)(M2C_FIELD(&D_800FF668, u16*, 0x7BA) - 1);
    }
    clear_object_slot();
}
