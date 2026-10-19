#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D2B0(s32);
extern s16 D_80097206;

void func_800F9D24(void* arg0) {
    ((void (*)(s32))func_8002D2B0)((s32)arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= (D_80097206 + 0xAA)) {
        M2C_FIELD(arg0, s16*, 0xE) = (s16)((u16)D_80097206 + 0xAA);
        ((void (*)(void*, s32))func_800179A4)(arg0, 1);
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}
