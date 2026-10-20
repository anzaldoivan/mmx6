#include "common.h"

extern u16 D_80097202;
#define D_80097202 (*(u16*)&D_80097202)

void func_800FF8C0(u8* arg0) {
    u8* p = *(u8**)(arg0 + 0x80);
    u16 g = D_80097202;
    s32 t = *(u16*)(p + 0xA) - g;

    t -= 0x140;
    *(s16*)(arg0 + 0xA) = g - t;
    *(u16*)(arg0 + 0xE) = *(u16*)(p + 0xE);
}
#undef D_80097202
