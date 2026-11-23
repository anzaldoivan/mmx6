// rolefeed (3.1 T4): func_800F3130 of src/rock_08/E9860.c

#include "common.h"
extern s16 D_800F6AF0;
#define M2C_UNK s32

M2C_UNK animate_object();

void func_800F3130(u8* arg0) {
    animate_object();
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
