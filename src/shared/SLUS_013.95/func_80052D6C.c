#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*, void*); /* extern */
extern s8 D_800CCEED;

void func_80052D6C(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    if ((M2C_FIELD(arg0, u8*, 2) & 0xF) == D_800CCEED) {
        func_8002CA14(arg0, arg0);
    }
}
