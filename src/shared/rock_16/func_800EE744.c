#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj D_800CCED0;
extern u16 D_800F128C[][2];

void func_800EE744(struct X4_AnimatedObj* self) {
    func_80017A04();
    if (D_800CCED0.character_state.bytes[3] != self->unk7) {
        self->x_pos.i.hi =
            D_800F128C[D_800CCED0.character_state.bytes[3]][0] + 0x600;
        self->y_pos.i.hi = D_800F128C[D_800CCED0.character_state.bytes[3]][1];
        func_800179A4(self, D_800CCED0.character_state.bytes[3]);
        self->unk7 = D_800CCED0.character_state.bytes[3];
    }
    func_8002CCB0(self, 0xA0, 0x10);
}
