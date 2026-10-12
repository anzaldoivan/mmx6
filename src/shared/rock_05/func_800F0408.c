#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(void*);
extern u16 D_800F447E;
extern s16 D_800970AA;

void func_800F0408(u8* arg0) {
    s16 x;
    register s32 t asm("$3");

    func_80017A04();
    func_8002D2B0(arg0);
    x = *(s16*)(arg0 + 0xA);
    if (x < (s16)D_800F447E + 0x1030) {
        *(u16*)(arg0 + 0xA) = D_800F447E + 0x1030;
    } else if ((s16)D_800F447E + 0x1150 < x) {
        *(u16*)(arg0 + 0xA) = D_800F447E + 0x1150;
    }
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[6] = 5;
        return;
    }
    if (arg0[0x15] == 0) {
        t = *(s16*)(arg0 + 0xA);
        t = t < D_800970AA;
    } else {
        t = *(s16*)(arg0 + 0xA) > D_800970AA;
    }
    if (t) {
        *(s32*)(arg0 + 0x28) = -0x4000;
        arg0[6]++;
    }
}
