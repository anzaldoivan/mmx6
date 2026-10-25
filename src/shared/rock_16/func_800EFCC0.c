#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179D0(void*, M2C_UNK, s8);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_8004FF4C(s32);
extern s32 D_8006D674[];
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj D_800CCED0;
extern s32 D_800F0E74[];
extern u16 D_800F1688[][2];

void func_800EFCC0(struct X4_AnimatedObj* self) {
    s32 r;
    s32 w;
    s32 i;
    s32 x;
    // !FAKE: depin: dropping it breaks the match (69/84)
    register s32 t asm("$3");

    t = D_800F1688[self->unk2][0];
    x = t + 0x9E;
    self->x_pos.i.hi = x;
    self->y_pos.i.hi = D_800F1688[self->unk2][1];
    t = self->bg_offset;
    if (background_objects[t].x_pos.i.hi < 0x400) {
        self->x_pos.i.hi = x - 0x600;
    }
    func_8002CCB0(self, 0x40, 0x10);
    r = func_8004FF4C(D_800CCED0.character_state.bytes[5] * 16 + self->unk2);
    if (r == 2 && (w = D_8006D674[D_800CCED0.character_state.bytes[5] * 16 +
                                  self->unk2]) != 0) {
        if (w == 1) {
            i = 0x18;
        } else if (w == r) {
            i = 0x19;
        } else {
            for (i = 0; i < 0x18; i++) {
                if (D_800F0E74[i] == w) {
                    goto found;
                }
            }
            i = 0;
        }
    found:
        ((void (*)(void*, s32, s32))func_800179D0)(self, 3, i);
        return;
    }
    self->on_screen = 0;
}
