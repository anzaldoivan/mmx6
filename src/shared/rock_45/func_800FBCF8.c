/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_65_magma_dragoon.c:magma_dragoon_breath, AGPL-3.0; proven shared with X6 by exact signature 98a46ba8d11d (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern void (*D_800FCDDC[])(struct X4_MainObj*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800FBCF8(struct X4_MainObj* self) {
    D_800FCDDC[self->unk6](self);
    func_8002CCB0((struct X4_BaseObj*)self, 0x40, 0x40);
}
