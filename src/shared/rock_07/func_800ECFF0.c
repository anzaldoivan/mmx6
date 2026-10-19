#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80049E50(void*);
extern s32 D_800F8848;

void func_800ECFF0(u8* arg0) {
    *(s32**)(arg0 + 0x50) = &D_800F8848;
    ((void (*)(void*))func_80049E50)(arg0);
    arg0[0x92] = 1;
    *(s16*)(arg0 + 0x88) = 0x1E;
    arg0[7] = arg0[7] + 1;
}
