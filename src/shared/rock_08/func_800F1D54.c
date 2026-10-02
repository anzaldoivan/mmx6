/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_54_slash_beast.c:slash_beast_death_blink, AGPL-3.0; proven shared with X6 by exact signature df30c9a4d6e8 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
struct X4_EffectObj* func_8002C3F8(void);
void func_8002CCB0(struct X4_BaseObj*, s32, s32);

void func_800F1D54(struct X4_MainObj* self) {
    struct X4_EffectObj* effect;

    self->unk7C--;
    if (self->unk7C == 0) {
        self->unk5 = 2;
        effect = func_8002C3F8();
        if (effect != NULL) {
            effect->active = 1;
            effect->id = 0x1A;
            effect->x_pos.i.hi = self->x_pos.u.hi;
            effect->y_pos.i.hi = self->y_pos.u.hi;
            self->ext.main_54.effect = effect;
        }
    }
    func_8002CCB0(BASE_OBJECT(self), 0x60, 0x60);
    if (self->unk7E-- == 0) {
        self->unk42 ^= 0x8000;
        self->invincibility_timer -= 5;
        if (self->invincibility_timer > 0x19) {
            self->invincibility_timer = 0;
        }
        self->unk7E =
            self->invincibility_timer > 5 ? self->invincibility_timer : 5;
    }
}
