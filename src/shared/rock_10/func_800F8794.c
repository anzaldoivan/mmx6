#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
extern M2C_UNK D_8007433C;

void func_800F8794(u8* arg0) {
    s8 state;

    state = *(s8*)(arg0 + 7);
    if (state == 3) {
        func_80016C48(2, 0x52, arg0);
        func_800179A4(arg0, 8);
        {
            register s32* p asm("$2") = &D_8007433C;
            register s32 one asm("$3") = 1;
            *(s32**)(arg0 + 0x58) = p;
            arg0[0x8E] = one;
        }
        arg0[7] = 0;
    } else if (state == 4) {
        func_80016C48(2, 0x52, arg0);
        func_800179A4(arg0, 6);
        {
            register s32* p asm("$2") = &D_8007433C;
            register s32 t asm("$4") = arg0[6];
            register s32 one asm("$3") = 1;
            *(s32**)(arg0 + 0x58) = p;
            arg0[0x8E] = one;
            *(s16*)(arg0 + 0x7C) = 0xA;
            arg0[7] = 0;
            arg0[6] = t + 1;
        }
    }
}
