#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */
void func_800F4144(void);
extern s16 D_800F9868;

void func_800F6118(void* arg0) {
    if (D_800F9868 == 0) {
        func_80016C48(2, 0x61, arg0);
        M2C_FIELD(arg0, u8*, 0x3) = 1;
        ((void (*)(void*))func_800F4144)(arg0);
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x22);
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}
