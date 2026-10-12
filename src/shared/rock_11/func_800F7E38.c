#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002F288(M2C_UNK*);
extern void (*D_800FD2F0[])(s8*);

void func_800F7E38(s8* arg0) {
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    D_800FD2F0[arg0[4]](arg0);
    if (!(arg0[2] & 0xF0)) {
        func_8002F288((M2C_UNK*)arg0);
    }
}
