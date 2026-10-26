#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define OB(p, o) (*(s8*)((u8*)(p) + (o)))
#define OUB(p, o) (*(u8*)((u8*)(p) + (o)))
#define OH(p, o) (*(s16*)((u8*)(p) + (o)))
#define OUH(p, o) (*(u16*)((u8*)(p) + (o)))
#define OW(p, o) (*(s32*)((u8*)(p) + (o)))
#define OP(p, o) (*(void**)((u8*)(p) + (o)))
#define SP20 (*(u8**)0x1F800020)
#define SP9C (*(u8**)0x1F80009C)
#define SP9CW (*(s32**)0x1F80009C)

void func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
s32 func_8002D2D4();
extern M2C_UNK D_8007433C;
extern M2C_UNK D_80074D3C;
extern M2C_UNK D_80074DDC;
extern M2C_UNK D_80075B9C;
extern struct X4_PlayerObj g_Player;
extern s16 D_800970AA;
extern struct X4_EngineObj D_800CCED0;
#define D_800CCED0 ((s8*)&D_800CCED0)
extern s8 D_800CCEDC;
extern u8 D_800CCF5F;
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
        func_800179A4(self, 6);
        self->terrain_box = &D_800FD9B0;
        self->unk5 = 0;
    } else if (self->unk2 < 5) {
        s8* eng = D_800CCED0;
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
            s8* eng2 = D_800CCED0;
            if ((u8)eng2[0x68] >= 2 && !(func_8002D2D4() & 1)) {
                func_800179A4(self, self->unk2 + 0xA);
                self->collision_data = &D_80074DDC;
                OB(self, 0x96) = 1;
            } else {
                func_800179A4(self, self->unk2 - 1);
                self->collision_data = &D_80074D3C;
            }
        } else {
            self->collision_data = &D_8007433C;
            self->unk2 = 1;
            func_800179A4(self, 0xA);
        }
        self->x_pos.i.hi = parent->x_pos.i.hi - (s8)D_800FDC18[self->unk2][0];
        self->y_pos.i.hi = parent->y_pos.i.hi - (s8)D_800FDC18[self->unk2][3];
        self->hp = D_800FDC18[self->unk2][1];
        self->unk16 = 5;
        self->terrain_box = 0;
        self->unk5 = 1;
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
        self->unk2 = (func_8002D2D4() & 3) + 1;
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
        func_800179A4(self, self->unk2 - 1);
        self->terrain_box = 0;
        self->unk5 = 6;
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
        func_800179A4(self, 1);
        self->terrain_box = 0;
        self->unk5 = 7;
    }
    OH(self, 0x92) = parent->y_pos.i.hi - (s8)D_800FDC18[self->unk2][3];
    OB(self, 0x94) = 0;
    OB(self, 0x95) = 0;
    self->unk15 = parent->unk15;
    self->contact_damage = D_800FDC18[self->unk2][2];
    self->hurt_box = D_800FD9B4 + self->unk2 * 4;
    self->attack_box = D_800FD9C8 + self->unk2 * 4;
    self->state = 1;
    self->unk6 = 0;
}
#undef D_800CCED0
