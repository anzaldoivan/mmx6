#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
extern M2C_UNK D_800F7448;
extern M2C_UNK D_800F744C;

void func_800ED924(void* arg0) {
    ((void (*)())func_80017A04)();
    {
        // !FAKE: call arg set before the test lands in the branch delay slot
        register void* a asm("$4") = arg0;
        if (M2C_FIELD(arg0, s8*, 0x45) == 3) {
            M2C_FIELD(arg0, s32**, 0x54) = &D_800F744C;
            M2C_FIELD(arg0, s32**, 0x50) = &D_800F7448;
            ((void (*)(void*, s32))func_800179A4)(a, 0);
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
            M2C_FIELD(arg0, s8*, 5) = 1;
        }
    }
}
