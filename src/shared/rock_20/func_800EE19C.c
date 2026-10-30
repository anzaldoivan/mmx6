#include "common.h"
#include "mmx6/x4.h"

extern u16 D_8006D600[];
extern s32 D_80070CC4[];
extern s8 D_800CC869;
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_MiscObj D_800E2F90;

#define DST (*(u8**)((u8*)&D_800E2F90 + 0xC))
#define MISC ((u8*)&D_800E2F90)
#define ENG ((u8*)&g_playthrough_state)

void func_800EE19C(void) {
    u8* dst;
    s32 i;
    s32 j;
    u8* q;
    u16 sum;
    u8* d84;
    u8* dCE;
    u8* d390;
    u8* dm;
    s32* w;

    {
        u8* m = MISC;
        dst = *(u8**)(m + 0xC);
    }
    {
        u8* src = ENG;
        dst[0] = 0;
        dst[1] = src[0x66];
        dst[2] = src[0x68];
        dst[3] = D_800CC869;
        *(s32*)(dst + 4) = *(s32*)(src + 0x70);
        for (i = 0; i < 2; i++) {
            ((s32*)(dst + 8))[i] = ((s32*)(src + 0x74))[i];
        }
    }
    {
        u8* src = ENG;
        *(s32*)(dst + 0x10) = *(s32*)(src + 0x6C);
        *(u16*)(dst + 0x14) = *(u16*)(src + 0x6A);
        for (i = 0; i < 16; i++) {
            ((u16*)(dst + 0x16))[i] = D_8006D600[i];
        }
    }
    {
        u8* src = ENG;
        dst[0x38] = src[0x61];
        dst[0x39] = src[0x62];
        dst[0x36] = src[0x5B];
        dst[0x37] = src[0x5C];
        dst[0x3A] = src[0x60];
        dst[0x3B] = src[0x5F];
        dst[0x3C] = src[0x69];
        dst[0x3D] = src[0x8D];
        dst[0x3E] = src[0x8E];
        *(s32*)(dst + 0x40) = *(s32*)(src + 0xCC);
        dst[0x3F] = src[0x43B];
        dst[0xCC] = src[0xC9];
        for (i = 0; i < 16; i++) {
            if (i < 8) {
                u8* d = dst + 0xAE;
                u8* s = src + 0x158;
                s32 o = i;
                *(u8*)(d + o) = *(u8*)(s + o);
            }
            {
                u8* d = dst + 0x44;
                u8* s = src + 0xD8;
                s32 o = i << 2;
                *(s32*)(d + o) = *(s32*)(s + o);
            }
            {
                u8* d = dst + 0xBC;
                u8* s = src + 0x168;
                s32 o = i;
                *(u8*)(d + o) = *(u8*)(s + o);
            }
        }
    }
    d84 = dst + 0x84;
    for (i = 0; i < 21; i++) {
        u8* src = ENG;
        ((u16*)d84)[i] = ((u16*)(src + 0x9E))[i];
    }
    for (i = 0; i < 22; i++) {
        u8* src = ENG;
        for (j = 0; j < 32; j++) {
            dCE = dst + 0xCE;
            dCE[j + (i << 5)] = (src + 0x178)[j + (i << 5)];
        }
    }
    {
        u8* src = ENG;
        dst[0xB6] = src[0xD0];
        dst[0xB7] = src[0xD1];
        *(u16*)(dst + 0xB8) = *(u16*)(src + 0xD2);
        *(u16*)(dst + 0xBA) = *(u16*)(src + 0xD4);
        dst[0xCD] = src[0x438];
        d390 = dst + 0x390;
        for (i = 0; i < 9; i++) {
            ((s32*)d390)[i] = ((s32*)(src + 0x43C))[i];
        }
    }
    {
        u8* src = ENG;
        dst[0x3B4] = src[0x465];
        dst[0x3B5] = src[0x466];
        dst[0x3B6] = src[0x467];
    }
    q = dst;
    dm = dst - 0x3B8;
    sum = 0;
    for (i = 0; i < dst - dm; i++) {
        sum += *q++;
    }
    *(u16*)(dst + 0x3B8) = sum + 0x55;
    {
        u8* m = MISC;
        w = *(s32**)(m + 0xC);
    }
    __builtin_memcpy(D_80070CC4, w, 0x3BC);
}

#undef DST
#undef ENG
#undef MISC
