#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F9E04(struct X4_AnimatedObj*);

extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;

void func_800F9204(struct X4_PlayerObj* self) {
    if (M2C_FIELD(self, s8*, 0x45) == 1) {
        self->unk16 = 6;
        set_animation(self, 0x1E);
        func_800F9E04((struct X4_AnimatedObj*)self);
        self->unk50 = &D_800FC734;
        self->unk54 = (const u32*)&D_800FC738;
        M2C_FIELD(self, s16*, 0x7C) = 0x14;
        self->unk6++;
    }
}
