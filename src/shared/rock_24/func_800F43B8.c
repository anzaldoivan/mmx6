#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD20_800F43B8 (*(s32*)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_80027BA0(s32, s32, s32, void*);
s32 func_8002A47C(s32);
extern u8 D_800F7518[];
extern u16 D_800F7768[];
extern void* D_800F7800;
#define D_800F7800 ((struct X4_MainObj*)D_800F7800)

void func_800F43B8(struct X4_MainObj* arg0) {
    s32 i;

    {
        struct X4_MainObj* p = D_800F7800;
        s32 b;
        arg0->animation_table = p->animation_table;
        b = (u8)p->bg_offset;
        arg0->unk16 = 6;
        arg0->air_state = 0;
        arg0->on_screen = 0;
        arg0->unk15 = 0;
        arg0->bg_offset = b;
    }
    arg0->terrain_box = 0;
    arg0->attack_box = 0;
    arg0->hurt_box = 0;
    arg0->collision_data = 0;
    arg0->unk40 = 0x540;
    arg0->unk42 = (((func_8002A47C(D_800F7800->id) + 1) * 4 + 0x20) % 16) |
                  (((func_8002A47C(D_800F7800->id) + 9) / 4 + 0x1E0) << 6);
    arg0->sprite_frames =
        (const u8*)(SPAD20_800F43B8 +
                    *(s32*)(func_8002A47C(D_800F7800->id) * 4 +
                            SPAD20_800F43B8 + 4));
    func_800179A4(arg0, 0x21);
    i = arg0->unk2 - 0xF;
    arg0->x_pos.u.hi = D_800F7768[i * 2];
    arg0->y_pos.u.hi = D_800F7768[i * 2 + 1];
    func_80027BA0(0, (s16)arg0->x_pos.u.hi - 0x10, (s16)arg0->y_pos.u.hi - 0x18,
                  D_800F7518 + arg0->unk2 * 8);
    {
        register u8 s asm("$3") = arg0->state;
        arg0->x_speed = 0;
        arg0->y_speed = 0;
        arg0->x_accel = 0;
        arg0->gravity = 0;
        arg0->hp = 0;
        arg0->contact_damage = 0;
        arg0->ext.raw[3] = 0;
        arg0->unk5 = 0;
        arg0->state = s + 1;
    }
}

#undef D_800F7800
#undef SPAD20_800F43B8
