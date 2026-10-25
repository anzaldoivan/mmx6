#include "common.h"
#define M2C_UNK s32

M2C_UNK move_object();
void func_800FB068(u8* arg0, u8 arg1);

void func_800FAA98(u8* self) {
    // !FAKE: retail passes the stale first argument register unchanged
    register u8* unused asm("$4");

    if (--*(s16*)(self + 0x88) == 0) {
        *(s16*)(self + 0x88) = 0xC;
        if (*(s16*)(self + 0x8A) != 0) {
            (*(s16*)(self + 0x8A))--;
            func_800FB068(unused, 0x20);
        }
    }
    move_object(self);
}
