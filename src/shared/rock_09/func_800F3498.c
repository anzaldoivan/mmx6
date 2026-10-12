#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_8002D2D4();
void func_800F0434(s8* self, u32 arg1);
extern u8 D_800CCF5F;
extern u8 D_800E98C4[];

void func_800F3498(void* arg0) {
    u8 tbl[4];

    __builtin_memcpy(tbl, D_800E98C4, 4);
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 8) {
        s16 n = M2C_FIELD(arg0, s16*, 0x7E);
        if (n == tbl[D_800CCF5F]) {
            func_800F0434(arg0, 0xA);
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
            M2C_FIELD(arg0, u8*, 6) += 1;
            return;
        }
        if (n == 0) {
            func_80016C48(2, 0x22, arg0);
            func_800F0434(arg0, 0x13);
        }
        M2C_FIELD(arg0, u8*, 7) = func_8002D2D4() & 1;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) += 1;
    }
}
