#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(s32);
extern s16 D_80097222;

void func_800F588C(void* arg0) {
    ((void (*)(s32))move_object)((s32)arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= D_80097222 + 0x70) {
        M2C_FIELD(arg0, s16*, 0xE) = D_80097222 + 0x70;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x40000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFC0000;
        }
        M2C_FIELD(arg0, s32*, 0x28) = 0x100;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
