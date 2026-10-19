#include "common.h"

#define M2C_UNK s32

void* func_8002C32C();
s32 func_8003EB0C(void* arg0, s32 arg1);
void func_8003F740(void*, s32);

#define F(T, o) (*(T*)((u8*)arg0 + (o)))
M2C_UNK func_801EA254(void* arg0) {
    s32 r;
    u8* q;

    if (!(F(u8, 0xC9) & 1)) {
        return 0;
    }
    if (!(F(u16, 0x7C) & 4)) {
        return 0;
    }
    if (!(F(u16, 0x80) & 0x20)) {
        return 0;
    }
    if (F(s8, 0xA6) == 1) {
        return 0;
    }
    if (func_8003EB0C(arg0, 3) > F(s16, 0xAE)) {
        return 0;
    }
    if (F(s8, 0x8E) != 0) {
        return 0;
    }
    q = func_8002C32C();
    if (q != 0) {
        F(s8, 0xA6) = 1;
        q[0] = 1;
        q[1] = 1;
        q[2] = 0;
        q[0x14] = F(u8, 0x14);
        F(u8, 0x93) = 3;
        func_8003F740(arg0, 3);
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
