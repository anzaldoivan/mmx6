#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80066150(M2C_UNK);
M2C_UNK func_800663FC(M2C_UNK*, M2C_UNK*);

void func_8001B84C(s32* arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4,
                   s32 arg5) {
    s16 rect[4];
    s32 h;
    u32 i;
    u32 t;

    h = 0x10;
    if (arg5 != 0) {
        h = 0x18;
    }
    rect[0] = arg1;
    rect[1] = arg2;
    rect[2] = h;
    rect[3] = arg4;
    t = (u32)(h * arg4) >> 1;
    for (i = 0; i < arg3 >> 4; i++) {
        func_800663FC((M2C_UNK*)rect, arg0);
        func_80066150(0);
        arg0 += t;
        rect[0] += h;
    }
}
