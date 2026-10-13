#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
s32 func_800EE330(void*, M2C_UNK*);
extern s32 D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern s8 D_800CCEF7;

void func_800EE5A8(struct X4_MainObj* self) {
    if (func_800EE330(self, (M2C_UNK*)&D_800970A0) != 0) {
        D_800CCEF7 = 1;
        D_800970A0.x_pos.i.hi = self->x_pos.i.hi;
        D_800970A0.y_pos.i.hi = self->y_pos.i.hi - D_800970A0.unk68->unk3;
        func_8003D308(0x14, D_800970A0.unk15);
        self->unk6++;
    }
}
#undef D_800970A0
