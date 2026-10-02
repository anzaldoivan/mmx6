#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_801EBF5C(); /* extern */

void func_801EB6E8(void* arg0) {
    func_801EBF5C();
    M2C_FIELD(arg0, s16*, 8) = 0;
    M2C_FIELD(arg0, s16*, 0xC) = 0;
    M2C_FIELD(arg0, s8*, 5) = 0x20;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, u16*, 0xA) =
        (u16)((M2C_FIELD(arg0, u16*, 0xA) & 0xFFF0) + 8);
}
