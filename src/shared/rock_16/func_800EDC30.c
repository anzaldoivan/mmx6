#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002CB50();
extern struct X4_EngineObj D_800CCED0;
extern u16 D_800F10F8[][2];

void func_800EDC30(struct X4_AnimatedObj* self) {
    self->x_pos.i.hi = D_800F10F8[D_800CCED0.character_state.bytes[1]][0];
    self->y_pos.i.hi = D_800F10F8[D_800CCED0.character_state.bytes[1]][1];
    if (D_800CCED0.character_state.bytes[0] != 0) {
        func_800179A4(self, 4);
        self->unk6++;
    }
    func_8002CB50(self);
}
