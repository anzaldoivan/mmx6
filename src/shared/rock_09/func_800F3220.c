#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_80040498();

void func_800F3220(u8* arg0) {
    if (func_80040498() != 0) {
        func_80017A04(arg0);
        func_8002CCB0(arg0, 0x80, 0x80);
        return;
    }
    func_80017A04(arg0);
    func_8002CCB0(arg0, 0x80, 0x80);
    {
        // !FAKE: depin: dropping it breaks the match (31/36)
        register s32 t asm("$2") = *(u16*)(arg0 + 0x7C) - 1;

        *(u16*)(arg0 + 0x7C) = t;
        if ((s16)t == 0) {
            *(u16*)(arg0 + 0x7C) = 3;
            arg0[6]++;
        }
    }
}
