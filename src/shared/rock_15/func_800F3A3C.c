#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();

void func_800F3A3C(void* arg0) {
    func_80017A04();
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        // !FAKE: pin the counter to the second return register so its load schedules first
        register s32 c asm("$3") = M2C_FIELD(arg0, u8*, 0x6);
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFE0000;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x2000;
        M2C_FIELD(arg0, u8*, 0x6) = c + 1;
    }
}
