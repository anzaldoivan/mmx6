#include "common.h"

#define M2C_UNK s32

void* func_8002C32C();
s32 func_8003EB0C(void* arg0, s32 arg1);
void func_8003F740(void*, s32);

#define F(T, o) (*(T*)((u8*)arg0 + (o)))
M2C_UNK func_801ECBE8(void* arg0) {
    u8* q;

    if (F(s8, 0xD3) != 0) {
        return 0;
    }
    if (!(F(u8, 0xC9) & 0x40)) {
        return 0;
    }
    if (F(s8, 0xA6) == 2) {
        return 0;
    }
    if (func_8003EB0C(arg0, 4) > F(s16, 0xB0)) {
        return 0;
    }
    if (F(s8, 0x8E) != 0) {
        return 0;
    }
    q = func_8002C32C();
    if (q != 0) {
        F(s8, 0xA6) = 2;
        q[0] = 1;
        q[1] = 7;
        q[2] = 0;
        q[0x14] = F(u8, 0x14);
        F(u8, 0x93) = 4;
        func_8003F740(arg0, 4);
        {
            // !FAKE: register pin matches the target allocation
            register s32 b asm("$2");
            s32 a = F(u8, 0x98);
            b = F(u8, 0x99);
            F(u8, 0x98) = a + 1;
            F(u8, 0x99) = b + 1;
        }
    }
}
#undef F
