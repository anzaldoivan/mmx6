#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
void func_800F5F04();
extern s16 D_800970AA;
extern s16 D_80097202;

void func_800F8278(u8* arg0) {
    s8 state;

    state = *(s8*)(arg0 + 0x45);
    if (state == 1) {
        {
            // !FAKE: depin: dropping it breaks the match (8/57)
            register u8* a asm("$4");
            func_800F5F04(a, 1);
        }
        func_800179A4(arg0, 1);
        if (D_800970AA > D_80097202 + 0xA0) {
            *(s16*)(arg0 + 0x7C) = 0;
        } else {
            *(s16*)(arg0 + 0x7C) = state;
        }
        *(u16*)(arg0 + 0x7E) = 0;
        if (func_8002D2D4() & 1) {
            *(u16*)(arg0 + 0x7E) = 0;
        } else {
            *(u16*)(arg0 + 0x7E) = 0xF;
        }
        if (!(func_8002D2D4() & 1)) {
            *(u16*)(arg0 + 0x7E) |= 0xF0;
        }
        arg0[7] = 0;
        arg0[6]++;
    } else if (state == 2) {
        func_80016C48(2, 0x51, arg0);
    }
}
