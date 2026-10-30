#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_800F82C0();

void func_800F6810(void* arg0) {
    func_800F82C0();
    func_80017A04(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (19/26)
        register s32 temp_v0 asm("$2") = M2C_FIELD(arg0, u16*, 0x7C);
        M2C_FIELD(arg0, u16*, 0x7C) = temp_v0 + 1;
        if ((s16)temp_v0 < 0x5B) {
            return;
        }
    }
    {
        ((void (*)(void*, s32))set_animation)(arg0, 9);
        M2C_FIELD(arg0, u16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
