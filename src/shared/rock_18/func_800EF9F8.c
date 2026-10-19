#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800CCEDA;

void func_800EF9F8(void* arg0) {
    M2C_FIELD(arg0, u8*, 3) = 1;
    if (D_800CCEDA != 0) {
        M2C_FIELD(arg0, s16*, 0xA) = 0x90;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) = 0x40;
    }
    if (M2C_FIELD(arg0, u8*, 2) == 0xBE) {
        M2C_FIELD(arg0, s16*, 0xE) = 0x64;
        return;
    }
    M2C_FIELD(arg0, s16*, 0xE) = 0xD4;
}
