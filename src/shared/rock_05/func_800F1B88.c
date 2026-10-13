#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
void* func_8002C458();
M2C_UNK func_800F2B4C();

void func_800F1B88(void* arg0) {
    s8 temp_s1;
    void* temp_v0;

    func_800F2B4C();
    func_80017A04(arg0);
    temp_s1 = M2C_FIELD(arg0, s8*, 0x45);
    if (temp_s1 == 1) {
        temp_v0 = func_8002C458();
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, u8*, 0) = 0x41;
            M2C_FIELD(temp_v0, u8*, 1) = 0x12;
            M2C_FIELD(temp_v0, u8*, 2) = temp_s1;
            M2C_FIELD(temp_v0, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(temp_v0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(temp_v0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(temp_v0, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(temp_v0, void**, 0x7C) = arg0;
            ((s32(*)(s32, s32, void*, void*))func_80016C48)(2, 0xC, arg0,
                                                            temp_v0);
            func_80016C48(2, 0x23, arg0);
        }
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
