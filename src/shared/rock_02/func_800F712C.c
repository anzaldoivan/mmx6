#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_800F82C0();

void func_800F712C(u8* arg0) {
    // !FAKE: depin: dropping it breaks the match (23/30)
    register s32 t asm("$2");
    func_800F82C0();
    func_80017A04(arg0);
    t = *(u16*)(arg0 + 0x7C) + 1;
    *(s16*)(arg0 + 0x7C) = t;
    if ((s16)t >= 10) {
        func_80012D9C(7);
        func_80016C48(2, 0x1D, arg0);
        arg0[6]++;
    }
}
