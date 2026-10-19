#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

void func_800FD374(void* arg0) {
    func_80016C48(2, 0x94, arg0);
    func_800179A4(arg0, 8);
    M2C_FIELD(arg0, s16*, 0x7C) = -0x28;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s16*, 0x8A) = 1;
    {
        // !FAKE: byte read held in $3 so it schedules before the field stores
        register s32 c asm("$3");
        c = M2C_FIELD(arg0, u8*, 6);
        M2C_FIELD(arg0, u8*, 6) = c + 1;
    }
    func_8002CCB0(arg0, 0x40, 0x40);
    func_8002D230(arg0);
}
