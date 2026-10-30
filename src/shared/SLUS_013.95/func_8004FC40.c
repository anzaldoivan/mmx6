#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
extern s32 D_80078908;
extern s32 D_8007890C;
extern s32 D_80078914;
extern s32 D_80078918;

void func_8004FC40(u8* arg0) {
    arg0[0x5C] = 0xD;
    arg0[0x60] = 6;
    if (arg0[0x84] == 0) {
        arg0[0x81] = 0x3C;
        *(s32**)(arg0 + 0x54) = &D_8007890C;
        *(s32**)(arg0 + 0x50) = &D_80078908;
        if (arg0[0x7E] == 0) {
            if (arg0[0x82] == 0) {
                set_animation(arg0, 0x13);
            } else {
                set_animation(arg0, 0x14);
            }
        } else if (arg0[0x82] == 0) {
            set_animation(arg0, 0x15);
        } else {
            set_animation(arg0, 0x16);
        }
    } else {
        arg0[0x81] = 0x14;
        *(s32**)(arg0 + 0x54) = &D_80078918;
        *(s32**)(arg0 + 0x50) = &D_80078914;
        if (arg0[0x82] == 0) {
            set_animation(arg0, 0x1C);
        } else {
            set_animation(arg0, 0x23);
        }
    }
    arg0[5]++;
}
#undef set_animation
