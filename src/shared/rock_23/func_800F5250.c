#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
extern u16 D_8009721A;
#define D_8009721A (*(s16*)&D_8009721A)

void func_800F5250(u8* arg0) {
    s32 lim;
    s32 y;
    ((void (*)(s32))move_object)((s32)arg0);
    lim = D_8009721A - 0x60;
    y = *(s16*)(arg0 + 0xE);
    y = y < lim;
    if (y) {
        // !FAKE: inherited from src/shared/rock_02/func_800F6548.c
        // !FAKE: depin: dropping it breaks the match (20/23)
        register s32 c asm("$2");
        func_80021760(6, 0xFF, 0);
        c = arg0[6];
        arg0[3] = 0;
        arg0[6] = c + 1;
    }
}
#undef D_8009721A
