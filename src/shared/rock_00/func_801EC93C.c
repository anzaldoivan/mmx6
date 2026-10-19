#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003CCBC(void*); /* extern */
extern s8 D_800CCEEC;

void func_801EC93C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        if (M2C_FIELD(arg0, s8*, 0xD0) == 0) {
            M2C_FIELD(arg0, s8*, 0x7A) = 0;
            D_800CCEEC = 0;
        }
        M2C_FIELD(arg0, s8*, 0xE0) = 0;
        ((void (*)(void*))func_8003CCBC)(arg0);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
