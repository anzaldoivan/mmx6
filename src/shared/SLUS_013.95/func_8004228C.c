#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_8004228C(void* arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 0x2);
    if (temp_v1 == 0x31) {
        func_800179A4(arg0, 7);
        {
            // !FAKE: constant lives in the first return register as retail
            register s32 c asm("$2") = 4;
            M2C_FIELD(arg0, s16*, 0x8A) = c;
        }
    } else if (temp_v1 == 0x32) {
        func_800179A4(arg0, 8);
        {
            // !FAKE: constant lives in the first return register as retail
            register s32 c asm("$2") = 0xC8;
            M2C_FIELD(arg0, s16*, 0x8A) = c;
        }
    } else {
        func_800179A4(arg0, 6);
        {
            // !FAKE: constant lives in the first return register as retail
            register s32 c asm("$2") = 8;
            M2C_FIELD(arg0, s16*, 0x8A) = c;
        }
    }
    M2C_FIELD(arg0, s32*, 0x24) = 0x80000;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0x8000;
    M2C_FIELD(arg0, u16*, 0x86) = M2C_FIELD(arg0, u16*, 0xE);
    M2C_FIELD(arg0, u8*, 0x6) += 1;
}
