#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern void (*D_800F7648[])(struct X4_MainObj*);

void func_800F4E1C(struct X4_MainObj* self) {
    func_8002D230(self);
    D_800F7648[self->unk6](self);
    func_80017A04(self);
    func_8002CCB0(self, 0x30, 0x40);
}
