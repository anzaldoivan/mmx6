#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0();            /* extern */
M2C_UNK func_8003D308(M2C_UNK, u8); /* extern */
extern u8 D_800970B5;

void func_800F8E60(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 3) {
        func_8002C9B0();
        return;
    }
    func_8003D308(0x14, D_800970B5);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x7F;
    M2C_FIELD(arg0, s16*, 0x7E) = 0x19;
    M2C_FIELD(arg0, s8*, 0x61) = 0x19;
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, s8*, 5) = 1;
}
