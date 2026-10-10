#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_80097427;
extern u8 D_800F1024[][3];

void func_800F0438(void* arg0) {
    u8 v;
    u8 b;

    v = M2C_FIELD(arg0, u8*, 0x57);
    M2C_FIELD(arg0, u8*, 3) = 1;
    if (v != 0) {
        if ((v - 1) == D_80097427) {
            M2C_FIELD(arg0, s16*, 0x42) = 0x78C6;
            return;
        }
        b = D_800F1024[M2C_FIELD(arg0, u8*, 2)][1];
        M2C_FIELD(arg0, s16*, 0x42) = (b & 0xF) | (((b >> 4) + 0x1E0) << 6);
    }
}
