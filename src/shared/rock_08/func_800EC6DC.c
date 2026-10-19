#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

extern void (*D_800F5620[])(void*);

void func_800EC6DC(void* arg0) {
    FX(arg0, u16, 0x80) -= 1;
    D_800F5620[FX(arg0, s8, 0x7)](arg0);
}
