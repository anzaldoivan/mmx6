#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230();
M2C_UNK func_80030ECC(void*);

void func_800EB29C(void* self) {
    if (M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s8*, 4) != 2) {
        M2C_FIELD(self, u8*, 6)++;
        switch (M2C_FIELD(self, s8*, 5)) {
        case 0:
            if (M2C_FIELD(self, s8*, 0x46) != 0) {
                break;
            }
            goto set;
        case 1:
            func_80030ECC(self);
            if (M2C_FIELD(self, s8*, 6) != 0x5A) {
                break;
            }
        set:
            ((void (*)(void*, s32))func_800179A4)(
                self, M2C_FIELD(self, u8*, 0x17) + 1);
            M2C_FIELD(self, u8*, 5)++;
            break;
        case 2:
            if (M2C_FIELD(self, s8*, 0x46) == 0) {
                goto inc;
            }
            break;
        }
        func_80017A04(self);
        func_8002D230(self);
        if (func_8002CBFC(self, 0x20, 0x20) == 0) {
            func_8002CCB0(self, 0x20, 0x20);
            return;
        }
    }
inc:
    M2C_FIELD(self, u8*, 4)++;
}
