#include "common.h"
#define M2C_UNK s32
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800FC1A0(void* arg0) {
    func_80016C48(2, 0x3E, arg0);
    ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0xA);
    F32(arg0, 0x20) = 0;
    F32(arg0, 0x24) = 0;
    F32(arg0, 0x28) = 0;
    F32(arg0, 0x2C) = 0;
    F16(arg0, 0x7C) = 0;
    F8(arg0, 6)++;
}
#undef F8
#undef F16
#undef F32
