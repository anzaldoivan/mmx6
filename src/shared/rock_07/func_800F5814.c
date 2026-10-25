#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK move_object(void*);
extern M2C_UNK D_800F907C;

void func_800F5814(void* arg0) {
    // !FAKE: pin the first compare operand to v0 so the loads and slt use retail's registers
    register s32 a asm("$2");

    move_object(arg0);
    a = M2C_FIELD(arg0, s16*, 0xE);
    if (a < M2C_FIELD(arg0, s16*, 0x86)) {
        M2C_FIELD(arg0, void**, 0x68) = &D_800F907C;
        func_800179A4(arg0, 4);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x105D;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
