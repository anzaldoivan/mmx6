#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();

void func_800F9DA4(void* arg0) {
    void* s0;

    s0 = M2C_FIELD(arg0, void**, 0x84);
    ((void (*)())func_80017A04)();
    if ((M2C_FIELD(arg0, s8*, 7) != 0) ||
        (M2C_FIELD(s0, u8*, 0x8D) == (M2C_FIELD(arg0, s8*, 2) + 2))) {
        M2C_FIELD(arg0, u8*, 6)++;
        M2C_FIELD(s0, u8*, 0x9A)++;
    }
}
