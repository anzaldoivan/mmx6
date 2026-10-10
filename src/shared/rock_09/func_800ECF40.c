#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80031DA8();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_8003208C();
s32 func_80032B34(struct X4_PlayerObj*);
void func_80032BE8(struct X4_PlayerObj*);
extern s32 D_800970A0;
extern u8 D_800F4BF0[];

void func_800ECF40(void* arg0) {
    struct X4_PlayerObj* p;

    func_80032B34(arg0);
    func_80032BE8(arg0);
    p = &D_800970A0;
    if (((s8*)p)[0xE0] != 2) {
        ((void (**)(void*))(D_800F4BF0 + 0x14B0))[M2C_FIELD(arg0, s8*, 6)](
            arg0);
    }
    func_80017A04(arg0);
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x30, 0x40);
    if (((u8*)p)[0xE5] == 0) {
        func_80031DA8(arg0);
    }
    func_8003208C(arg0);
    func_80031F4C(arg0);
}
