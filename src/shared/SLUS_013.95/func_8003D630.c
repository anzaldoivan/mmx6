#include "common.h"
#define M2C_UNK s32

void func_8003D598(void*);

M2C_UNK func_8003D630(void* arg0) {
    u8* p = arg0;

    func_8003D598(p);
    if (*(s32*)(p + 0xEC) & 8) {
        *(s32*)(p + 0x134) -= 0x1080;
    }
    if (*(u8*)(p + 0xE7) == 2) {
        *(s32*)(p + 0x110) = 0;
    }
    if (*(s32*)(p + 0xEC) & 0x10) {
        *(s32*)(p + 0x104) += 0x1A000;
        *(s32*)(p + 0x108) += 0x10800;
        *(s32*)(p + 0x10C) += 0xC00;
        *(s32*)(p + 0x12C) += 0x10800;
        *(s32*)(p + 0x130) += 0x10800;
    }
    if (*(s32*)(p + 0xEC) & 4) {
        *(s32*)(p + 0xF0) += 0x4000;
        *(s32*)(p + 0xF4) += 0x10000;
    }
}
