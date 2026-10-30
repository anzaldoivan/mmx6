#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800FCA84;

void func_800FB9F8(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x7) == 0) {
        u8* p;
        s32 t;
        s32 x;
        set_animation(arg0, 1);
        p = ((u8*)&D_800FCA84 + 0x28C);
        t = (u8)M2C_FIELD(arg0, u8*, 0x8B)++;
        x = M2C_FIELD(arg0, u8*, 0x8A) * 6;
        M2C_FIELD(arg0, u8*, 0x5) = p[t + x];
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
}
