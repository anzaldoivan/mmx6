#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_80017A04();
M2C_UNK func_800F82C0();
extern u8 D_800FB810[];

void func_800F7D9C(void* arg0) {
    s32 t;
    s32 v;

    ((M2C_UNK(*)())func_80017A04)();
    func_800F82C0(arg0);
    if (SPAD4C[0x88] != 0 && M2C_FIELD(arg0, s8*, 0x45) == 1) {
        SPAD4C[0x88] = 0;
        {
            register u8* q asm("$3") = SPAD4C;
            t = q[0x85] + 1;
            q[0x85] = t;
        }
        v = D_800FB810[(t & 3) + SPAD4C[0x84] * 4];
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 5) = v;
        return;
    }
    if (SPAD4C[0x8A] != 0x11) {
        M2C_FIELD(arg0, u8*, 6) = 5;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    }
}
