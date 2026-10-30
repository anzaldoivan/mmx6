#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_80027BA0(s32, s32, s32, void*);
s32 func_8002A47C(s32);
M2C_UNK clear_object_slot();
s32 random_byte();
extern s32 D_8007465C;
extern u32* D_80095098;
extern u8 D_800970B4;
extern s8 D_80097244;
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800EFBA0;
extern s32 D_800EFBA8;
extern s32 D_800EFBB0;
extern s32 D_800EFBF0;
extern s32 D_800EFC04[];
extern s32 D_800EFC14;

void func_800ED41C(struct X4_MainObj* self) {
    struct X4_EngineObj* e = &g_playthrough_state;
    s32* p;
    s32 i;
    s8 t;
    s32 r;
    s32 v;

    if (M2C_FIELD(e, s8*, 0x43A) != 3) {
        clear_object_slot();
        return;
    }
    self->hp = 8;
    self->contact_damage = 4;
    self->collision_data = &D_8007465C;
    self->invincibility_timer = 0;
    self->active = 0x41;
    self->unk18.val = self->x_pos.val;
    self->unk1C.val = self->y_pos.val;
    self->unk40 = D_80095098[func_8002A47C(self->id)] >> 7;
    self->unk42 = ((func_8002A47C(self->id) * 4 + 0x20) % 16) |
                  (((func_8002A47C(self->id) + 8) / 4 + 0x1E0) << 6);
    i = func_8002A47C(self->id);
    p = SPAD20;
    v = p[i];
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->air_state = 0;
    self->collision_flags = 0;
    self->sprite_frames = (const u8*)p + v;
    self->bg_offset = D_800970B4;
    self->unk15 = 0;
    self->animation_table = (const u8* const*)&D_800EFBF0;
    self->unk16 = 5;
    self->unk7C = 0;
    self->unk7E = 0;
    self->terrain_box = (struct X4_Unk_unk68*)&D_800EFBA0;
    self->hurt_box = &D_800EFBB0;
    self->attack_box = &D_800EFBA8;
    self->ext.main_0.background_relative = 2;
    self->ext.main_0.flags[0] = 0;
    r = random_byte();
    t = self->unk2;
    self->ext.main_0.index = (r % 3) * 10 + 0x14;
    if (t == 0) {
        self->on_screen = 1;
        self->x_speed = 0;
        self->y_speed = -0x30000;
        ((void (*)(void*, s32))set_animation)(self, 0);
        self->unk5 = 1;
        self->terrain_box = NULL;
        play_sound(2, 0x50, self);
    } else if (t == 1) {
        if (e->stage == 2) {
            func_80027BA0(0, 0x1390, 0x210, D_800EFC04);
            func_80027BA0(0, 0x1390, 0x2E0, D_800EFC04 + 2);
            D_80097244 = t;
        } else if (*(u16*)&e->stage == 0x113) {
            func_80027BA0(0, 0x840, 0x430, &D_800EFC14);
            D_80097244 = t;
        }
        self->unk5 = 2;
    }
    self->state = 1;
    self->unk6 = 0;
}
