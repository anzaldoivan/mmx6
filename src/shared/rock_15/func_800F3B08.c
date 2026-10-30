#include "common.h"
#define M2C_UNK s32

#define F(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800F3B08(void* arg0) {
    ((void (*)())func_80017A04)();
    if (--F(arg0, s16*, 0x8C) == 0) {
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 6);
        F(arg0, u8*, 5) = 1;
        F(arg0, u8*, 6) = 0;
    }
}
