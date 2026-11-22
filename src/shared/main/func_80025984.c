#include "common.h"
#include "mmx6/x4.h"

extern X4_P_TAG* D_8008EB08[2][4][8];
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_80071E68[];

#define SP_BUFFER (*(s32*)0x1F800000)
#define SP_SPRBANK (*(u8**)0x1F80001C)
#define SP_PRIM (*(u8**)0x1F800100)
#define SP_TPAGE (*(u8**)0x1F800104)
#define SP_COUNT (*(s32*)0x1F800124)

#define PW(p, o) (*(u32*)((p) + (o)))
#define PH(p, o) (*(s16*)((p) + (o)))
#define PB(p, o) (*(u8*)((p) + (o)))
#define TAG(p) ((X4_P_TAG*)(p))

void func_80025984(struct X4_AnimatedObj* arg0, s32 arg1) {
    s16 x;
    s16 y;
    u8* prim;
    u8* tpage;
    u8* base;
    u16* hdr;
    u8* spr;
    u8 flip;
    s32 tbase;
    s32 count;
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;
    u32 tile;
    u8 attr;
    u8 uL;
    u16 clut;
    u32 word;
    u8 uR;
    u8 vT;
    u8 vB;
    u8* next;
    u32 slot;
    u32 hi4;
    u32 lo3;
    s32 n;

    if (arg0->bg_offset < 0) {
        x = arg0->x_pos.i.hi;
        y = arg0->y_pos.i.hi;
    } else {
        x = arg0->x_pos.i.hi - background_objects[arg0->bg_offset].x_pos.i.hi;
        y = arg0->y_pos.i.hi - background_objects[arg0->bg_offset].y_pos.i.hi;
    }
    prim = SP_PRIM;
    tpage = SP_TPAGE;
    base = SP_SPRBANK;
    hdr = (u16*)(s32)arg0->animation_step.fields.frame_index;
    flip = arg0->unk15;
    tbase = arg0->unk40;
    spr = (u8*)*(s32*)(base + arg1 * 4);
    base = base + (s32)spr;
    hdr = (u16*)(base + (s32)hdr * 4);
    count = hdr[0];
    spr = base + hdr[1] * 4;
    if (count != 0) {
        s32 one;
        s32 mlo;
        s32 mhi;
        s32 k2d;
        one = 1;
        mlo = 0xFFFFFF;
        mhi = 0xFF000000;
        k2d = 0x2D;
        for (; count != 0; prim += 0x28, tpage = next, count--, spr += 4) {
            if (SP_COUNT >= 1000) {
                return;
            }
            SP_COUNT++;
            x0 = (s8)spr[2];
            attr = spr[0];
            if (flip == 0) {
                x1 = x0 + 16;
            } else {
                x1 = -x0;
                x0 = -(x0 + 16);
            }
            x0 = x0 + x;
            x1 = x1 + x;
            y0 = y + (s8)spr[3];
            y1 = y0 + 16;
            tile = spr[1] | ((attr & 3) << 8);
            tile = (u16)(tile + tbase);
            clut = D_80071E68[(attr & 0xC) >> 2];
            if (!(attr & 0x80)) {
                vT = tile & 0xF0;
                if ((attr & 0x40) == flip) {
                    n = 3;
                    TAG(prim)->len = n;
                    TAG(prim)->code = 0x7D;
                    if (*(u8*)arg0 & 0x10) {
                        n = 0x7F;
                        TAG(prim)->code = n;
                    }
                    PB(prim, 0xC) = tile << 4;
                    word = (tile >> 8) | 0xE1000020;
                    PH(prim, 0xE) = clut;
                    PH(prim, 8) = x0;
                    PH(prim, 0xA) = y0;
                    PB(prim, 0xD) = vT;
                    PW(tpage, 4) = word;
                    TAG(tpage)->len = one;
                    PW(tpage, 0) = (PW(tpage, 0) & mhi) | ((u32)prim & mlo);
                    PW(prim, 0) =
                        (PW(prim, 0) & mhi) | ((u32)(tpage + 8) & mlo);
                    next = tpage + 8;
                    continue;
                }
                n = 9;
                TAG(prim)->len = n;
                do {
                    do {
                        do {
                            TAG(prim)->code = k2d;
                        } while (0);
                    } while (0);
                } while (0);
                if (*(u8*)arg0 & 0x10) {
                    n = 0x2F;
                    TAG(prim)->code = n;
                }
                uR = (tile << 4) - 1;
                uL = uR + 16;
                PH(prim, 0x16) = (tile >> 8) | 0x20;
                PH(prim, 0xE) = clut;
                if (uR == 0xFF) {
                    uR = 0;
                    x1--;
                }
                vB = vT + 16;
                if (vB == 0) {
                    vB = 0xFF;
                    y1--;
                }
                word = 0xE1000020;
                PH(prim, 8) = x0;
                PH(prim, 0xA) = y0;
                PH(prim, 0x10) = x1;
                PH(prim, 0x12) = y0;
                PH(prim, 0x18) = x0;
                PH(prim, 0x1A) = y1;
                PH(prim, 0x20) = x1;
                PH(prim, 0x22) = y1;
                PB(prim, 0xC) = uL;
                PB(prim, 0xD) = vT;
                PB(prim, 0x14) = uR;
                PB(prim, 0x15) = vT;
                PB(prim, 0x1C) = uL;
                PB(prim, 0x1D) = vB;
                PB(prim, 0x24) = uR;
                PB(prim, 0x25) = vB;
                PW(tpage, 4) = word;
                TAG(tpage)->len = one;
                PW(tpage, 0) = (PW(tpage, 0) & mhi) | ((u32)prim & mlo);
                PW(prim, 0) = (PW(prim, 0) & mhi) | ((u32)(tpage + 8) & mlo);
                next = tpage + 8;
            } else {
                n = 9;
                TAG(prim)->len = n;
                do {
                    do {
                        do {
                            TAG(prim)->code = k2d;
                        } while (0);
                    } while (0);
                } while (0);
                if (*(u8*)arg0 & 0x10) {
                    n = 0x2F;
                    TAG(prim)->code = n;
                }
                vB = (tile & 0xF0) - 1;
                vT = vB + 16;
                PH(prim, 0xE) = clut;
                PH(prim, 0x16) = (tile >> 8) | 0x20;
                if (vB == 0xFF) {
                    vB = 0;
                    y1--;
                }
                if ((attr & 0x40) == flip) {
                    uL = tile << 4;
                    uR = uL + 16;
                    if (uR == 0) {
                        uR = 0xFF;
                        x1--;
                    }
                } else {
                    uR = (tile << 4) - 1;
                    uL = uR + 16;
                    if (uR == 0xFF) {
                        uR = 0;
                        x1--;
                    }
                }
                word = 0xE1000020;
                PH(prim, 8) = x0;
                PH(prim, 0xA) = y0;
                PH(prim, 0x10) = x1;
                PH(prim, 0x12) = y0;
                PH(prim, 0x18) = x0;
                PH(prim, 0x1A) = y1;
                PH(prim, 0x20) = x1;
                PH(prim, 0x22) = y1;
                PB(prim, 0xC) = uL;
                PB(prim, 0xD) = vT;
                PB(prim, 0x14) = uR;
                PB(prim, 0x15) = vT;
                PB(prim, 0x1C) = uL;
                PB(prim, 0x1D) = vB;
                PB(prim, 0x24) = uR;
                PB(prim, 0x25) = vB;
                PW(tpage, 4) = word;
                TAG(tpage)->len = one;
                PW(tpage, 0) = (PW(tpage, 0) & mhi) | ((u32)prim & mlo);
                PW(prim, 0) = (PW(prim, 0) & mhi) | ((u32)(tpage + 8) & mlo);
                next = tpage + 8;
            }
        }
    }
    slot = arg0->unk16;
    hi4 = slot >> 4;
    lo3 = slot & 7;
    D_8008EB08[SP_BUFFER][hi4][lo3]->addr = (u32)SP_TPAGE;
    D_8008EB08[SP_BUFFER][hi4][lo3] = (X4_P_TAG*)(prim - 0x28);
    SP_PRIM = prim;
    SP_TPAGE = tpage;
}
