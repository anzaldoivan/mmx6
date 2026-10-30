#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD9C_800F5C34 (*(s32**)0x1F80009C)

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007569C;
extern u8 D_800970B4;
extern u16 D_800CCEDC;
#define D_800CCEDC (*(s8*)&D_800CCEDC)
extern s32 D_800FCED8;
extern s32 D_800FD278;
extern u8 D_800FDA78[];
extern u16 D_800FDA7C;
extern u16 D_800FDA7E;
extern u32 D_800FDA84;

#define P(type, off) M2C_FIELD(arg0, type*, off)

void func_800F5C34(void* arg0) {
    s32 t;
    s32 b;

    if (D_800CCEDC == 0xC) {
        s32* sp = SPAD9C_800F5C34;
        s32 n = *sp;
        P(u16, 0x42) = 0x7948;
        P(u8*, 0x3C) = (u8*)sp + n;
    }
    P(u8, 0x5C) = 0;
    P(u8, 0x60) = 6;
    P(void*, 0x58) = &D_8007569C;
    P(u8, 0x61) = 0;
    P(u8, 0x3) = 0;
    b = D_800970B4;
    P(s32, 0x20) = 0;
    P(s32, 0x24) = 0;
    P(s32, 0x28) = 0;
    P(s32, 0x2C) = 0;
    P(u8, 0x67) = 0;
    P(void*, 0x30) = &D_800FD278;
    P(u8, 0x16) = 5;
    P(s32, 0x50) = 0;
    P(s32, 0x54) = 0;
    P(s32, 0x68) = 0;
    t = P(s8, 0x2) & 0xF0;
    P(u8, 0x14) = b;
    if (t == 0) {
        P(u16, 0x40) = 0x140;
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        P(s8, 0x86) = -1;
        P(u8, 0x87) = 0;
        P(u8, 0x88) = 0;
        P(u8, 0x8A) = 0;
        P(u8, 0x8B) = 0;
        P(u8, 0x8C) = 0;
        P(u8, 0x8D) = 0;
        P(u8, 0x8E) = 0;
        P(void*, 0x68) = &D_800FCED8;
        if (!(P(u8, 0x2) & 0xF)) {
            P(u8, 0x15) = 0;
            D_800FDA78[0] = 0;
            D_800FDA78[1] = 0;
            D_800FDA78[2] = 0;
            D_800FDA7C = 0;
            D_800FDA7E = 0;
            D_800FDA84 = 0;
            P(u8, 0x4) = 1;
            P(u8, 0x5) = 2;
        } else {
            P(u8, 0x5C) = 0x10;
            P(u8, 0x4) = 2;
            P(u8, 0x5) = 3;
        }
    } else if (t == 0x10) {
        P(u8, 0x60) = 4;
        P(u8, 0x5C) = 5;
        P(u8, 0x16) = 5;
        P(u8, 0x4) = 4;
        P(u8, 0x5) = 0;
        P(u8, 0x0) |= 0x10;
    } else if (t == 0x20) {
        set_animation(arg0, 0x15);
        P(u8, 0x8A) = 0;
        P(u16, 0x88) = 0;
        P(u16, 0x86) = 0;
        P(u16, 0x84) = 0;
        P(u8, 0x5C) = 0x32;
        P(u8, 0x16) = 6;
        P(u8, 0x4) = 5;
        P(u8, 0x5) = 0;
    }
    P(u8, 0x6) = 0;
    P(u8, 0x7) = 0;
}
#undef D_800CCEDC
