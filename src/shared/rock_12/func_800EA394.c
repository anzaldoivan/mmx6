#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern u8 D_800CCF99;
extern u8 D_800CD40C;

void func_800EA394(void* arg0) {
    if (!(D_800CCF99 & 0x10) || (D_800CD40C == 2)) {
        ((void (*)(M2C_UNK, M2C_UNK, M2C_UNK))open_text_box)(
            M2C_FIELD(arg0, u16*, 8), 0xFF, 0);
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) + 1);
    }
}
