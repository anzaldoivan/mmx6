#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003D26C(void*);

void func_801EC878(void* arg0) {
    s32 v;

    if (*(s8*)((u8*)arg0 + 0x46) == 0) {
        v = *(s32*)((u8*)arg0 + 0x24);
        if (v > 0) {
            func_8003BA04(arg0, 0xAC);
        } else if (v < 0) {
            func_8003BA04(arg0, 0xAD);
        } else {
            func_8003BA04(arg0, 0xAB);
        }
        *(u8*)((u8*)arg0 + 0x8C) = 1;
        func_8003D26C(arg0);
        *(u8*)((u8*)arg0 + 6) = *(u8*)((u8*)arg0 + 6) + 1;
    }
}
