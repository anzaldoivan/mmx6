#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0(); /* extern */
extern s8 D_800CCEED;

void func_800EDD3C(void* arg0) {
    if (D_800CCEED == 0) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    ((M2C_UNK(*)())func_8002C9B0)();
}
