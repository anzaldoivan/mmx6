#include "common.h"

extern s32 D_80097420;
extern void (*D_800760E8[])(void*);

void func_80043174(u8* arg0) {
    arg0[3] = (*(u8*)&D_80097420 + arg0[2]) & 1;
    D_800760E8[((s8*)arg0)[6]](arg0);
}
