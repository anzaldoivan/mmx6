#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002C9B0();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);

extern u8 D_800F79D0[];

void func_800ED264(u8* arg0) {
    s8 state;
    s16* t;

    state = arg0[5];
    if (state == 0) {
        if (!(*(s8*)(arg0 + 2) & 0xF0)) {
            s32 next;
            // !FAKE: pin keeps the constants in the first return register
            register s32 k asm("$2");

            func_800477E4(4, (M2C_UNK*)(D_800F79D0 + 0xCB8), arg0);
            next = arg0[5];
            k = 0x3C;
            *(s16*)(arg0 + 0x88) = k;
            k = 5;
            *(s16*)(arg0 + 0x8A) = k;
            arg0[5] = next + 1;
            return;
        }
        arg0[5] = 2;
    } else if (state == 1) {
        t = (s16*)(arg0 + 0x7C);
        if ((t[6] = *(s16*)(arg0 + 0x88) - 1) == 0) {
            arg0[5]++;
            return;
        }
        if ((t[7] = *(s16*)(arg0 + 0x8A) - 1) == 0) {
            func_80049EBC(arg0, 1, 0x10, 0x40);
            *(s16*)(arg0 + 0x8A) = 5;
        }
    } else if (state == 2) {
        func_8002C9B0(arg0);
    }
}
