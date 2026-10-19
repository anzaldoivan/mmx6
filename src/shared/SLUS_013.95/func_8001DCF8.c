#include "common.h"
#define M2C_UNK s32

void func_800139F4(s32);
extern u16 D_800C4570;

void func_8001DCF8(u8* arg0) {
    s32 flag;
    s16 t;

    t = --*(s16*)(arg0 + 4);
    flag = 0;
    if (t < 0x12D) {
        flag = (D_800C4570 & 0x8F0) != 0;
    }
    if (t <= 0) {
        flag = 1;
    }
    if (flag != 0) {
        arg0[1]++;
        ((void (*)(s32))func_800139F4)(8);
    }
}
