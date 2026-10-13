#include "common.h"
#include "mmx6/x4.h"

extern s32 D_800F70CC;
extern s32 D_800F70D0;
extern s32 D_800F70D4;
extern s32 D_800F70D8;

void func_800F326C(void* arg0) {
    struct X4_MainObj* self = arg0;

    if (self->animation_step.fields.event == 1) {
        self->unk7C = 300;
        switch (self->unk2) {
        case 16:
        case 18:
            self->hurt_box = &D_800F70CC;
            self->attack_box = &D_800F70D0;
            break;
        case 17:
            self->hurt_box = &D_800F70D4;
            self->attack_box = &D_800F70D8;
            break;
        }
        self->unk5++;
    }
}
