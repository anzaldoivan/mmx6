#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_8002B2F8(s32);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_8009742C;
extern u8 D_800C4560;
extern s8 D_800CF850;

void func_80050540(void* arg0, void* arg1, void* arg2) {
    s16 i;

    if (M2C_FIELD(arg2, s8*, 0xD4) < 0) {
        M2C_FIELD(arg2, s8*, 0xD4) = -2;
        M2C_FIELD(arg1, s8*, 0x10) = 1;
        M2C_FIELD(arg1, s8*, 0x12) = 1;
        M2C_FIELD(arg2, s32*, 0x68) = 0;
        M2C_FIELD(arg0, s32*, 0x80) = D_800971F8[0].unk47;
        D_800971F8[0].unk47 = 2;
        if (M2C_FIELD(arg0, s8*, 2) == 0x1F) {
            func_8002B2F8(0);
            D_80090D56 = 1;
            D_8009742C = 1;
            D_800CF850 = 1;
            D_80090C90[2] = 0xF;
            for (i = 3; i < 0xF; i++) {
                D_80090C90[i] = -1;
            }
            D_800C4560 |= 1;
            M2C_FIELD(arg0, s16*, 0xA0) = 2;
            D_800971F8[0].unk34 &= 0xF;
            M2C_FIELD(arg0, s8*, 5) = 5;
            return;
        }
        M2C_FIELD(arg0, s8*, 5) = 2;
        func_80016C48(0, 0x10, arg0);
    }
    D_800971F8[0].unk34 &= 0xF;
}
