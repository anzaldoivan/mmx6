/* Adapted from sozud/mmx4 @29b62af src/main/effects/effect_27_teleport_intro.c:teleport_intro_spawn_quads, AGPL-3.0; proven shared with X6 by exact signature 6c6bde588dbe (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
struct X4_QuadObj* func_8002C7F0(void);

void func_8005400C(struct X4_EffectObj* self) {
    struct X4_QuadObj* X4_quad;
    u32 var_i;

    switch (self->unk5) {
    case 0:
        X4_quad = func_8002C7F0();
        if (X4_quad != NULL) {
            X4_quad->active = 0x81;
            X4_quad->id = 7;
            X4_quad->unk2 = 0;
            X4_quad->link.owner = self;
        }
        self->unk5 = 1;
        self->ext.effect_27.unk14++;
        return;
    case 1:
        var_i = 0;
        // spawn blue quads behind "READY"
        if (self->ext.effect_27.unk14 == 0) {
            self->ext.effect_27.unk14 = 0;
            do {
                X4_quad = func_8002C7F0();
                if (X4_quad != NULL) {
                    X4_quad->active = 0x81;
                    X4_quad->id = 7;
                    X4_quad->unk2 = 1;
                    X4_quad->unk7 = var_i;
                    X4_quad->link.owner = self;
                    self->ext.effect_27.unk14++;
                }
                var_i += 1;
            } while (var_i < 0xA);
            self->unk5 = 2;
            return;
        }
        return;
    case 2:
        var_i = 0;
        if (self->ext.effect_27.unk14 == 0) {
            self->ext.effect_27.unk14 = 0;
            do {
                X4_quad = func_8002C7F0();
                if (X4_quad != NULL) {
                    X4_quad->active = 0x81;
                    X4_quad->id = 7;
                    X4_quad->unk2 = 2;
                    X4_quad->unk7 = func_8002D2D4() & 3;
                    X4_quad->link.owner = self;
                    self->ext.effect_27.unk14++;
                }
                var_i += 1;
            } while (var_i < 8);
            self->unk5 = 3;
            return;
        }
        break;
    case 3:
        if (self->ext.effect_27.unk14 == 0) {
            self->ext.effect_27.unk14 = 0;
            self->ext.effect_27.unk16 = 1;
        }
        break;
    }
}
