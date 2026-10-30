#include "common.h"
#define M2C_UNK s32

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define FP(p, o) (*(void**)((u8*)(p) + (o)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK clear_object_slot();
s32 random_byte();

extern u8 D_800E9860[];
/* linker symbol at the same address as D_800E9860: a distinct symbol keeps cse from
   deriving the second table address from the first (the original had two rodata labels) */
extern u8 rock_05_RODATA_START[];
extern u8 D_800746FC;
extern u8 D_800970B4;
extern s8 D_800CD30A;
extern u8 D_800F3D24;
extern u8 D_800F3D28;
extern u8 D_800F3D44;

void func_800EA07C(void* arg0) {
    u16 a[8];
    u16 b[3];
    s8 mode;
    u16 t;
    u16* src;

    __builtin_memcpy(a, D_800E9860 + 4, 16);
    src = (u16*)(rock_05_RODATA_START + 0x14);
    __builtin_memcpy(b, src, 6);
    mode = D_800CD30A;
    if (mode != 1) {
        clear_object_slot();
        return;
    }
    F8(arg0, 0x5C) = 8;
    F8(arg0, 0x60) = 2;
    FP(arg0, 0x58) = &D_800746FC;
    F8(arg0, 0x61) = 0;
    F8(arg0, 0x14) = D_800970B4;
    FP(arg0, 0x30) = &D_800F3D44;
    F8(arg0, 0x16) = 5;
    F32(arg0, 0x20) = 0;
    F32(arg0, 0x24) = 0;
    F8(arg0, 0x67) = 0;
    F8(arg0, 0x70) = 0;
    F8(arg0, 0x15) = 0;
    F32(arg0, 0x68) = 0;
    FP(arg0, 0x54) = &D_800F3D28;
    FP(arg0, 0x50) = &D_800F3D24;
    F16(arg0, 0x80) = a[random_byte() & 7];
    t = b[random_byte() % 3];
    F8(arg0, 0x85) = 0;
    F16(arg0, 0x82) = t;
    set_animation(arg0, 0);
    F8(arg0, 4) = mode;
    F8(arg0, 5) = mode;
    F8(arg0, 6) = 0;
}
