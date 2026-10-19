#include "common.h"
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

void func_800EA738(struct X4_MainObj* self) {
    if (self->unk7C == 0x1E) {
        SPAD[0x83] = 1;
    }
    if (--self->unk7C == 0) {
        SPAD[0x82] = 1;
        self->unk5 = 5;
        self->unk6 = 0;
    }
}

#undef SPAD
