#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800FA81C(void* arg0) {
    s8 st = M2C_FIELD(arg0, s8*, 0x45);

    if (st == 1) {
        // !FAKE: pin the old counter to the first return register (v0/v1 swap)
        register u16 t asm("$2");

        func_800179A4(arg0, 0x1F);
        t = M2C_FIELD(arg0, u16*, 0x54);
        M2C_FIELD(arg0, u16*, 0x54) = t + 1;
        if ((s16)t >= 2) {
            M2C_FIELD(arg0, u8*, 3) = 0;
            M2C_FIELD(arg0, u8*, 4)++;
        }
    } else if (st == 2) {
        func_80016C48(2, 0x4F, arg0);
    }
}
