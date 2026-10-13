#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CA14();
extern s8 D_800CCEED;

void func_800EDA70(void* arg0) {
    func_8002CCB0(arg0, 0x20, 0x20);
    if (D_800CCEED >= 4) {
        ((M2C_UNK(*)())func_8002CA14)(arg0);
    }
}
