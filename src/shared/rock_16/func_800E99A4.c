#include "common.h"

extern s32 D_800F0E74[];
extern s8 D_800F0ED4[];
extern s8 D_800F1C80[];
extern s8 D_800F1CD0[][5];

void func_800E99A4(u8* arg0) {
    s32* flags;
    s32* q;
    s8* d;
    s8* idx;
    s32 i;
    s32 j;
    s32 n;

    for (j = 0; j < 5; j++) {
        D_800F1CD0[0][j] = -1;
        D_800F1CD0[1][j] = -1;
    }

    flags = (s32*)(arg0 + 0x74);
    idx = (s8*)(arg0 + 0x8D);
    for (i = 0; i < 2; i++) {
        n = 0;
        for (j = 0; j < 0x12; j++) {
            if ((flags[i] & D_800F0E74[j]) && n < D_800F0ED4[idx[i]]) {
                D_800F1CD0[i][n] = j;
                n++;
            }
        }
        D_800F1C80[i] = n;
    }
    i = 0;
    q = flags;
    flags = 0;
    for (; i < 2; i++) {
        for (j = 0x12; j < 0x18; j++) {
            if (*(s32*)((u8*)q + (i << 2)) & D_800F0E74[j]) {
                D_800F1CD0[i][4] = j;
            }
        }
    }
}
