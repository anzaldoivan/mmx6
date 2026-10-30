#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern u8 g_temp_options;
extern u16 D_8006D600[];
extern u16 D_80071080[];
void func_800122A4();

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_8001BA1C(u8* arg0) {
    u8 i;
    u8 j;
    s8 v;
    u8* e = (u8*)&g_playthrough_state;

    B(e, 0x66) = arg0[1];
    B(e, 0x68) = arg0[2];
    W(e, 0x70) = W(arg0, 4);
    for (i = 0; i < 2; i++) {
        u8* d = e + 0x74;
        u8* s = arg0 + 8;
        s32 o = i * 4;
        *(s32*)(d + o) = *(s32*)(s + o);
    }
    W(e, 0x6C) = W(arg0, 0x10);
    H(e, 0x6A) = H(arg0, 0x14);
    for (i = 0; i < 16; i++) {
        u8* d = (u8*)D_8006D600;
        u8* s = arg0 + 0x16;
        s32 o = i * 2;
        *(u16*)(o + d) = *(u16*)(s + o);
    }
    B(e, 0x61) = arg0[0x38];
    B(e, 0x62) = arg0[0x39];
    B(e, 0x5B) = arg0[0x36];
    B(e, 0x5C) = arg0[0x37];
    B(e, 0x60) = arg0[0x3A];
    B(e, 0x5F) = arg0[0x3B];
    B(e, 0x69) = arg0[0x3C];
    v = 2;
    if (H(arg0, 0x14) & D_80071080[3]) {
        v = 4;
    }
    B(e, 0x39) = v;
    B(e, 0x63) = 0;
    B(e, 0x64) = 0;
    B(e, 0x65) = 0;
    B(e, 0x8D) = arg0[0x3D];
    B(e, 0x8E) = arg0[0x3E];
    W(e, 0xCC) = W(arg0, 0x40);
    B(e, 0x43B) = arg0[0x3F];
    B(e, 0xC9) = arg0[0xCC];
    g_temp_options = arg0[0xCC];
    for (i = 0; i < 16; i++) {
        s32 o;
        if (i < 8) {
            u8* d0 = e + 0x158;
            u8* s0 = arg0 + 0xAE;
            *(d0 + i) = *(s0 + i);
        }
        {
            u8* D = e + 0xD8;
            u8* S = arg0 + 0x44;
            u8* d = e + 0x168;
            u8* s = arg0 + 0xBC;
            o = i * 4;
            *(s32*)(D + o) = *(s32*)(S + o);
            *(d + i) = *(s + i);
        }
    }
    for (i = 0; i < 21; i++) {
        u8* d = e + 0x9E;
        u8* s = arg0 + 0x84;
        s32 o = i * 2;
        *(u16*)(d + o) = *(u16*)(s + o);
    }
    for (i = 0; i < 22; i++) {
        for (j = 0; j < 32; j++) {
            u8* D = e + 0x178;
            u8* S = arg0 + 0xCE;
            s32 o = j + i * 32;
            *(D + o) = *(S + o);
        }
    }
    B(e, 0xD0) = arg0[0xB6];
    B(e, 0xD1) = arg0[0xB7];
    H(e, 0xD2) = H(arg0, 0xB8);
    H(e, 0xD4) = H(arg0, 0xBA);
    B(e, 0x438) = arg0[0xCD];
    for (i = 0; i < 9; i++) {
        u8* d = e + 0x43C;
        u8* s = arg0 + 0x390;
        s32 o = i * 4;
        *(s32*)(d + o) = *(s32*)(s + o);
    }
    B(e, 0x465) = arg0[0x3B4];
    B(e, 0x466) = arg0[0x3B5];
    B(e, 0x467) = arg0[0x3B6];
    func_800122A4(*(s8*)(e + 0xD0), *(s8*)(e + 0xD1));
}
