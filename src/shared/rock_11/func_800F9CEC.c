#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

void func_800F9CEC(u8* arg0) {
    u8 v;

    func_8002D230(arg0);
    v = arg0[0x15];
    if ((v == 0 && (arg0[0x70] & 1)) || (v == 0x40 && (arg0[0x70] & 2))) {
        func_80016C48(2, 0x4E, arg0);
        func_80012D9C(5);
        func_8002943C(0x14, 6, 2);
        {
            register s32 t asm("$2") = arg0[6] + 1;
            *(s16*)(arg0 + 0x7C) = 0x5A;
            arg0[6] = t;
        }
    }
}
