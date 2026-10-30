#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CFE0(void*, M2C_UNK);
void func_801EC334(u8* arg0);
s32 func_801ECCD4(void*);

s32 func_801EC178(void* arg0) {
    u8* p = arg0;

    if (func_801ECCD4(p) == 0) {
        return 0;
    }
    func_8003BA04(p, 0x5E);
    play_sound(1, 7, p);
    if (random_byte() & 4) {
        func_8003CFE0(p, 8);
    }
    p[5] = 0x34;
    p[6] = 0;
    func_801EC334(p);
    return 1;
}
