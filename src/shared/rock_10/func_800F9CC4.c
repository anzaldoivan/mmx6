#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_80097202;
#define D_80097202 (*(u16*)&D_80097202)

void func_800F9CC4(void* arg0) {
    void* temp_a1;
    s32 e;

    temp_a1 = M2C_FIELD(arg0, void**, 0x80);
    if (M2C_FIELD(temp_a1, s8*, 7) == 3) {
        s32 x = (M2C_FIELD(temp_a1, u16*, 0xA) - D_80097202) - 0x140;
        M2C_FIELD(arg0, s16*, 0xA) = D_80097202 - x;
        e = M2C_FIELD(temp_a1, u16*, 0xE);
        M2C_FIELD(arg0, u8*, 5) = M2C_FIELD(arg0, u8*, 5) + 1;
        M2C_FIELD(arg0, s16*, 0xE) = e;
    }
}

#undef D_80097202
