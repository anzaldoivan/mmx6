#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern s16 D_800970AA;
extern s16 D_800F6AF2;

void func_800F341C(u8* arg0) {
    s32 temp_a1;
    s32 y;

    y = *(s16*)(arg0 + 0xA) + 0x10;
    temp_a1 = ((D_800970AA - y) << 0x10) / 40;
    *(s32*)(arg0 + 0x28) = 0;
    {
        s32 k1 = 0x1400;
        *(s32*)(arg0 + 0x2C) = k1;
    }
    {
        // !FAKE: depin: dropping it breaks the match (36/42)
        register s32 k2 asm("$2") = 0x28000;
        *(s32*)(arg0 + 0x24) = k2;
    }
    *(s32*)(arg0 + 0x20) = temp_a1;
    if (temp_a1 > 0) {
        arg0[0x15] = 0x40;
    } else {
        arg0[0x15] = 0;
    }
    func_80016C48(2, 0x35, arg0);
    D_800F6AF2 = 0;
    arg0[6] = arg0[6] + 1;
}
