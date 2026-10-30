#include "common.h"
#include "mmx6/x4.h"

extern u16 D_8006D600[];
extern s32 D_80070CC4[];
extern s8 D_800CC869;
extern struct X4_EngineObj g_playthrough_state;

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_8001BD40(void) {
    u8 i;
    u8 j;
    u8* a = (u8*)D_80070CC4;
    u8* e = (u8*)&g_playthrough_state;

    B(a, 0) = 1;
    B(a, 1) = B(e, 0x66);
    B(a, 2) = B(e, 0x68);
    B(a, 3) = D_800CC869;
    W(a, 4) = W(e, 0x70);
    for (i = 0; i < 2; i++) {
        u8* d = a + 8;
        u8* s = e + 0x74;
        s32 o = i * 4;
        *(s32*)(d + o) = *(s32*)(s + o);
    }
    W(a, 0x10) = W(e, 0x6C);
    H(a, 0x14) = H(e, 0x6A);
    for (i = 0; i < 16; i++) {
        u8* d = a + 0x16;
        u8* s = (u8*)D_8006D600;
        s32 o = i * 2;
        *(u16*)(d + o) = *(u16*)(o + s);
    }
    B(a, 0x38) = B(e, 0x61);
    B(a, 0x39) = B(e, 0x62);
    B(a, 0x36) = B(e, 0x5B);
    B(a, 0x37) = B(e, 0x5C);
    B(a, 0x3A) = B(e, 0x60);
    B(a, 0x3B) = B(e, 0x5F);
    B(a, 0x3C) = B(e, 0x69);
    B(a, 0x3D) = B(e, 0x8D);
    B(a, 0x3E) = B(e, 0x8E);
    W(a, 0x40) = W(e, 0xCC);
    B(a, 0x3F) = B(e, 0x43B);
    B(a, 0xCC) = B(e, 0xC9);
    for (i = 0; i < 16; i++) {
        s32 o;
        if (i < 8) {
            u8* d0 = a + 0xAE;
            u8* s0 = e + 0x158;
            *(d0 + i) = *(s0 + i);
        }
        {
            u8* D = a + 0x44;
            u8* S = e + 0xD8;
            u8* d = a + 0xBC;
            u8* s = e + 0x168;
            o = i * 4;
            *(s32*)(D + o) = *(s32*)(S + o);
            *(d + i) = *(s + i);
        }
    }
    for (i = 0; i < 21; i++) {
        u8* d = a + 0x84;
        u8* s = e + 0x9E;
        s32 o = i * 2;
        *(u16*)(o + d) = *(u16*)(s + o);
    }
    for (i = 0; i < 22; i++) {
        for (j = 0; j < 32; j++) {
            u8* D = a + 0xCE;
            u8* S = e + 0x178;
            s32 o = j + i * 32;
            *(D + o) = *(S + o);
        }
    }
    B(a, 0xB6) = B(e, 0xD0);
    B(a, 0xB7) = B(e, 0xD1);
    H(a, 0xB8) = H(e, 0xD2);
    H(a, 0xBA) = H(e, 0xD4);
    B(a, 0xCD) = B(e, 0x438);
    for (i = 0; i < 9; i++) {
        u8* d = a + 0x390;
        u8* s = e + 0x43C;
        s32 o = i * 4;
        *(s32*)(d + o) = *(s32*)(s + o);
    }
    B(a, 0x3B4) = B(e, 0x465);
    B(a, 0x3B5) = B(e, 0x466);
    B(a, 0x3B6) = B(e, 0x467);
}

#undef B
#undef H
#undef W
