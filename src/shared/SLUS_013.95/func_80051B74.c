#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
void play_stage_bgm(void);
M2C_UNK func_80018774(M2C_UNK);
extern u8 D_8008EAFC;
extern u8 D_800CD40C;

void func_80051B74(s8* arg0) {
    if (arg0[6] == 0) {
        if (D_8008EAFC == 0) {
            func_80018774(3);
            arg0[6]++;
        }
    } else if (D_800CD40C == 0) {
        play_stage_bgm();
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0xC);
        arg0[6] = 0;
        arg0[5]++;
    }
}
