#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj D_800970A0;

void func_800F21EC(void* arg0) {
    {
        struct X4_PlayerObj* p = &D_800970A0;
        ((u8*)p)[0xCA] = 0;
        ((void (*)(s32, s32))func_8003D308)(0x14, p->unk15);
    }
    ((void (*)(s32, s32, void*))func_80016C48)(2, 0x20, arg0);
    ((void (*)(void*, s32))func_800179A4)(arg0, 3);
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x60, 0x60);
    *(s32*)((u8*)arg0 + 0x80) = 0x78;
    *(s32*)((u8*)arg0 + 0x8C) = 1;
    *(s32*)((u8*)arg0 + 0x90) = 1;
    *(u8*)((u8*)arg0 + 5) = 1;
    *(u16*)((u8*)arg0 + 0x42) &= 0x7FFF;
}
