#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK move_object(void*);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);

void func_800F3678(void* arg0) {
    s32 s1;

    s1 = M2C_FIELD(arg0, s32*, 0x7C);
    ((void (*)())move_object)();
    if (func_80031474(arg0) >= 0) {
        func_80030ECC(arg0);
        if (M2C_FIELD(arg0, s16*, 0x92) > M2C_FIELD(arg0, s16*, 0xE)) {
            move_object(arg0);
            return;
        }
        func_80016C48(2, 0x36, (void*)s1);
        func_80012D9C(5);
    }
    M2C_FIELD(arg0, u8*, 5) = 2;
    M2C_FIELD(arg0, s16*, 0x90) = 0x3C;
}
