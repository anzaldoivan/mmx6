#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_8004FF4C(s32);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj D_800CCED0;

void func_800EFE10(struct X4_AnimatedObj* self) {
    s32 count;
    s32 i;
    s32 base;

    count = 0;
    i = 0;
    do {
        if (func_8004FF4C(D_800CCED0.character_state.bytes[5] * 0x10 + i) ==
            2) {
            count++;
        }
        i++;
    } while (i < 0x10);
    self->y_pos.i.hi = 0x97;
    base = self->unk2 * 0x18;
    self->x_pos.i.hi = base + 0x7C0;
    if (background_objects[self->bg_offset].x_pos.i.hi < 0x400) {
        self->x_pos.i.hi = base + 0x1C0;
    }
    if (self->unk2 == 0) {
        self->animation_step.fields.frame_index = count / 10 - 0x61;
    } else {
        self->animation_step.fields.frame_index = count % 10 - 0x61;
    }
    func_8002CCB0(self, 0x10, 0x10);
}
