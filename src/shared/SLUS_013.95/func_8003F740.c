#include "common.h"

s32 func_8003EB0C(void* arg0, s32 arg1);
extern s32 D_800971E4;

void func_8003F740(void* arg0, s32 arg1) {
    s8 id = arg1;
    u16* p;
    s32 t;

    if ((D_800971E4 != 3) || (id == 0x2F) || (id == 0x2C) || (id == 0x31)) {
        t = func_8003EB0C(arg0, id);
        p = (u16*)((u8*)arg0 + 0xA8);
        p += *((s8*)arg0 + 0x93);
        *p -= t;
    }
}
