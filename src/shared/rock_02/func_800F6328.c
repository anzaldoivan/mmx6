#include "common.h"
#define M2C_UNK s32

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800F6328(u8* arg0) {
    u8* sp = SPAD;
    u8 t = sp[0x8B];
    // !FAKE: depin: dropping it breaks the match (49/54)
    register s32 t2 asm("$2");

    if (t != 0) {
        sp[0x8B] = t - 1;
        if (!(SPAD[0x8B] & 3)) {
            *(u16*)(arg0 + 0x42) |= 0x8000;
        } else {
            *(u16*)(arg0 + 0x42) &= 0x7FFF;
        }
    }
    func_80017A04(arg0);
    t2 = *(u16*)(arg0 + 0x7C) - 1;
    *(s16*)(arg0 + 0x7C) = t2;
    if ((s16)t2 == 0) {
        set_animation(arg0, 5);
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        *(s32*)(arg0 + 0x24) = 0x50000;
        SPAD[0x8B] = 0x78;
        arg0[6]++;
    }
}
