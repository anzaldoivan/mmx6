#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_80047674(u8* arg0) {
    u8* eng;
    s32 var_v0;
    s32 temp_v0;
    s32 sum;
    s32 add;

    eng = (u8*)&g_playthrough_state;
    eng[0x27] = 1;
    sum = *(s32*)(arg0 + 0x1C);
    add = *(s32*)(arg0 + 0x18);
    sum += add;
    temp_v0 = *(u16*)(arg0 + 0x16) - 1;
    *(u16*)(arg0 + 0x16) = temp_v0;
    *(s32*)(arg0 + 0x1C) = sum;
    if ((temp_v0 << 0x10) == 0) {
        var_v0 = eng[0x68] < 2U;
        if (var_v0 != 0) {
            var_v0 = 0x10000;
        } else {
            var_v0 = 0x14000;
        }
        *(s32*)(arg0 + 0x18) = var_v0;
        *(s16*)(arg0 + 0x14) = 0x32;
        arg0[5] = 1;
    }
}
