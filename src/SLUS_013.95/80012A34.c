#include "common.h"
#include "mmx6/globals.h"

extern u16 g_pad2_buttons[];
void func_80013064(void);

void func_80012A34(void) {
    u16 v;
    u16 old;
    u16 t;

    if (D_800CF920[0] == 0xFF ||
        ((t = D_800CF920[1] & 0xF0) != 0x40 && t != 0x70 && t != 0x50)) {
        v = 0;
    } else {
        v = D_800CF920[2] << 8;
        v = ~(v | D_800CF920[3]);
        if (t == 0x50) {
            t = (v << 1) & 4;
            if (v & 0x80) {
                t |= 2;
            }
            if (v & 4) {
                t |= 0x80;
            }
            if (v & 8) {
                t |= 0x10;
            }
            if (v & 0x10) {
                t |= 8;
            }
            {
                u16 m = v & 0xFF61;

                v = m | t;
            }
        }
        if ((v & 0xA000) == 0xA000) {
            v = g_pad1_buttons[1];
        } else if ((v & 0x5000) == 0x5000) {
            v = g_pad1_buttons[1];
        }
    }
    old = g_pad1_buttons[0];
    g_pad1_buttons[0] = v;
    g_pad1_buttons[1] = old;
    g_pad1_buttons[2] = v & (v ^ old);

    if (D_800CF870[0] == 0xFF ||
        ((t = D_800CF870[1] & 0xF0) != 0x40 && t != 0x70 && t != 0x50)) {
        v = 0;
    } else {
        v = D_800CF870[2] << 8;
        v = ~(v | D_800CF870[3]);
        if (t == 0x50) {
            t = (v << 1) & 4;
            if (v & 0x80) {
                t |= 2;
            }
            if (v & 4) {
                t |= 0x80;
            }
            if (v & 8) {
                t |= 0x10;
            }
            if (v & 0x10) {
                t |= 8;
            }
            {
                u16 m = v & 0xFF61;

                v = m | t;
            }
        }
        if ((v & 0xA000) == 0xA000) {
            v = g_pad2_buttons[1];
        } else if ((v & 0x5000) == 0x5000) {
            v = g_pad2_buttons[1];
        }
    }
    old = g_pad2_buttons[0];
    g_pad2_buttons[0] = v;
    g_pad2_buttons[1] = old;
    g_pad2_buttons[2] = v & (v ^ old);
    func_80013064();
}

#include "common.h"
#include "psyq/libpad.h"

extern s32 D_8006D894;
extern u8 D_8006D8A0[];
extern s32 D_8006D9A4;
#define D_8006D9A4 (*(u8**)&D_8006D9A4)
extern s8 D_8006D9A8;
#define D_8006D9A8 (*(u8*)&D_8006D9A8)

void func_80012C54(void) {
    s32 v;

    if (D_8006D894 != 0) {
        if (D_8006D9A4 != 0 && (u8)++D_8006D9A8 >= D_8006D9A4[2]) {
            D_8006D9A4 += 3;
            v = PadInfoMode(0, 2, 0);
            if (v == 4 || v == 7) {
                D_8006D8A0[0] = D_8006D9A4[0];
                D_8006D8A0[1] = D_8006D9A4[1];
            } else {
                D_8006D8A0[0] = 0x40;
                D_8006D8A0[1] = 1;
            }
            D_8006D9A8 = 0;
            if (D_8006D9A4[2] == 0) {
                D_8006D894 = 0;
                D_8006D9A4 = 0;
            }
        }
    } else {
        s32 w = PadInfoMode(0, 2, 0);
        if (w == 4 || w == 7) {
            D_8006D8A0[0] = 0;
            D_8006D8A0[1] = 0;
        } else {
            D_8006D8A0[0] = 0x40;
            D_8006D8A0[1] = 0;
        }
    }
}
#undef D_8006D9A4
#undef D_8006D9A8
