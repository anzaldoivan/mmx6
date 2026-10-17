#include "common.h"

void func_800F0434(s8* self, u32 arg1);
extern s32 D_800F6BFC;

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F462C(void* arg0) {
    if (++F(s16, arg0, 0x7C) == 0x32) {
        F(s16, arg0, 0x7C) = 0;
        D_800F6BFC = 0;
        func_800F0434(arg0, 0xA);
        F(u8, arg0, 6)++;
    }
}
