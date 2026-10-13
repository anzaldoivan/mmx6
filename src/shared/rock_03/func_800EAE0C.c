#include "common.h"
#define M2C_UNK s32

#define SP64 (*(u8**)(0x1F800064))

M2C_UNK func_80017A04();
M2C_UNK func_8002C9B0();

void func_800EAE0C(u8* arg0) {
    func_80017A04();
    if (--*(s16*)(SP64 + 0x54) == 0) {
        func_8002C9B0(arg0);
        return;
    }
    if (!(*(u16*)(SP64 + 0x54) & 1)) {
        arg0[3] = 0;
        return;
    }
    arg0[3] = 1;
}
