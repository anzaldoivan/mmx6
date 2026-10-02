#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */

void func_80043038(void* arg0) {
    s32 temp_v1;

    M2C_FIELD(arg0, s8*, 3) = 0;
    temp_v1 = M2C_FIELD(arg0, s8*, 2) & 0xF0;
    M2C_FIELD(arg0, s8*, 0x16) = 3;
    switch (temp_v1) { /* irregular */
    case 0:
        func_800179A4(arg0, 0);
        M2C_FIELD(arg0, s8*, 5) = 0;
        break;
    case 16:
        M2C_FIELD(arg0, s8*, 0x16) = 1;
        func_800179A4(arg0, 3);
        M2C_FIELD(arg0, s8*, 5) = 1;
        break;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s8*, 4) = 1;
    M2C_FIELD(arg0, s8*, 6) = 0;
}
