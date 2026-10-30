#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
extern s8 D_800CCF5C;
extern u8 D_800F6DF8[];

void func_800F04A0(void* arg0) {
    u32 r;

    r = random_byte() & 0xF;
    if (D_800CCF5C / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
        if (r < 6) {
            M2C_FIELD(arg0, s8*, 0x88) = 0;
            M2C_FIELD(arg0, s8*, 0x8C)++;
        } else {
            if (r < 11) {
                M2C_FIELD(arg0, s8*, 0x88) = 1;
            } else {
                M2C_FIELD(arg0, s8*, 0x88) = 2;
            }
            M2C_FIELD(arg0, s8*, 0x8C) = 0;
        }
        if (M2C_FIELD(arg0, s8*, 0x8C) >= 3 ||
            M2C_FIELD(arg0, s8*, 0x8D) >= 0x28) {
            M2C_FIELD(arg0, s8*, 0x88) = 1;
        }
    } else {
        if (r < 3) {
            M2C_FIELD(arg0, s8*, 0x88) = 0;
            M2C_FIELD(arg0, s8*, 0x8C)++;
        } else {
            if (r < 6) {
                M2C_FIELD(arg0, s8*, 0x88) = 3;
            } else if (r < 9) {
                M2C_FIELD(arg0, s8*, 0x88) = 4;
            } else if (r < 12) {
                M2C_FIELD(arg0, s8*, 0x88) = 5;
            } else {
                M2C_FIELD(arg0, s8*, 0x88) = 6;
            }
            M2C_FIELD(arg0, s8*, 0x8C) = 0;
        }
        if (M2C_FIELD(arg0, s8*, 0x8C) >= 3 ||
            M2C_FIELD(arg0, s8*, 0x8D) >= 0x28) {
            M2C_FIELD(arg0, s8*, 0x88) = 3;
        }
    }
    M2C_FIELD(arg0, s8*, 0x89) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = D_800F6DF8[M2C_FIELD(arg0, s8*, 0x88) * 4];
    M2C_FIELD(arg0, s8*, 0x6) = 0;
}
