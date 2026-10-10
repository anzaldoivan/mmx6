#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define NULL ((void*)0)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */
M2C_UNK func_80017A04();                        /* extern */
struct X4_VisualObj* func_8002C398(void);
s32 func_8002D2D4();
extern M2C_UNK D_800970A0;
extern s8 D_800970FC;
extern struct X4_ObjectHeader D_80097420;
#define D_80097420 (*(s32*)&D_80097420)

void func_800EF950(void* arg0) {
    s32 hit;
    s32 cond;
    u16 t;
    s32 mask;
    s32 mask2;
    u8 a8;
    u8 f97;
    u16 f;
    u16 g;
    s8 st;
    struct X4_VisualObj* o;

    if (!(D_80097420 & 3) && (func_8002D2D4() & 1)) {
        func_8002D2D4();
    }
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, u8*, 6) = 1;
        M2C_FIELD(arg0, s16*, 0x98) = 0x420;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x42000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = -0x42000;
        }
        M2C_FIELD(arg0, u8*, 0x90) = 0x1E;
        ((void (*)(void*, s32))func_800179A4)(arg0, 5);
        if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            void* pl = &D_800970A0;
            M2C_FIELD(pl, u8*, 0xD8) = 0x2F;
            M2C_FIELD(pl, u8*, 0x6) = 0;
        }
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            func_80016C48(2, 0x29, 0);
            o = func_8002C398();
            if (o != NULL) {
                o->active = M2C_FIELD(arg0, s8*, 0);
                o->id = 0xC;
                o->unk2 = 5;
                o->x_pos.val = M2C_FIELD(arg0, s32*, 8);
                o->y_pos.val = M2C_FIELD(arg0, s32*, 0xC);
                o->animation_table = M2C_FIELD(arg0, u32***, 0x30);
                o->unk40 = M2C_FIELD(arg0, u16*, 0x40);
                o->unk3C = M2C_FIELD(arg0, void**, 0x3C);
                o->unk42 = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                o->unk16 = M2C_FIELD(arg0, u8*, 0x16);
                o->unk15 = M2C_FIELD(arg0, u8*, 0x15);
                o->unk50 = arg0;
            }
        } else {
            func_80016C48(2, 2, 0);
        }
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
        st = 0xB;
        goto set_ret;
    }
    if (!(M2C_FIELD(arg0, u8*, 0x97) & 2)) {
        f = M2C_FIELD(arg0, u16*, 0x8A);
        if (f & 0x80) {
            st = 4;
            goto set_call;
        }
        if (f & 0x30) {
            cond = 1;
            if (M2C_FIELD(arg0, s8*, 2) != 0) {
                cond = M2C_FIELD(arg0, u8*, 0x7E) == 0;
            }
        } else {
            cond = 0;
        }
        if (cond != 0) {
            st = 9;
            goto set_call;
        }
        a8 = M2C_FIELD(arg0, u8*, 0xA8);
        if (!(a8 & 8)) {
            st = 0xC;
        set_call:
            M2C_FIELD(arg0, s8*, 5) = st;
            M2C_FIELD(arg0, s8*, 6) = 0;
        } else {
            if (a8 & 3) {
                st = 8;
                goto set_ret;
            }
            if (!(M2C_FIELD(arg0, u8*, 0x97) & 8)) {
                mask = 2;
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    mask = 1;
                }
                t = M2C_FIELD(arg0, u16*, 0x88) & mask;
            } else {
                mask2 = 2;
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    mask2 = 1;
                }
                g = M2C_FIELD(arg0, u16*, 0x88);
                t = g & mask2;
                if (t == 0) {
                    t = g & 0x100;
                }
            }
            if (t != 0) {
                M2C_FIELD(arg0, s32*, 8) += M2C_FIELD(arg0, s32*, 0x20);
                if (M2C_FIELD(arg0, s8*, 0x90)-- >= 0) {
                    goto call;
                }
            }
            st = 8;
        set_ret:
            M2C_FIELD(arg0, s8*, 5) = st;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        }
    call:
        ((M2C_UNK(*)())func_80017A04)(arg0, hit);
    } else {
        ((M2C_UNK(*)())func_80017A04)(arg0);
    }
}
#undef D_80097420
