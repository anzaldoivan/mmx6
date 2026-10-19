#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80012D9C(M2C_UNK);                 /* extern */
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8002D230();                        /* extern */

void func_800F4EB0(u8* arg0) {
    ((void (*)(void*))func_8002D230)(arg0);
    if (arg0[0x70] & 8) {
        ((void (*)(s32, s32, void*))func_80016C48)(2, 0x12, arg0);
        ((void (*)(s32))func_80012D9C)(8);
        arg0[6]++;
    }
}
