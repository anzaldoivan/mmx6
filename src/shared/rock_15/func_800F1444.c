#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049D90();
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern M2C_UNK D_8007433C;
extern s32 D_800970A8;
extern void (*D_800F6F94[])(void*);

void func_800F1444(void* arg0) {
    void* p;
    s32 r;
    s32 c;
    s8 v;
    s8 d;

    p = M2C_FIELD(arg0, void**, 0x7C);
    D_800F6F94[M2C_FIELD(arg0, s8*, 5)](arg0);
    if (M2C_FIELD(arg0, s8*, 4) != 1) {
        return;
    }
    r = func_80031474(arg0);
    v = M2C_FIELD(arg0, s8*, 2);
    if (v < 3) {
        if (v < 2 && M2C_FIELD(p, s8*, 0x8B) != 0) {
            M2C_FIELD(arg0, s8*, 3) = 0;
            func_80049E50(arg0);
            M2C_FIELD(arg0, s8*, 4) = 2;
            func_8004E654(arg0, 0x11);
            if (M2C_FIELD(p, s8*, 0x8D) != 0) {
                M2C_FIELD(p, u8*, 0x8D)--;
            }
            return;
        }
        if (r < 0 || M2C_FIELD(p, s8*, 5) == 4 || M2C_FIELD(p, s8*, 4) == 2) {
            M2C_FIELD(arg0, s8*, 3) = 0;
            func_80049E50(arg0);
            M2C_FIELD(arg0, s8*, 4) = 2;
            M2C_FIELD(arg0, s8*, 5) = 0;
            if (M2C_FIELD(p, s8*, 0x8D) != 0) {
                M2C_FIELD(p, u8*, 0x8D)--;
            }
            if (M2C_FIELD(arg0, s8*, 2) == 2) {
                M2C_FIELD(p, s8*, 0x8A) = 0;
            }
            func_8004E654(arg0, 0x11);
            return;
        }
        if (r > 0 && M2C_FIELD(arg0, s8*, 2) == 0 &&
            M2C_FIELD(arg0, s8*, 0x92) == 0 && M2C_FIELD(arg0, s8*, 0x5C) < 8) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
            M2C_FIELD(arg0, s8*, 0x92) = 0x20;
            if (M2C_FIELD(arg0, s8*, 0x67) == 0) {
                func_800179A4(arg0, 9);
            } else {
                func_800179A4(arg0, 0xA);
            }
            if (D_800970A8 > M2C_FIELD(arg0, s32*, 8)) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
        }
    } else if (v != 0xD &&
               (M2C_FIELD(p, s8*, 5) == 4 || M2C_FIELD(p, s8*, 4) == 2)) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    c = func_80030ECC(arg0);
    if (M2C_FIELD(arg0, s8*, 2) == 3) {
        if (c != 0 || M2C_FIELD(p, s8*, 0x8B) != 0 || r < 0) {
            M2C_FIELD(arg0, s8*, 3) = 0;
            func_80049D90(arg0);
            M2C_FIELD(arg0, s8*, 4) = 2;
            return;
        }
    }
    if (func_8002CBFC(arg0, 0xA0, 0xA0) == 0) {
        d = M2C_FIELD(arg0, s8*, 2);
        if (d != 2 && d != 0xD) {
            func_8002CCB0(arg0, 0x80, 0x80);
        }
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s8*, 0x67) = 0;
        return;
    }
    {
        register s32 x asm("$2") = M2C_FIELD(arg0, s32*, 0x24);
        register s32 e asm("$2");
        if (x < 0) {
            e = -1;
        } else {
            e = 1;
        }
        M2C_FIELD(arg0, s8*, 0x67) = e;
    }
}
