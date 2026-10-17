#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F4E20(u8* arg0, u8 arg1, s16 arg2, s16 arg3);

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800F47B8(void* arg0) {
    s16 i;
    s16 j;

    if (++F(s16, 0x88) == 0x10) {
        F(u8, 0x3) = 0;
        F(u8, 0x4)++;
        return;
    }
    j = 0x27;
    for (i = 0; i < (0xF - F(s16, 0x88)) / 4; i++) {
        j -= 2;
        if (j >= 0) {
            func_800F4E20(arg0, 3, j, 1);
        }
    }
}
