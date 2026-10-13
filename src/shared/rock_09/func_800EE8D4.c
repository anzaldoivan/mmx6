#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800EE8D4(void* arg0) {
    func_80017A04(arg0);
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s8*, 6) >= 5) {
        func_800179A4(arg0, 6);
        {
            register s32 a asm("$2") = M2C_FIELD(arg0, u8*, 0);
            register s32 b asm("$3") = M2C_FIELD(arg0, u8*, 5);
            M2C_FIELD(arg0, u8*, 0) = a & 0xEF;
            M2C_FIELD(arg0, u8*, 5) = b + 1;
        }
    }
}
