#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80040488(M2C_UNK);
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_80097420;

void func_800F921C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) >= 2) {
        M2C_FIELD(arg0, s8*, 7) = 0;
        D_800971F8[0].unk48 = 2;
        M2C_FIELD(arg0, s16*, 0x7C) = 2;
        D_800971F8[0].unk26 = 0x1F30;
        ((void (*)(s32))func_80040488)(0);
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
    if (!(D_80097420 & 0x3F)) {
        func_80016C48(2, 0x69, arg0);
    }
}
