#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
extern s16 D_800F6AF0;

void func_800F3130(u8* arg0) {
    func_80017A04();
    if (((s8*)arg0)[7] == 2) {
        if (--((s8*)arg0)[0x89] == 0) {
            arg0[5] = 7;
            arg0[6] = 0;
            D_800F6AF0 = 0;
        } else {
            arg0[6]++;
        }
        arg0[7] = 0;
    }
}
