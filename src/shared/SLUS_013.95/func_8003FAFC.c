#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);

void func_8003FAFC(void* arg0) {
    func_8003BA04(arg0, 0x61);
    play_sound(1, 0x1A, arg0);
    ((u8*)arg0)[0x67] = 1;
    ((u8*)arg0)[0x5] = 0x28;
    ((u8*)arg0)[0x6] = 0;
}
