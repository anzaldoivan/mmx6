#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FA4C8(struct X4_MainObj* self);
extern M2C_UNK D_8007433C;

void func_800F8FB4(void* arg0) {
    func_800FA4C8(arg0);
    M2C_FIELD(arg0, u8*, 0x8C) = M2C_FIELD(arg0, u8*, 0x8B);
    M2C_FIELD(arg0, u8*, 0x8B) = 0;
    M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    M2C_FIELD(arg0, s16*, 0x84) = 0x2710;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
    M2C_FIELD(arg0, u8*, 6) += 1;
}
