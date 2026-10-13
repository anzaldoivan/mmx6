#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002C9B0(); /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern s8 D_800CCEED;

void func_800F9854(void* arg0) {
    func_8002CCB0(arg0, 0x20, 0x20);
    if (D_800CCEED >= 2) {
        func_8002C9B0(arg0);
    }
}
