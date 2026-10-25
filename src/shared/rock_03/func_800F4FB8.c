#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);

void func_800F4FB8(u8* arg0) {
    // !FAKE: depin: dropping it breaks the match (20/36)
    register s32 v asm("$2");

    if (*(s16*)(arg0 + 0x7C) == 0x5A) {
        ((void (*)(s32, s32, void*))func_80016C48)(2, 0x29, arg0);
    }
    if (++*(s16*)(arg0 + 0x7C) == 0x104) {
        *(s16*)(arg0 + 0x7E) = 0;
        {
            // !FAKE: depin: dropping it breaks the match (19/36)
            register s32 f asm("$2") = arg0[0x15];
            if (f != 0) {
                v = 0x20000;
            } else {
                v = 0xFFFD0000;
            }
        }
        v |= 0x8000;
        *(s32*)(arg0 + 0x20) = v;
        *(s16*)(arg0 + 0x8E) = 0;
        {
            // !FAKE: depin: dropping it breaks the match (31/36)
            register s32 c asm("$2") = arg0[6];
            arg0[6] = c + 1;
        }
    }
}
