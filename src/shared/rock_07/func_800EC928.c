#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define W(p, o) M2C_FIELD(p, s32*, o)

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800EC928(void* arg0) {
    ((void (*)(void*, s32))func_800179A4)(arg0, 1);
    B(W(arg0, 0x80), 0x7) = 0;
    B(arg0, 0x6) = 0;
}
