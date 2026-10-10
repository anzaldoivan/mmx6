#include "common.h"

#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
extern u8 D_8006D5F7;
extern u16 D_8006D600[];
extern u8 D_8007360C[];
extern u16 D_80073610[];
extern u16 D_80073620[];
extern u16 D_800C456C[];

#define ENG_B(o) ((u8)D_80097420[o])
#define ENG_SB(o) (D_80097420[o])

void func_800EA0E8(u8* arg0) {
    extern s8 D_80097420[];
    u8 sel;
    u8 i;
    u8 k;
    u16 key;
    u16 old;

    if (ENG_SB(4) != 0) {
        return;
    }
    if (D_800C456C[2] & 0x800) {
        goto hit;
    }
    if ((D_800C456C[2] & 0x40) && ENG_B(7) == 0xB) {
    hit:
        func_80016C48(0, 0x22, 0);
        ((void (*)(s32))func_800139F4)(8);
        arg0[1]++;
        return;
    }
    if (D_800C456C[2] & 0x1000) {
        func_80016C48(0, 0xC, 0);
        if (ENG_B(7) == 0) {
            D_80097420[7] = 0xB;
        } else {
            D_80097420[7] = D_80097420[7] - 1;
        }
    }
    if (D_800C456C[2] & 0x4000) {
        func_80016C48(0, 0xC, 0);
        if (ENG_B(7) == 0xB) {
            D_80097420[7] = 0;
        } else {
            D_80097420[7] = D_80097420[7] + 1;
        }
    }
    sel = 0xFF;
    if (ENG_B(7) < 7) {
        i = 4;
        {
            register s32 c16 asm("$6") = 0x10;

            if (D_80073610[ENG_B(7)] == c16) {
                sel = 4;
            } else {
            next:
                i++;
                if (i < 0x10) {
                    register s32 one asm("$5") = 1;

                    if ((one << i) == D_80073610[ENG_B(7)]) {
                        do {
                            sel = i;
                        } while (0);
                    } else {
                        goto next;
                    }
                }
            }
        }
        if (sel == 0xFF) {
            return;
        }
        key = D_800C456C[2];
        for (i = 0; i < 8; i++) {
            if (key == D_80073620[i]) {
                func_80016C48(0, 0x22, 0);
                old = D_8006D600[sel];
                D_8006D600[sel] = D_80073620[i];
                for (k = 0; D_8006D600[k] != 0; k++) {
                    if (k != sel && D_8006D600[k] == D_80073620[i]) {
                        D_8006D600[k] = old;
                    }
                }
                return;
            }
        }
    } else if (ENG_B(7) < 0xB && (D_800C456C[2] & 0x40)) {
        func_80016C48(0, 0x22, 0);
        D_8006D5F7 ^= D_8007360C[ENG_B(7) - 7];
    }
}

#undef ENG_B
#undef ENG_SB
