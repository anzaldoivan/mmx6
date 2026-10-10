#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern void (*D_800F69F8[])(struct X4_MainObj*);
M2C_UNK func_80017A04(void*);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F3380(struct X4_MainObj* self) {
    D_800F69F8[self->unk6](self);
    func_80017A04(self);
    func_8002D230(self);
    func_8002CCB0(self, 0x80, 0x80);
}
