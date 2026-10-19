#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 func_8003A628(void*);
M2C_UNK func_8003CCBC();
extern void (*D_80073C04[])(struct X4_MainObj*);

void func_800370B0(struct X4_MainObj* self) {
    if (func_8003A628(self) == 0) {
        ((void (*)())func_80017A04)(self);
        D_80073C04[self->unk6](self);
    }
    if (self->unk5 != 0xC && self->terrain_box != 0) {
        ((void (*)())func_8003CCBC)(self);
    }
}
