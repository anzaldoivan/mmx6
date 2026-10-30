#include "common.h"

extern u16 D_800C4570;
extern s32 D_800EA760[];

s32 play_sound(s32, s32, void*);

void func_800E9864(u8* arg0) {
    s32 i = (s32)arg0;
    s32 v = D_800EA760[i];

    if (v < 0) {
        // !FAKE: retail block order, out-of-range arm shares the clear block
        goto clear;
    }
    if (v >= 2) {
        if (v >= 0xB) {
            // !FAKE: retail block order, out-of-range arm shares the clear block
            goto clear;
        }
        // !FAKE: retail places the count arm after the low arm
        goto count;
    }
    if (D_800C4570 & 0x1000) {
        D_800EA760[i] = v + 1;
        return;
    }
    if (D_800C4570 & 0x4000) {
        D_800EA760[i] = 0;
    }
    return;
count:
    if (D_800C4570 & 0x4000) {
        if (++D_800EA760[i] == 0xB) {
            play_sound(5, 1, 0);
        }
    }
    return;
clear:
    if (D_800C4570 & 0x5000) {
        D_800EA760[i] = 0;
    }
}
