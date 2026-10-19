#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0();
extern struct X4_PlayerObj D_800970A0;

void func_80045138(void* arg0) {
    u8 temp_v0;
    void* temp_v1;

    if (M2C_FIELD(arg0, s8*, 0x2) == 0) {
        if (M2C_FIELD(arg0, u8*, 0x8C) == 0) {
            struct X4_PlayerObj* p = &D_800970A0;
            M2C_FIELD(p, u8*, 0x98) -= 1;
            M2C_FIELD(p, u8*, 0x99) -= 1;
            // !FAKE: retail shares the call block with the else arm
            goto block_5;
        }
    } else {
        temp_v1 = M2C_FIELD(arg0, void**, 0x7C);
        temp_v0 = M2C_FIELD(temp_v1, u8*, 0x8C);
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v1, u8*, 0x8C) = temp_v0 - 1;
        }
    block_5:
        func_8002C9B0(arg0, arg0);
    }
}
