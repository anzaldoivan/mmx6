#include "common.h"

#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCEED;

void func_800E9CF8(void* arg0) {
    if (D_800CCEED == 1) {
        D_800971F8[1].unk4 = 5;
        *(s16*)((u8*)arg0 + 0x14) = D_800971F8[0].unk1C;
        ((u8*)arg0)[4]++;
    }
}
