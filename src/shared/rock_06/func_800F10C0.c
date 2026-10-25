#include "common.h"
#define M2C_UNK s32

#define NULL ((void*)0)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */
M2C_UNK func_80017A04();                        /* extern */
s32 func_8002A47C(s32);                         /* extern */
void* func_8002C32C();                          /* extern */
extern M2C_UNK g_Player;

static inline void F10C0_spawn(void* self, s32 kind) {
    void* o = func_8002C32C();
    if (o != NULL) {
        s32 r;
        M2C_FIELD(o, u8*, 0) = 0x41;
        M2C_FIELD(o, u8*, 1) = 0x3B;
        M2C_FIELD(o, u8*, 2) = kind;
        M2C_FIELD(o, u16*, 0xA) = M2C_FIELD(self, u16*, 0xA);
        M2C_FIELD(o, u16*, 0xE) = M2C_FIELD(self, u16*, 0xE);
        M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(self, s32*, 0x30);
        M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(self, u16*, 0x40);
        M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(self, s32*, 0x3C);
        r = func_8002A47C(0xE1) & 0xFF;
        M2C_FIELD(o, u16*, 0x42) =
            ((r * 4 + 0x20) % 16) | (((r + 8) / 4 + 0x1E0) << 6);
        M2C_FIELD(o, u8*, 0x16) = M2C_FIELD(self, u8*, 0x16);
        M2C_FIELD(o, void**, 0x7C) = self;
        M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(self, u8*, 0x15);
        M2C_FIELD(self, u8*, 0x86)++;
    }
}

void func_800F10C0(void* arg0) {
    u8 f97;
    s32 t;
    s32 m;
    s32 n;
    s32 cond;
    u16 g;
    s32 v;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, u8*, 6) = 1;
        if (M2C_FIELD(arg0, u16*, 0x88) & 8) {
            if (M2C_FIELD(arg0, u8*, 0x86) < 3) {
                F10C0_spawn(arg0, 1);
            }
            ((void (*)(void*, s32))func_800179A4)(arg0, 0xA);
            if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
                void* pl = &g_Player;
                M2C_FIELD(pl, u8*, 0xD8) = 0x37;
                M2C_FIELD(pl, u8*, 0x6) = 0;
            }
        } else if (M2C_FIELD(arg0, u8*, 0x86) < 3) {
            F10C0_spawn(arg0, 0);
        }
        func_80016C48(2, 7, 0);
    }
    t = M2C_FIELD(arg0, u8*, 0x90) - 1;
    f97 = M2C_FIELD(arg0, u8*, 0x97);
    M2C_FIELD(arg0, u8*, 0x90) = t;
    if (!(f97 & 2)) {
        if ((M2C_FIELD(arg0, u8*, 0xA8) & 3) || ((s8)t < 0)) {
            M2C_FIELD(arg0, s8*, 5) = 0xC;
            M2C_FIELD(arg0, s8*, 6) = 0;
        } else if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            M2C_FIELD(arg0, s8*, 5) = 0xF;
            M2C_FIELD(arg0, s8*, 6) = 1;
            M2C_FIELD(arg0, s32*, 8) += M2C_FIELD(arg0, s32*, 0x20);
        } else {
            if (!(f97 & 8)) {
                n = 2;
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    n = 1;
                }
                v = M2C_FIELD(arg0, u16*, 0x88) & n;
            } else {
                m = 2;
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    m = 1;
                }
                g = M2C_FIELD(arg0, u16*, 0x88);
                if (g & m) {
                    goto add;
                }
                v = g & 0x100;
            }
            if (v != 0) {
            add:
                M2C_FIELD(arg0, s32*, 8) += M2C_FIELD(arg0, s32*, 0x20);
            }
            cond = 0;
            if (M2C_FIELD(arg0, u16*, 0x8A) & 0x30) {
                cond = 1;
                if (M2C_FIELD(arg0, s8*, 2) != 0) {
                    cond = M2C_FIELD(arg0, u8*, 0x7E) == 0;
                }
            }
            if (cond != 0 && M2C_FIELD(arg0, u8*, 0x86) < 3) {
                M2C_FIELD(arg0, s8*, 5) = 0x10;
                M2C_FIELD(arg0, s8*, 6) = 0;
                if (M2C_FIELD(arg0, u16*, 0x88) & 8) {
                    ((void (*)(void*, s32))func_800179A4)(arg0, 0xA);
                } else {
                    ((void (*)(void*, s32))func_800179A4)(arg0, 0xC);
                }
            }
        }
        ((M2C_UNK(*)())func_80017A04)(arg0);
    } else {
        ((M2C_UNK(*)())func_80017A04)(arg0);
    }
}
