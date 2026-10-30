#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8003D330();                     /* extern */
extern s32 D_80097420;

void func_800ED6E8(void* arg0) {
    s8 kind;

    if (--M2C_FIELD(arg0, s16*, 0x7E) == 0) {
        play_sound(0, 0xE, 0);
        M2C_FIELD(arg0, u16*, 0x7E) = 3;
    }
    if (!(D_80097420 & 1)) {
        if ((s8)++M2C_FIELD(arg0, u8*, 0x5C) == 0x7F) {
            func_8003D330();
            kind = M2C_FIELD(arg0, s8*, 0x2);
            if (kind == 4) {
                M2C_FIELD(arg0, u8*, 0x5) = 2;
            } else if (kind == 5) {
                M2C_FIELD(arg0, u8*, 0x5) = 3;
            } else if (kind == 6) {
                M2C_FIELD(arg0, u8*, 0x5) = 4;
            } else if (kind == 7) {
                M2C_FIELD(arg0, u8*, 0x5) = 5;
            } else if (kind == 0xA) {
                M2C_FIELD(arg0, u8*, 0x5) = 7;
            }
            M2C_FIELD(arg0, u8*, 0x6) = 0;
        }
    }
}
