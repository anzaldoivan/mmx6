#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139A0(s8);
M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK func_80026028();
M2C_UNK func_8002AB58();
extern s8 D_80097424;

void func_80034A88(s8* arg0) {
    switch (arg0[6]) {
    case 0:
        func_800139F4(0x20);
        arg0[6]++;
        func_80026028();
        break;
    case 1:
        if (D_80097424 == 0) {
            arg0[6]++;
        }
        func_80026028();
        break;
    case 2:
        func_8002AB58(arg0);
        break;
    case 3:
        func_800139A0(0x20);
        arg0[6]++;
        func_80026028();
        break;
    case 4:
        if (D_80097424 == 0) {
            arg0[5] = 2;
            arg0[6] = 0;
        } else {
            func_80026028();
        }
        break;
    }
}
