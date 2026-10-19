#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F3E10(void* arg0, s32 arg1); /* extern */
extern s8 D_800FD51B;

void func_800F2A70(void* arg0) {
    M2C_FIELD(arg0, u8*, 7) = 0;
    if (D_800FD51B == -3) {
        M2C_FIELD(arg0, u8*, 7) = 6;
        func_800F3E10(arg0, 0x36);
        func_800F3E10(arg0, 0x37);
        func_800F3E10(arg0, 0x38);
        func_800F3E10(arg0, 0x39);
        func_800F3E10(arg0, 0x3A);
        func_800F3E10(arg0, 0x3B);
        M2C_FIELD(arg0, s16*, 0x7C) = 0xB4;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
