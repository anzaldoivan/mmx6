#include "common.h"

extern u16 D_800C456C[];
extern u16 D_800C4758[];
extern u8 D_800CF870[];
extern u8 D_800CF920[];
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
            v = D_800C456C[1];
        } else if ((v & 0x5000) == 0x5000) {
            v = D_800C456C[1];
        }
    }
    old = D_800C456C[0];
    D_800C456C[0] = v;
    D_800C456C[1] = old;
    D_800C456C[2] = v & (v ^ old);

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
            v = D_800C4758[1];
        } else if ((v & 0x5000) == 0x5000) {
            v = D_800C4758[1];
        }
    }
    old = D_800C4758[0];
    D_800C4758[0] = v;
    D_800C4758[1] = old;
    D_800C4758[2] = v & (v ^ old);
    func_80013064();
}
