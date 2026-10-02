#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CB50(); /* extern */
extern s8 D_800CCEF6;

void func_800EDCC0(void* arg0) {
    if (D_800CCEF6 != 0) {
        func_8002CB50();
        return;
    }
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
