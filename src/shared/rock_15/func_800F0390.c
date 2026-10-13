#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();
void func_800F1DA8(void*, s32, s32);
extern u8 D_800F6DF8[];

void func_800F0390(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x86) != 0) {
        M2C_FIELD(arg0, s16*, 0x86)--;
        if (M2C_FIELD(arg0, s8*, 0x8D) < 3) {
            if (M2C_FIELD(arg0, s8*, 0x8A) == 1) {
                if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
                    M2C_FIELD(arg0, s16*, 0x7C)--;
                    return;
                }
                func_800F1DA8(arg0, func_8002D2D4() & 1, 0);
                M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
            } else {
                if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
                    M2C_FIELD(arg0, s16*, 0x7C)--;
                    return;
                }
                func_800F1DA8(arg0, 2, 0);
                M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
                M2C_FIELD(arg0, s8*, 0x8A) = 1;
            }
            M2C_FIELD(arg0, s8*, 0x8D)++;
        }
    } else {
        s8 t = ++M2C_FIELD(arg0, s8*, 0x89);
        u8 v = D_800F6DF8[t + M2C_FIELD(arg0, s8*, 0x88) * 4];
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = v;
    }
}
