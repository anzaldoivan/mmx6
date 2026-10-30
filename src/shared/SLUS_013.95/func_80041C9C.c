#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK move_object(void*);
s32 random_byte();
M2C_UNK func_800429D4();
extern u8 D_800CCF38;

void func_80041C9C(struct X4_MainObj* self) {
    s8 v;

    ((void (*)(void*))move_object)(self);
    if (--self->unk7C == 0) {
        if (--self->unk7E == 0) {
            if (D_800CCF38 < 2 || !(random_byte() & 1)) {
                func_800429D4(self);
                return;
            }
            v = 3;
        } else {
            v = 1;
        }
        self->unk6 = v;
    }
}
