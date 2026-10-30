/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_02_charge_muzzle_flash.c:charge_muzzle_flash_fade, AGPL-3.0; proven shared with X6 by exact signature eb3a6db008dc (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK clear_object_slot(void*, void*);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
void func_80049950(struct X4_VisualObj* arg0) {
    if (arg0->animation_step.fields.relative_step == 0 ||
        arg0->unk5C.value != 0) {
        ((void (*)())clear_object_slot)(arg0);
    } else {
        func_8002CCB0(arg0, 0x40, 0x20);
    }
}
