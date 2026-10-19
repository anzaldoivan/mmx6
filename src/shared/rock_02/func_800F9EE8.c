#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);

void func_800F9EE8(struct X4_MainObj* self) {
    if (*(s8*)self->attack_box == 0) {
        ((void (*)(s32, s32, s32))func_80021760)(3, 0xFF, 0);
        self->unk5++;
    }
}
