#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CFE0(void*, M2C_UNK);
void func_801EB934(s8* p);
s32 func_801ECCD4(void*);

s32 func_801EC0F0(void* arg0) {
    u8* p = arg0;

    if (func_801ECCD4(p) == 0) {
        return 0;
    }
    func_8003BA04(p, 0x5D);
    play_sound(1, 7, p);
    if (random_byte() & 4) {
        func_8003CFE0(p, 8);
    }
    p[0x84] = 0;
    p[0x86] = 0;
    p[5] = 0x33;
    p[6] = 0;
    func_801EB934((s8*)p);
    return 1;
}
