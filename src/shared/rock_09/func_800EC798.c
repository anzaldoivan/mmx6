#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
extern u8 D_800F4BF0[];

void func_800EC798(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (35/63)
    register s32 r asm("$16");
    s32 t;
    // !FAKE: depin: dropping it breaks the match (60/63)
    register s32 tbl asm("$5");
    // !FAKE: depin: dropping it breaks the match (58/63)
    register s32 v asm("$4");

    set_animation(arg0, 3);
    r = random_byte();
    t = random_byte();
    tbl = (s32)(D_800F4BF0 + 0x132C);
    v = ((s32*)tbl)[(M2C_FIELD(arg0, u8*, 0x15) >> 6) & 1];
    M2C_FIELD(arg0, s32*, 0x20) = v;
    r = ((r << 8) + t) & 0xFFFF;
    if (random_byte() & 1) {
        M2C_FIELD(arg0, s32*, 0x20) += r;
    } else {
        M2C_FIELD(arg0, s32*, 0x20) -= r;
    }
    M2C_FIELD(arg0, s32*, 0x28) = -0x1000;
    M2C_FIELD(arg0, s32*, 0x24) = 0x18000;
    M2C_FIELD(arg0, void**, 0x50) = D_800F4BF0 + 0x1314;
    M2C_FIELD(arg0, s32*, 0x88) = 1;
    if (M2C_FIELD(arg0, s8*, 0x2) == 2) {
        M2C_FIELD(arg0, s16*, 0x7C) = random_byte() & 0x3F;
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    } else {
        M2C_FIELD(arg0, u8*, 0x6) += 2;
    }
}
