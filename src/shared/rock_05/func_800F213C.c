#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(void*);

void func_800F213C(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 2) {
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        func_800179A4(arg0, 4);
        {
            // !FAKE: pin the 0x40 constant to v0 so the byte load follows its store
            register s32 c asm("$2") = 0x40;
            M2C_FIELD(arg0, u8*, 0x15) = c;
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0xFFFB0000;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        return;
    }
    func_8002D2B0(arg0);
    func_80017A04(arg0);
}
