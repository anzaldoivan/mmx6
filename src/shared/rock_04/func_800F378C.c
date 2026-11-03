#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK apply_object_motion();

void func_800F378C(struct X4_AnimatedObj* arg0) {
    if (((u8*)arg0)[0x70] & 8) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x12, arg0);
        ((void (*)(s32))start_pad_vibration)(8);
        ((void (*)(void*, s32))set_animation)(arg0, 4);
        *(s16*)((u8*)arg0 + 0x7C) = 0xD;
        ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
        return;
    }
    apply_object_motion(arg0);
}
