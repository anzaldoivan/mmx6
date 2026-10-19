#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_80065944(s32);
extern s32 D_80097420;

void func_800423A0(void* arg0) {
    s16 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u16*, 0x86) +
              (func_80065944((D_80097420 & 0x7F) << 5) >> 9);
    M2C_FIELD(arg0, s16*, 0xE) = temp_v1;
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_800179A4(arg0, 7);
        {
            // !FAKE: constants live in the first return register as retail
            register s32 c asm("$2") = 4;
            M2C_FIELD(arg0, s16*, 0x8A) = c;
            c = 0xB4;
            M2C_FIELD(arg0, u16*, 0x7C) = c;
        }
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}
