#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800FCA84;

#define CUR (*(u8**)((u8*)&D_800FCA84 + 0x3DC))

void func_800FC8CC(void* arg0) {
    u8* p = CUR;
    s32 x;
    u8 t;
    // !FAKE: pin keeps the reloaded base in the first return register
    register u8* q asm("$2");
    u16 e;
    u8 b;

    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(p, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    x = M2C_FIELD(p, s32*, 0x3C);
    M2C_FIELD(arg0, u8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 0x16) = 1;
    q = CUR;
    M2C_FIELD(arg0, s32*, 0x3C) = x;
    t = M2C_FIELD(q, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    M2C_FIELD(arg0, u8*, 0x15) = t;
    set_animation(arg0, 0xE);
    q = CUR;
    b = M2C_FIELD(arg0, u8*, 0x4) + 1;
    e = M2C_FIELD(q, u16*, 0xE);
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 8;
    M2C_FIELD(arg0, s32*, 0x8C) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = b;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, s16*, 0xE) = e - 0x36;
}
#undef CUR
