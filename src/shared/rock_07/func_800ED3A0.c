#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800ECD7C(s32, M2C_UNK, M2C_UNK); /* extern */

void func_800ED3A0(void* arg0) {
    M2C_FIELD(arg0, u8*, 3) = 1;
    switch (M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 0x90)) {
    case 0:
        func_800ECD7C(arg0 + 0x86, 0x40, 2);
        break;
    case 1:
        func_800ECD7C(arg0 + 0x86, -0x40, 2);
        break;
    case 2:
        func_800ECD7C(arg0 + 0x86, -0x40, 4);
        break;
    }
}
