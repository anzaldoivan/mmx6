#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
extern void (*D_800FC4E8[])(void*);
extern void (*D_800FC4F0)(void*);

#define F530_FLD(p, type, off) (*(type*)((u8*)(p) + (off)))
static inline u8 f530_tile(struct X4_PlayerObj* p, s16 x, s16 y) {
    if (p->unk68 == 0) {
        return 0;
    }
    return func_80030234(p, x, y);
}
#define F530_TILE(dy)                                                          \
    f530_tile(&D_800970A0, D_800970A0.x_pos.i.hi,                              \
              D_800970A0.unk68->unk1 +                                         \
                  (D_800970A0.y_pos.i.hi + D_800970A0.unk68->unk3) + (dy))
#define F530_MAX(a, b) ((a) > (b) ? (a) : (b))
#define F530_MIN(a, b) ((a) < (b) ? (a) : (b))
#define F530_ABS(x) ((x) >= 0 ? (x) : -(x))
#define F530_NEG()                                                             \
    {                                                                          \
        D_800970A0.x_pos.val =                                                 \
            F530_FLD(&D_800970A0, s32, 0x13C) +                                \
            F530_MAX(dx - 0x38000, -F530_FLD(&D_800970A0, s32, 0x104));        \
        D_800970A0.y_pos.val += F530_ABS(                                      \
            F530_MAX(dx - 0x38000, -F530_FLD(&D_800970A0, s32, 0x104)));       \
    }
#define F530_POS()                                                             \
    {                                                                          \
        D_800970A0.x_pos.val =                                                 \
            F530_FLD(&D_800970A0, s32, 0x13C) +                                \
            F530_MIN(dx + 0x38000, F530_FLD(&D_800970A0, s32, 0x104));         \
        D_800970A0.y_pos.val += F530_ABS(                                      \
            F530_MIN(dx + 0x38000, F530_FLD(&D_800970A0, s32, 0x104)));        \
    }

void func_800F0BB0(u8* arg0) {
    s32 dx;

    arg0[0x21] = arg0[0x20];
    arg0[0x20] = F530_TILE(0);
    dx = D_800970A0.x_pos.val - F530_FLD(&D_800970A0, s32, 0x13C);
    if (D_800970A0.state == 1) {
    loop:
        switch (arg0[0x20]) {
        case 17:
        case 18:
        case 19:
        case 20:
            arg0[4] = 1;
            if (arg0[0x21] == 0x3C && D_800970A0.unk15 != 0 &&
                D_800970A0.unk5 != 0xC) {
                D_800970A0.x_pos.val = F530_FLD(&D_800970A0, s32, 0x13C);
                goto tail;
            }
            F530_NEG();
            goto tail;
        case 21:
        case 22:
        case 23:
        case 24:
            arg0[4] = 1;
            if (arg0[0x21] == 0x3C && D_800970A0.unk15 == 0 &&
                D_800970A0.unk5 != 0xC) {
                D_800970A0.x_pos.val = F530_FLD(&D_800970A0, s32, 0x13C);
                goto tail;
            }
            F530_POS();
            goto tail;
        case 25:
        case 26:
            arg0[4] = 1;
            if (arg0[0x21] == 0x3C && D_800970A0.unk15 != 0 &&
                D_800970A0.unk5 != 0xC) {
                D_800970A0.x_pos.val = F530_FLD(&D_800970A0, s32, 0x13C);
                goto tail;
            }
            F530_NEG();
            goto tail;
        case 27:
        case 28:
            arg0[4] = 1;
            if (arg0[0x21] == 0x3C && D_800970A0.unk15 == 0 &&
                D_800970A0.unk5 != 0xC) {
                D_800970A0.x_pos.val = F530_FLD(&D_800970A0, s32, 0x13C);
                goto tail;
            }
            F530_POS();
            goto tail;
        case 16:
            arg0[0x20] = F530_TILE(-0x10);
            goto loop;
        case 0:
            if (D_800970A0.unk88.unsigned_bytes.collision_flags & 8) {
                goto call;
            }
            if ((s8)arg0[4] == 2) {
                D_800FC4F0(arg0);
            }
            arg0[0x1C] = D_800970A0.unk5;
            break;
        default:
            arg0[4] = 1;
            arg0[0x1C] = D_800970A0.unk5;
            break;
        tail:
            switch (arg0[0x20] = F530_TILE(0)) {
            case 0:
                if ((s8)arg0[4] != 2) {
                    D_800FC4E8[(s8)arg0[4]](arg0);
                }
                arg0[0x1C] = D_800970A0.unk5;
                break;
            case 0x10 ... 0x1C:
            case 0x38:
                break;
            default:
                goto call;
            }
            break;
        case 60:
        call:
            D_800FC4E8[(s8)arg0[4]](arg0);
            arg0[0x1C] = D_800970A0.unk5;
            break;
        }
    }
    if (D_800970A0.x_pos.val != F530_FLD(&D_800970A0, s32, 0x13C)) {
        arg0[0x1E] =
            D_800970A0.x_pos.val < F530_FLD(&D_800970A0, s32, 0x13C) ? 0 : 0x40;
    }
}
