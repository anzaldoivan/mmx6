#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD20_800F4790 (*(s32*)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s16 D_800F7780[];
extern void* D_800F7800;
#define D_800F7800 ((struct X4_MainObj*)D_800F7800)

void func_800F4790(struct X4_MainObj* arg0) {
    u16 y;
    s32 xv;
    u8 s;

    arg0->animation_table = D_800F7800->animation_table;
    arg0->bg_offset = D_800F7800->bg_offset;
    arg0->unk16 = 2;
    arg0->air_state = 0;
    arg0->on_screen = 0;
    arg0->terrain_box = 0;
    arg0->attack_box = 0;
    arg0->hurt_box = 0;
    arg0->collision_data = 0;
    if (D_800F7780[arg0->unk2 - 0x1E] < 0x1F) {
        arg0->unk40 = 0x140;
        arg0->unk42 = ((func_8002A47C(D_800F7800->id) * 4 + 0x20) % 16) |
                      (((func_8002A47C(D_800F7800->id) + 8) / 4 + 0x1E0) << 6);
        arg0->sprite_frames =
            (const u8*)(SPAD20_800F4790 +
                        *(s32*)(func_8002A47C(D_800F7800->id) * 4 +
                                SPAD20_800F4790));
    } else {
        arg0->unk40 = 0x540;
        arg0->unk42 = (((func_8002A47C(D_800F7800->id) + 1) * 4 + 0x20) % 16) |
                      (((func_8002A47C(D_800F7800->id) + 9) / 4 + 0x1E0) << 6);
        arg0->sprite_frames =
            (const u8*)(SPAD20_800F4790 +
                        *(s32*)(func_8002A47C(D_800F7800->id) * 4 +
                                SPAD20_800F4790 + 4));
    }
    func_800179A4(arg0, D_800F7780[arg0->unk2 - 0x1E]);
    do {
        // !FAKE: depin: dropping it breaks the match (144/152)
        register u8 c asm("$2") = D_800F7800->unk15;
        arg0->unk15 = c;
        xv = D_800F7800->x_pos.u.hi;
    } while (0);
    *(u16*)((u8*)arg0 + 0xA) = xv;
    s = arg0->state;
    y = D_800F7800->y_pos.u.hi;
    arg0->x_speed = 0;
    arg0->y_speed = 0;
    arg0->x_accel = 0;
    arg0->gravity = 0;
    arg0->hp = 0;
    arg0->contact_damage = 0;
    arg0->ext.raw[3] = 0;
    arg0->state = s + 1;
    arg0->unk5 = 0;
    arg0->y_pos.u.hi = y;
}

#undef D_800F7800
#undef SPAD20_800F4790
