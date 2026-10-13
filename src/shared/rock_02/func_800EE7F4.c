#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s32 D_800970A8;
extern s8 D_80097244;
extern u8 D_800FB218[];

void func_800EE7F4(void* arg0) {
    s32 base;
    s32 t;

    func_80027BA0(0, 0x17B0, 0xD0, D_800FB218);
    func_80027BA0(0, 0x1930, 0xD0, D_800FB218 + 0x10);
    D_80097244 = 1;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x7F;
    M2C_FIELD(arg0, s16*, 0x7E) = 0x19;
    M2C_FIELD(arg0, u8*, 0x61) = 0x19;
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    t = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
    base = SPAD20;
    t = *(s32*)(t * 4 + base);
    M2C_FIELD(arg0, s32*, 0x3C) = base + t;
    func_800179A4(arg0, 0);
    M2C_FIELD(arg0, s32*, 0x24) = -0x4000;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    {
        // !FAKE: depin: dropping it breaks the match (59/68)
        register s32 c asm("$2") = M2C_FIELD(arg0, u8*, 5) + 1;
        M2C_FIELD(arg0, u8*, 5) = c;
    }
    {
        s32 g = D_800970A8;
        if (M2C_FIELD(arg0, s32*, 8) < g) {
            func_8003D308(0x14, 0);
        } else {
            func_8003D308(0x14, 0x40);
        }
    }
    func_8002CCB0(arg0, 0xA0, 0xA0);
}
