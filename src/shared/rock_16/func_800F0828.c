#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800328B0(void*, void*); /* extern */
extern s8 D_800CCEFC;

void func_800F0828(void* arg0) {
    if (D_800CCEFC == 2) {
        M2C_FIELD(arg0, s16*, 0x38) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
    func_800328B0(arg0, arg0);
}
