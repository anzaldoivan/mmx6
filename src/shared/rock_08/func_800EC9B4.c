#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
void* func_8002C458();

void func_800EC9B4(u8* arg0) {
    u8* p;

    ((void (*)(void*))func_80017A04)(arg0);
    if ((arg0[0x45] & 0xF) == 1) {
        p = func_8002C458();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 8;
            p[2] = arg0[0x86];
            if (((s8*)arg0)[3] != 0) {
                if (((s8*)p)[2] == 0) {
                    play_sound(2, 0xA, arg0);
                } else {
                    play_sound(2, 0x19, arg0);
                }
            }
            *(u16*)(p + 0x40) = *(u16*)(arg0 + 0x40);
            *(s16*)(p + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
            *(s32*)(p + 0x30) = *(s32*)(arg0 + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
            p[0x15] = arg0[0x15];
            *(s32*)(p + 0x8) = *(s32*)(arg0 + 0x8);
            *(s32*)(p + 0xC) = *(s32*)(arg0 + 0xC);
            p[4] = 0;
        }
        arg0[7] = 0;
    }
}
