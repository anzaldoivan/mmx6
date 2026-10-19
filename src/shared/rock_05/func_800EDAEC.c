#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_80097420;
extern u16 D_800F3F0C[];

void func_800EDAEC(void* arg0) {
    if ((u32)D_80097420 == (u32)D_80097420 / 10 * 10) {
        M2C_FIELD(arg0, u8*, 0x92) = (M2C_FIELD(arg0, u8*, 0x92) + 1) & 3;
        if (M2C_FIELD(arg0, s16*, 0xA) == 0xCE0) {
            D_800971F8[2].unk40 =
                D_800F3F0C[M2C_FIELD(arg0, u8*, 0x92)] - 0xCA0;
        } else {
            D_800971F8[2].unk40 =
                D_800F3F0C[M2C_FIELD(arg0, u8*, 0x92)] - 0xB20;
        }
    }
    D_800971F8[2].unk4C = 1;
}
