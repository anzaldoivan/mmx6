#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern u8 D_800F698C[];

void func_800F3EE0(void* arg0) {
    s16 t;

    t = ++M2C_FIELD(arg0, u16*, 0x7C);
    if (t == 0x32) {
        func_80027BA0(0, 0x22F0, 0x290, D_800F698C);
        func_80027BA0(0, 0x2480, 0x290, D_800F698C + 0x10);
        M2C_FIELD(arg0, u8*, 6) = 3;
    }
}
