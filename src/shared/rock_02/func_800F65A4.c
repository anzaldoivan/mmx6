#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0(); /* extern */
extern u8 D_8008EAFC;
extern s8 D_800CCEDF;

void func_800F65A4(void* arg0) {
    if (D_8008EAFC == 0) {
        D_800CCEDF = 0x40;
        M2C_FIELD(arg0, s8*, 3) = 0;
        func_8002C9B0();
    }
}
