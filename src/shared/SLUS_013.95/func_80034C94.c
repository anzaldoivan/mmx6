#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80026028(); /* extern */
extern s8 D_80097424;

void func_80034C94(void* arg0) {
    if (D_80097424 != 0) {
        func_80026028();
        return;
    }
    M2C_FIELD(arg0, s8*, 5) = 2;
}
