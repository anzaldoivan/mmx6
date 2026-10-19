#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern void (*D_800F1218[])(void*);

void func_800EE1EC(u8* arg0) {
    D_800F1218[(s8)arg0[4]](arg0);
    func_8002CCB0(arg0, 0x60, 0x10);
}
