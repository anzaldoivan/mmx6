#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800328B0(void*, void*); /* extern */
extern s8 D_800CCEFC;

void func_800F086C(void* arg0) {
    s32 v;
    s32 q;
    s32 t;
    s32 n;

    n = M2C_FIELD(arg0, u16*, 0x38) + 1;
    M2C_FIELD(arg0, u16*, 0x38) = n;
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        t = (s16)n * 0x9C / 16;
        M2C_FIELD(arg0, s16*, 0x2E) = t;
        M2C_FIELD(arg0, s16*, 0x16) = t;
    } else {
        v = (s16)n * 0x9C;
        q = v >> 4;
        if (v < 0) {
            q = (v + 15) >> 4;
        }
        t = 0x138 - q;
        M2C_FIELD(arg0, s16*, 0x26) = t;
        M2C_FIELD(arg0, s16*, 0x1E) = t;
    }
    if (M2C_FIELD(arg0, s16*, 0x38) >= 0x10) {
        D_800CCEFC = 0;
        M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
    }
    ((void (*)())func_800328B0)(arg0);
}
