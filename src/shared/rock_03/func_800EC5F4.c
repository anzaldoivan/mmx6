#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D230(void*);
extern s32 D_800970A8;

void func_800EC5F4(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        s32 x = M2C_FIELD(arg0, s32*, 8);
        M2C_FIELD(arg0, u8*, 6) = 0;
        if (D_800970A8 < x) {
            M2C_FIELD(arg0, s32*, 0x20) = -0x8000;
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            M2C_FIELD(arg0, s32*, 0x20) = 0x8000;
        }
        M2C_FIELD(arg0, u8*, 0x67) = 0;
    } else {
        func_8002D230(arg0);
    }
}
