#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_800FCA84;

void func_800FB6F0(void* arg0) {
    u8 t;
    u8* p;
    s32 i;

    if (M2C_FIELD(arg0, u8*, 0x89) == 0) {
        p = (u8*)&D_800FCA84 + 0x28C;
        i = M2C_FIELD(arg0, u8*, 0x8B) + M2C_FIELD(arg0, u8*, 0x8A) * 6;
        t = p[i];
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 0x8B)++;
        M2C_FIELD(arg0, u8*, 5) = t;
        return;
    }
    M2C_FIELD(arg0, u8*, 0x89)--;
}
