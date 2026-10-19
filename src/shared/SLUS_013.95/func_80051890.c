#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_8003208C();
s32 func_80032B34(struct X4_PlayerObj*);
extern void (*D_80078E18[])(struct X4_PlayerObj*);
extern u8 D_80097185;

void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
void func_80031DA8(struct X4_MainObj*);
s8 func_80032BE8(struct X4_PlayerObj* arg0);
M2C_UNK func_80051890(struct X4_PlayerObj* self) {
    ((M2C_UNK(*)())func_80017A04)();
    D_80078E18[self->unk5](self);
    func_80032B34(self);
    if (D_80097185 == 0) {
        ((M2C_UNK(*)())func_80031DA8)(self);
    }
    func_8003208C(self);
    func_80031F4C(self);
    ((void (*)())func_80032BE8)(self);
    return ((M2C_UNK(*)())func_8002CCB0)(self, 0x88, 0x88);
}
