#include "common.h"

extern void (*D_800F7404[])(void*);

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EC300(void* arg0) {
    if (FU8(arg0, 0x70) & 8) {
        F32(arg0, 0x24) = 0;
    }
    F32(arg0, 0x18) = F32(arg0, 0x8);
    F32(arg0, 0x1C) = F32(arg0, 0xC);
    D_800F7404[F8(arg0, 4)](arg0);
}

#undef F8
#undef FU8
#undef F32
