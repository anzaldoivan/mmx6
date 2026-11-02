void func_8002B410(u16* dst, u16* src, s32 n, s32 num, s32 den) {
    u32 c;
    u32 r;
    u32 g;
    u32 b;
    u16 out;
    s32 i;

    if (num >= den) {
        num = den;
    }
    if (num == den) {
        for (i = 0; i < n; i++) {
            *dst++ = 0;
        }
    } else {
        for (i = 0; i < n; i++) {
            c = *src++;
            r = (c & 0x1F) << 8;
            g = (c & 0x3E0) << 8;
            b = (c & 0x7C00) << 8;
            r = (r - r * num / den) >> 8;
            g = (g - g * num / den) >> 8;
            b = (b - b * num / den) >> 8;
            r &= 0x1F;
            g &= 0x3E0;
            b &= 0x7C00;
            out = r | g | b | (c & 0x8000);
            if (out == 0 && c != 0) {
                out = 0x8000;
            }
            *dst++ = out;
        }
    }
}

#include "common.h"

void func_8002B54C(u16* dst, u16* src, s32 count, s32 level) {
    u16 c;
    u32 r;
    u32 g;
    u32 b;
    u16 v;

    if (level >= 0x1F) {
        level = 0x1F;
    }
    if (level == 0x1F) {
        if (count > 0) {
            do {
                *dst = 0;
                count--;
                dst++;
            } while (count != 0);
        }
    } else if (count > 0) {
        do {
            c = *src;
            r = (c & 0x1F) << 8;
            g = (c & 0x3E0) << 8;
            b = (c & 0x7C00) << 8;
            r = (r - ((r * level) >> 5)) >> 8;
            r &= 0x1F;
            g = (g - ((g * level) >> 5)) >> 8;
            g &= 0x3E0;
            b = (b - ((b * level) >> 5)) >> 8;
            b &= 0x7C00;
            v = r | g | b | (c & 0x8000);
            src++;
            if (v == 0 && c != 0) {
                v = 0x8000;
            }
            *dst = v;
            count--;
            dst++;
        } while (count != 0);
    }
}

#include "common.h"

extern s32 D_80090C90[][16];

void func_8002B63C(s32 arg0, s32 arg1) {
    D_80090C90[arg0][arg1 >> 5] |= 0x80000000U >> (arg1 & 0x1F);
}

#include "common.h"

extern s32 D_80090C90[][16];

void func_8002B674(s32 arg0, s32 arg1) {
    s32 b = (s32)D_80090C90;
    s32* p = (s32*)(((arg1 >> 5) << 2) + (arg0 << 6) + b);
    *p &= ~(0x80000000U >> (arg1 & 0x1F));
}

#include "common.h"
#include "mmx6/x4.h"

extern u8 D_80073738[];
extern u8 D_80091298[];
extern s8 D_800950A0[];
#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_8002B6B0(void) {
    u32 i;
    s8* p;
    s8* q;
    s32 n;
    s8 z;

    z = 0;

    for (i = 0; i < 0x20; i++) {
        p = &D_800950A0[i * 0xA0];
        if (p[0] == 0 || p[1] != 0x37) {
            q = p;
            n = 0x9F;
            do {
                *q++ = z;
            } while (n--);
        }
    }
    for (i = 0; i < 0x60; i++) {
        p = (s8*)&D_80091298[i * 0x70];
        if (p[0] != 0 && D_80073738[p[1]] != 0) {
            q = p;
            n = 0x6F;
            do {
                *q++ = z;
            } while (n--);
        }
    }
    g_Player.special_shot_count = 0;
    g_Player.shot_count = 0;
    g_Player.stock_charge = 0;
}
#undef g_Player

#include "common.h"

extern s8 g_enemies[];
#include "mmx6/projectile.h"

void func_8002B79C(void) {
    s8 z;
    u32 i;
    s8* p;
    s8* q;
    s32 k;

    z = 0;
    for (i = 0; i < 0x30; i++) {
        p = &g_enemies[i * 0x9C];
        if (p[1] != 0x2F) {
            q = p;
            k = 0x9C;
            while (k--) {
                *q++ = z;
            }
        }
    }
    for (i = 0; i < 0x20; i++) {
        q = (s8*)&g_projectiles[i];
        k = 0xA0;
        while (k--) {
            *q++ = z;
        }
    }
}
