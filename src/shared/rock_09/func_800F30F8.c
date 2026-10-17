#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
void func_800F0434(s8* self, u32 arg1);
extern u8 D_8008EAFC;

void func_800F30F8(s8* arg0) {
    if (D_8008EAFC == 0) {
        func_800F0434(arg0, 7);
        *(s16*)(arg0 + 0x7C) = 0;
        *(u8*)(arg0 + 6) += 1;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x80, 0x80);
}
