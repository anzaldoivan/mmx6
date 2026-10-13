#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F6E48(struct X4_MainObj*);

void func_800F7224(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x88) == 0) {
        func_800F6E48(arg0);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFEB852;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0x147AE;
        }
        M2C_FIELD(arg0, s32*, 0x2C) = 0x4189;
        M2C_FIELD(arg0, s32*, 0x24) = 0x66666;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s16*, 0x88) = 9;
        M2C_FIELD(arg0, u8*, 0x94) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
