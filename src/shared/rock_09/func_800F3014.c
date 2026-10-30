#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern struct X4_EngineObj g_playthrough_state;

void func_800F3014(struct X4_MainObj* self) {
    if (++self->unk7C == 0x1C) {
        play_sound(2, 0x39, self);
        func_80029478(0x3C, 2, 2);
        func_80012D9C(3);
    }
    if (self->animation_step.fields.relative_step == 0 && self->unk7C == 0x64) {
        struct X4_EngineObj* e = &g_playthrough_state;
        if (e->stage != 0xC) {
            open_text_box(0, 0xFF, e->character_state.bytes[8]);
            e->character_state.bytes[8] = 1;
        }
        self->unk7C = 0;
        self->unk6++;
    }
    func_80017A04(self);
    func_8002D230(self);
    func_8002CCB0(self, 0x80, 0x80);
}
