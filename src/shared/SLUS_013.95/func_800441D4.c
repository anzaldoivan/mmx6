#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();

void func_800441D4(void* arg0) {
    u8* temp_a1;

    ((void (*)())func_80017A04)(arg0);
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        temp_a1 = M2C_FIELD(arg0, u8**, 0x7C);
        temp_a1[0x8D] &= ~(1 << (M2C_FIELD(arg0, s8*, 2) - 1));
        M2C_FIELD(arg0, u8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 5) += 1;
    }
}
