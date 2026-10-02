#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003B114(s32); /* extern */
M2C_UNK func_8003CCBC(void*); /* extern */
extern s8 D_800CCEEC;

void func_801ECC38(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x99) == 0) {
        M2C_FIELD(arg0, s8*, 0xE0) = 0;
        if (M2C_FIELD(arg0, s8*, 0xD3) == 0) {
            D_800CCEEC = 0;
            M2C_FIELD(arg0, s8*, 0x7A) = 0;
        }
        func_8003CCBC(arg0);
        func_8003B114(arg0);
    }
}
