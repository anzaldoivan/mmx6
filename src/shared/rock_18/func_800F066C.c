#include "common.h"

extern u16 D_8006D600[];
extern u16 D_80073610[];
extern u16 D_80073620[];
extern u8 D_800F1148[];

void func_800F066C(u8* arg0) {
    u8 i;
    u8 sel;
    u16 key;

    i = 0;
    arg0[3] = 1;
    {
        register s32 c1 asm("$6") = 1;

        if (D_80073610[arg0[2] & 0xF] == c1) {
            do {
                sel = 0;
            } while (0);
        } else {
        next:
            i++;
            if (i < 0x10) {
                register s32 one asm("$4") = 1;

                if ((one << i) == D_80073610[arg0[2] & 0xF]) {
                    sel = i;
                } else {
                    goto next;
                }
            }
        }
    }
    {
        register u16* tbl asm("$2") = D_8006D600;

        key = tbl[sel];
    }
    i = 0;
    do {
        if (key == D_80073620[0]) {
            arg0[0x47] = D_800F1148[0];
            return;
        }
    } while (0);
next2:
    i++;
    if (i < 8) {
        if (key == D_80073620[i]) {
            arg0[0x47] = D_800F1148[i];
        } else {
            goto next2;
        }
    }
}
