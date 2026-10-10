#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800122A4();
M2C_UNK func_8001BD40();

extern u8 D_8006D5F7;
extern u16 D_8006D600[];
extern u16 D_80071080[];
extern struct X4_EngineObj D_800CCED0;
extern void* D_800E2F9C;

void func_800ECE54(void) {
    u8* src;
    u8* dst;
    u8 i;
    u8 j;
    s8 v;

    src = D_800E2F9C;
    dst = (u8*)&D_800CCED0;
    dst[0x66] = src[1];
    dst[0x68] = src[2];
    *(s32*)(dst + 0x70) = *(s32*)(src + 4);
    for (i = 0; i < 2; i++) {
        {
            u8* d = dst + 0x74;
            u8* s = src + 8;
            s32 o = i << 2;
            *(s32*)(d + o) = *(s32*)(s + o);
        }
    }
    *(s32*)(dst + 0x6C) = *(s32*)(src + 0x10);
    *(u16*)(dst + 0x6A) = *(u16*)(src + 0x14);
    for (i = 0; i < 16; i++) {
        u16* d = D_8006D600;
        u8* s = src + 0x16;
        s32 o = i << 1;
        d[i] = *(u16*)(s + o);
    }
    dst[0x61] = src[0x38];
    dst[0x62] = src[0x39];
    dst[0x5B] = src[0x36];
    dst[0x5C] = src[0x37];
    dst[0x60] = src[0x3A];
    dst[0x5F] = src[0x3B];
    dst[0x69] = src[0x3C];
    v = 2;
    if (*(u16*)(src + 0x14) & D_80071080[3]) {
        v = 4;
    }
    dst[0x39] = v;
    dst[0x63] = 0;
    dst[0x64] = 0;
    dst[0x65] = 0;
    dst[0x8D] = src[0x3D];
    dst[0x8E] = src[0x3E];
    *(s32*)(dst + 0xCC) = *(s32*)(src + 0x40);
    dst[0x43B] = src[0x3F];
    dst[0xC9] = src[0xCC];
    D_8006D5F7 = src[0xCC];
    for (i = 0; i < 16; i++) {
        if (i < 8) {
            {
                u8* d = dst + 0x158;
                u8* s = src + 0xAE;
                s32 o = i;
                *(u8*)(d + o) = *(u8*)(s + o);
            }
        }
        {
            u8* d = dst + 0xD8;
            u8* s = src + 0x44;
            s32 o = i << 2;
            *(s32*)(d + o) = *(s32*)(s + o);
        }
        {
            u8* d = dst + 0x168;
            u8* s = src + 0xBC;
            s32 o = i;
            *(u8*)(d + o) = *(u8*)(s + o);
        }
    }
    for (i = 0; i < 21; i++) {
        {
            u8* d = dst + 0x9E;
            u8* s = src + 0x84;
            s32 o = i << 1;
            *(u16*)(d + o) = *(u16*)(s + o);
        }
    }
    for (i = 0; i < 22; i++) {
        for (j = 0; j < 32; j++) {
            u8* d = dst + 0x178;
            u8* s = src + 0xCE;
            s32 o = j + (i << 5);
            *(u8*)(d + o) = *(u8*)(s + o);
        }
    }
    dst[0xD0] = src[0xB6];
    dst[0xD1] = src[0xB7];
    *(u16*)(dst + 0xD2) = *(u16*)(src + 0xB8);
    *(u16*)(dst + 0xD4) = *(u16*)(src + 0xBA);
    dst[0x438] = src[0xCD];
    for (i = 0; i < 9; i++) {
        {
            u8* d = dst + 0x43C;
            u8* s = src + 0x390;
            s32 o = i << 2;
            *(s32*)(d + o) = *(s32*)(s + o);
        }
    }
    dst[0x38] = 0;
    dst[0x465] = src[0x3B4];
    dst[0x466] = src[0x3B5];
    dst[0x467] = src[0x3B6];
    func_800122A4(((s8*)dst)[0xD0], ((s8*)dst)[0xD1]);
    func_8001BD40();
}
