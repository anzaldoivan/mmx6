#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern s32 D_800F7DE4;

void func_800F5E0C(u8* arg0) {
    u8* p;

    if (D_800F7DE4 != 0) {
        goto block_2;
    }
    p = *(u8**)(arg0 + 0x7C);
    arg0[0x15] = p[0x15];
    *(u16*)(arg0 + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(arg0 + 0xE) = *(u16*)(p + 0xE);
    if ((*(s32*)(p + 4) & 0xFFFF00) != 0x50500) {
    block_2:
        arg0[4] = 2;
        return;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x20, 0x20);
}
