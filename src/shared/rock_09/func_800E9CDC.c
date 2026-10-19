#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800F4BF0[];

s32 func_800E9CDC(void* arg0) {
    s32 t;
    s32 i;
    s32 r;

    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        t = (s32)(D_800F4BF0 + 0x7F0);
        i = M2C_FIELD(arg0, u8*, 0x17);
        r = *(u8*)(i + t);
    } else {
        t = (s32)(D_800F4BF0 + 0x880);
        i = M2C_FIELD(arg0, u8*, 0x17);
        r = *(u8*)(i + t);
    }
    return r == 1;
}
