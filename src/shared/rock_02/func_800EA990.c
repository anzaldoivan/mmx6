#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define A990_SP64 (*(u8**)(0x1F800064))

M2C_UNK func_800179A4(void*, M2C_UNK);

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800EA990(void* arg0) {
    s8 temp_s1;

    F(u8, 0x15) = 0;
    *(s16*)(A990_SP64 + 0x56) = 0;
    temp_s1 = F(s8, 0x2);
    switch (temp_s1) {
    case 0:
        F(u8, 0x16) = 0x20;
        ((void (*)(void*, s32))func_800179A4)(arg0, 1);
        F(u8, 0x3) = 1;
        F(u8, 0x5) = 0;
        break;
    case 1:
        F(u8, 0x16) = 0x20;
        ((void (*)(void*, s32))func_800179A4)(arg0, 2);
        F(u8, 0x3) = 0;
        F(u8, 0x5) = temp_s1;
        break;
    }
    F(s32, 0x20) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x2C) = 0;
    F(u8, 0x4) = 1;
}
