#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK D_80074BFC;
extern u8 D_800970B4;
extern struct X4_MainObj* D_800F7DEC;
extern u16* D_800F7DF0;
extern s16 D_800F7E10;
extern s16 D_800F7E20[];

void func_800F1A3C(struct X4_MainObj* arg0) {
    struct X4_MainObj* src;
    s16* p;
    s32 i;
    u8 t;
    u8 st;

    src = D_800F7DEC;
    arg0->unk40 = src->unk40;
    arg0->animation_table = src->animation_table;
    arg0->sprite_frames = src->sprite_frames;
    i = 0;
    arg0->unk42 = src->unk42 & 0x7FFF;
    t = D_800970B4;
    arg0->unk16 = 4;
    arg0->air_state = 0;
    arg0->on_screen = 0;
    arg0->terrain_box = 0;
    arg0->attack_box = 0;
    arg0->hurt_box = 0;
    arg0->collision_data = &D_80074BFC;
    arg0->unk62 = 0;
    arg0->invincibility_timer = 0;
    arg0->bg_offset = t;
    do {
        goto test;
    inc:
        i++;
    test:
        if (i < *(s16*)D_800F7DF0) {
            {
                s16* b = D_800F7E20;
                p = b + i;
            }
            if (*p != 0) {
                goto inc;
            }
            *p = 1;
            arg0->ext.main_33.unk88 = i;
        }
    } while (0);
    D_800F7E10++;
    do {
        st = arg0->state;
    } while (0);
    arg0->hp = 8;
    arg0->x_speed = 0;
    arg0->y_speed = 0;
    arg0->x_accel = 0;
    arg0->gravity = 0;
    arg0->contact_damage = 2;
    arg0->ext.main_33.unk84 = 0;
    arg0->unk7E = 0;
    arg0->unk6 = 0;
    do {
        arg0->state = st + 1;
    } while (0);
}
