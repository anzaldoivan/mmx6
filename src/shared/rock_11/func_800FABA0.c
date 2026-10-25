#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK move_object();
extern u16 D_80097222;
#define D_80097222 (*(s16*)&D_80097222)

void func_800FABA0(void* arg0) {
    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= D_80097222 + 0x110) {
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0xF);
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
#undef D_80097222
