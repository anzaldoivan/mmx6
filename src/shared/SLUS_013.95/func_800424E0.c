#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_80042C18(struct X4_MainObj* self);

#define F24E0_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F24E0_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F24E0_S16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800424E0(void* arg0) {
    F24E0_U8(arg0, 3) = 0;
    if (F24E0_S8(arg0, 7) == 0) {
        func_80042C18(arg0);
        ((void (*)(void*, s32))func_800179A4)(arg0, 0);
        F24E0_S16(arg0, 0x7C) = 0x1E;
        F24E0_U8(arg0, 6) = F24E0_U8(arg0, 6) + 1;
    }
}

#undef F24E0_S8
#undef F24E0_U8
#undef F24E0_S16
