#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);   /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern s16 D_80097222;
extern s32 D_80097420;

void func_800ED860(void* arg0) {
    if (!(D_80097420 & 3)) {
        func_80029478(3, 2, 1);
    }
    if (!(D_80097420 & 0x1F)) {
        func_80016C48(2, 3, arg0);
    }
    M2C_FIELD(arg0, s32*, 0xC) = (s32)(M2C_FIELD(arg0, s32*, 0xC) + 0xFFFF0000);
    if ((D_80097222 + 0xC0) >= M2C_FIELD(arg0, s16*, 0xE)) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
