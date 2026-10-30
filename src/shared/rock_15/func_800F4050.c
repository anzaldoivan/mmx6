#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800F4050(void* arg0) {
    func_80017A04();
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        set_animation(arg0, 2);
        {
            // !FAKE: pin the constant to the first return register as retail does
            register s32 k asm("$2") = 4;
            M2C_FIELD(arg0, u8*, 0x5) = k;
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = 0xA;
    }
}
