#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
void func_800F1DA8(void*, s32, s32);
extern s8 D_800CCF5C;

void func_800F0268(void* arg0) {
    s32 q;
    s32 hp;

    if (M2C_FIELD(arg0, s16*, 0x7C)++ >= 0x3C) {
        if (M2C_FIELD(arg0, s16*, 0x86) != 0) {
            M2C_FIELD(arg0, s16*, 0x86)--;
        }
        q = D_800CCF5C / 4;
        hp = M2C_FIELD(arg0, s8*, 0x5C);
        if (q >= hp) {
            M2C_FIELD(arg0, s16*, 0x7E) = 5;
        } else if (D_800CCF5C / 2 >= hp) {
            M2C_FIELD(arg0, s16*, 0x7E) = 4;
        } else if (q * 3 >= hp) {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
        }
        if (M2C_FIELD(arg0, s8*, 0x8A) == 1) {
            func_800F1DA8(arg0, random_byte() & 1, 0);
        } else {
            func_800F1DA8(arg0, 2, 0);
            M2C_FIELD(arg0, s8*, 0x8A) = 1;
        }
        M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
        M2C_FIELD(arg0, s8*, 0x8D)++;
        M2C_FIELD(arg0, s8*, 0x6)++;
    }
}
