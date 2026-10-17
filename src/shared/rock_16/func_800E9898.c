#include "common.h"

extern u8 D_800F1CB0[];
extern u8 D_800F1CEB;

void func_800E9898(u8* arg0) {
    D_800F1CEB = 1;
    D_800F1CB0[0] = 0;
    if (arg0[0x5F] & 1) {
        D_800F1CEB = 2;
        D_800F1CB0[1] = 1;
    }
    if (arg0[0x5F] & 0x10) {
        D_800F1CB0[D_800F1CEB++] = 5;
    }
    if (arg0[0x5F] & 2) {
        D_800F1CB0[D_800F1CEB++] = 2;
    }
    if (arg0[0x5F] & 4) {
        D_800F1CB0[D_800F1CEB++] = 3;
    }
    if (arg0[0x5F] & 8) {
        D_800F1CB0[D_800F1CEB++] = 4;
    }
}
