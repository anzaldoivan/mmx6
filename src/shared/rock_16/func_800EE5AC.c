#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_80097420;
extern struct X4_EngineObj D_800CCED0;
extern u16 D_800F128C[][2];

void func_800EE5AC(struct X4_AnimatedObj* self) {
    func_80017A04();
    if (D_800CCED0.character_state.bytes[3] != self->unk7) {
        self->x_pos.i.hi = D_800F128C[D_800CCED0.character_state.bytes[3]][0];
        self->y_pos.i.hi = D_800F128C[D_800CCED0.character_state.bytes[3]][1];
        func_800179A4(self, D_800CCED0.character_state.bytes[3]);
        self->unk7 = D_800CCED0.character_state.bytes[3];
    }
    if (self->unk6 == 0) {
        if (D_800CCED0.unk1 == 6) {
            self->on_screen = 0;
            self->unk6++;
            return;
        }
        func_8002CCB0(self, 0xA0, 0x10);
        if ((*(s32*)&D_800CCED0 & 0xFFFF00) == 0x40500 && (D_80097420 & 1)) {
            self->on_screen = 0;
        }
    } else if (D_800CCED0.unk1 == 5 ||
               background_objects[self->bg_offset].x_pos.i.hi >= 0x400) {
        self->unk6--;
    }
}
