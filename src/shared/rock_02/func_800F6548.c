#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D2B0(s32);
extern u16 D_8009721A;
#define D_8009721A (*(s16*)&D_8009721A)

void func_800F6548(u8* arg0) {
    s32 lim;
    s32 y;
    ((void (*)(s32))func_8002D2B0)((s32)arg0);
    lim = D_8009721A - 0x60;
    y = *(s16*)(arg0 + 0xE);
    y = y < lim;
    if (y) {
        register s32 c asm(
            "$2"); // !FAKE: depin: dropping it breaks the match (20/23)
        func_80021760(6, 0xFF, 0);
        c = arg0[6];
        arg0[3] = 0;
        arg0[6] = c + 1;
    }
}
#undef D_8009721A
