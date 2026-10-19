#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80025FD8();

extern struct X4_EngineObj D_800CCED0;

void func_800ED904(struct X4_MainObj* self) {
    D_800CCED0.enable_boss = 1;
    M2C_FIELD(&D_800CCED0, u8*, 0x8C) = 0x7F;
    func_80025FD8(0);
    D_800CCED0.unk25 = 0;
    D_800CCED0.boss_ptr = self;
    self->unk7E = 3;
    self->unk6++;
}
