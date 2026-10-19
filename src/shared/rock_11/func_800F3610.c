#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F4254(void* arg0, u8 arg1);
M2C_UNK func_800F4534(void*, M2C_UNK);
extern s8 D_800FD51B;
extern s8 D_800FD51E;

void func_800F3610(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        D_800FD51E = 0;
        D_800FD51B = 0;
        func_800F4254(arg0, 0x20);
        ((void (*)(void*, M2C_UNK))func_800F4534)(arg0, 0);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) - 1);
    }
}
