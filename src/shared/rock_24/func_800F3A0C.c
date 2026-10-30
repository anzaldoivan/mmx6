#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s32 D_8007573C[];
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern M2C_UNK D_800F76B8;
extern M2C_UNK D_800F76BC;
extern void* D_800F7800;
#define D_800F7800 ((struct X4_MainObj*)D_800F7800)

void func_800F3A0C(struct X4_MainObj* arg0) {
    struct X4_MainObj* p;
    struct X4_MainObj* q;
    u8 bg;
    s32 a;
    s32 b;
    s16 angle;

    p = D_800F7800;
    arg0->animation_table = p->animation_table;
    bg = p->bg_offset;
    {
        s32 k = 3;

        arg0->unk16 = k;
    }
    arg0->air_state = 0;
    arg0->on_screen = 0;
    arg0->attack_box = &D_800F76B8;
    arg0->hurt_box = &D_800F76BC;
    arg0->collision_data = D_8007573C;
    arg0->bg_offset = bg;
    arg0->terrain_box = 0;
    arg0->unk40 = 0x140;
    a = func_8002A47C(D_800F7800->id);
    b = func_8002A47C(D_800F7800->id);
    arg0->unk42 = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    arg0->sprite_frames =
        (const u8*)(SPAD20 +
                    *(s32*)(func_8002A47C(D_800F7800->id) * 4 + SPAD20));
    ((void (*)(void*, s32))set_animation)(arg0, 0xD);
    q = *(struct X4_MainObj**)((u8*)arg0 + 0x7C);
    arg0->x_pos.i.hi = q->x_pos.i.hi;
    arg0->y_pos.i.hi = q->y_pos.i.hi;
    angle = ratan2(g_Player.y_pos.i.hi - arg0->y_pos.i.hi,
                   g_Player.x_pos.i.hi - arg0->x_pos.i.hi);
    arg0->x_speed = rcos(angle) << 6;
    arg0->y_speed = -rsin(angle) << 6;
    if (arg0->x_speed < 0) {
        arg0->unk15 = 0;
    } else {
        arg0->unk15 = 0x40;
    }
    arg0->x_accel = 0;
    arg0->gravity = 0;
    arg0->hp = 1;
    arg0->contact_damage = 4;
    arg0->ext.raw[3] = 0;
    ((void (*)(s32, s32, void*))play_sound)(2, 0x8C, arg0);
    arg0->unk5 = 0;
    {
        // !FAKE: depin: dropping it breaks the match (121/124)
        register s32 t asm("$3") = (u8)arg0->state + 1;

        arg0->state = t;
    }
}
#undef D_800F7800
#undef g_Player
