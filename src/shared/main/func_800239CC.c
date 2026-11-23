#include "common.h"
#include "mmx6/x4.h"

extern X4_P_TAG* D_8008EB08[2][4][8];
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_DrawInfo* g_cur_draw_info;

#define SP_BUFFER (*(s32*)0x1F800000)
#define SP_PRIM (*(u8**)0x1F800100)
#define SP_TPAGE (*(u8**)0x1F800104)
#define SP_COUNT (*(s32*)0x1F800124)

#define PW(p, o) (*(u32*)((p) + (o)))
#define PH(p, o) (*(s16*)((p) + (o)))
#define PB(p, o) (*(u8*)((p) + (o)))
#define TAG(p) ((X4_P_TAG*)(p))

void func_800239CC(struct X4_AnimatedObj* arg0) {
    s16 x;
    s16 y;
    u8* prim;
    u8* tpage;
    u8* base;
    u16* hdr;
    u8* spr;
    s32 flip;
    s32 tbase;
    u16 clut;
    s32 count;
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;
    u32 tile;
    u8 flags;
    u8 attr;
    u8* next;
    u32 hi;
    u8 u0;
    u8 u1;
    u8 v0;
    u32 slot;
    u32 hi4;
    u32 lo3;

    if (SP_COUNT < 1000) {
        if (arg0->bg_offset < 0) {
            x = arg0->x_pos.i.hi;
            y = arg0->y_pos.i.hi;
        } else {
            x = arg0->x_pos.i.hi -
                background_objects[arg0->bg_offset].x_pos.i.hi;
            y = arg0->y_pos.i.hi -
                background_objects[arg0->bg_offset].y_pos.i.hi;
        }
        prim = SP_PRIM;
        tpage = SP_TPAGE;
        base = arg0->unk3C;
        flip = arg0->unk15;
        tbase = arg0->unk40;
        clut = arg0->unk42;
        hdr = (u16*)(base + arg0->animation_step.fields.frame_index * 4);
        count = hdr[0];
        spr = base + hdr[1] * 4;
        for (; count != 0; count--, spr += 4) {
            if (SP_COUNT >= 1000) {
                return;
            }
            SP_COUNT++;
            x0 = (s8)spr[2];
            slot = 1;
            attr = spr[0];
            if (flip == 0) {
                x1 = x0 + 16;
                slot = 2;
            } else {
                x1 = -x0;
                slot = 3;
                x0 = -(x0 + 16);
                slot = 4;
            }
            x0 = x0 + x;
            slot = 5;
            x1 = x1 + x;
            slot = 6;
            y0 = y + (s8)spr[3];
            slot = 7;
            y1 = y0 + 16;
            slot = 8;
            tile = spr[1] | ((attr & 3) << 8);
            slot = 9;
            tile = tile * 2;
            slot = 10;
            tile = (u16)(tile + tbase);
            slot = 11;
            flags = *(u8*)arg0;
            if ((flags & 0x60) == 0x60) {
                tile = (((tile >> 4) << 8) + (tile & 0xF) + 0x600) & 0xFFFF;
                slot = 12;
            } else if (flags & 0x40) {
                tile = ((((tile / 160) & 0xFFFF) << 8) + (tile % 160) + 0x610) &
                       0xFFFF;
                slot = 13;
            } else if (flags & 0x20) {
                tile = ((((tile / 80) & 0xFFFF) << 8) + (tile % 80) + 0x5B0) &
                       0xFFFF;
                slot = 14;
            }
            if (!(flip & 0x40)) {
                v0 = tile & 0xF0;
                TAG(prim)->len = 3;
                TAG(prim)->code = 0x7D;
                slot = 15;
                if (*(u8*)arg0 & 0x10) {
                    TAG(prim)->code = 0x7F;
                }
                u1 = (tile * 8) & 0x70;
                PB(prim, 0xC) = u1;
                slot = 16;
                PH(prim, 0xE) = clut;
                slot = 17;
                PH(prim, 8) = x0;
                slot = 18;
                PH(prim, 0xA) = y0;
                slot = 19;
                PB(prim, 0xD) = v0;
                slot = 20;
                TAG(tpage)->len = 1;
                PW(tpage, 4) = (tile >> 8) | 0xE10000A0;
                TAG(tpage)->addr = (u32)prim;
                TAG(prim)->addr = (u32)(tpage + 8);
                next = tpage + 8;
            } else {
                TAG(prim)->len = 9;
                TAG(prim)->code = 0x2D;
                slot = 21;
                if (*(u8*)arg0 & 0x10) {
                    TAG(prim)->code = 0x2F;
                }
                u0 = (tile * 8) & 0x70;
                hi = tile >> 8;
                PH(prim, 0x16) = hi | 0xA0;
                PH(prim, 0xE) = clut;
                if (u0 == 0) {
                    PH(prim, 0x16) = (hi - 1) | 0xA0;
                    u0 = 0x80;
                }
                u0 = u0 - 1;
                u1 = u0 + 0x10;
                if (u0 == 0xFF) {
                    u0 = 0;
                    x1--;
                }
                v0 = tile & 0xF0;
                tile = (v0 + 0x10) & 0xFF;
                if (tile == 0) {
                    tile = 0xFF;
                    y1--;
                }
                PH(prim, 8) = x0;
                PH(prim, 0xA) = y0;
                PH(prim, 0x10) = x1;
                PH(prim, 0x12) = y0;
                PH(prim, 0x18) = x0;
                PH(prim, 0x1A) = y1;
                PH(prim, 0x20) = x1;
                PH(prim, 0x22) = y1;
                PB(prim, 0xC) = u1;
                PB(prim, 0xD) = v0;
                PB(prim, 0x14) = u0;
                PB(prim, 0x15) = v0;
                PB(prim, 0x1C) = u1;
                PB(prim, 0x1D) = tile;
                PB(prim, 0x24) = u0;
                PB(prim, 0x25) = tile;
                {
                    u8 one = 1;
                    TAG(tpage)->len = one;
                }
                PW(tpage, 4) = 0xE1000020;
                TAG(tpage)->addr = (u32)prim;
                TAG(prim)->addr = (u32)(tpage + 8);
                next = tpage + 8;
            }
            prim += 0x28;
            tpage = next;
        }
        slot = arg0->unk16;
        if ((slot & 0xFF) == 0xFF) {
            TAG(prim - 0x28)->addr =
                TAG(&g_cur_draw_info->ordering_table.fade)->addr;
            TAG(&g_cur_draw_info->ordering_table.fade)->addr = (u32)SP_TPAGE;
        } else {
            hi4 = (slot & 0xFF) >> 4;
            lo3 = slot & 7;
            D_8008EB08[SP_BUFFER][hi4][lo3]->addr = (u32)SP_TPAGE;
            D_8008EB08[SP_BUFFER][hi4][lo3] = (X4_P_TAG*)(prim - 0x28);
        }
        SP_PRIM = prim;
        SP_TPAGE = tpage;
    }
}
