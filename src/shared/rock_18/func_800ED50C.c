#include "common.h"

void* alloc_sprite_slot();

void func_800ED50C(u8 arg0, s8 arg1, s16 arg2, s16 arg3) {
    u8* obj;

    obj = alloc_sprite_slot();
    if (obj != 0) {
        obj[0] = 1;
        obj[1] = 0x2E;
        obj[2] = arg0;
        obj[0x54] = arg1;
        obj[0x57] = 0;
        *(s16*)(obj + 0xA) = arg2;
        *(s16*)(obj + 0xE) = arg3;
    }
}
