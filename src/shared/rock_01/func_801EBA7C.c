#include "common.h"

#define M2C_UNK s32

void* func_8002C32C();
s32 func_8002CFB0(void* arg);
s32 func_8003906C(void*);
s32 func_8003A2CC(void*);
s32 func_8003A488(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
void func_8003D394(void* arg0);
s32 func_8003EB0C(void* arg0, s32 arg1);
void func_8003F740(void*, s32);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);

#define F(T, o) (*(T*)((u8*)arg0 + (o)))

void func_801EBA7C(void* arg0) {
    s16 y;
    s16 x;
    u16 t;
    // !FAKE: register pin matches the target's allocation
    register s32 e asm("$2");
    s32 c;
    u8* p;

    if (F(u8, 0x89) & 8) {
        func_8003BA04(arg0, 0x63);
        y = F(s16, 0xE);
        e = F(u16, 0xE);
        t = F(u16, 0xA);
        F(u16, 0xE) = e + 0x13;
        do {
        } while (0);
        c = F(u8, 0x15);
        x = F(s16, 0xA);
        if (c != 0) {
            F(u16, 0xA) = t + 0xB;
        } else {
            F(u16, 0xA) = t - 0xB;
        }
        func_80049EBC(arg0, 0, 0xF, 0xF);
        func_80049EBC(arg0, 0, 0xF, 0xF);
        func_80049EBC(arg0, 0, 0xF, 0xF);
        func_80049EBC(arg0, 0, 0xF, 0xF);
        F(s16, 0xA) = x;
        F(s16, 0xE) = y;
        F(u8, 0x67) = 0;
        F(u8, 0x84) = 0;
        F(u8, 0x86) = 0;
        F(u8, 0x8C) = 0;
        if (F(s8, 0xD3) == 0 && func_8003EB0C(arg0, 2) <= F(s16, 0xAC)) {
            F(u8, 0x93) = 2;
            func_8003F740(arg0, 2);
            p = func_8002C32C();
            if (p != 0) {
                p[0] = 1;
                p[1] = 4;
                p[0x14] = F(u8, 0x14);
                p[2] = 0;
            }
        }
        F(u8, 6)++;
        return;
    }
    F(u8, 0x8E) = 0;
    if (func_8003A488(arg0) == 0 && func_8003A2CC(arg0) == 0 &&
        func_8003906C(arg0) == 0) {
        F(u8, 0x8E) = 1;
        F(s32, 0x20) = 0;
        if (F(s8, 0xD3) == 0) {
            if (F(u16, 0x7C) & 2) {
                F(s32, 0x20) = 0xFFFE8000;
            }
            if (F(u16, 0x7C) & 1) {
                F(s32, 0x20) = 0x18000;
            }
        }
        func_8002CFB0(arg0);
        func_8003D394(arg0);
    }
}

#undef F
