#include "common.h"
#define M2C_UNK s32

#define NULL ((void*)0)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */
M2C_UNK func_80017A04();                        /* extern */
s32 func_8002A47C(s32);                         /* extern */
void* func_8002C32C();                          /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
extern M2C_UNK D_800970A0;

static inline void F0B5C_spawn(void* self, s32 kind) {
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
        {
            u8 t = M2C_FIELD(self, u8*, 0x16);
            M2C_FIELD(o, void**, 0x7C) = self;
            M2C_FIELD(o, u8*, 0x16) = t;
        }
        M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(self, u8*, 0x15);
        M2C_FIELD(self, u8*, 0x86)++;
    }
}

void func_800F0B5C(void* arg0) {
    u16 f;
    s32 v;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, u8*, 6) = 1;
        if (M2C_FIELD(arg0, u16*, 0x88) & 8) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 9);
            if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
                void* pl = &D_800970A0;
                M2C_FIELD(pl, u8*, 0xD8) = 0x33;
                M2C_FIELD(pl, u8*, 0x6) = 0;
            }
            if (M2C_FIELD(arg0, u8*, 0x86) < 3) {
                F0B5C_spawn(arg0, 1);
            }
        } else if (M2C_FIELD(arg0, u8*, 0x86) < 3) {
            F0B5C_spawn(arg0, 0);
        }
        func_80016C48(2, 7, 0);
    }
    if (M2C_FIELD(arg0, u8*, 0xA8) & 8) {
        M2C_FIELD(arg0, s8*, 5) = 5;
        M2C_FIELD(arg0, s8*, 6) = 0;
        return;
    }
    if (!(M2C_FIELD(arg0, u8*, 0x97) & 2)) {
        f = M2C_FIELD(arg0, u16*, 0x88);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        if (f & 3) {
            v = M2C_FIELD(arg0, s16*, 0x98) << 8;
            if (!(f & 1)) {
                v = -v;
            }
            M2C_FIELD(arg0, s32*, 0x20) = v;
        }
        if (M2C_FIELD(arg0, s32*, 0x24) >= 0 &&
            ((M2C_FIELD(arg0, u8*, 0xA8) & 4) ||
             !(M2C_FIELD(arg0, u16*, 0x88) & 0x80))) {
            M2C_FIELD(arg0, s32*, 0x24) = 0;
        }
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            s8 st = 4;
            if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
                st = 0xC;
            }
            M2C_FIELD(arg0, s8*, 5) = st;
        } else {
            if (M2C_FIELD(arg0, s32*, 0x24) < -0x5E000) {
                M2C_FIELD(arg0, s32*, 0x24) = -0x5E000;
            }
            ((void (*)(void*))func_8002D230)(arg0);
            if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
                s32 cond;
                cond = 0;
                if (M2C_FIELD(arg0, u16*, 0x8A) & 0x30) {
                    cond = 1;
                    if (M2C_FIELD(arg0, s8*, 2) != 0) {
                        cond = M2C_FIELD(arg0, u8*, 0x7E) == 0;
                    }
                }
                if (cond && M2C_FIELD(arg0, u8*, 0x86) < 3) {
                    M2C_FIELD(arg0, s8*, 5) = 6;
                    M2C_FIELD(arg0, s8*, 6) = 0;
                }
            }
        }
        func_80017A04(arg0);
        return;
    }
    func_80017A04(arg0);
}
