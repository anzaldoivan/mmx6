#include "common.h"

#define SPAD (*(u8**)0x1F80004C)

s32 random_byte();

void func_800EC7A0(void* arg0) {
    u8* self = arg0;

    if (*(s8*)(self + 5) != 2 && !(random_byte() & 3)) {
        SPAD[0x8B] = self[5];
        self[5] = 0xB;
        self[6] = 0;
    }
}
