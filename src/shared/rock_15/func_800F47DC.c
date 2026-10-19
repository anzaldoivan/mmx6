#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(s32);

void func_800F47DC(void* arg0) {
    ((void (*)())func_80017A04)(arg0);
    if (*(s8*)((u8*)arg0 + 0x92) != 0) {
        (*(s8*)((u8*)arg0 + 0x92))--;
        return;
    }
    if (*(s16*)((u8*)arg0 + 0x8C) != 0) {
        (*(s16*)((u8*)arg0 + 0x8C))--;
        func_8002D2B0(arg0);
    }
    if ((*((u8*)arg0 + 0x70) & 2) || (*(s16*)((u8*)arg0 + 0x8C) == 0)) {
        *(s32*)((u8*)arg0 + 0x20) = 0x20000;
        *(s16*)((u8*)arg0 + 0x8C) = 0x30;
        *(s8*)((u8*)arg0 + 0x92) = 0x3C;
        (*((u8*)arg0 + 6))--;
    }
}
