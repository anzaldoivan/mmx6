#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern void (*D_800FBB48[])(u8*);

void func_800F92B0(u8* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    D_800FBB48[*(s8*)(arg0 + 5)](arg0);
    func_8002CCB0(arg0, 0x80, 0x20);
}
