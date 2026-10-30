#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_800EAA00(void*);
extern u8 D_800FA900[];

void func_800ECA5C(u8* arg0) {
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    ((void (**)(u8*))(D_800FA900 + 0x1654))[*(s8*)(arg0 + 5)](arg0);
    func_8002CCB0(arg0, 0x30, 0x30);
    if (func_800EAA00(arg0) != 0) {
        if (*(s8*)(arg0 + 5) == 2) {
            play_sound(2, 0x20, arg0);
            *(s8*)(arg0 + 5) = 3;
            *(s8*)(arg0 + 6) = 0;
        }
    } else {
        arg0[0x89] = 0;
    }
}
