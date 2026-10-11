#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800F33F8(); /* extern */

void func_800F4A9C(struct X4_MainObj* self) {
    self->unk7C--;
    if (self->unk7C == 0) {
        *(s16*)((u8*)self + 0x88) = 0x28;
        ((M2C_UNK(*)())func_800F33F8)();
    }
}
