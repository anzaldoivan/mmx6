#include "common.h"
#include "mmx6/x4.h"

#define F(T, o) (*(T*)((u8*)arg0 + (o)))

void func_8002F288(struct X4_PlayerObj*);
extern void (*D_800788F8[])(void*);
extern s8 D_80097180;

void func_8004E5D8(void* arg0) {
    if (D_80097180 != 2 || F(s8, 0x4) <= 0) {
        F(s32, 0x18) = F(s32, 0x8);
        F(s32, 0x1C) = F(s32, 0xC);
        D_800788F8[F(s8, 0x4)](arg0);
        func_8002F288(arg0);
    }
}

#undef F
