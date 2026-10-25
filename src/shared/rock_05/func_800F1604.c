#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
extern s32 D_800F4144;
extern s16 D_800F4480;

void func_800F1604(void* arg0) {
    ((void (*)(void*))move_object)(arg0);
    ((void (*)())func_80017A04)(arg0);
    if ((D_800F4480 + 0x420) < ((s16*)arg0)[7]) {
        ((s32**)arg0)[0x68 / 4] = &D_800F4144;
    }
    if (((u8*)arg0)[0x70] & 8) {
        ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
    }
}
