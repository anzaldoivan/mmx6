#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
void* alloc_sprite_slot();
extern s32 D_8007447C;
extern u8 D_800970B4;
extern s32 D_800FAB7C;
extern s32 D_800FAB80;
extern s32 D_800FAB84;
extern s32 D_800FACD4;

void func_800EB450(struct X4_MainObj* arg0) {
    struct X4_MainObj* child;
    u8 v;

    arg0->unk7C = 0;
    arg0->hp = 0x20;
    arg0->invincibility_timer = 0;
    v = D_800970B4;
    arg0->animation_table = (void*)&D_800FACD4;
    arg0->unk16 = 6;
    arg0->terrain_box = (void*)&D_800FAB7C;
    arg0->bg_offset = v;
    arg0->hurt_box = &D_800FAB84;
    arg0->attack_box = &D_800FAB80;
    arg0->air_state = 0;
    arg0->collision_data = &D_8007447C;
    arg0->contact_damage = 4;
    arg0->unk5 = 2;
    arg0->unk15 = 0;
    arg0->x_speed = 0;
    arg0->x_accel = -0xC00;
    arg0->unk18.val = arg0->x_pos.val;
    arg0->y_speed = 0;
    arg0->gravity = 0x2000;
    arg0->state = 1;
    arg0->unk6 = 0;
    arg0->unk1C.val = arg0->y_pos.val;
    if (arg0->unk2 == 0) {
        arg0->unk7 = 0;
        ((void (*)(void*, s32, s32))set_animation)(arg0, 2, v);
    } else {
        arg0->unk7 = 0x40;
        ((void (*)(void*, s32, s32))set_animation)(arg0, 0, v);
    }
    arg0->ext.raw[0] = arg0->animation_step.fields.frame_index;
    child = alloc_sprite_slot();
    if (child != 0) {
        child->active = 0x41;
        child->id = 2;
        child->unk2 = arg0->animation_step.fields.frame_index;
        child->unk40 = arg0->unk40;
        child->unk42 = arg0->unk42 & 0x7FFF;
        child->animation_table = arg0->animation_table;
        child->sprite_frames = arg0->sprite_frames;
        child->bg_offset = arg0->bg_offset;
        child->x_pos.val = arg0->x_pos.val;
        child->y_pos.u.hi = arg0->y_pos.u.hi;
        child->unk15 = arg0->unk15;
        child->attack_box = arg0;
    }
}
