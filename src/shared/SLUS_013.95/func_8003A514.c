#include "common.h"
#define M2C_UNK s32

s32 func_8003015C();
void func_8003B6B4(void*);
void func_8003B774(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);

s32 func_8003A514(u8* arg0) {
    s32 v;
    s32 t;

    v = func_8003015C(arg0);
    if (arg0[0x89] & 8) {
        func_8003B774(arg0);
        return 1;
    }
    if ((*(u16*)(arg0 + 0x7C) & 4) && v == 0x21) {
        func_8003B6B4(arg0);
        return 1;
    }
    t = (u8)(v - 0x20) >= 2;
    if (*(u16*)(arg0 + 0x80) & 0x80) {
        t = 1;
    }
    if (t != 0) {
        func_8003BA04(arg0, 0x1E);
        arg0[5] = 0xE;
        arg0[6] = 4;
        return 1;
    }
    return 0;
}
