#include "common.h"

#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEED;

void func_800E9CF8(void* arg0) {
    if (D_800CCEED == 1) {
        background_objects[1].unk4 = 5;
        *(s16*)((u8*)arg0 + 0x14) = background_objects[0].unk1C;
        ((u8*)arg0)[4]++;
    }
}
