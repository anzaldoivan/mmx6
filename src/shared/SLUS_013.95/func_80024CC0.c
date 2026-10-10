#include "common.h"
#include "mmx6/x4.h"

extern s16 D_80071DCC[][3];
extern struct X4_DrawInfo* D_8009B7A0;
extern struct X4_EngineObj D_800CCED0;

#define SP_1C (*(u8**)SP(0x01C))
#define SP_3C (*(u8**)SP(0x03C))
#define PRIM_NEXT (*(u8**)SP(0x108))
#define TPAGE_NEXT (*(u8**)SP(0x10C))
#define PB(p, o) (*(u8*)((p) + (o)))
#define PH(p, o) (*(s16*)((p) + (o)))
#define PW(p, o) (*(u32*)((p) + (o)))

void func_80024CC0(s32 arg0, u8 arg1) {
    u8* base;
    u8* ent;
    u8* src;
    u8* p;
    u8* t;
    s32 count;
    s8* e;
    u16 clut;
    s32 add;
    s32 flags;
    s16 x;
    s16 y;
    u8 b0;
    u32 tile;
    u32* ot;
    s32 w;
    u8 c;

    add = 0;
    flags = 0x21;
    if (arg0 == 10) {
        base = SP_1C + *(s32*)(SP_1C + 0x58);
    } else if (arg0 == 16) {
        base = SP_1C + *(s32*)(SP_1C + 0x5C);
    } else if (arg0 == 5 || arg0 == 18) {
        flags = 0;
        add = 0x1E00;
        base = SP_3C + *(s32*)SP_3C;
    } else {
        base = SP_1C + *(s32*)(SP_1C + 4);
    }
    ent = base + arg1 * 4;
    count = *(u16*)ent;
    p = PRIM_NEXT;
    t = TPAGE_NEXT;
    src = base + *(u16*)(ent + 2) * 4;
    clut = D_80071DCC[arg0][2];
    if (count != 0) {
        do {
            b0 = src[0];
            x = D_80071DCC[arg0][0] + (s8)src[2];
            y = D_80071DCC[arg0][1] + (s8)src[3];
            if ((u32)(arg0 - 0xE) < 2) {
                e = (s8*)&D_800CCED0;
                y += ((e[0x8C] - 0x20) >> 1) << 1;
            }
            {
                u32 h = (b0 & 3) << 8;
                tile = src[1] | h;
            }
            w = flags & 0x20;
            tile += add;
            if (w) {
                u16 q = tile / 80;
                tile = (u16)((q << 8) + tile % 80 + 0x5B0);
            }
            c = 0x7D;
            PB(p, 3) = 3;
            PB(p, 7) = c;
            PB(p, 0xC) = tile << 4;
            PB(p, 0xD) = tile & 0xF0;
            PH(p, 8) = x;
            PH(p, 0xA) = y;
            PH(p, 0xE) = clut + ((b0 & 0xC) >> 2);
            PB(t, 3) = 1;
            PW(t, 4) = (tile >> 8) | 0xE1000000;
            ((X4_P_TAG*)t)->addr = (u32)p;
            ((X4_P_TAG*)p)->addr = (u32)(t + 8);
            t += 8;
            p += 0x10;
            src += 4;
            count--;
        } while (count != 0);
    }
    ot = &D_8009B7A0->ordering_table.unk5[0];
    PW(p, -0x10) = (PW(p, -0x10) & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)TPAGE_NEXT & 0xFFFFFF);
    PRIM_NEXT = p;
    TPAGE_NEXT = t;
}
