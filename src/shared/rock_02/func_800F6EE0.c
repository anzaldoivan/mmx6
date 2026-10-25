#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
M2C_UNK func_800F82C0();

void func_800F6EE0(void* arg0) {
    func_800F82C0(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (17/24)
        register s32 temp_v0 asm("$2") = M2C_FIELD(arg0, u16*, 0x7C);
        M2C_FIELD(arg0, u16*, 0x7C) = temp_v0 + 1;
        if ((s16)temp_v0 < 0x1F) {
            return;
        }
    }
    {
        // !FAKE: depin: dropping it breaks the match (21/24)
        register s32 temp_b asm("$2");
        func_800179A4(arg0, 0x13);
        temp_b = M2C_FIELD(arg0, u8*, 6);
        M2C_FIELD(arg0, u8*, 6) = temp_b + 1;
    }
}
