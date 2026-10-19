#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
extern u16 D_800F766C[];

void func_800F5344(void* arg0) {
    M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0x88) +
                                 D_800F766C[0xF - M2C_FIELD(arg0, s16*, 0x7C)];
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x10) {
        M2C_FIELD(arg0, u8*, 5) = M2C_FIELD(arg0, u8*, 5) + 1;
    }
    func_8002CCB0(arg0, 0x30, 0x40);
}
