#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_800F82C0();
extern u8 D_800FB810[];

#define SPAD (*(u8**)0x1F80004C)

void func_800F6058(u8* arg0) {
    register s32 t asm("$2");
    s32 c;
    s32 v;

    func_80017A04(arg0);
    func_800F82C0(arg0);
    t = *(u16*)(arg0 + 0x7C);
    {
        register s32 n asm("$3") = t + 1;
        *(u16*)(arg0 + 0x7C) = n;
    }
    if ((s16)t >= 0x28) {
        *(u16*)(arg0 + 0x7C) = 0;
        c = SPAD[0x85] + 1;
        SPAD[0x85] = c;
        v = D_800FB810[(c & 3) + SPAD[0x84] * 4];
        arg0[6] = 0;
        arg0[5] = v;
    }
}
