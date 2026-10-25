#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_80031474(void*);
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_800FBC70;

#define SET_ANIM(obj, id)                                                      \
    {                                                                          \
        s32 idx = func_8002A47C(M2C_FIELD(obj, s8*, 1));                       \
        s32 base = SPAD20;                                                     \
        register s32 off asm("$6") = *(s32*)(idx * 4 + base + 4);              \
        M2C_FIELD(obj, s32*, 0x3C) = base + off;                               \
        ((void (*)(void*, s32, s32))func_800179A4)(obj, id, off);              \
    }

#define SPAWN(obj, kind)                                                       \
    {                                                                          \
        p = func_8002C458();                                                   \
        if (p != 0) {                                                          \
            u8 o = M2C_FIELD(obj, u8*, 0);                                     \
            M2C_FIELD(p, s8*, 1) = 1;                                          \
            M2C_FIELD(p, s8*, 2) = kind;                                       \
            M2C_FIELD(p, void**, 0x7C) = obj;                                  \
            M2C_FIELD(p, u8*, 0) = o;                                          \
        }                                                                      \
    }

void func_800EECAC(void* arg0) {
    void* parent;
    s32 timer;
    void* p;
    s32 r;

    if (D_800FBC70 != 0) {
        func_80016C48(2, 0x14, arg0);
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    parent = M2C_FIELD(arg0, void**, 0x80);
    if (M2C_FIELD(parent, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(parent, s16*, 0xA) - 0x3E;
    } else {
        M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(parent, s16*, 0xA) + 0x3E;
    }
    M2C_FIELD(arg0, s32*, 0x24) =
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s16*, 0xE) - 0x3C;
    if (M2C_FIELD(arg0, s16*, 0xA) < M2C_FIELD(arg0, s32*, 0x20)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    timer = M2C_FIELD(arg0, u16*, 0x7E) + 1;
    M2C_FIELD(arg0, u16*, 0x7E) = timer;

    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        switch (M2C_FIELD(arg0, s8*, 6)) {
        case 0:
            if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
                // !FAKE: depin: macro pin; drop breaks match (82/400)
                SET_ANIM(arg0, 0xC);
                func_80016C48(2, 7, arg0);
                M2C_FIELD(arg0, s16*, 0x7C) = 0;
                M2C_FIELD(arg0, s8*, 6)++;
            }
            break;
        case 1:
            if ((s16)((s16)timer % 6) == 0) {
                SPAWN(arg0, 0);
            }
            if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x64) {
                M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 7) = 1;
                M2C_FIELD(arg0, s8*, 6)++;
            }
            break;
        case 2:
            if ((s16)((s16)timer % 6) == 0) {
                SPAWN(arg0, 0);
            }
            if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 5) == 4) {
                M2C_FIELD(arg0, s8*, 6) = 0;
                M2C_FIELD(arg0, s8*, 5)++;
            }
            break;
        }
        goto tail;
    case 1:
        if ((s16)((s16)timer % 6) == 0) {
            SPAWN(arg0, 0);
        }
        switch (M2C_FIELD(arg0, s8*, 6)) {
        case 0:
            if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 5) == 8) {
                M2C_FIELD(arg0, s16*, 0x7C) = 0;
                M2C_FIELD(arg0, s8*, 6)++;
            }
            break;
        case 1:
            if (g_Player.unk2 == 0) {
                if (M2C_FIELD(arg0, s16*, 0x7C) == 0 ||
                    M2C_FIELD(arg0, s16*, 0x7C) == 8 ||
                    M2C_FIELD(arg0, s16*, 0x7C) == 0x10 ||
                    M2C_FIELD(arg0, s16*, 0x7C) == 0x18) {
                    SPAWN(arg0, 2);
                    func_80016C48(2, 8, arg0);
                } else if (M2C_FIELD(arg0, s16*, 0x7C) == 0x7C) {
                    M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 7) = 1;
                    M2C_FIELD(arg0, s8*, 6)--;
                }
            } else {
                if (M2C_FIELD(arg0, s16*, 0x7C) == 0 ||
                    M2C_FIELD(arg0, s16*, 0x7C) == 0x3C ||
                    M2C_FIELD(arg0, s16*, 0x7C) == 0x78) {
                    SPAWN(arg0, 2);
                    func_80016C48(2, 8, arg0);
                } else if (M2C_FIELD(arg0, s16*, 0x7C) == 0xDC) {
                    M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 7) = 1;
                    M2C_FIELD(arg0, s8*, 6)--;
                }
            }
            M2C_FIELD(arg0, s16*, 0x7C)++;
            break;
        }
        M2C_FIELD(arg0, u8*, 0x5C) = 0x7F;
        r = func_80031474(arg0);
        M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        if (g_Player.unk2 == 0) {
            if (!((r >= 0x13 && r < 0x17) || r == 0x33 || r == 0x34)) {
                goto tail;
            }
        } else if (r <= 0) {
            goto tail;
        }
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 5) = 0x63;
        // !FAKE: depin: macro pin; drop breaks match (82/400)
        SET_ANIM(arg0, 0x10);
        func_80016C48(2, 9, arg0);
        func_80016C48(2, 0x14, arg0);
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s8*, 5)++;
        goto tail;
    case 2:
        switch (M2C_FIELD(arg0, s8*, 6)) {
        case 0:
            if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
                M2C_FIELD(arg0, s16*, 0x7C) = 0;
                M2C_FIELD(arg0, s8*, 6)++;
            }
        tail:
            func_80017A04(arg0);
            func_8002CCB0(arg0, 0x20, 0x20);
            return;
        case 1:
            if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x3C) {
                if (g_Player.x_pos.i.hi < 0x1878) {
                    M2C_FIELD(arg0, s16*, 0xA) = 0x18E0;
                } else {
                    M2C_FIELD(arg0, s16*, 0xA) = 0x1810;
                }
                M2C_FIELD(arg0, s16*, 0xE) = 0x100;
                if (g_Player.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
                    M2C_FIELD(arg0, u8*, 0x15) = 0x40;
                } else {
                    M2C_FIELD(arg0, u8*, 0x15) = 0;
                }
                // !FAKE: depin: macro pin; drop breaks match (82/400)
                SET_ANIM(arg0, 0xF);
                func_80016C48(2, 9, arg0);
                M2C_FIELD(arg0, s8*, 5) = 0;
                M2C_FIELD(arg0, s8*, 6) = 0;
            }
            return;
        default:
            return;
        }
        return;
    default:
        return;
    }
}
#undef g_Player
