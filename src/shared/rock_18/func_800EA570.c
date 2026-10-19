#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002AA74();

void func_800EA570(u8* arg0) {
    extern s8 D_80097420[];
    u8* e = (u8*)D_80097420;

    if (((s8*)e)[4] == 0) {
        if (e[8] != 0) {
            arg0[0] = 8;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
        }
        func_8002AA74();
    }
}
