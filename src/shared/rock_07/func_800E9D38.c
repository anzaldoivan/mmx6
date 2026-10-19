#include "common.h"

#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;

void func_800E9D38(void* arg0) {
    u8* pl = (u8*)&D_800970A0;

    if (D_800970A0.unk5 == 2) {
        *(s32*)(pl + 0xF4) += 0x8000;
        ((u8*)arg0)[4]++;
    }
}
