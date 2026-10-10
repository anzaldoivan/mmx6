#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */
M2C_UNK func_80017A04();                        /* extern */
extern M2C_UNK D_800970A0;
extern s8 D_800970FC;

void func_800F0EA4(void* arg0) {
    s32 flag;
    s32 cond;
    s32 m;
    s32 v;
    s32 st;
    u16 t;
    u8 c;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, u8*, 6) = 1;
        M2C_FIELD(arg0, u8*, 0x7D) = 1;
        M2C_FIELD(arg0, s16*, 0x98) = 0x420;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x42000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = -0x42000;
        }
        M2C_FIELD(arg0, u8*, 0x90) = 0x1E;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0xC);
        if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            void* pl = &D_800970A0;
            M2C_FIELD(pl, u8*, 0xD8) = 0x2F;
            M2C_FIELD(pl, u8*, 0x6) = 0;
        }
        func_80016C48(2, 2, 0);
    }
    if ((M2C_FIELD(arg0, u16*, 0x88) & 7) == 4) {
        if (!(M2C_FIELD(arg0, u16*, 0x8A) & 0x80)) {
            goto clear;
        }
        func_80016C48(2, 0x25, 0);
        flag = 1;
    } else {
        flag = 1;
        if (D_800970FC != -0x80) {
        clear:
            flag = 0;
        }
    }
    if (flag != 0) {
        st = 0xB;
        goto store;
    }
    if (M2C_FIELD(arg0, u8*, 0x97) & 2) {
        goto call2;
    }
    cond = 0;
    if (M2C_FIELD(arg0, u16*, 0x8A) & 0x30) {
        cond = 1;
        if (M2C_FIELD(arg0, s8*, 2) != 0) {
            cond = M2C_FIELD(arg0, u8*, 0x7E) == 0;
        }
    }
    if (cond) {
        M2C_FIELD(arg0, s8*, 5) = 0x10;
        M2C_FIELD(arg0, s8*, 6) = 0;
        goto call;
    }
    if (M2C_FIELD(arg0, u8*, 0xA8) & 3) {
        st = 0xC;
        goto store;
    }
    if (!(M2C_FIELD(arg0, u8*, 0x97) & 8)) {
        s32 ma = 2;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            ma = 1;
        }
        v = M2C_FIELD(arg0, u16*, 0x88) & ma;
    } else {
        m = 2;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            m = 1;
        }
        t = M2C_FIELD(arg0, u16*, 0x88);
        if (t & m) {
            goto move;
        }
        v = (u16)(t & 0x100);
    }
    if (v == 0) {
        st = 0xC;
        goto store;
    }
move:
    c = M2C_FIELD(arg0, u8*, 0x90);
    M2C_FIELD(arg0, s32*, 8) += M2C_FIELD(arg0, s32*, 0x20);
    M2C_FIELD(arg0, u8*, 0x90) = c - 1;
    if ((s8)c >= 0) {
        goto call;
    }
    st = 0xC;
store:
    M2C_FIELD(arg0, s8*, 5) = st;
    M2C_FIELD(arg0, s8*, 6) = 0;
    return;
call:
    func_80017A04(arg0);
    return;
call2:
    func_80017A04(arg0);
}
