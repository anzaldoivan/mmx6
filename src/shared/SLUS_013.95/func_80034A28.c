#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80026028();
extern s8 D_80097424;

void func_80034A28(u8* arg0) {
    s8 temp_v1;

    if (D_80097424 == 0) {
        temp_v1 = ((s8*)arg0)[0x14];
        arg0[4] = 1;
        arg0[5] = 0;
        if (temp_v1 >= 0xD) {
            arg0[5] = 2;
        } else if (temp_v1 >= 0xA) {
            arg0[5] = 1;
        }
    }
    func_80026028();
}
