#include "common.h"
#include "mmx6/x4.h"

extern X4_P_TAG* D_8008EB08[2][4][8];
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_DrawInfo* D_8009B7A0;

#define SP_PRIM_COUNT (*(s32*)SP(0x124))
#define SP_PRIM_NEXT (*(u8**)SP(0x100))
#define SP_MODE_NEXT (*(u8**)SP(0x104))
#define PB(p, o) (*(u8*)((p) + (o)))
#define PH(p, o) (*(s16*)((p) + (o)))
#define PW(p, o) (*(u32*)((p) + (o)))

void func_800232D4(struct X4_VisualObj* obj) {
    s16 sx;
    s16 sy;
    u8* prim;
    u8* mode;
    u8* frames;
    u8* entry;
    u8* tile_ptr;
    s32 count;
    u16 q;
    u8 flip;
    s32 tbase;
    u16 pal;
    u8 attr;
    u16 clut;
    u16 tile;
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;
    u8 ul;
    u8 ur;
    u8 vt;
    u8 vb;
    u32 tpage;
    u8 flags;
    u32 idx;
    u32 hi;
    u32 lo;

    if (SP_PRIM_COUNT < 1000) {
        if (obj->bg_offset < 0) {
            sx = obj->x_pos.i.hi;
            sy = obj->y_pos.i.hi;
        } else {
            sx = obj->x_pos.u.hi - D_800971F8[obj->bg_offset].x_pos.u.hi;
            sy = obj->y_pos.u.hi - D_800971F8[obj->bg_offset].y_pos.u.hi;
        }
        prim = SP_PRIM_NEXT;
        mode = SP_MODE_NEXT;
        frames = obj->unk3C;
        flip = obj->unk15;
        entry = frames + obj->animation_step.fields.frame_index * 4;
        count = *(u16*)entry;
        tile_ptr = frames + *(u16*)(entry + 2) * 4;
        tbase = obj->unk40;
        pal = obj->unk42;
        if (count != 0) {
            do {
                if (SP_PRIM_COUNT >= 1000) {
                    hi = obj->unk16 >> 4;
                    lo = obj->unk16 & 7;
                    D_8008EB08[SP_DRAW_BUFFER][hi][lo]->addr =
                        (u32)SP_MODE_NEXT;
                    D_8008EB08[SP_DRAW_BUFFER][hi][lo] =
                        (X4_P_TAG*)(prim - 0x28);
                    SP_PRIM_NEXT = prim;
                    SP_MODE_NEXT = mode;
                    return;
                }
                SP_PRIM_COUNT++;
                attr = tile_ptr[0];
                clut = 0x7840;
                if (!(pal & 0x8000)) {
                    clut = pal + ((attr & 0xC) >> 2);
                }
                if (attr & 0x20) {
                    x0 = (s8)tile_ptr[2];
                    x0 <<= 1;
                    if (attr & 0x80) {
                        x0 |= 1;
                    }
                    x0 += sx;
                    y0 = sy + (s8)tile_ptr[3];
                    tile = ((attr & 1) << 8) | tile_ptr[1];
                    tile += tbase;
                    PB(prim, 3) = 3;
                    PB(prim, 7) = 0x7C;
                    PB(prim, 7) |= 1;
                    (obj->active & 0x10) ? (PB(prim, 7) |= 2)
                                         : (PB(prim, 7) &= ~2);
                    vt = tile & 0xF0;
                    PB(prim, 0xC) = tile << 4;
                    tpage = (tile >> 8) | 0xE1000020;
                    PH(prim, 0xE) = clut;
                    PH(prim, 8) = x0;
                    PH(prim, 0xA) = y0;
                    PB(prim, 0xD) = vt;
                    PW(mode, 4) = tpage;
                    ((X4_P_TAG*)mode)->len = 1;
                    ((X4_P_TAG*)mode)->addr = (u32)prim;
                    ((X4_P_TAG*)prim)->addr = (u32)(mode + 8);
                } else {
                    x0 = (s8)tile_ptr[2];
                    if (flip == 0) {
                        x1 = x0 + 0x10;
                    } else {
                        x1 = -x0;
                        x0 = -(x0 + 0x10);
                    }
                    x0 += sx;
                    x1 += sx;
                    flags = obj->active;
                    y0 = sy + (s8)tile_ptr[3];
                    y1 = y0 + 0x10;
                    tile = ((attr & 3) << 8) | tile_ptr[1];
                    tile += tbase;
                    if ((flags & 0x60) == 0x60) {
                        tile = ((tile >> 4) << 8) + (tile & 0xF) + 0x600;
                    } else if (flags & 0x40) {
                        q = tile / 160;
                        tile = (q << 8) + (tile % 160) + 0x610;
                    } else if (flags & 0x20) {
                        q = tile / 80;
                        tile = (q << 8) + (tile % 80) + 0x5B0;
                    }
                    if (!(attr & 0x80)) {
                        vt = tile & 0xF0;
                        if ((attr & 0x40) == flip) {
                            PB(prim, 3) = 3;
                            PB(prim, 7) = 0x7C;
                            PB(prim, 7) |= 1;
                            (obj->active & 0x10) ? (PB(prim, 7) |= 2)
                                                 : (PB(prim, 7) &= ~2);
                            PB(prim, 0xC) = tile << 4;
                            tpage = (tile >> 8) | 0xE1000020;
                            PH(prim, 0xE) = clut;
                            PH(prim, 8) = x0;
                            PH(prim, 0xA) = y0;
                            PB(prim, 0xD) = vt;
                            PW(mode, 4) = tpage;
                            ((X4_P_TAG*)mode)->len = 1;
                            ((X4_P_TAG*)mode)->addr = (u32)prim;
                            ((X4_P_TAG*)prim)->addr = (u32)(mode + 8);
                            // !FAKE: skip the POLY_FT4 path to the step; retail cross-jumps the tails
                            goto next;
                        }
                        PB(prim, 3) = 9;
                        PB(prim, 7) = 0x2C;
                        PB(prim, 7) |= 1;
                        (obj->active & 0x10) ? (PB(prim, 7) |= 2)
                                             : (PB(prim, 7) &= ~2);
                        ur = (tile << 4) - 1;
                        ul = ur + 0x10;
                        PH(prim, 0x16) = (tile >> 8) | 0x20;
                        PH(prim, 0xE) = clut;
                        if (ur == 0xFF) {
                            ur = 0;
                            x1--;
                        }
                        vb = vt + 0x10;
                        if (vb == 0) {
                            vb = 0xFF;
                            y1--;
                        }
                        tpage = 0xE1000020;
                        PH(prim, 8) = x0;
                        PH(prim, 0xA) = y0;
                        PH(prim, 0x10) = x1;
                        PH(prim, 0x12) = y0;
                        PH(prim, 0x18) = x0;
                        PH(prim, 0x1A) = y1;
                        PH(prim, 0x20) = x1;
                        PH(prim, 0x22) = y1;
                        PB(prim, 0xC) = ul;
                        PB(prim, 0xD) = vt;
                        PB(prim, 0x14) = ur;
                        PB(prim, 0x15) = vt;
                        PB(prim, 0x1C) = ul;
                        PB(prim, 0x1D) = vb;
                        PB(prim, 0x24) = ur;
                        PB(prim, 0x25) = vb;
                        PW(mode, 4) = tpage;
                        ((X4_P_TAG*)mode)->len = 1;
                        ((X4_P_TAG*)mode)->addr = (u32)prim;
                        ((X4_P_TAG*)prim)->addr = (u32)(mode + 8);
                    } else {
                        PB(prim, 3) = 9;
                        PB(prim, 7) = 0x2C;
                        PB(prim, 7) |= 1;
                        (obj->active & 0x10) ? (PB(prim, 7) |= 2)
                                             : (PB(prim, 7) &= ~2);
                        vb = (tile & 0xF0) - 1;
                        vt = vb + 0x10;
                        PH(prim, 0xE) = clut;
                        PH(prim, 0x16) = (tile >> 8) | 0x20;
                        if (vb == 0xFF) {
                            vb = 0;
                            y1--;
                        }
                        if ((attr & 0x40) == flip) {
                            ul = tile << 4;
                            ur = ul + 0x10;
                            if (ur == 0) {
                                ur = 0xFF;
                                x1--;
                            }
                        } else {
                            ur = (tile << 4) - 1;
                            ul = ur + 0x10;
                            if (ur == 0xFF) {
                                ur = 0;
                                x1--;
                            }
                        }
                        tpage = 0xE1000020;
                        PH(prim, 8) = x0;
                        PH(prim, 0xA) = y0;
                        PH(prim, 0x10) = x1;
                        PH(prim, 0x12) = y0;
                        PH(prim, 0x18) = x0;
                        PH(prim, 0x1A) = y1;
                        PH(prim, 0x20) = x1;
                        PH(prim, 0x22) = y1;
                        PB(prim, 0xC) = ul;
                        PB(prim, 0xD) = vt;
                        PB(prim, 0x14) = ur;
                        PB(prim, 0x15) = vt;
                        PB(prim, 0x1C) = ul;
                        PB(prim, 0x1D) = vb;
                        PB(prim, 0x24) = ur;
                        PB(prim, 0x25) = vb;
                        PW(mode, 4) = tpage;
                        ((X4_P_TAG*)mode)->len = 1;
                        ((X4_P_TAG*)mode)->addr = (u32)prim;
                        ((X4_P_TAG*)prim)->addr = (u32)(mode + 8);
                    }
                }
            next:
                prim += 0x28;
                mode += 8;
                tile_ptr += 4;
            } while (--count != 0);
        }
        idx = obj->unk16;
        if ((u8)idx == 0xFF) {
            ((X4_P_TAG*)(prim - 0x28))->addr =
                ((X4_P_TAG*)&D_8009B7A0->ordering_table.fade)->addr;
            ((X4_P_TAG*)&D_8009B7A0->ordering_table.fade)->addr =
                (u32)SP_MODE_NEXT;
        } else {
            hi = (u8)idx >> 4;
            lo = idx & 7;
            D_8008EB08[SP_DRAW_BUFFER][hi][lo]->addr = (u32)SP_MODE_NEXT;
            D_8008EB08[SP_DRAW_BUFFER][hi][lo] = (X4_P_TAG*)(prim - 0x28);
        }
        SP_PRIM_NEXT = prim;
        SP_MODE_NEXT = mode;
    }
}

#undef SP_PRIM_COUNT
#undef SP_PRIM_NEXT
#undef SP_MODE_NEXT
#undef PB
#undef PH
#undef PW
