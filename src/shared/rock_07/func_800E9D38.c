#include "common.h"

#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;

void func_800E9D38(void* arg0) {
    u8* pl = (u8*)&g_Player;

    if (g_Player.unk5 == 2) {
        *(s32*)(pl + 0xF4) += 0x8000;
        ((u8*)arg0)[4]++;
    }
}
