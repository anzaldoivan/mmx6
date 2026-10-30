#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK move_object(s32);

void func_800F96C4(void* arg0) {
    s8 v;

    ((void (*)(void))func_80017A04)();
    if (*(s16*)((u8*)arg0 + 0x7C) != 0) {
        ((void (*)(void*))move_object)(arg0);
        *(s16*)((u8*)arg0 + 0x7C) -= 1;
        return;
    }
    v = *(s8*)((u8*)arg0 + 0x45);
    if (v == 0) {
        set_animation(arg0, 0x2A);
    } else if (v == 1) {
        set_animation(arg0, 0x2B);
    } else if (v == 2) {
        set_animation(arg0, 0x2C);
    } else if (v == 3) {
        set_animation(arg0, 0x2D);
    }
    play_sound(2, 0x6B, arg0);
    *((u8*)arg0 + 6) += 1;
}
