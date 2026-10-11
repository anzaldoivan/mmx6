#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern void (*D_800FB24C[])(void*);

void func_800F0C0C(u8* arg0) {
    if (arg0[0x84] < 0x32U) {
        arg0[0x84] = 0x64;
    }
    D_800FB24C[(s8)arg0[6]](arg0);
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0xA0, 0xA0);
}
