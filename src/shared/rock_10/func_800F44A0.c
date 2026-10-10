#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_9C (*(s32**)0x1F80009C)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */
#define SET_ANIM(o, n) ((void (*)(void*, s32))func_800179A4)((o), (n))
extern M2C_UNK D_8007433C;
extern u8 D_800970B4;
extern s8 D_800CCEDC;
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;
extern M2C_UNK D_800FC748;
extern M2C_UNK D_800FC74C;
extern M2C_UNK D_800FC750;
extern M2C_UNK D_800FC754;
extern M2C_UNK D_800FCBBC;
extern s32 D_800FD000;
extern s32 D_800FD004;

void func_800F44A0(void* arg0) {
    s32* tbl;
    s32 off;
    s8 sub;
    s32 kind;
    void* parent;
    s8 st;

    if (D_800CCEDC == 0xC && M2C_FIELD(arg0, s8*, 2) == 0) {
        tbl = SCRATCH_9C;
        off = *tbl;
        M2C_FIELD(arg0, s16*, 0x42) = 0x7948;
        M2C_FIELD(arg0, void**, 0x3C) = (u8*)tbl + off;
    }
    {
        register s32 m asm("$2");
        m = 0xA;
        M2C_FIELD(arg0, u8*, 0x60) = m;
    }
    M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_8007433C;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = D_800970B4;
    sub = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, M2C_UNK**, 0x30) = &D_800FCBBC;
    kind = sub & 0xF0;
    if (kind == 0x00) {
        M2C_FIELD(arg0, s16*, 0x40) = 0x140;
        M2C_FIELD(arg0, u8*, 0x16) = 5;
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC734;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC738;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        SET_ANIM(arg0, 4);
        D_800FD000 = 0;
        M2C_FIELD(arg0, s8*, 0x8A) = -1;
        M2C_FIELD(arg0, u8*, 0x8B) = 0;
        M2C_FIELD(arg0, u8*, 0x8C) = 0;
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        D_800FD004 = 0;
        M2C_FIELD(arg0, u8*, 0x4) = 1;
        M2C_FIELD(arg0, u8*, 0x5) = 8;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = 0;
    } else if (kind == 0x10) {
        parent = M2C_FIELD(arg0, void**, 0x80);
        st = M2C_FIELD(parent, s8*, 4);
        if (st != 1) {
            M2C_FIELD(arg0, u8*, 0x4) = 7;
            M2C_FIELD(arg0, u8*, 0x3) = 0;
            return;
        }
        M2C_FIELD(arg0, u8*, 0x16) = 5;
        M2C_FIELD(arg0, u8*, 0x3) = st;
        switch (sub) {
        case 0x10:
            SET_ANIM(arg0, 0x18);
            M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC748;
            M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC74C;
            M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(parent, u16*, 0xA);
            M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(parent, u16*, 0xE) - 0x26;
            break;
        case 0x11:
            SET_ANIM(arg0, 0x19);
            M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC750;
            M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC754;
            M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(parent, u16*, 0xA) - 0x26;
            M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(parent, u16*, 0xE);
            break;
        case 0x12:
            SET_ANIM(arg0, 0x18);
            M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC748;
            M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC74C;
            M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(parent, u16*, 0xA);
            M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(parent, u16*, 0xE) + 0x26;
            break;
        case 0x13:
            SET_ANIM(arg0, 0x19);
            M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC750;
            M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC754;
            M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(parent, u16*, 0xA) + 0x26;
            M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(parent, u16*, 0xE);
            break;
        }
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, u8*, 0x4) = 3;
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = 0;
    } else if (kind == 0x20) {
        func_80016C48(2, 0x65, arg0);
        parent = M2C_FIELD(arg0, void**, 0x80);
        st = M2C_FIELD(parent, s8*, 4);
        if (st != 1) {
            M2C_FIELD(arg0, u8*, 0x4) = 7;
            M2C_FIELD(arg0, u8*, 0x3) = 0;
            return;
        }
        M2C_FIELD(arg0, u8*, 0x16) = 5;
        M2C_FIELD(arg0, u8*, 0x3) = st;
        SET_ANIM(arg0, 8);
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC734;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC738;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA) + 0x20;
        } else {
            M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA) - 0x20;
        }
        M2C_FIELD(arg0, u8*, 0x4) = 4;
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = 0;
    } else if (kind == 0x30) {
        parent = M2C_FIELD(arg0, void**, 0x80);
        st = M2C_FIELD(parent, s8*, 4);
        if (st != 1) {
            M2C_FIELD(arg0, u8*, 0x4) = 7;
            M2C_FIELD(arg0, u8*, 0x3) = 0;
            return;
        }
        switch (sub) {
        case 0x30:
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            break;
        case 0x31:
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            break;
        case 0x32:
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            break;
        case 0x33:
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            break;
        }
        M2C_FIELD(arg0, u8*, 0x16) = 5;
        M2C_FIELD(arg0, u8*, 0x3) = 1;
        SET_ANIM(arg0, 2);
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC734;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC738;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, u8*, 0x89) = 0;
        M2C_FIELD(arg0, u8*, 0x4) = 5;
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = 0;
    }
}
