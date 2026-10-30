#include "common.h"
#define M2C_UNK s32

extern M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
extern M2C_UNK move_object(void*);
extern s32 random_byte();

void func_800F78C8(u8* arg0) {
    ((void (*)(void*))move_object)(arg0);
    if (--*(s16*)(arg0 + 0x88) == 0) {
        s32 state;

        ((void (*)())set_animation_frame)(arg0, 0x1B, (random_byte() & 3) * 2 + 2);
        state = arg0[6];
        *(s16*)(arg0 + 0x88) = 0x28;
        arg0[6] = state + 1;
    }
}
