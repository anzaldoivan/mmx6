#include "common.h"

extern s32 D_800FDE30;

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800FD664(void* arg0) {
    u8* src = *(u8**)((u8*)&D_800FDE30 + 0x468);
    s32 t;

    F16(arg0, 0x40) = F16(src, 0x40);
    F16(arg0, 0x42) = F16(src, 0x42) & 0x7FFF;
    F32(arg0, 0x30) = F32(src, 0x30);
    t = F32(src, 0x3C);
    F8(arg0, 0x14) = 0;
    F8(arg0, 0x16) = 3;
    F8(arg0, 0x67) = 0;
    F8(arg0, 0x3) = 0;
    F32(arg0, 0x68) = 0;
    F32(arg0, 0x50) = 0;
    F32(arg0, 0x54) = 0;
    F32(arg0, 0x58) = 0;
    F32(arg0, 0x20) = 0;
    F32(arg0, 0x24) = 0;
    F32(arg0, 0x28) = 0;
    F32(arg0, 0x2C) = 0;
    F8(arg0, 0x5C) = 0;
    F8(arg0, 0x60) = 0;
    F8(arg0, 0x5) = 0;
    F8(arg0, 0x4)++;
    F32(arg0, 0x3C) = t;
}
