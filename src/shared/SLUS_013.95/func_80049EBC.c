#include "common.h"

s32 func_8002D2D4();
extern u8 D_800E4470[];
#define D_800E4470 (*(u8*)&D_800E4470)

#define M2C_UNK s32
M2C_UNK func_8004A0C0(s8, s16, s16, s32);
void func_80049EBC(void* arg0, s8 arg1, u8 arg2, u8 arg3) {
    s16 x;
    s16 y;
    s32 n;

    arg2 &= func_8002D2D4();
    if (func_8002D2D4() & 1) {
        x = ((s16*)arg0)[5] + arg2;
    } else {
        x = ((s16*)arg0)[5] - arg2;
    }
    arg3 &= func_8002D2D4();
    if (func_8002D2D4() & 1) {
        y = ((s16*)arg0)[7] + arg3;
    } else {
        y = ((s16*)arg0)[7] - arg3;
    }
    n = D_800E4470 + 1;
    D_800E4470 = n;
    ((void (*)())func_8004A0C0)(arg1, x, y, (n & 1) ^ 1);
}
#undef D_800E4470
