#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
s32 func_8002CBFC(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D2B0(s32);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80030ECC(void*);

void func_800EBCEC(u8* arg0) {
    func_80017A04();
    func_8002D2B0((s32)arg0);
    func_80030ECC(arg0);
    {
        register s32 g asm("$2") = arg0[0x70];
        if (g != 0) {
            goto H;
        }
    }
    {
        func_8002EE10(arg0);
        {
            register s32 f asm("$3") = arg0[0x70];
            if (f == 0 && func_8002CBFC((s32)arg0, 0x20, 0x20) == 0) {
                func_8002CCB0(arg0, 0x10, 0x10);
                return;
            }
        }
    }
H:
    arg0[4]++;
}
