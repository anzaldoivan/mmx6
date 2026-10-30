#include "common.h"
#include "mmx6/x4.h"

s32 random_byte();
extern struct X4_PlayerObj g_Player;
extern u8 D_800FD4E4[];

void func_800FA01C(u8* arg0) {
    if (arg0[0x8E] != 0) {
        arg0[0x8E]--;
    }
    {
        volatile u8* pl = (u8*)&g_Player;
        arg0[0x93] = pl[0xA4];
    }
    if (*(s8*)(arg0 + 7) >= 2) {
        u8 c;
        u8 t;
        *(s16*)(arg0 + 0x7C) = (u8)((u32)random_byte() % 6);
        c = arg0[6];
        t = D_800FD4E4[*(s8*)(arg0 + 0x90) + *(s8*)(arg0 + 0x91) * 4];
        arg0[7] = 0;
        arg0[6] = c + 1;
        *(s16*)(arg0 + 0x7E) = (s8)t;
    }
}
