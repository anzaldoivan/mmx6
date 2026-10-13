#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800F3E10(void*, M2C_UNK); /* extern */

void func_800F2CE8(void* arg0) {
    M2C_FIELD(arg0, u8*, 7) = 0;
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 7) = 6;
        func_800F3E10(arg0, 0x45);
        func_800F3E10(arg0, 0x46);
        func_800F3E10(arg0, 0x47);
        func_800F3E10(arg0, 0x48);
        func_800F3E10(arg0, 0x49);
        {
            // !FAKE: depin: dropping it breaks the match (30/35)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6);
            M2C_FIELD(arg0, s16*, 0x7C) = 0x4B;
            M2C_FIELD(arg0, u8*, 6) = t + 1;
        }
    }
}
