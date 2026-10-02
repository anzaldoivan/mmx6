#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80017A04();                  /* extern */
M2C_UNK func_8002C9B0(s32);               /* extern */
s32 func_8002CBFC(s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D2B0(s32);               /* extern */

void func_800EDF30(s32 arg0) {
    func_80017A04();
    func_8002D2B0(arg0);
    if (func_8002CBFC(arg0, 0x40, 0x40) == 1) {
        func_8002C9B0(arg0);
    }
}
