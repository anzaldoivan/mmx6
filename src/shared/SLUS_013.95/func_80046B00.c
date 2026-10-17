#include "common.h"
#include "mmx6/x4.h"

s32 func_8002CB50(struct X4_BaseObj*);
extern u16 D_8006D600[];
extern u16 D_80073610[];
extern u16 D_80073620[];
extern u8 D_80076298[];

void func_80046B00(struct X4_BaseObj* arg0) {
    u8 i;
    s32 sel;
    u16 btn;
    // !FAKE: depin: dropping it breaks the match (61/67)
    register s32 one asm("$6") = 1;

    i = 0;
    if (D_80073610[arg0->unk2] == one) {
        sel = 0;
    } else {
    next:
        i++;
        if (i < 16) {
            // !FAKE: depin: dropping it breaks the match (61/67)
            register s32 b asm("$5") = 1;

            if ((b << i) == D_80073610[arg0->unk2]) {
                do {
                    sel = i;
                } while (0);
            } else {
                // !FAKE: goto: rotated loop shape of twin rock_18 func_800EA0E8 (block order)
                goto next;
            }
        }
    }
    btn = D_8006D600[sel];
    for (i = 0; i < 8; i++) {
        if (btn == D_80073620[i]) {
            ((u8*)arg0)[0x47] = D_80076298[i];
            break;
        }
    }
    ((s32(*)())func_8002CB50)(arg0, btn, one, i);
}
