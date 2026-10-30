#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_800741FC;
extern M2C_UNK D_800F5E88;
extern M2C_UNK D_800F5E8C;

void func_800EA448(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
    M2C_FIELD(arg0, s32*, 0x2C) = 0x3000;
    M2C_FIELD(arg0, void**, 0x68) = &D_800F5E88;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F5E8C;
    M2C_FIELD(arg0, void**, 0x58) = &D_800741FC;
    M2C_FIELD(arg0, void**, 0x50) = &D_800F5E8C;
    {
        // !FAKE: depin: dropping it breaks the match (25/35)
        register s32 one asm("$5") = 1;
        M2C_FIELD(arg0, u8*, 0x3) = one;
        {
            // !FAKE: depin: dropping it breaks the match (29/35)
            register s32 k asm("$3") = 5;
            M2C_FIELD(arg0, u8*, 0x60) = k;
        }
        M2C_FIELD(arg0, u8*, 0x5C) = one;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = (u8)(M2C_FIELD(arg0, u8*, 0x4) + 1);
    M2C_FIELD(arg0, u16*, 0x42) = (u16)(M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF);
    set_animation(arg0, 2);
}
