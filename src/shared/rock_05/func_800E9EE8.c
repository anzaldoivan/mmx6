#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
#define SCRATCH_4C (*(u8**)0x1F80004C)

void func_800E9EE8(u8* arg0) {
    s32 temp_v1;

    func_80016C48(2, 0x16, arg0);
    if (!(*(s8*)(arg0 + 2) & 0xF0)) {
        func_800179A4(arg0, 0);
    } else {
        func_800179A4(arg0, 2);
    }
    temp_v1 = arg0[2] & 0xF;
    *(s16*)(arg0 + 0x7E) = 0;
    if ((s8)temp_v1 == 0) {
        SCRATCH_4C[0x85] = 1;
        *(s16*)(arg0 + 0x7C) = 0xB4;
    } else {
        if ((s8)temp_v1 >= 0) {
            if ((s8)temp_v1 < 8) {
                SCRATCH_4C[0x85] = temp_v1;
                *(s16*)(arg0 + 0x7C) = 0xE;
                goto end;
            }
        }
        SCRATCH_4C[0x85] = (func_8002D2D4() & 3) + 1;
        *(s16*)(arg0 + 0x7C) = 0xE;
    }
end:
    arg0[6]++;
}
