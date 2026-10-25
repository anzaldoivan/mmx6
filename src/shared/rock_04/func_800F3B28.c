#include "common.h"
#define M2C_UNK s32

M2C_UNK move_object(void*);

void func_800F3B28(u8* a) {
    u8 f;
    s32 v;
    // !FAKE: depin: dropping it breaks the match (12/37)
    register u8 t asm("$3");

    move_object(a);
    f = a[0x70];
    if (f & 8) {
        v = 7;
        goto store;
    }
    if ((f & 4) || (((v = a[0x15]), (t = v), v == 0) && (f & 2)) ||
        ((t == 0x40) && (*(volatile u8*)&a[0x70] & 1))) {
        v = a[6] + 1;
    store:
        a[6] = v;
    }
}
