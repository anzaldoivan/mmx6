#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002D230(void*);

void func_800EEF78(void* arg0) {
    s32 v;

    if (((*((u8*)arg0 + 0x15) == 0) && (*((u8*)arg0 + 0x70) & 1)) ||
        ((*((volatile u8*)arg0 + 0x15) == 0x40) && (*((u8*)arg0 + 0x70) & 2))) {
        *((u8*)arg0 + 6) += 1;
    } else {
        v = *(s32*)((u8*)arg0 + 0x20);
        if (v < 0) {
            v = -v;
        }
        if (v < 0x3000) {
            *((u8*)arg0 + 6) += 1;
        } else {
            ((void (*)(void*))func_8002D230)(arg0);
        }
    }
}
