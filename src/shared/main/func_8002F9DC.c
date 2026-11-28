#include "common.h"
#include "mmx6/x4.h"

extern u8 D_800E4191;
extern s16 D_800E41A4;
u8 func_80030304(struct X4_PlayerObj*, s16, s16);
s32 func_80030834(struct X4_PlayerObj* arg0, s16 arg1, s16 arg2, s32 arg3);

s32 func_8002F9DC(struct X4_PlayerObj* o, u8 t, s16 a, s16 b) {
    s32 f = 0;
    s16 c;
    s16 h;

    if (t == 0x10) {
        f = 1;
        o->y_pos.i.hi -= 0x10;
        t = func_80030304(o, a, b - 0x10);
    }
    switch (t) {
    case 0x9:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x1C:
        t &= 0xF;
        c = a & 0xF;
        if (t == 0xA) {
            c += 0x10;
        }
        if (t == 0xC) {
            c += 0x10;
        }
        h = t >= 0xB ? c / 2 : 0xF - c / 2;
        return func_80030834(o, b, h, f);
    case 0x1:
    case 0x2:
    case 0x3:
    case 0x4:
    case 0x5:
    case 0x6:
    case 0x7:
    case 0x8:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
        t &= 0xF;
        c = a & 0xF;
        if (t == 2) {
            c += 0x10;
        }
        if (t == 6) {
            c += 0x10;
        }
        if (t == 3) {
            c += 0x20;
        }
        if (t == 7) {
            c += 0x20;
        }
        if (t == 4) {
            c += 0x30;
        }
        if (t == 8) {
            c += 0x30;
        }
        h = t >= 5 ? c / 4 : 0xF - c / 4;
        return func_80030834(o, b, h, f);
    case 0x21:
    case 0x22:
    case 0x38:
    case 0x39:
    case 0x3A:
    case 0x3C:
    case 0x3E:
    case 0x3F:
        D_800E4191 |= 8;
        D_800E41A4 = -o->unk6E;
        return -1;
    case 0:
        return 0;
    default:
        return 0;
    }
}
