#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 func_8002B2F8(s32);
s32 func_800EA480(s8* arg0);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s8 D_8009742C;
extern s8 D_800CF850;

void func_800FA330(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        func_8002B2F8(0);
        D_8009742C = 0;
        D_80090D56 = 0;
        D_800CF850 = 0;
        D_80090C90[0] = 0;
        D_80090C90[1] = -1;
        D_80090C90[2] = -1;
        D_80090C90[3] = -1;
        D_80090C90[4] = -1;
        D_80090C90[5] = -1;
        D_80090C90[6] = -1;
        D_80090C90[7] = -1;
        D_80090C90[8] = -1;
        D_80090C90[9] = -1;
        play_sound(0, 8, 0);
        play_sound(0, 6, 0);
        arg0[1]++;
    }
}
