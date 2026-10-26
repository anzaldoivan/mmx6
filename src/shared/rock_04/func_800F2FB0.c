/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_57_frost_walrus.c:frost_walrus_death_explode, AGPL-3.0; proven shared with X6 by exact signature f2023113f312 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
struct X4_EffectObj* func_8002C3F8(void);

#define M2C_UNK s32
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800F2FB0(struct X4_MainObj* self) {
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
            self->ext.main_57.effect = effect;
        }
    }
    ((void (*)())func_8002CCB0)(BASE_OBJECT(self), 0x60, 0x60);
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
