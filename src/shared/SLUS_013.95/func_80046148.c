#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);
M2C_UNK func_8002D2B0(void*);
M2C_UNK func_8002EE10(void*);
void func_80049D90(void*);

void func_80046148(u8* arg0) {
    if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
        arg0[3] = 1;
        func_80017A04(arg0);
        func_8002D2B0(arg0);
        {
            register s32 t asm("$2") = *(s8*)(arg0 + 0x98);
            if (t != 0) {
                goto block_5;
            }
        }
        if (arg0[0x70] == 0) {
            func_8002EE10(arg0);
            if (arg0[0x70] == 0) {
                return;
            }
        }
        func_80049D90(arg0);
    }
block_5:
    arg0[3] = 0;
    arg0[4] = 3;
}
