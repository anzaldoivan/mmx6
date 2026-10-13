#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();

void func_800F5EEC(u8* arg0) {
    if (*(u16*)(arg0 + 0x7C) & 1) {
        arg0[3] = 1;
        func_80017A04();
    } else {
        arg0[3] = 0;
    }
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[3] = 0;
        if (--*(s16*)(arg0 + 0x7E) == 0) {
            arg0[4] = 4;
            return;
        }
        arg0[6] = 1;
    }
}
