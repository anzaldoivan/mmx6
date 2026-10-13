#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80031DA8();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_8003208C();
void func_80032BE8(struct X4_PlayerObj*);
extern M2C_UNK D_800F62F0;

void func_800EE4C4(void* arg0) {
    ((void (**)(void*)) & D_800F62F0)[M2C_FIELD(arg0, s8*, 5)](arg0);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
    func_80031DA8(arg0);
    func_8003208C(arg0);
    func_80031F4C(arg0);
    func_80032BE8(arg0);
}
