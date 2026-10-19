#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002B2F8(s32);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s8 D_800970A5;
extern s8 D_8009742C;
extern u8 D_800C4560;
extern s8 D_800CF850;

void func_800F32A8(void* arg0) {
    s32 i;

    if (D_800970A5 == 0x14) {
        func_8002B2F8(0);
        D_80090D56 = 1;
        D_8009742C = 1;
        D_800CF850 = 1;
        D_80090C90[1] = 0xF0000000;
        for (i = 3; i < 15; i++) {
            D_80090C90[i] = -1;
        }
        D_800C4560 |= 1;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
    }
}
