#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
#define SCRATCH_4C (*(u8**)0x1F80004C)

void func_800E9EE8(u8* arg0) {
    s32 temp_v1;

    play_sound(2, 0x16, arg0);
    if (!(*(s8*)(arg0 + 2) & 0xF0)) {
        set_animation(arg0, 0);
    } else {
        set_animation(arg0, 2);
    }
    temp_v1 = arg0[2] & 0xF;
    *(s16*)(arg0 + 0x7E) = 0;
    if ((s8)temp_v1 == 0) {
        SCRATCH_4C[0x85] = 1;
        *(s16*)(arg0 + 0x7C) = 0xB4;
    } else {
        if ((s8)temp_v1 >= 0) {
            if ((s8)temp_v1 < 8) {
                SCRATCH_4C[0x85] = temp_v1;
                *(s16*)(arg0 + 0x7C) = 0xE;
                goto end;
            }
        }
        SCRATCH_4C[0x85] = (random_byte() & 3) + 1;
        *(s16*)(arg0 + 0x7C) = 0xE;
    }
end:
    arg0[6]++;
}
