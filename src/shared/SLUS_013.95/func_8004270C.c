#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800429D4();
void func_80042D98(s8* arg0);

void func_8004270C(void* arg0) {
    s8 temp_s1;

    temp_s1 = M2C_FIELD(arg0, s8*, 0x45);
    if (temp_s1 == 1) {
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        func_80042D98(arg0);
        if (M2C_FIELD(arg0, s32*, 0x80) == 0) {
            M2C_FIELD(arg0, u8*, 0x8F) = 0;
            func_800429D4(arg0);
            return;
        }
        M2C_FIELD(arg0, u8*, 0x8D) = temp_s1;
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}
