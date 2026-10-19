#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80064C94(M2C_UNK*, u32);
extern u32 D_80070CC0;
extern s8 D_800CC869;
extern M2C_UNK D_800E2F3C;

void func_8001B984(s32 arg0) {
    u8 v;
    u32 t;

    D_800CC869 = arg0;
    if ((u8)arg0 != 0) {
        u8 l;
        M2C_FIELD(&D_800E2F3C, s8*, 0) = l = D_80070CC0;
        v = l;
        M2C_FIELD(&D_800E2F3C, s8*, 1) = 0;
        M2C_FIELD(&D_800E2F3C, s8*, 2) = v;
        M2C_FIELD(&D_800E2F3C, s8*, 3) = 0;
    } else {
        M2C_FIELD(&D_800E2F3C, s8*, 0) = t = D_80070CC0 >> 1;
        M2C_FIELD(&D_800E2F3C, s8*, 1) = t;
        M2C_FIELD(&D_800E2F3C, s8*, 2) = t;
        M2C_FIELD(&D_800E2F3C, s8*, 3) = t;
    }
    func_80064C94(&D_800E2F3C, v);
}
