/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_13_ride_chaser_jet.c:ride_chaser_jet_main, AGPL-3.0; proven shared with X6 by exact signature ca898a8565aa (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern u8 D_800F4C24[16];
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
void func_800179D0(struct X4_AnimatedObj*, s32, s32);
M2C_UNK func_80017A04();

void func_800E99EC(struct X4_VisualObj* arg0) {
    struct X4_PlayerObj* player;
    u8 animation;
    s16 previous_frame;
    u8 frame;
    u8 next_animation;

    player = arg0->unk50;
    if (player->state != 2) {
        frame = player->animation_step.fields.frame_index;
        previous_frame = arg0->unk56;
        next_animation = D_800F4C24[frame];
        if (frame != previous_frame &&
            (animation = next_animation & 0xFF) != arg0->unk54) {
            func_800179D0(ANIMATED_OBJECT(arg0), animation,
                          arg0->animation_step.fields.event);
            frame = player->animation_step.fields.frame_index;
            arg0->unk56 = frame;
            arg0->unk54 = next_animation;
        }
        arg0->x_pos.i.hi = player->x_pos.i.hi;
        arg0->y_pos.i.hi = player->y_pos.i.hi;
        func_80017A04(ANIMATED_OBJECT(arg0));
        func_8002CCB0(BASE_OBJECT(arg0), 0x10, 0x10);
        return;
    }
    arg0->state = 2;
}
