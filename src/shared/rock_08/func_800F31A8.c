#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
void* func_8002C458();

void func_800F31A8(u8* arg0) {
    u8* p;

    func_80017A04();
    p = func_8002C458();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0xE;
        p[2] = 5;
        p[0x14] = arg0[0x14];
        *(s32*)(p + 8) = *(s32*)(arg0 + 8);
        *(s32*)(p + 0xC) = *(s32*)(arg0 + 0xC);
        p[0x15] = arg0[0x15];
        *(u8**)(p + 0x7C) = arg0;
    }
    arg0[6]++;
}
