#include "common.h"
#include "mmx6/x4.h"

extern void (*D_8006E348[])();
extern u8 D_8008EC08;
extern u8 D_800DF998;
extern u16 D_800E01D4;
extern u16 D_800E01D6;
extern struct X4_CdCompletionSlot D_800E01E8[16];

void func_80015C5C(void) {
    while (D_800E01E8[D_800DF998].pending != 0) {
        D_8006E348[D_800E01E8[D_800DF998].callback]();
        D_800E01E8[D_800DF998].pending = 0;
        D_800DF998++;
        if (D_800DF998 == 0x20) {
            D_800DF998 = 0;
        }
        D_800E01D4++;
    }
    if (D_800E01D6 == D_800E01D4) {
        D_8008EC08 = 0;
    }
}
