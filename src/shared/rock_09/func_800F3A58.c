#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F0434(s8* self, u32 arg1);
extern u8 D_800F6924[];

void func_800F3A58(s8* self) {
    s32 t;

    if (M2C_FIELD(self, s8*, 0x46) == 0) {
        func_800F0434(self, 0xA);
    }
    t = M2C_FIELD(self, u16*, 0x7C) + 1;
    M2C_FIELD(self, u16*, 0x7C) = t;
    if ((s16)t == 0x10E) {
        M2C_FIELD(self, u8*, 5) = D_800F6924[M2C_FIELD(self, u8*, 0x87)++ +
                                             M2C_FIELD(self, u8*, 0x86) * 6];
        M2C_FIELD(self, u8*, 6) = 0;
    }
}
