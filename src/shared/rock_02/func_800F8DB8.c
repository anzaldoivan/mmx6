#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */

void func_800F8DB8(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (17/28)
    register void* temp_s1 asm("$17");

    temp_s1 = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())func_80017A04)();
    if ((M2C_FIELD(temp_s1, s8*, 5) == 0xB) &&
        (M2C_FIELD(temp_s1, s8*, 6) >= 7)) {
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, u8*, 0x8D) = 0x28;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
