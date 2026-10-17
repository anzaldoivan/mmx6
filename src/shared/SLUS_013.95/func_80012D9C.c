#include "common.h"

extern s32 func_8006AA54();
extern s32 D_8006D894;
extern u8 D_8006D8A0[];
extern u8* D_8006D978[];
extern s32 D_8006D9A4;
#define D_8006D9A4 (*(u8**)&D_8006D9A4)
extern s8 D_8006D9A8;
extern s8 D_80097426;
extern u8 D_800CCF99;
extern u8 D_800CF900;

void func_80012D9C(s32 arg0) {
    s32 v;

    if (D_80097426 == 0) {
        if (!(D_800CCF99 & 4)) {
            D_8006D894 = 0;
            D_8006D9A4 = 0;
            D_8006D9A8 = 0;
            return;
        }
        if (D_8006D894 == 0 || arg0 <= D_800CF900) {
            D_8006D894 = 1;
            D_8006D9A8 = 0;
            D_8006D9A4 = D_8006D978[arg0];
            D_800CF900 = arg0;
            v = func_8006AA54(0, 2, 0);
            if (v == 4 || v == 7) {
                D_8006D8A0[0] = D_8006D9A4[0];
                D_8006D8A0[1] = D_8006D9A4[1];
                return;
            }
            D_8006D8A0[0] = 0x40;
            D_8006D8A0[1] = 1;
        }
    }
}
#undef D_8006D9A4
