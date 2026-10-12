#include "common.h"

void func_800F0434(s8* self, u32 arg1);

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F3A14(void* arg0) {
    if (F(s8, arg0, 0x46) == 0) {
        func_800F0434(arg0, 0x10);
        F(s16, arg0, 0x7C) = 0;
        F(u8, arg0, 6) = 0xB;
    }
}
