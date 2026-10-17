#include "common.h"
#define M2C_UNK s32

extern M2C_UNK func_800179D0(void*, M2C_UNK, s8);
extern M2C_UNK func_8002D2B0(void*);
extern s32 func_8002D2D4();

void func_800F78C8(u8* arg0) {
    ((void (*)(void*))func_8002D2B0)(arg0);
    if (--*(s16*)(arg0 + 0x88) == 0) {
        s32 state;

        ((void (*)())func_800179D0)(arg0, 0x1B, (func_8002D2D4() & 3) * 2 + 2);
        state = arg0[6];
        *(s16*)(arg0 + 0x88) = 0x28;
        arg0[6] = state + 1;
    }
}
