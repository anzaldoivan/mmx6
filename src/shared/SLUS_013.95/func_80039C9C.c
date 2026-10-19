#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003B9AC(void*);
extern u8 D_800CCF99;

s32 func_80039C9C(void* arg0) {
    if (((s8*)arg0)[0xD3] != 0) {
        return 0;
    }
    if (!(D_800CCF99 & 8)) {
        return 0;
    }
    if (!(*(u16*)((u8*)arg0 + 0x7C) & 8)) {
        return 0;
    }
    func_8003B9AC(arg0);
    return 1;
}
