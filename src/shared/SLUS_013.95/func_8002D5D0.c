#include "common.h"

#define M2C_UNK s32

extern s8 D_800971F0;

M2C_UNK func_8002D5D0(void* arg) {
    u8* arg0 = arg;
    s32 t;
    s32 v;
    s32 q;

    if (D_800971F0 != 0 && arg0[0x15] != 0) {
        t = *(s32*)(arg0 + 0x20);
        v = t * 3;
        q = v / 4;
        *(s32*)(arg0 + 0x20) = t;
        *(s32*)(arg0 + 0x8) += q;
        *(s32*)(arg0 + 0xC) -= *(s32*)(arg0 + 0x24);
    } else {
        *(s32*)(arg0 + 0x8) += *(s32*)(arg0 + 0x20);
        *(s32*)(arg0 + 0xC) -= *(s32*)(arg0 + 0x24);
    }
}
