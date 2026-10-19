#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8003B114(s32);

void func_801ED0A0(void* arg0) {
    ((void (*)())func_80017A04)(arg0);
    if (((s8*)arg0)[0x46] == 0) {
        ((u8*)arg0)[0x8E] = 0;
        func_8003B114((s32)arg0);
    }
}
