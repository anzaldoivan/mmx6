#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern void (*D_800F767C[])(void*);

void func_800F30A4(void* arg0) {
    if (((s8*)(*(void**)((u8*)arg0 + 0x80)))[4] != 1) {
        ((s8*)arg0)[4] = 5;
        ((s8*)arg0)[3] = 0;
        return;
    }
    D_800F767C[((s8*)arg0)[5]](arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}
