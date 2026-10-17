#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
void func_800F0434(s8* self, u32 arg1);
extern u8 D_800970B5;

void func_800F472C(s8* self) {
    M2C_FIELD(self, s16*, 0x7C) = 0x7F;
    M2C_FIELD(self, s16*, 0x7E) = 0x19;
    M2C_FIELD(self, s8*, 0x61) = 0x19;
    M2C_FIELD(self, u16*, 0x42) &= 0x7FFF;
    func_800F0434(self, 0x20);
    M2C_FIELD(self, u8*, 5)++;
    func_8003D308(0x14, D_800970B5);
    func_8002CCB0(self, 0x80, 0x80);
}
