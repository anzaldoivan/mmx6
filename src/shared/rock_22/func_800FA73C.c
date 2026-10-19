#include "common.h"
#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D2B0(s32);
M2C_UNK func_80030ECC(void*);
M2C_UNK func_80049D90(void*);

void func_800FA73C(u8* arg0) {
    func_80017A04();
    func_8002D2B0((s32)arg0);
    {
        // !FAKE: test byte lands in the first return register
        register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 0x70);
        if ((t != 0) || (func_80030ECC(arg0) != 0)) {
            func_80049D90(arg0);
            M2C_FIELD(arg0, u8*, 0x4) = 2;
            return;
        }
    }
    if (func_8002CBFC(arg0, 0xF0, 0xF0) == 0) {
        func_8002CCB0(arg0, 0x40, 0x40);
        return;
    }
    M2C_FIELD(arg0, u8*, 0x4) = 2;
}
