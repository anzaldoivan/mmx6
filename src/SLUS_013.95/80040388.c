#include "common.h"
#include "mmx6/x4.h"

#define UNK98(self) (((u8*)(self))[0x98])

void func_80040388(struct X4_MainObj* self) {
    u8 step;

    if (self->unk6 == 0) {
        self->unk6++;
        self->x_speed = 0;
        self->x_accel = 0;
        if (self->unk63 == 3) {
            self->invincibility_timer = 0x12;
        } else {
            self->invincibility_timer = 3;
        }
        UNK98(self) = 2;
    }
    step = UNK98(self);
    self->x_pos.i.hi += (s8)step;
    {
        s32 a = (s8)step;
        UNK98(self) = -a;
    }
    if ((s8)(self->invincibility_timer % 9)) {
        self->unk42 &= 0x7FFF;
    } else {
        self->unk42 |= 0x8000;
    }
    if (--self->invincibility_timer == 0) {
        self->unk5 = 1;
        self->unk6 = 0;
        self->unk42 &= 0x7FFF;
    }
}

#include "common.h"

extern s8 D_800CCEDE;

void func_80040488(void) {
    D_800CCEDE = 1;
}

#include "common.h"
#include "mmx6/x4.h"

void func_80017F6C(void);
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800CD40C;

u8 func_80040498(void) {
    if (D_800CD40C == 0) {
        g_playthrough_state.unkE = 0;
        func_80017F6C();
    }
    return g_playthrough_state.unkE;
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_800404D8);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK func_80017A04();
s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
s32 func_8002DCF4(void*, void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
s32 func_80042CE8(void*);
void register_orb(void*);
void func_80049E50(struct X4_MainObj* self);
extern s32 D_80075EE0;
extern void (*D_80076018[])(void*);
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_RideArmorObj D_800CD340;

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_80040800(struct X4_MainObj* self) {
    void* tgt;
    u16* cnt;
    s8 st;

    self->unk18 = self->x_pos;
    self->unk1C = self->y_pos;
    ((void (*)())func_80017A04)();
    if (self->unk5 != 7) {
        func_8002CCB0(self, 0x30, 0x30);
    }
    D_80076018[self->unk5](self);
    if (self->unk5 != 5) {
        if (self->unk5 != 7) {
            if (self->hurt_box != 0 && check_enemy_hits(self) < 0) {
                if (func_80042CE8(self) == 0) {
                    func_80049E50(self);
                    st = 2;
                    goto set;
                }
                func_80049E50(self);
                register_orb(self);
                self->contact_damage = 0;
                F8(self, 0x8E) = 1;
                self->attack_box = 0;
                self->hurt_box = 0;
                self->unk5 = 5;
                self->unk6 = 0;
                self->unk42 &= 0x7FFF;
                return;
            }
            func_80030ECC(self);
        }
    } else {
        tgt = &g_Player;
        if (S8(&g_Player, 0xD5) != 0) {
            tgt = &D_800CD340;
            if (D_800CD340.unk5 == 0) {
                tgt = (u8*)&D_800CD340 + 0xB0;
            }
        }
        if (F8(self, 0x8E) != 0) {
            PTR(self, 0x68) = &D_80075EE0;
        } else {
            PTR(self, 0x68) = 0;
        }
        if (func_8002DCF4(self, tgt) != 0) {
            {
                u8* e = (u8*)&g_playthrough_state;
                s32 i = g_Player.unk2 << 1;
                u16* b = (u16*)(e + 0xD2);
                cnt = (u16*)((u8*)b + i);
            }
            *cnt += U16(self, 0x8A);
            play_sound(0, 0x29, self);
            st = 2;
            PTR(self, 0x68) = 0;
            goto set;
        }
        PTR(self, 0x68) = 0;
    }
    if (func_8002CBFC(self, 0x40, 0x40) == 1) {
        if (F8(self, 0x8D) == 0) {
            st = 3;
        set:
            self->state = st;
        }
    }
}

#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
extern struct X4_PlayerObj g_Player;

void func_80040A04(struct X4_PlayerObj* arg0) {
    s32 ang;

    M2C_FIELD(arg0, s16*, 0x7C) = (random_byte() % 13) + 4;
    {
        s32 px = g_Player.x_pos.i.hi;
        s32 py = g_Player.y_pos.i.hi;
        ang = ratan2(arg0->y_pos.i.hi - py, px - arg0->x_pos.i.hi);
    }
    arg0->unk28 = 0;
    arg0->unk2C = 0;
    arg0->x_vel.val = rcos(ang) * 0x10;
    arg0->y_vel.val = rsin(ang) * 0x10;
    if (arg0->x_vel.val > 0) {
        arg0->unk15 = 0x40;
    } else {
        arg0->unk15 = 0;
    }
    switch (random_byte() % 3) {
    case 0:
        break;
    case 1:
        arg0->x_vel.val = (arg0->x_vel.val * 3) / 2;
        arg0->y_vel.val = (arg0->y_vel.val * 3) / 2;
        break;
    case 2:
        arg0->x_vel.val = arg0->x_vel.val * 2;
        arg0->y_vel.val = arg0->y_vel.val * 2;
        break;
    }
    arg0->unk6++;
}

#undef M2C_FIELD

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_80040B84(void* arg0) {
    s32 angle;
    s32 t;
    s32 u;
    s32 d;

    {
        s32 x = F(s16, 0x84);
        s32 y = F(s16, 0x86);
        angle = ratan2(F(s16, 0xE) - y, x - F(s16, 0xA));
    }
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    {
        s32 m = rcos(angle) * 16;
        F(s32, 0x20) = (m * 2 + m) * 2;
    }
    angle = rsin(angle) * 16;
    F(s32, 0x24) = (angle * 2 + angle) * 2;
    u = F(s32, 0x20);
    if (u > 0) {
        F(u8, 0x15) = 0x40;
    } else {
        F(u8, 0x15) = 0;
    }
    move_object(arg0);
    u = F(s16, 0x84);
    t = F(s16, 0xA);
    d = u - t;
    if (d >= 0) {
        if (d < 7) {
            goto L1;
        }
        return;
    }
    if (t - u < 7) {
    L1:
        u = F(s16, 0x86);
        t = F(s16, 0xE);
        d = u - t;
        if (d >= 0) {
            if (d < 7) {
                goto L2;
            }
            return;
        }
        if (t - u < 7) {
        L2:
            F(s16, 0x7C) = 8;
            F(u8, 0x6)++;
        }
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(void*);
M2C_UNK func_800429D4();
void register_orb(void*);
s32 func_80042E68(void*);

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define PTR(p, o) (*(struct X4_MainObj**)((u8*)(p) + (o)))

void func_80040CB0(struct X4_MainObj* self) {
    struct X4_MainObj* tgt;
    s32 ang;
    s32 d;
    s32 y;
    s32 y2;
    s32 pad[2];

    set_animation(self, 1);
    F8(self, 0x8D) = 0;
    if (func_80042E68(PTR(self, 0x80)) == 0) {
        func_800429D4(self);
        return;
    }
    tgt = PTR(self, 0x80);
    F8(self, 0x8D) = 1;
    y = self->y_pos.i.hi + 0x1C;
    ang = ratan2(y - tgt->y_pos.i.hi, tgt->x_pos.i.hi - self->x_pos.i.hi);
    self->x_accel = 0;
    self->gravity = 0;
    self->x_speed = (rcos(ang) << 4) >> 1;
    self->y_speed = (rsin(ang) << 4) >> 1;
    if (self->x_speed > 0) {
        self->unk15 = 0x40;
    } else {
        self->unk15 = 0;
    }
    move_object(self);
    d = tgt->x_pos.i.hi - self->x_pos.i.hi;
    if (d >= 0 ? d < 2 : self->x_pos.i.hi - tgt->x_pos.i.hi < 2) {
        y2 = self->y_pos.i.hi + 0x1C;
        d = tgt->y_pos.i.hi - y2;
        if (d >= 0 ? d < 2 : y2 - tgt->y_pos.i.hi < 2) {
            set_animation(self, 2);
            register_orb(self);
            tgt->unk7 = 2;
            self->hurt_box = 0;
            self->unk6 = 5;
            self->unk42 &= 0x7FFF;
            return;
        }
    }
    self->unk6++;
}
#undef F8
#undef PTR

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(void*);
M2C_UNK func_800429D4();
void register_orb(void*);
s32 func_80042E68(void*);

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define PTR(p, o) (*(struct X4_MainObj**)((u8*)(p) + (o)))

void func_80040E3C(struct X4_MainObj* self) {
    struct X4_MainObj* tgt;
    s32 ang;
    s32 d;
    s32 y;
    s32 y2;
    s32 pad[2];

    F8(self, 0x8D) = 0;
    if (func_80042E68(PTR(self, 0x80)) == 0) {
        func_800429D4(self);
        return;
    }
    tgt = PTR(self, 0x80);
    F8(self, 0x8D) = 1;
    y = self->y_pos.i.hi + 0x1C;
    ang = ratan2(y - tgt->y_pos.i.hi, tgt->x_pos.i.hi - self->x_pos.i.hi);
    self->x_accel = 0;
    self->gravity = 0;
    self->x_speed = (rcos(ang) << 4) >> 1;
    self->y_speed = (rsin(ang) << 4) >> 1;
    if (self->x_speed > 0) {
        self->unk15 = 0x40;
    } else {
        self->unk15 = 0;
    }
    move_object(self);
    d = tgt->x_pos.i.hi - self->x_pos.i.hi;
    if (d >= 0 ? d < 2 : self->x_pos.i.hi - tgt->x_pos.i.hi < 2) {
        y2 = self->y_pos.i.hi + 0x1C;
        d = tgt->y_pos.i.hi - y2;
        if (d >= 0 ? d < 2 : y2 - tgt->y_pos.i.hi < 2) {
            set_animation(self, 2);
            register_orb(self);
            tgt->unk7 = 2;
            self->hurt_box = 0;
            self->unk42 &= 0x7FFF;
            self->unk6++;
        }
    }
}
#undef F8
#undef PTR

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_80040FB4);
// clang-format on

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
extern u8 D_800760C4[];
extern struct X4_PlayerObj g_Player;

void func_80041290(struct X4_MainObj* self) {
    s32 ang;

    self->contact_damage = 4;
    self->hp = 1;
    self->collision_data = 0;
    self->unk16 = 3;
    self->air_state = 1;
    set_animation(self, 5);
    self->terrain_box = 0;
    self->attack_box = D_800760C4;
    self->hurt_box = 0;
    self->state = 1;
    self->unk5 = 0;
    self->unk6 = 0;
    self->unk7 = 0;
    if (self->unk15 == 0) {
        self->x_pos.i.hi -= 4;
        self->y_pos.i.hi += 0xB;
    } else {
        self->x_pos.i.hi += 4;
        self->y_pos.i.hi += 0xB;
    }
    {
        s32 px = g_Player.x_pos.i.hi;
        s32 py = g_Player.y_pos.i.hi;
        ang = ratan2(self->y_pos.i.hi - py, px - self->x_pos.i.hi);
    }
    self->x_accel = 0;
    self->gravity = 0;
    self->x_speed = (rcos(ang) << 4) * 5;
    self->y_speed = (rsin(ang) << 4) * 5;
    if (func_8002CBFC(self, 0x20, 0x20) == 0) {
        func_8002CCB0(self, 0x10, 0x10);
        return;
    }
    self->state++;
}

#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
extern s16 D_800115B0[16][2];
extern struct X4_BackgroundObj background_objects[3];
#include "mmx6/state.h"

void func_800413D0(void* arg0) {
    s16 tbl[16][2];
    void* parent;
    X4_f32 px;
    X4_f32 py;
    s16 ang;
    s16 ang2;
    s16 bx;
    s16 by;
    s16 h;
    s16 cx;
    s16 cy;
    s32 dx;
    s32 dy;
    s32 n;
    s16 r;
    s16 q;
    s32 t;
    s32 w;
    // !FAKE: depin: dropping it breaks the match (201/232)
    register s32 x asm("$5");
    s32 y;
    s32 k;
    s32 a;
    s32 z;
    u16 bgx;
    u16 bgy;

    __builtin_memcpy(tbl, D_800115B0, sizeof(tbl));
    n = 0;
    M2C_FIELD(arg0, s8*, 3) = 1;
    a = M2C_FIELD(arg0, u16*, 0x46) & 0xFFF;
    ang = a;
    parent = M2C_FIELD(arg0, void**, 0x5C);
    bx = M2C_FIELD(parent, s16*, 0xA) + tbl[(a << 16) >> 24][0];
    by = M2C_FIELD(parent, s16*, 0xE) + tbl[(a << 16) >> 24][1];
    px.i.hi = bx;
    py.i.hi = by;
    dx = rcos(ang) << 8;
    dy = -rsin(ang) << 8;
    do {
        px.val += dx;
        py.val += dy;
        if (px.i.hi < background_objects[0].x_pos.i.hi - 0x10) {
            break;
        }
        if (background_objects[0].x_pos.i.hi + 0x150 < px.i.hi) {
            break;
        }
        if (py.i.hi < background_objects[0].y_pos.i.hi - 0x30) {
            break;
        }
        if (background_objects[0].y_pos.i.hi + 0x100 < py.i.hi) {
            break;
        }
        n++;
    } while (n < 50);
    ang2 = (ang + 0x400) & 0xFFF;
    t = rcos(ang2);
    w = M2C_FIELD(arg0, s16*, 0x4E) + 1;
    r = (t * (s16)(((s16)n >> 1) + w)) >> 12;
    t = rsin(ang2);
    x = px.i.hi;
    z = py.i.hi;
    bgx = background_objects[0].x_pos.i.hi;
    bgy = background_objects[0].y_pos.i.hi;
    bx -= bgx;
    by -= bgy;
    M2C_FIELD(arg0, s16*, 0x16) = bx + (r >> 2);
    M2C_FIELD(arg0, s16*, 0x1E) = bx - (r >> 2);
    cx = x - bgx;
    M2C_FIELD(arg0, s16*, 0x26) = cx - r;
    M2C_FIELD(arg0, s16*, 0x2E) = cx + r;
    M2C_FIELD(arg0, u16*, 0x46) -= M2C_FIELD(arg0, u16*, 0x4A);
    k = M2C_FIELD(arg0, s16*, 0x4E) + 1;
    q = (-t * (s16)(((s16)n >> 1) + k)) >> 12;
    y = q >> 2;
    M2C_FIELD(arg0, s16*, 0x1A) = by + y;
    M2C_FIELD(arg0, s16*, 0x22) = by - y;
    cy = z - bgy;
    M2C_FIELD(arg0, s16*, 0x2A) = cy - q;
    M2C_FIELD(arg0, s16*, 0x32) = cy + q;
    if ((D_80097420.frame_counter + M2C_FIELD(arg0, s8*, 2)) & 1) {
        M2C_FIELD(arg0, s16*, 0x34) = (random_byte() & 1) + 0x1A;
    } else {
        M2C_FIELD(arg0, s16*, 0x34) = 0x1C;
    }
    if (M2C_FIELD(arg0, s16*, 0x46) <= M2C_FIELD(arg0, s16*, 0x48) ||
        M2C_FIELD(arg0, s8*, 7) != M2C_FIELD(parent, s8*, 6)) {
        M2C_FIELD(arg0, s16*, 0x4C) = n * 4;
        M2C_FIELD(arg0, u8*, 5) += 1;
    }
}

#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
extern s16 D_800115B0[16][2];
extern struct X4_BackgroundObj background_objects[3];

void func_80041770(void* arg0) {
    s16 tbl[16][2];
    void* ext;
    void* parent;
    X4_f32 px;
    X4_f32 py;
    s16 ang;
    s16 ang2;
    s16 bx;
    s16 by;
    s16 r;
    s16 q;
    s16 cx;
    s16 cy;
    s16 z;
    s32 dx;
    s32 dy;
    s32 n;
    s32 t;
    s32 w;
    s32 k;
    s32 a;
    u16 bgx;
    u16 bgy;
    s32 y;
    // !FAKE: depin: dropping it breaks the match (200/210)
    register s32 e asm("$4");

    __builtin_memcpy(tbl, D_800115B0, sizeof(tbl));
    M2C_FIELD(arg0, s8*, 3) = 1;
    a = M2C_FIELD(arg0, u16*, 0x46) & 0xFFF;
    ang = a;
    parent = M2C_FIELD(arg0, void**, 0x5C);
    bx = M2C_FIELD(parent, s16*, 0xA) + tbl[(a << 16) >> 24][0];
    by = M2C_FIELD(parent, s16*, 0xE) + tbl[(a << 16) >> 24][1];
    px.i.hi = bx;
    py.i.hi = by;
    ext = (s8*)arg0 + 0x38;
    dx = rcos(ang) << 6;
    dy = -rsin(ang) << 6;
    for (n = 0; n < M2C_FIELD(arg0, s16*, 0x4C); n++) {
        px.val += dx;
        py.val += dy;
    }
    ang2 = (ang + 0x400) & 0xFFF;
    t = rcos(ang2);
    w = M2C_FIELD(arg0, s16*, 0x4E) + 1;
    r = (t * (s16)(((s16)(n >> 2) >> 1) + w)) >> 12;
    t = rsin(ang2);
    z = py.i.hi;
    bgx = background_objects[0].x_pos.i.hi;
    bgy = background_objects[0].y_pos.i.hi;
    bx -= bgx;
    by -= bgy;
    e = bx + (r >> 2);
    M2C_FIELD(arg0, s16*, 0x16) = e;
    M2C_FIELD(arg0, s16*, 0x1E) = bx - (r >> 2);
    cx = px.i.hi - bgx;
    M2C_FIELD(arg0, s16*, 0x26) = cx - r;
    M2C_FIELD(arg0, s16*, 0x2E) = cx + r;
    k = M2C_FIELD(arg0, s16*, 0x4E) + 1;
    q = (-t * (s16)(((s16)(n >> 2) >> 1) + k)) >> 12;
    y = q >> 2;
    M2C_FIELD(arg0, s16*, 0x1A) = by + y;
    M2C_FIELD(arg0, s16*, 0x22) = by - y;
    cy = z - bgy;
    M2C_FIELD(arg0, s16*, 0x2A) = cy - q;
    M2C_FIELD(arg0, s16*, 0x32) = cy + q;
    if ((D_80097420.frame_counter + M2C_FIELD(arg0, s8*, 2)) & 1) {
        M2C_FIELD(arg0, s16*, 0x34) = (random_byte() & 1) + 0x1A;
    } else {
        M2C_FIELD(arg0, s16*, 0x34) = 0x1C;
    }
    M2C_FIELD(arg0, u16*, 0x46) -= M2C_FIELD(arg0, u16*, 0x4A);
    if ((s16)(M2C_FIELD(ext, s16*, 0x14) = M2C_FIELD(arg0, u16*, 0x4C) - 1) ==
        0) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s16*, 0x4C) = n;
        M2C_FIELD(arg0, u8*, 4) += 1;
    }
}

#include "../shared/save_file/func_80041AB8.c"

#define func_80041AB8 func_80041AF4
#define D_80075FD8 D_800760C8
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_80041B30
#define D_80075FD8 D_800760D4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_80041B6C
#define D_80075FD8 D_800760F4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_80041BA8(void) {
    func_8002CA14();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_80041BC8(void) {
    func_8002CA54();
}

#define func_8003744C func_80041BE8
#define D_80073C1C D_80076048
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_80042C18(struct X4_MainObj* self);

void func_80041C24(struct X4_MainObj* self) {
    s32 r;

    func_80042C18(self);
    set_animation(self, 1);
    r = random_byte();
    self->unk6++;
    self->unk7E = r % 7 + 6;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK move_object(void*);
s32 random_byte();
M2C_UNK func_800429D4();
extern u8 D_800CCF38;

void func_80041C9C(struct X4_MainObj* self) {
    s8 v;

    ((void (*)(void*))move_object)(self);
    if (--self->unk7C == 0) {
        if (--self->unk7E == 0) {
            if (D_800CCF38 < 2 || !(random_byte() & 1)) {
                func_800429D4(self);
                return;
            }
            v = 3;
        } else {
            v = 1;
        }
        self->unk6 = v;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80041D38(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);
s32 random_byte();
void func_80042A9C(struct X4_MainObj* self, s32);
void func_80042C18(struct X4_MainObj* self);
extern struct X4_PlayerObj g_Player;

void func_80041D5C(struct X4_MainObj* self) {
    s16 ang;
    s32 t;

    self->on_screen = 0;
    if (--self->unk7C == 0) {
        if (func_8002CBFC(self, 0x40, 0x40) == 1) {
            self->state = 3;
            return;
        }
        func_80042C18(self);
        ang = random_byte() * 0x10;
        {
            struct X4_PlayerObj* p = &g_Player;
            M2C_FIELD(self, u16*, 0x84) = p->x_pos.i.hi;
            M2C_FIELD(self, u16*, 0x86) = p->y_pos.i.hi;
        }
        self->x_pos.i.hi = M2C_FIELD(self, u16*, 0x84) + (rcos(ang) >> 6);
        t = rsin(ang) >> 6;
        self->unk7 = 0;
        self->y_pos.i.hi = M2C_FIELD(self, u16*, 0x86) + t;
        func_80042A9C(self, 0);
        func_80042A9C(self, 1);
        self->unk6++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
extern s32 D_80075EDC;
extern s32 D_80075EE4;

void func_80041E4C(void* self) {
    M2C_FIELD(self, u8*, 0x3) = 0;
    if (M2C_FIELD(self, s8*, 0x7) == 0) {
        set_animation(self, 1);
        M2C_FIELD(self, void**, 0x54) = &D_80075EE4;
        M2C_FIELD(self, void**, 0x50) = &D_80075EDC;
        func_8002CCB0(self, 0x30, 0x30);
        M2C_FIELD(self, u8*, 0x6) += 1;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);

void func_80041EBC(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        move_object(arg0);
        return;
    }
    M2C_FIELD(arg0, u8*, 0x6) += 1;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_800429D4(); /* extern */

void func_80041F10(void) {
    func_800429D4();
}

#define func_8003744C func_80041F30
#define D_80073C1C D_80076038
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/animation/func_80041F6C.c"

#include "../shared/SLUS_013.95/func_80041FB0.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80041FE4(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_800429D4(); /* extern */

void func_8004200C(void) {
    func_800429D4();
}

#include "common.h"
#include "mmx6/x4.h"

extern void (*D_8007606C[])(struct X4_ObjectHeader*);
extern struct X4_BackgroundObj background_objects[3];

void func_8004202C(struct X4_ObjectHeader* self) {
    if (self->x_pos.i.hi < background_objects[0].x_pos.i.hi + 0x10 ||
        background_objects[0].x_pos.i.hi + 0x130 < self->x_pos.i.hi ||
        self->y_pos.i.hi < background_objects[0].y_pos.i.hi + 0x10 ||
        background_objects[0].y_pos.i.hi + 0xE0 < self->y_pos.i.hi) {
        self->unk5 = 2;
        self->unk6 = 0;
        return;
    }
    D_8007606C[self->unk6](self);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_80042C18(struct X4_MainObj* self);
extern u8 D_800CCF38;

void func_800420CC(struct X4_MainObj* self) {
    s32 d;
    s32 var_v0;
    // !FAKE: retail keeps the second stored value in the second return register
    register s32 var_v1 asm("$3");

    func_80042C18(self);
    ((void (*)(void*, M2C_UNK))set_animation)(self, 4);
    d = D_800CCF38;
    {
        s32 one = 1;
        if (d != one) {
            if (d < 2) {
                var_v0 = 0x1E;
                var_v1 = 5;
                if (d == 0) {
                    var_v0 = 0x5A;
                    var_v1 = 3;
                }
            } else {
                // !FAKE: places the two-or-more arm after the equals-one arm
                goto block_a3;
            }
        } else {
            var_v0 = 0x3C;
            var_v1 = 4;
        }
    }
    if (0) {
    block_a3:
        var_v0 = 0x1E;
        var_v1 = 5;
    }
    self->unk7C = var_v0;
    self->unk7E = var_v1;
    do {
    } while (0);
    self->unk6++;
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_80042B68(void* arg0, u8 arg1);
void func_80042C18(struct X4_MainObj* self);
extern u8 D_800CCF38;

void func_80042150(struct X4_MainObj* self) {
    s16 v;

    if (--self->unk7C == 0) {
        func_80042C18(self);
        play_sound(2, 0x42, self);
        func_80042B68(self, 0);
        if (--self->unk7E == 0) {
            self->unk7C = 0x28;
            self->unk6++;
            return;
        }
        switch (D_800CCF38) {
        case 0:
            v = 0x5A;
            break;
        case 1:
            v = 0x3C;
            break;
        case 2:
        default:
            v = 0x1E;
            break;
        }
        self->unk7C = v;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_800429D4();

void func_80042214(void* arg0) {
    if (--*(s16*)((u8*)arg0 + 0x7C) == 0) {
        func_800429D4();
    }
}

#define func_8003744C func_80042250
#define D_80073C1C D_80076078
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C
