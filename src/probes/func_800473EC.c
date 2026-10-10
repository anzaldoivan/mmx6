/* Probe (phase 1.4 T6): lb of an s8 global, sltiu, halfword decrement. Game TU 120A0. */
#include "common.h"

extern s8 D_800970A5;
extern u8 D_800CCF38;

void func_800473EC(Probe800473EC* arg0) {
    if (D_800970A5 != 0) {
        arg0->unk1C += arg0->unk18;
        if (--arg0->unk16 == 0) {
            if (D_800CCF38 < 2) {
                arg0->unk18 = 0x10000;
            } else {
                arg0->unk18 = 0x14000;
            }
            arg0->unk14 = 0xB4;
            arg0->unk5++;
        }
    }
}
