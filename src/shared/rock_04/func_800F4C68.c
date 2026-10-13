#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
extern s16 D_80090D5C;
extern s16 D_80097430;
extern u8 D_800C4560;
extern s16 D_800CF854;

void func_800F4C68(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == -1) {
        M2C_FIELD(arg0, s16*, 0x7C) = 3;
        D_800CF854--;
        D_80097430 -= 0x20;
        D_80090D5C -= 0x400;
        D_800C4560 |= 1;
        if (!(D_800CF854 & 0xFFFF)) {
            ((void (*)(s32, s32, void*))func_80016C48)(2, 0x10, arg0);
            ((void (*)(void*, s32))func_800179A4)(arg0, 8);
            M2C_FIELD(arg0, u8*, 6)++;
        }
    }
}
