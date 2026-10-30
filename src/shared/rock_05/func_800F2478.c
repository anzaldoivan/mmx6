#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
extern s32 D_80074FBC;
extern s32 D_800F414C;
extern s32 D_800F4154;
extern s32 D_800F42B4;
extern u16 D_800F447E;
extern s16 D_800F4480;

void func_800F2478(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (55/58)
    register s32 var_v0 asm("$2");
    u16 e;

    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(SCRATCH_4C, u16*, 0x84);
    {
        s32 t = M2C_FIELD(SCRATCH_4C, s32*, 0x8C);
        M2C_FIELD(arg0, u16*, 0x40) = 0x140;
        M2C_FIELD(arg0, void**, 0x30) = &D_800F42B4;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F414C;
        M2C_FIELD(arg0, void**, 0x50) = &D_800F4154;
        M2C_FIELD(arg0, void**, 0x58) = &D_80074FBC;
        M2C_FIELD(arg0, s32*, 0x3C) = t;
    }
    if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        var_v0 = D_800F447E + 0x1140;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        var_v0 = D_800F447E + 0x1040;
    }
    M2C_FIELD(arg0, s16*, 0xA) = var_v0;
    e = D_800F4480;
    {
        // !FAKE: depin: dropping it breaks the match (50/58)
        register s32 k asm("$4") = 0xFFFB0000;
        M2C_FIELD(arg0, s32*, 0x24) = k;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s16*, 0xE) = e + 0x380;
    set_animation(arg0, 4);
    {
        // !FAKE: depin: dropping it breaks the match (55/58)
        register s32 c asm("$2") = M2C_FIELD(arg0, u8*, 0x6) + 1;
        M2C_FIELD(arg0, u8*, 0x6) = c;
    }
}
