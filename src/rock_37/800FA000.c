// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", D_800FA000);

INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FA004);

INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FA268);

INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FA6A4);
// clang-format on

#define func_800F0794 func_800FA7FC
#include "../shared/rock_08/func_800F0794.c"
#undef func_800F0794

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FAA1C);

INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FAB18);
// clang-format on

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define OB(p, o) (*(s8*)((u8*)(p) + (o)))
#define OUB(p, o) (*(u8*)((u8*)(p) + (o)))
#define OH(p, o) (*(s16*)((u8*)(p) + (o)))
#define OUH(p, o) (*(u16*)((u8*)(p) + (o)))
#define OW(p, o) (*(s32*)((u8*)(p) + (o)))
#define OP(p, o) (*(void**)((u8*)(p) + (o)))
#define SP20 (*(u8**)0x1F800020)
#define SP9C (*(u8**)0x1F80009C)
#define SP9CW (*(s32**)0x1F80009C)

void set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
s32 random_byte();
extern M2C_UNK D_8007433C;
extern M2C_UNK D_80074D3C;
extern M2C_UNK D_80074DDC;
extern struct X4_PlayerObj g_Player;
extern s16 D_800970AA;
extern struct X4_EngineObj g_playthrough_state;
#define g_playthrough_state ((s8*)&g_playthrough_state)
extern s8 D_800CCEDC;
extern M2C_UNK D_800FD9B0;
extern u8 D_800FD9B4[];
extern u8 D_800FD9C8[];
extern M2C_UNK D_800FDBC4;
extern u8 D_800FDC18[][4];
extern u16 D_800FDC8A;

void func_800FAC3C(struct X4_MainObj* self) {
    struct X4_MainObj* parent;
    s32 a;
    s32 b;
    u8* base;
    s32 temp;
    s32 off;

    parent = OP(self, 0x7C);
    self->unk42 &= 0x7FFF;
    self->on_screen = 1;
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    OB(self, 0x96) = 0;
    if (self->unk2 == 0) {
        if (D_800CCF5F < 2) {
            self->x_speed = 0x30000;
            if (parent->unk15 == 0) {
                self->x_speed = -0x30000;
            }
        } else {
            temp = ratan2(g_Player.y_pos.i.hi - self->y_pos.i.hi,
                          g_Player.x_pos.i.hi - self->x_pos.i.hi);
            {
                s32 m;
                s32 t;
                m = rcos(temp);
                t = m << 4;
                self->x_speed = (m << 5) + t;
            }
            {
                s32 m;
                s32 t;
                m = -rsin(temp);
                t = m << 4;
                self->y_speed = (m << 5) + t;
            }
        }
        if (parent->unk15 == 0) {
            self->x_pos.i.hi =
                parent->x_pos.i.hi - (s8)D_800FDC18[self->unk2][0];
        } else {
            self->x_pos.i.hi =
                parent->x_pos.i.hi + (s8)D_800FDC18[self->unk2][0];
        }
        self->collision_data = &D_80075B9C;
        self->unk16 = 0;
        self->y_pos.i.hi += 6;
        set_animation(self, 6);
        self->terrain_box = &D_800FD9B0;
        self->action = 0;
    } else if (self->unk2 < 5) {
        s8* eng = g_playthrough_state;
        self->unk40 = parent->unk40 + 0x100;
        if (eng[0xC] != 0xC) {
            self->unk42 = (((func_8002A47C(parent->id) + 1) * 4 + 0x20) % 16) |
                          (((func_8002A47C(parent->id) + 9) / 4 + 0x1E0) << 6);
            temp = func_8002A47C(parent->id);
            self->sprite_frames = SP20 + ((s32*)SP20)[temp + 1];
        } else {
            self->sprite_frames = SP9C + (SP9CW)[1];
            self->unk42 = 0x794C;
        }
        self->animation_table = (void*)&D_800FDBC4;
        if (self->unk7 == 0) {
            s8* eng2 = g_playthrough_state;
            if ((u8)eng2[0x68] >= 2 && !(random_byte() & 1)) {
                set_animation(self, self->unk2 + 0xA);
                self->collision_data = &D_80074DDC;
                OB(self, 0x96) = 1;
            } else {
                set_animation(self, self->unk2 - 1);
                self->collision_data = &D_80074D3C;
            }
        } else {
            self->collision_data = &D_8007433C;
            self->unk2 = 1;
            set_animation(self, 0xA);
        }
        self->x_pos.i.hi = parent->x_pos.i.hi - (s8)D_800FDC18[self->unk2][0];
        self->y_pos.i.hi = parent->y_pos.i.hi - (s8)D_800FDC18[self->unk2][3];
        self->hp = D_800FDC18[self->unk2][1];
        self->unk16 = 5;
        self->terrain_box = 0;
        self->action = 1;
    } else if (self->unk2 == 5) {
        self->unk40 = parent->unk40 + 0x100;
        if (D_800CCEDC != 0xC) {
            self->unk42 = (((func_8002A47C(parent->id) + 1) * 4 + 0x20) % 16) |
                          (((func_8002A47C(parent->id) + 9) / 4 + 0x1E0) << 6);
            temp = func_8002A47C(parent->id);
            self->sprite_frames = SP20 + ((s32*)SP20)[temp + 1];
        } else {
            self->sprite_frames = SP9C + (SP9CW)[1];
            self->unk42 = 0x794C;
        }
        self->collision_data = &D_80074D3C;
        self->animation_table = (void*)&D_800FDBC4;
        self->unk2 = (random_byte() & 3) + 1;
        if (parent->unk15 != 0) {
            self->x_pos.i.hi =
                parent->x_pos.i.hi + (s8)D_800FDC18[self->unk2][0];
        } else {
            self->x_pos.i.hi =
                parent->x_pos.i.hi - (s8)D_800FDC18[self->unk2][0];
        }
        self->y_pos.i.hi = D_800FDC8A + 0x400;
        self->hp = D_800FDC18[self->unk2][1];
        self->y_speed = -0x30000;
        self->unk16 = 5;
        set_animation(self, self->unk2 - 1);
        self->terrain_box = 0;
        self->action = 6;
    } else if (self->unk2 == 6) {
        self->unk40 = parent->unk40 + 0x100;
        if (D_800CCEDC != 0xC) {
            self->unk42 = (((func_8002A47C(parent->id) + 1) * 4 + 0x20) % 16) |
                          (((func_8002A47C(parent->id) + 9) / 4 + 0x1E0) << 6);
            temp = func_8002A47C(parent->id);
            self->sprite_frames = SP20 + ((s32*)SP20)[temp + 1];
        } else {
            self->sprite_frames = SP9C + (SP9CW)[1];
            self->unk42 = 0x794C;
        }
        self->animation_table = (void*)&D_800FDBC4;
        self->collision_data = &D_8007433C;
        self->unk2 = 2;
        self->x_pos.i.hi = g_Player.x_pos.i.hi;
        self->y_pos.i.hi = D_800FDC8A + 0x440;
        self->hp = D_800FDC18[2][1];
        self->y_speed = -0x30000;
        self->unk16 = 5;
        set_animation(self, 1);
        self->terrain_box = 0;
        self->action = 7;
    }
    OH(self, 0x92) = parent->y_pos.i.hi - (s8)D_800FDC18[self->unk2][3];
    OB(self, 0x94) = 0;
    OB(self, 0x95) = 0;
    self->unk15 = parent->unk15;
    self->contact_damage = D_800FDC18[self->unk2][2];
    self->hurt_box = D_800FD9B4 + self->unk2 * 4;
    self->attack_box = D_800FD9C8 + self->unk2 * 4;
    self->state = 1;
    self->action_phase = 0;
}
#undef g_playthrough_state

#define func_800F12D4 func_800FB33C
#define D_800F6288 D_800FDC18
#include "common.h"
#define M2C_UNK s32

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK animate_object();
s32 random_byte();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern u8 D_800FDC18[][4];
#define D_800FDC18 (*(u8(*)[]) & D_800FDC18)

void func_800FB33C(void* arg0) {
    void* parent;
    s8 t;
    s32 r;

    parent = FLD(arg0, void*, 0x7C);
    FLD(arg0, s32, 0x8C) = check_enemy_hits(arg0);
    if (FLD(arg0, s32, 0x8C) < 0) {
        FLD(arg0, u8, 0x5) = 2;
        FLD(arg0, s16, 0x90) = 0x3C;
        FLD(parent, u8, 0x7) = 1;
        return;
    }
    func_80030ECC(arg0);
    if (FLD(parent, s8, 0x5) != 8) {
        if (FLD(parent, u8, 0x15) != 0) {
            FLD(arg0, s16, 0xA) =
                FLD(parent, s16, 0xA) + (s8)D_800FDC18[FLD(arg0, s8, 0x2) * 4];
        } else {
            FLD(arg0, s16, 0xA) =
                FLD(parent, s16, 0xA) - (s8)D_800FDC18[FLD(arg0, s8, 0x2) * 4];
        }
    }
    if (FLD(parent, s8, 0x5) != 0xA && FLD(parent, s8, 0x4) != 2) {
        {
            u8* p = D_800FDC18;
            p -= -(FLD(arg0, s8, 0x2) * 4);
            FLD(arg0, s16, 0xE) = FLD(parent, s16, 0xE) - (s8)p[3];
        }
    }
    FLD(arg0, u8, 0x15) = FLD(parent, u8, 0x15);
    if (FLD(parent, s8, 0x5) == 3) {
        FLD(arg0, u8, 0x4) = 2;
        return;
    }
    t = FLD(parent, s8, 0x45);
    if (t == 1) {
        animate_object(arg0);
    } else if (t == 2) {
        r = random_byte();
        FLD(arg0, u8, 0x6) = 0;
        FLD(arg0, u8, 0x5) = (u32)r % 3 + 3;
    }
}
#undef D_800FDC18
#undef func_800F12D4
#undef D_800F6288

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FB4D8);

INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FB650);

INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FB790);

INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FB874);

INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FBA24);
// clang-format on

#define func_800F1AEC func_800FBB54
#define D_800F62D0 D_800FDC60
#include "../shared/rock_08/func_800F1AEC.c"
#undef func_800F1AEC
#undef D_800F62D0
