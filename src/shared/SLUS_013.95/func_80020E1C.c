#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
extern M2C_UNK g_Player;
extern void (*D_80071388[])(struct X4_UnkObj*, struct X4_PlayerObj*);

void func_80020E1C(struct X4_UnkObj* arg0) {
    struct X4_PlayerObj* p = &g_Player;

    arg0->animation_step.fields.frame_index =
        p->animation_step.fields.frame_index;
    arg0->unk15 = p->unk15;
    arg0->unk38 = p->unk38;
    arg0->unk3C = p->unk3C;
    arg0->unk18 = arg0->x_pos;
    arg0->unk1C = arg0->y_pos;
    if (arg0->state == 0) {
        if (p->afterimage != 0) {
            if (p->afterimage > 0) {
                arg0->on_screen = 1;
                arg0->ext.afterimage.position_timer = 3;
                arg0->ext.afterimage.blink_timer = 8;
                arg0->ext.afterimage.palette_offset = (5 - arg0->unk2) * 2;
                arg0->x_pos = p->x_pos;
                arg0->y_pos = p->y_pos;
                arg0->state = 1;
                arg0->unk5 = 0;
                return;
            }
            p->afterimage = 0;
        }
    } else {
        if (p->afterimage == 0) {
            arg0->on_screen = 0;
            arg0->state = 0;
            return;
        }
        D_80071388[arg0->unk5](arg0, p);
    }
}
