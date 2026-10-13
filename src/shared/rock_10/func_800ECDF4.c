#include "common.h"

#define F(type, off) (*(type*)((u8*)arg0 + (off)))

void func_800EADA8(void*, s32);

void func_800ECDF4(void* arg0) {
    u8 v = F(u8, 0x89);

    if (v == 0) {
        if (F(u8, 0x8C) == 1) {
            func_800EADA8(arg0, 0);
            F(u8, 0x8C) = 0;
        }
    } else if (v == 2) {
        F(u8, 0x89) = 0;
        F(u8, 0x8A) = 1;
    }
}
#undef F
