#include "common.h"

extern s32 play_sound(s32, s32, void*);
extern s32 set_animation(void*, s32);
extern s32 D_8007429C;
extern s32 D_800FC4D4;
extern s32 D_800FC4D8;

void func_800F0A00(u8* arg0) {
    *(s32**)(arg0 + 0x58) = &D_8007429C;
    arg0[4] = 1;
    arg0[3] = 1;
    arg0[0x16] = 0;
    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    if (arg0[0x15] == 0) {
        *(u16*)(arg0 + 0xA) -= 6;
    } else {
        *(u16*)(arg0 + 0xA) += 6;
    }
    play_sound(2, 0x4F, arg0);
    *(s32**)(arg0 + 0x68) = &D_800FC4D8;
    *(s32**)(arg0 + 0x54) = &D_800FC4D4;
    *(s32**)(arg0 + 0x50) = &D_800FC4D4;
    arg0[0x5C] = 1;
    arg0[0x60] = 3;
    set_animation(arg0, 5);
}
