#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);   /* extern */

void func_800FC67C(void* arg0) {
    if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
        func_80021760(3, 0xFF, 0);
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
    func_8002CCB0(arg0, 0x40, 0x40);
}
