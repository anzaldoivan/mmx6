#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_8001854C(void);
M2C_UNK func_80018774(M2C_UNK);
extern u8 D_8008EAFC;
extern u8 D_800CD40C;

void func_80051B74(s8* arg0) {
    if (arg0[6] == 0) {
        if (D_8008EAFC == 0) {
            func_80018774(3);
            arg0[6]++;
        }
    } else if (D_800CD40C == 0) {
        func_8001854C();
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0xC);
        arg0[6] = 0;
        arg0[5]++;
    }
}
