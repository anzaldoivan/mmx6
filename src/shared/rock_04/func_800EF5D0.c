#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern M2C_UNK D_800F6D84;

void func_800EF5D0(struct X4_BaseObj* self) {
    M2C_FIELD(self, s32*, 0x18) = M2C_FIELD(self, s32*, 0x8);
    M2C_FIELD(self, s32*, 0x1C) = M2C_FIELD(self, s32*, 0xC);
    ((void (**)(struct X4_BaseObj*)) & D_800F6D84)[self->unk5](self);
    if (self->unk2 == 0) {
        if (func_80031474(self) < 0) {
            func_8004E654(self, 0x12);
            func_80049E50(self);
        } else {
            func_80030ECC(self);
            if (func_8002CBFC(self, 0x80, 0x80) == 0) {
                func_8002CCB0(self, 0x40, 0x40);
                return;
            }
        }
        self->state = 2;
    }
}
