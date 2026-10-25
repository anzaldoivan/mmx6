#include "common.h"

void* func_8002C32C();
extern u8 D_800970B4;

void* player_spawn_weapon(s8 arg0, s8 arg1, s8 arg2, s32 arg3) {
    u8* p;

    p = func_8002C32C();
    if (p != 0) {
        p[0] = arg0;
        p[1] = arg1;
        p[2] = arg2;
        p[0x14] = D_800970B4;
        if (arg3 != 0) {
            *(s32*)(p + 0x7C) = arg3;
        }
        return p;
    }
    return 0;
}
