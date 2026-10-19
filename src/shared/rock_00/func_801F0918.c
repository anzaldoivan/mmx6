#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_8002D2B0(struct X4_MovingObj*);

void func_801F0918(void* arg0) {
    if (func_8002CBFC(arg0, 0x40, 0x40) == 0) {
        func_80017A04(arg0);
        func_8002D2B0(arg0);
        ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x40, 0x40);
        return;
    }
    ((u8*)arg0)[3] = 0;
    ((u8*)arg0)[4] = 3;
    *(s32*)((u8*)arg0 + 0x50) = 0;
    *(s32*)((u8*)arg0 + 0x68) = 0;
}
