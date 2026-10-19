#include "common.h"
#define M2C_UNK s32

s32 func_801ECCD4(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_8002D2D4();
M2C_UNK func_8003CFE0(void*, M2C_UNK);
void func_801EAE7C(void* arg0);

s32 func_801EBE54(u8* arg0) {
    if (func_801ECCD4(arg0) == 0) {
        return 0;
    }
    func_8003BA04(arg0, 0x58);
    func_80016C48(1, 7, arg0);
    if (func_8002D2D4() & 4) {
        func_8003CFE0(arg0, 3);
    }
    arg0[0x84] = 0;
    arg0[0x86] = 0;
    arg0[5] = 0x30;
    arg0[6] = 0;
    func_801EAE7C(arg0);
    return 1;
}
