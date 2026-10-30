#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s32 D_8007573C[];
extern void* D_800F7800;
#define D_800F7800 ((struct X4_MainObj*)D_800F7800)

void func_800F3BFC(struct X4_MainObj* arg0) {
    struct X4_MainObj* p;
    struct X4_MainObj* q;
    u8 bg;
    s32 a;
    s32 b;

    p = D_800F7800;
    arg0->animation_table = p->animation_table;
    bg = p->bg_offset;
    arg0->unk16 = 3;
    arg0->air_state = 0;
    arg0->on_screen = 0;
    arg0->collision_data = D_8007573C;
    arg0->bg_offset = bg;
    arg0->terrain_box = 0;
    arg0->attack_box = 0;
    arg0->hurt_box = 0;
    arg0->unk40 = 0x540;
    a = func_8002A47C(D_800F7800->id);
    b = func_8002A47C(D_800F7800->id);
    arg0->unk42 = (((a + 1) * 4 + 0x20) % 16) | (((b + 9) / 4 + 0x1E0) << 6);
    arg0->sprite_frames =
        (const u8*)(SPAD20 +
                    *(s32*)(func_8002A47C(D_800F7800->id) * 4 + SPAD20 + 4));
    ((void (*)(void*, s32))set_animation)(arg0, 0x1F);
    q = *(struct X4_MainObj**)((u8*)arg0 + 0x7C);
    arg0->unk15 = q->unk15;
    arg0->x_pos.i.hi = q->x_pos.i.hi;
    arg0->y_pos.i.hi = q->y_pos.i.hi - 0xC;
    arg0->hp = 2;
    arg0->x_speed = 0;
    arg0->y_speed = 0;
    arg0->x_accel = 0;
    arg0->gravity = 0;
    arg0->contact_damage = 4;
    arg0->ext.raw[3] = 0;
    arg0->unk5 = 0;
    arg0->state++;
}
#undef D_800F7800
