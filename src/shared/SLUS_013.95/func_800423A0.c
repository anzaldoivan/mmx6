#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_80097420;

void func_800423A0(void* arg0) {
    s16 temp_v1;

    temp_v1 =
        M2C_FIELD(arg0, u16*, 0x86) + (rsin((D_80097420 & 0x7F) << 5) >> 9);
    M2C_FIELD(arg0, s16*, 0xE) = temp_v1;
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        set_animation(arg0, 7);
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
