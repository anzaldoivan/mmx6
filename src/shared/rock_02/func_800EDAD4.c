#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK func_8002D230(void*);

void func_800EDAD4(struct X4_MainObj* self) {
    ((M2C_UNK(*)())func_80017A04)();
    {
        register s32 c asm("$2") = self->unk7C;
        if (c != 0) {
            self->unk7C--;
            return;
        }
    }
    func_8002D230(self);
    if (self->y_speed > 0x1FFFF) {
        self->gravity = 0x1000;
    }
    if (self->y_speed == 0) {
        self->unk6 = 0;
    }
}
