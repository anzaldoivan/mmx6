#include "common.h"
#define M2C_UNK s32

M2C_UNK move_object(void*);

#define SP64_322C (*(u8**)0x1F800064)

void func_8004322C(u8* arg0) {
    ((void (*)(void*))move_object)(arg0);
    if (!(arg0[2] & 0xF)) {
        u8* temp_v0 = SP64_322C;
        if (*(s16*)(arg0 + 0xA) >= *(s16*)(temp_v0 + 0x54)) {
            *(s16*)(arg0 + 0xA) = *(s16*)(temp_v0 + 0x54);
            arg0[6]++;
        }
    } else {
        // !FAKE: retail keeps this arm's pointer in the first argument register
        register u8* temp_a0 asm("$4") = SP64_322C;
        if (*(s16*)(temp_a0 + 0x54) >= *(s16*)(arg0 + 0xA)) {
            *(s16*)(arg0 + 0xA) = *(s16*)(temp_a0 + 0x54);
            arg0[6]++;
        }
    }
}

#undef SP64_322C
