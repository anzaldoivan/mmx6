#include "common.h"
#include "mmx6/x4.h"

extern s32 D_800F70B4;
extern s32 D_800F70B8;
extern s32 D_800F70BC;
extern s32 D_800F70C0;
extern u8 D_800F70C4[];
extern s32 D_800F70C8;

void func_800F4FD8(void* arg0) {
    struct X4_MainObj* self = arg0;

    switch (self->animation_step.fields.frame_index) {
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 26:
    case 27:
    case 28:
    case 29:
    case 91:
    case 96:
    case 97:
        self->attack_box = &D_800F70BC;
        self->hurt_box = &D_800F70C0;
        break;
    case 25:
        self->attack_box = D_800F70C4;
        self->hurt_box = &D_800F70C8;
        break;
    default:
        self->attack_box = &D_800F70B4;
        self->hurt_box = &D_800F70B8;
        break;
    }
}
