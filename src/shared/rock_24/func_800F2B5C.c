#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800F77EC;
extern s32 D_800F77F4;
extern void* D_800F7800;
#define D_800F7800 ((struct X4_MainObj*)D_800F7800)

void func_800F2B5C(struct X4_MainObj* arg0) {
    s32 a;
    s32 b;
    struct X4_MainObj* p;

    p = D_800F7800;
    arg0->animation_table = p->animation_table;
    arg0->bg_offset = p->bg_offset;
    arg0->unk16 = 4;
    arg0->air_state = 0;
    arg0->on_screen = 0;
    arg0->terrain_box = 0;
    arg0->attack_box = 0;
    arg0->hurt_box = 0;
    arg0->collision_data = &D_8007433C;
    arg0->unk15 = D_800F7800->unk15;
    arg0->unk40 = 0x140;
    a = func_8002A47C(D_800F7800->id);
    b = func_8002A47C(D_800F7800->id);
    arg0->unk42 = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    arg0->sprite_frames =
        (const u8*)(SPAD20 +
                    *(s32*)(func_8002A47C(D_800F7800->id) * 4 + SPAD20));
    ((void (*)(void*, s32))set_animation)(arg0, 0x1A);
    if (arg0->unk15 == 0) {
        arg0->x_pos.i.hi = D_800F7800->x_pos.i.hi - 0x18;
    } else {
        arg0->x_pos.i.hi = D_800F7800->x_pos.i.hi + 0x18;
    }
    arg0->y_pos.i.hi = D_800F7800->y_pos.i.hi - 0xE;
    arg0->contact_damage = 4;
    arg0->hp = 8;
    arg0->x_speed = 0;
    arg0->y_speed = 0;
    arg0->x_accel = 0;
    arg0->gravity = 0;
    arg0->ext.raw[3] = 0;
    D_800F77EC += 1;
    D_800F77F4 = 1;
    *(s16*)((u8*)arg0 + 0x8A) = 0;
    arg0->unk5 = 0;
    arg0->state++;
}
#undef D_800F7800
