#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EF2E8(struct X4_MainObj* self);
extern M2C_UNK D_8007591C;

void func_800EE230(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_800EF2E8(arg0);
        M2C_FIELD(arg0, void**, 0x58) = &D_8007591C;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0x2000;
        M2C_FIELD(arg0, u8*, 5) += 1;
    }
}
