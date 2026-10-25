#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);

void func_800EABD4(struct X4_BaseObj* self) {
    func_80017A04();
    move_object(self);
    if (func_80031474(self) < 0) {
        ((void (*)(void*))func_80049E50)(self);
        self->state++;
    } else {
        M2C_FIELD(self, u16*, 0x42) &= 0x7FFF;
    }
    func_80030ECC(self);
    if (func_8002CBFC(self, 0x20, 0x20) == 0) {
        func_8002CCB0(self, 0x10, 0x10);
        return;
    }
    self->state++;
}
