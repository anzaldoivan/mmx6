#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EF6B8 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s16 D_800970AA;
extern s32 D_800FB28C;
extern void* D_800FBC78;

void func_800EF6B8(void* arg0) {
    void* p;
    s32 base;
    s32 idx;
    void* g;
    s32* f;

    p = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(p, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(arg0, u8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 0x16) = 4;
    f = &D_800FB28C;
    M2C_FIELD(arg0, u8*, 0x15) = M2C_FIELD(p, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    g = D_800FBC78;
    M2C_FIELD(arg0, s32**, 0x68) = f;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    idx = func_8002A47C(M2C_FIELD(g, s8*, 1));
    base = SPAD20_800EF6B8;
    M2C_FIELD(arg0, s32*, 0x3C) = base + *(s32*)(idx * 4 + base + 4);
    set_animation(arg0, 0x13);
    {
        // !FAKE: depin: dropping it breaks the match (81/83)
        register s32 c asm("$2") = M2C_FIELD(arg0, u8*, 0x15);
        if (c == 0) {
            M2C_FIELD(arg0, s16*, 0xA) =
                M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), u16*, 0xA) - 0x38;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) =
                M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), u16*, 0xA) + 0x38;
        }
    }
    M2C_FIELD(arg0, s16*, 0xE) =
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), u16*, 0xE) - 0x18;
    M2C_FIELD(arg0, s32*, 0x20) = (D_800970AA - M2C_FIELD(arg0, s16*, 0xA))
                                  << 11;
    M2C_FIELD(arg0, s32*, 0x2C) = 0x4000;
    M2C_FIELD(arg0, u8*, 0x60) = 6;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = M2C_FIELD(arg0, u8*, 0x4) + 1;
}
