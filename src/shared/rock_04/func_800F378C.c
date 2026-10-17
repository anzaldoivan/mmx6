#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D230();

void func_800F378C(struct X4_AnimatedObj* arg0) {
    if (((u8*)arg0)[0x70] & 8) {
        ((void (*)(s32, s32, void*))func_80016C48)(2, 0x12, arg0);
        ((void (*)(s32))func_80012D9C)(8);
        ((void (*)(void*, s32))func_800179A4)(arg0, 4);
        *(s16*)((u8*)arg0 + 0x7C) = 0xD;
        ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
        return;
    }
    func_8002D230(arg0);
}
