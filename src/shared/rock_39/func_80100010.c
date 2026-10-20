#include "common.h"

s32 func_8002D2D4();
extern u16 D_80097202;
#define D_80097202 (*(u16*)&D_80097202)

void func_80100010(u8* arg0) {
    u16 temp_a0;

    if (arg0[0x15] == 0) {
        arg0[0x94] = 0;
    } else {
        arg0[0x94] = 1;
    }
    {
        s32 a = *(u16*)(arg0 + 0xA);
        s32 g = D_80097202;
        register s32 d asm("$2"); // !FAKE: inherited from src/shared/rock_10/func_800FA468.c
        temp_a0 = *(u16*)(arg0 + 0xE);
        *(s32*)(arg0 + 0x84) = 0;
        d = (a - g) - 0x140;
        *(s16*)(arg0 + 0x88) = g - d;
    }
    *(u16*)(arg0 + 0x8A) = temp_a0;
    if (func_8002D2D4(temp_a0) & 1) {
        *(s32*)(arg0 + 0x84) = 0;
    } else {
        *(s32*)(arg0 + 0x84) = 0xF;
    }
    if (!(func_8002D2D4() & 1)) {
        *(s32*)(arg0 + 0x84) |= 0xF0;
    }
    arg0[7] = 0;
    arg0[6]++;
}
#undef D_80097202
