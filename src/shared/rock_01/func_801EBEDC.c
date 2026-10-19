#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003CD9C();
M2C_UNK func_8003BA04(void*, M2C_UNK);
s32 func_8002D2D4();
M2C_UNK func_8003CFE0(void*, M2C_UNK);
void func_801EACAC(u8* arg0);

s32 func_801EBEDC(u8* arg0) {
    if (((s8*)arg0)[0xD3] != 0) {
        return 0;
    }
    if (!(*(u16*)(arg0 + 0x80) & 0x20)) {
        return 0;
    }
    if (((s8*)arg0)[0x8E] != 0) {
        return 0;
    }
    arg0[0x8E] = 1;
    arg0[0xCB] = 0;
    func_8003CD9C(arg0);
    func_8003BA04(arg0, 0x6E);
    if (func_8002D2D4() & 4) {
        func_8003CFE0(arg0, 9);
    }
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x24) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    arg0[5] = 0x3E;
    arg0[6] = 0;
    func_801EACAC(arg0);
    return 1;
}
