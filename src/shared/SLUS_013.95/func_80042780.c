#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80016C48(s32 a0, s32 a1, void* arg2);
void func_80042A9C(struct X4_MainObj* self, s32 arg1);

void func_80042780(void* arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 0x45);
    if (temp_v1 == 1) {
        M2C_FIELD(arg0, u8*, 0x7) = temp_v1;
        func_80016C48(2, 0x3F, arg0);
        func_80042A9C(arg0, 0x10);
        M2C_FIELD(arg0, u16*, 0x7C) = 0x3C;
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}
