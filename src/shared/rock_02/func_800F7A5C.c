#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_80017A04();
M2C_UNK func_800F82C0();
extern u8 D_800FB810[];

void func_800F7A5C(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (30/37)
    register s32 t asm("$2");
    s32 c;
    u8 x;

    ((M2C_UNK(*)())func_80017A04)();
    func_800F82C0(arg0);
    t = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = t + 1;
    if ((s16)t >= 0x79) {
        c = ++SPAD4C[0x85];
        x = D_800FB810[(c & 3) + SPAD4C[0x84] * 4];
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 5) = x;
    }
}
