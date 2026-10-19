#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CB50();
extern u8 D_800F1CF0[];

void func_800EDF20(void* arg0) {
    if (*((*((u8*)arg0 + 2) & 0xF) + D_800F1CF0) != 0) {
        ((void (*)())func_8002CB50)(arg0, arg0);
        return;
    }
    *((u8*)arg0 + 3) = 0;
}
