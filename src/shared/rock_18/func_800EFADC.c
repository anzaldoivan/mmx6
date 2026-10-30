#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(void*, void*); /* extern */
extern u8 D_80097427;
extern s8 D_800CCED1;

void func_800EFADC(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 1;
    if (M2C_FIELD(arg0, u8*, 0x59) != D_800CCED1) {
        clear_object_slot(arg0, arg0);
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x5A) != D_80097427) {
        clear_object_slot(arg0, arg0);
    }
}
