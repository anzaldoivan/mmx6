#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800F1E60(u8* arg0) {
    s8 temp_s1;

    ((M2C_UNK(*)())func_80017A04)();
    temp_s1 = arg0[0x45];
    if (temp_s1 == 2) {
        if (--*(s16*)(arg0 + 0x7E) != 0) {
            func_800179A4(arg0, 0);
            arg0[6] = temp_s1;
            *(s16*)(arg0 + 0x7C) = 0x5A;
            return;
        }
        arg0[5] = 7;
        arg0[6] = 0;
    }
}
