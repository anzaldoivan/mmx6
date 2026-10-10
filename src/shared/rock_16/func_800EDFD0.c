#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179D0(void*, M2C_UNK, s8);
extern u16 D_800F11E0[];
extern u16 D_800F11F8[][2];

#define DFD0_S8(o) (*(s8*)((s8*)arg0 + (o)))
#define DFD0_U8(o) (*(u8*)((s8*)arg0 + (o)))
#define DFD0_S16(o) (*(s16*)((s8*)arg0 + (o)))
#define DFD0_U16(o) (*(u16*)((s8*)arg0 + (o)))
#define DFD0_PTR(o) (*(void**)((s8*)arg0 + (o)))
#define DFD0_SCRATCH (*(u8**)0x1F800020)

void func_800EDFD0(void* arg0) {
    s32 v;

    v = DFD0_S8(2);
    DFD0_S16(0x40) = 0x1800;
    DFD0_PTR(0x30) = D_800F11E0;
    DFD0_U8(0x16) = 3;
    if (v < 2) {
        register u8* p asm("$5");
        register s32 a asm("$6");
        p = DFD0_SCRATCH;
        p += *(s32*)(p + 0);
        DFD0_S16(0x42) = 0x780D;
        DFD0_PTR(0x3C) = p;
        a = D_800F11F8[v][0];
        DFD0_U16(0xA) = a;
        DFD0_U16(0xE) = D_800F11F8[v][1];
        DFD0_U8(5) = 0;
        ((void (*)(void*, s32, s32))func_800179D0)(arg0, v, 0);
    } else if (v < 4) {
        register u8* p asm("$5");
        register s32 a asm("$6");
        p = DFD0_SCRATCH;
        p += *(s32*)(p + 8);
        DFD0_S16(0x42) = 0x788E;
        DFD0_PTR(0x3C) = p;
        a = D_800F11F8[v][0];
        DFD0_U16(0xA) = a;
        DFD0_U16(0xE) = D_800F11F8[v][1];
        DFD0_U8(5) = 0;
        ((void (*)(void*, s32, s32))func_800179D0)(arg0, v, 1);
    } else if (v < 6) {
        u8* p;
        register s32 a asm("$6");
        DFD0_S16(0x42) = 0x7843;
        p = DFD0_SCRATCH;
        p += *(s32*)(p + 4);
        DFD0_PTR(0x3C) = p;
        a = D_800F11F8[v][0];
        DFD0_U16(0xA) = a;
        DFD0_U16(0xE) = D_800F11F8[v][1];
        DFD0_U8(5) = 0;
        ((void (*)(void*, s32, s32))func_800179D0)(arg0, v, 1);
    } else if (v < 8) {
        u8* p;
        s32 w = v - 2;
        DFD0_S16(0x42) = 0x7843;
        p = DFD0_SCRATCH;
        p += *(s32*)(p + 4);
        DFD0_PTR(0x3C) = p;
        DFD0_U16(0xA) = D_800F11F8[w][0] + 0x600;
        DFD0_U16(0xE) = D_800F11F8[w][1];
        DFD0_U8(5) = 1;
        ((void (*)(void*, s32, s32))func_800179D0)(arg0, w, 1);
    } else if (v < 10) {
        u8* p;
        s32 w = v - 6;
        p = DFD0_SCRATCH;
        p += *(s32*)(p + 8);
        DFD0_S16(0x42) = 0x788E;
        DFD0_PTR(0x3C) = p;
        DFD0_U16(0xA) = D_800F11F8[w][0] - 0x600;
        DFD0_U16(0xE) = D_800F11F8[w][1];
        DFD0_U8(5) = 1;
        ((void (*)(void*, s32, s32))func_800179D0)(arg0, w, 1);
    }
    DFD0_U8(0x14) = 1;
    DFD0_U8(4)++;
}
