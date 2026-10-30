#include "common.h"

extern u16 D_800C4570;
extern s32 D_800EA760[];

s32 play_sound(s32, s32, void*);

void func_800E9958(s32 arg0) {
    switch (D_800EA760[arg0]) {
    case 0 ... 1:
        if (D_800C4570 & 0x4000) {
            D_800EA760[arg0]++;
            return;
        }
        if (D_800C4570 & 0x1000) {
            D_800EA760[arg0] = 0;
        }
        break;
    case 2 ... 10:
        if (D_800C4570 & 0x1000) {
            if (++D_800EA760[arg0] == 0xB) {
                play_sound(5, 1, 0);
            }
        } else if (D_800C4570 & 0x4000) {
            D_800EA760[arg0] = 0;
        }
        break;
    default:
        if (D_800C4570 & 0x4000) {
            D_800EA760[arg0] = 0;
        }
        break;
    }
}
