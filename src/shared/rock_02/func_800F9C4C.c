#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern void (*D_800FBC48[])(void*);

void func_800F9C4C(s8* arg0) {
    func_80017A04(arg0);
    D_800FBC48[arg0[5]](arg0);
    func_8002CCB0(arg0, 0x20, 0x20);
}
