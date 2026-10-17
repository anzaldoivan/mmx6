#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139A0(M2C_UNK); /* extern */
void* func_8002C530();          /* extern */
extern s8 D_80097424;

void func_800EC95C(void* arg0) {
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;

    if (D_80097424 == 0) {
        temp_v0 = func_8002C530();
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, s8*, 0) = 1;
            M2C_FIELD(temp_v0, s8*, 1) = 0x38;
            M2C_FIELD(temp_v0, s8*, 2) = 0x28;
        }
        temp_v0_2 = func_8002C530();
        if (temp_v0_2 != 0) {
            M2C_FIELD(temp_v0_2, s8*, 0) = 1;
            M2C_FIELD(temp_v0_2, s8*, 1) = 0x38;
            M2C_FIELD(temp_v0_2, s8*, 2) = 0x29;
        }
        temp_v0_3 = func_8002C530();
        if (temp_v0_3 != 0) {
            M2C_FIELD(temp_v0_3, s8*, 0) = 1;
            M2C_FIELD(temp_v0_3, s8*, 1) = 0x38;
            M2C_FIELD(temp_v0_3, s8*, 2) = 0x2A;
        }
        ((void (*)(s32))func_800139A0)(8);
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}
