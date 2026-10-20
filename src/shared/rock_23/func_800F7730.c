#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0();

void func_800F7730(u8* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    func_8002D2B0((s32)arg0);
    {
        // !FAKE: decrement temp lands in the first return register as retail
        register s32 temp_v0 asm("$2") = arg0[0x8D] - 1;
        arg0[0x8D] = temp_v0;
        if (!(temp_v0 & 0xFF)) {
            arg0[6]++;
        }
    }
}
