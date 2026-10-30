#include "common.h"

void* enemy_slot_alloc();

void func_800F54B8(s32 arg0, void* arg1) {
    u8 v = arg0;
    u8* p = enemy_slot_alloc();

    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0xF;
        p[2] = v;
    }
}
