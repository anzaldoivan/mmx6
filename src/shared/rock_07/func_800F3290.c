#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
void func_800F6D4C(void*, s32);
extern u8 D_800CCF5F;
extern u8 D_800E9A7C[];
extern s16 D_800F986A;

void func_800F3290(void* arg0) {
    s8 tbl[4];
    s8 n;
    s32 step;
    s16 ang;
    s16 i;

    __builtin_memcpy((u8*)tbl, (u8*)D_800E9A7C, 4);
    if (M2C_FIELD(arg0, s16*, 0x7E) != 0) {
        M2C_FIELD(arg0, s16*, 0x7E)--;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        n = tbl[D_800CCF5F];
        M2C_FIELD(arg0, u8*, 7) = 0;
        D_800F986A = 0;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            ang = 0xBE2;
            step = -0x3C4 / (n - 1);
        } else {
            ang = 0xC1E;
            step = 0x3C4 / (n - 1);
        }
        play_sound(2, 0x64, arg0);
        for (i = 0; i < n; i++) {
            func_800F6D4C(arg0, ang);
            ang += step;
        }
        M2C_FIELD(arg0, s16*, 0x86) = D_800F986A;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
