#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern void* D_800F70E4;

void func_800EDC04(s8* arg0) {
    s8 one;
    s32 sel;
    s32 sub;
    u16 x;
    s32 v;

    one = *((s8*)D_800F70E4 + 4);
    if (one != 1) {
        arg0[3] = 0;
        arg0[4] = 2;
        return;
    }
    arg0[0x16] = 4;
    arg0[3] = 0;
    arg0[4] = one;
    sel = arg0[2] & 0xF0;
    arg0[6] = 0;
    if (sel == 0) {
        set_animation(arg0, 5);
        x = *(u16*)(arg0 + 0xA);
        sub = (u8)arg0[2] & 0xF;
        *(u16*)(arg0 + 0x5C) = x;
        *(u16*)(arg0 + 0x5E) = *(u16*)(arg0 + 0xE);
        if (sub == 0) {
            // !FAKE: retail places the zero arm after the else arm
            goto zero;
        }
        if (sub == one) {
            // !FAKE: retail places the plus arm after the zero arm
            goto plus;
        }
        arg0[5] = 0;
        *(s16*)(arg0 + 0x54) = 0x1E;
        return;
    zero:
        v = x - 0x40;
        // !FAKE: zero arm jumps over the plus arm to the shared store
        goto store;
    plus:
        v = x + 0x40;
    store:
        *(u16*)(arg0 + 0xA) = v;
        arg0[5] = 0;
        *(s16*)(arg0 + 0x54) = 0x1E;
    } else if (sel == 0x10) {
        if (!((u8)arg0[2] & 0xF)) {
            arg0[0x16] = 4;
            set_animation(arg0, 0xB);
        }
        arg0[3] = one;
        arg0[5] = one;
    }
}
