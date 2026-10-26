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
