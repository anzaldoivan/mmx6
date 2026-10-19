#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(s32);
extern s16 D_8009721E;

void func_800F4974(u8* arg0) {
    func_80017A04();
    {
        // !FAKE: call arg set before the zero test, as retail fills the delay slot
        register u8* a0 asm("$4") = arg0;
        if (*(s16*)(arg0 + 0x8C) != 0) {
            *(s16*)(arg0 + 0x8C) = *(s16*)(arg0 + 0x8C) - 1;
            ((void (*)(void*))func_8002D2B0)(a0);
            if (*(s16*)(arg0 + 0x8C) != 0) {
                return;
            }
        }
    }
    *(s32*)(arg0 + 0x24) = 0;
    *(s16*)(arg0 + 0x8C) = 0x30;
    if (*(s16*)(arg0 + 0xA) < D_8009721E + 0x70) {
        *(s32*)(arg0 + 0x20) = 0x20000;
    } else {
        *(s32*)(arg0 + 0x20) = 0xFFFE0000;
    }
    do {
        arg0[6] = arg0[6] - 1;
    } while (0);
}
