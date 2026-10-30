/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_22_missile_smoke.c:missile_smoke_main, AGPL-3.0; proven shared with X6 by exact signature c82f771f5c19 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
M2C_UNK set_animation(void* arg0, M2C_UNK arg1);

M2C_UNK func_80017A04();
M2C_UNK clear_object_slot(void*, void*);
s32 func_8002CB50(struct X4_BaseObj*);
void func_8004B50C(struct X4_VisualObj* arg0) {
    struct X4_PlayerObj* temp_a0;

    if (arg0->unk2 != 0x10) {
        if (arg0->unk2 <= 6) {
            if (arg0->unk2 == 0) {
                set_animation(arg0, 0x21);
            } else {
                set_animation(arg0, ((arg0->unk2 - 1) >> 1) + 0x21);
            }
            arg0->unk2++;
            ((void (*)())func_8002CB50)(arg0);
        } else {
            arg0->on_screen = 0;
            arg0->state = 2;
        }
    } else {
        temp_a0 = arg0->unk50;
        if (((u8)temp_a0->shot_types[0] == 2) && (temp_a0->active != 0) &&
            (temp_a0->last_shot_type & 0x40)) {
            arg0->unk15 = temp_a0->unk15;
            arg0->x_pos.i.hi = temp_a0->x_pos.i.hi;
            arg0->y_pos.i.hi = temp_a0->y_pos.i.hi;
            ((void (*)())func_80017A04)(arg0);
            ((void (*)())func_8002CB50)(arg0);
            return;
        }
        arg0->on_screen = 0;
        ((void (*)())clear_object_slot)(arg0);
    }
}
