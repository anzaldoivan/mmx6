#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */
struct X4_VisualObj* func_8002C398(void);       /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
extern M2C_UNK g_Player;
extern s8 D_800970FC;

void func_800EF288(void* arg0) {
    void* o;
    u16 f;
    u16 m;
    s32 t;
    s32 h;
    s32 v;
    s32 d;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, s32*, 0x24) = 0x58000;
        M2C_FIELD(arg0, s8*, 6) = 1;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x4200;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, u8*, 0x67) = 1;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            o = func_8002C398();
            if (o != 0) {
                M2C_FIELD(o, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
                M2C_FIELD(o, u8*, 1) = 0xC;
                M2C_FIELD(o, u8*, 2) = 6;
                M2C_FIELD(o, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
                M2C_FIELD(o, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(o, u8*, 0x16) = M2C_FIELD(arg0, u8*, 0x16);
                M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
                M2C_FIELD(o, void**, 0x50) = arg0;
            }
        }
        ((void (*)(void*, s32))func_800179A4)(arg0, 2);
        if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            u8* pl = (u8*)&g_Player;
            M2C_FIELD(pl, u8*, 0xD8) = 0x2B;
            M2C_FIELD(pl, u8*, 6) = 0;
        }
        M2C_FIELD(arg0, u8*, 0x87) = 0;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            func_80016C48(2, 0x27, 0);
        } else {
            func_80016C48(2, 3, 0);
        }
    }
    if (M2C_FIELD(arg0, u16*, 0x8A) & 0x30) {
        t = 1;
        if (M2C_FIELD(arg0, s8*, 2) != 0) {
            t = M2C_FIELD(arg0, u8*, 0x7E) == 0;
        }
    } else {
        t = 0;
    }
    if (t) {
        M2C_FIELD(arg0, u8*, 5) = 6;
        M2C_FIELD(arg0, u8*, 6) = 0;
        return;
    }
    if ((M2C_FIELD(arg0, u16*, 0x88) & 7) == 4) {
        if (M2C_FIELD(arg0, u16*, 0x8A) & 0x80) {
            func_80016C48(2, 0x25, 0);
            h = 1;
            goto h_done;
        }
    } else if (D_800970FC == -0x80) {
        h = 1;
        goto h_done;
    }
    h = 0;
h_done:
    if (h) {
        M2C_FIELD(arg0, u8*, 5) = 0xB;
        M2C_FIELD(arg0, u8*, 6) = 0;
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x97) & 2) {
        return;
    }
    m = M2C_FIELD(arg0, u16*, 0x88);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    if (m & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        v = 1;
    } else if (m & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        v = 1;
    } else {
        v = 0;
    }
    if (v) {
        d = M2C_FIELD(arg0, s16*, 0x98) << 8;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            d = -d;
        }
        M2C_FIELD(arg0, s32*, 0x20) = d;
    }
    if (!(M2C_FIELD(arg0, u8*, 0xA8) & 4) && M2C_FIELD(arg0, s32*, 0x24) >= 0 &&
        (M2C_FIELD(arg0, u16*, 0x88) & 0x80)) {
        func_8002D230(arg0);
        return;
    }
    M2C_FIELD(arg0, u8*, 5) = 0xC;
    M2C_FIELD(arg0, u8*, 6) = 0;
}
