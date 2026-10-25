#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA234(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[2].x_pos.i.hi = 0;
        background_objects[2].y_pos.i.hi = 0x100;
        background_objects[2].unk4C = 1;
        *(s16*)(arg0 + 8) = 0x26;
        *(s16*)(arg0 + 0xA) = 1;
        arg0[1]++;
    }
}
