#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800FA2C8(u8* arg0) {
    s32 v;

    if (func_800EA480((s8*)arg0) != 0) {
        u8* p = (u8*)D_800971F8;
        v = *(u16*)(p + 0x5E) + 0x10;
        *(u16*)(p + 0x5E) = v;
        if ((s16)v >= 0x120) {
            *(u16*)(p + 0x5E) = 0x120;
            *(s16*)(arg0 + 8) = 0x1E1;
            *(s16*)(arg0 + 0xA) = 6;
            arg0[1]++;
        }
    }
}
