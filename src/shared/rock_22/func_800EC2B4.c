#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_80097420;

void func_800EC2B4(void* arg0) {
    if (!(D_80097420 & 1)) {
        struct X4_BackgroundObj* bg = D_800971F8;
        M2C_FIELD(bg, u16*, 0x96) = M2C_FIELD(bg, u16*, 0x96) + 1;
    }
    M2C_FIELD(arg0, s16*, 0x7E) = M2C_FIELD(arg0, s16*, 0x7E) - 1;
    if (M2C_FIELD(arg0, s16*, 0x7E) == 0) {
        func_8002943C(0xA, 2, 2);
        M2C_FIELD(arg0, s16*, 0x7E) = 0xA;
    }
    {
        struct X4_BackgroundObj* bg = D_800971F8;
        if (M2C_FIELD(bg, s16*, 0x96) >= -0x1F) {
            func_80016C48(5, 3, arg0);
            M2C_FIELD(bg, s16*, 0x96) = -0x20;
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    }
}
