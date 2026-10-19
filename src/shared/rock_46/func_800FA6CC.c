#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];

void func_800FA6CC(u8* arg0) {
    u8* bg = (u8*)D_800971F8;
    s32 t;

    t = *(u16*)(bg + 0x62) + 0x10;
    *(u16*)(bg + 0x62) = t;
    if ((s16)t >= 0x2A0) {
        *(u16*)(bg + 0x62) = 0x2A0;
        *(s16*)(arg0 + 8) = 0xB;
        *(s16*)(arg0 + 0xA) = 7;
        arg0[1]++;
    }
}
