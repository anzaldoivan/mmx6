#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D2B0(s32);
extern s16 D_80097202;

void func_800FA2B0(void* arg0) {
    void* temp_s1;
    s32 v;

    temp_s1 = M2C_FIELD(arg0, void**, 0x7C);
    ((void (*)(void*))func_8002D2B0)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        if (D_80097202 + 0x30 >= M2C_FIELD(arg0, s16*, 0xA)) {
            v = 3;
            M2C_FIELD(temp_s1, s8*, 7) = v;
            goto block_5;
        }
    } else if (M2C_FIELD(arg0, s16*, 0xA) >= D_80097202 + 0x110) {
        v = 3;
        M2C_FIELD(temp_s1, s8*, 7) = v;
    block_5:
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = v;
    }
}
