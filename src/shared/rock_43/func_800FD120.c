#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AA;

void func_800FD120(void* arg0) {
    s32 g;

    ((void (*)(void*, M2C_UNK))set_animation)(arg0, 6);
    g = D_800970AA;
    if (M2C_FIELD(arg0, s16*, 0xA) < g) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    M2C_FIELD(arg0, u8*, 6)++;
}
