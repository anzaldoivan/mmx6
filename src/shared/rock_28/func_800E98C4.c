#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(void*, void*); /* extern */
extern u16 D_80097214;
extern s8 D_800CCEED;

void func_800E98C4(void* arg0) {
    if (D_800CCEED == 1) {
        clear_object_slot(arg0, arg0);
        return;
    }
    M2C_FIELD(arg0, u16*, 0x14) = (u16)D_80097214;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}
