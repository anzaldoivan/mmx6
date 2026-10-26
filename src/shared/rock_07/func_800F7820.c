#include "common.h"
#include "psyq/libgte.h"

extern s32 D_800F9794;
extern s32 D_800F9798;
extern s32 D_800F979C;

void func_800F7820(u8* arg0) {
    s32 m;

    arg0[3] = 1;
    *(s32**)(arg0 + 0x50) = &D_800F9794;
    *(s32**)(arg0 + 0x54) = &D_800F9798;
    *(s32**)(arg0 + 0x68) = &D_800F979C;
    m = rcos(*(s32*)(arg0 + 0x84)) * 0x10;
    *(s32*)(arg0 + 0x20) = m * 2 + m;
    m = rsin(*(s32*)(arg0 + 0x84)) * 0x10;
    *(s32*)(arg0 + 0x24) = m * 2 + m;
    if (*(s32*)(arg0 + 0x20) > 0) {
        arg0[0x15] = 0x40;
    } else {
        arg0[0x15] = 0;
    }
    *(s16*)(arg0 + 0x88) = 0x20;
    arg0[6]++;
}
