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
extern s8 D_800970FC;

static inline void F1670_spawn(void* self, s32 kind) {
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

#define CRY(self, anim, voice)                                                 \
    {                                                                          \
        ((void (*)(void*, s32))func_800179A4)(self, anim);                     \
        if (M2C_FIELD(self, u8*, 0x8D) == 0) {                                 \
            void* pl = &g_Player;                                              \
            M2C_FIELD(pl, u8*, 0xD8) = voice;                                  \
            M2C_FIELD(pl, u8*, 0x6) = 0;                                       \
        }                                                                      \
    }

void func_800F1670(void* arg0) {
    s32 hit;
    s32 cond;
    s32 turn;
    u16 f;
    u16 g;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, u8*, 6) = 1;
        M2C_FIELD(arg0, u8*, 0x7D) = 1;
        M2C_FIELD(arg0, s16*, 0x98) = 0x160;
        if (M2C_FIELD(arg0, u16*, 0x88) & 8) {
            if (M2C_FIELD(arg0, u8*, 0x86) < 3) {
                F1670_spawn(arg0, 1);
            }
            CRY(arg0, 0xB, 0x3D)
        } else if (M2C_FIELD(arg0, u8*, 0x86) < 3) {
            F1670_spawn(arg0, 0);
        }
        M2C_FIELD(arg0, u8*, 0x87) = 0;
        func_80016C48(2, 7, 0);
    }
    if ((M2C_FIELD(arg0, u16*, 0x88) & 7) == 4) {
        if (M2C_FIELD(arg0, u16*, 0x8A) & 0x80) {
            func_80016C48(2, 0x25, 0);
            hit = 1;
        } else {
            goto clear;
        }
    } else {
        hit = 1;
        if (D_800970FC != -0x80) {
        clear:
            hit = 0;
        }
    }
    if (hit != 0) {
        M2C_FIELD(arg0, s8*, 5) = 0xB;
        M2C_FIELD(arg0, s8*, 6) = 0;
    } else if (M2C_FIELD(arg0, u8*, 0xA8) & 8) {
        M2C_FIELD(arg0, s8*, 5) = 5;
        M2C_FIELD(arg0, s8*, 6) = 0;
    } else if (!(M2C_FIELD(arg0, u8*, 0x97) & 2)) {
        f = M2C_FIELD(arg0, u16*, 0x8A);
        if (f & 0x80) {
            M2C_FIELD(arg0, s8*, 5) = 0xC;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        }
        if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
            M2C_FIELD(arg0, s8*, 5) = 0xE;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        }
        if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
            if (f & 0x30) {
                cond = 1;
                if (M2C_FIELD(arg0, s8*, 2) != 0) {
                    cond = M2C_FIELD(arg0, u8*, 0x7E) == 0;
                }
            } else {
                cond = 0;
            }
            if (cond != 0 && M2C_FIELD(arg0, u8*, 0x86) < 3) {
                M2C_FIELD(arg0, s8*, 5) = 0x11;
                if (M2C_FIELD(arg0, u16*, 0x88) & 8) {
                    F1670_spawn(arg0, 1);
                    CRY(arg0, 0xB, 0x3D)
                } else {
                    CRY(arg0, 0xD, 0x3C)
                    if (M2C_FIELD(arg0, u8*, 0x86) < 3) {
                        F1670_spawn(arg0, 0);
                    }
                }
                return;
            }
        }
        g = M2C_FIELD(arg0, u16*, 0x88);
        if (g & 2) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            turn = 1;
        } else if (g & 1) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            turn = 1;
        } else {
            turn = 0;
        }
        if (turn != 0) {
            if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                M2C_FIELD(arg0, s32*, 0x20) = 0x16000;
            } else {
                M2C_FIELD(arg0, s32*, 0x20) = -0x16000;
            }
            M2C_FIELD(arg0, s32*, 8) += M2C_FIELD(arg0, s32*, 0x20);
        }
        ((M2C_UNK(*)())func_80017A04)(arg0, hit);
    } else {
        ((M2C_UNK(*)())func_80017A04)(arg0);
    }
}
