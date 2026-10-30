#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */
extern u16 D_800F70DC;

void func_800EE398(void* arg0) {
    if ((M2C_FIELD(arg0, s8*, 2) & 0xF0) == 0x10) {
        D_800F70DC -= 1;
    }
    clear_object_slot();
}
