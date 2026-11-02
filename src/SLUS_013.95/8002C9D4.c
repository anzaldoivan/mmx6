// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_8002C9D4);

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_8002CA14);
// clang-format on

#include "common.h"
#define M2C_UNK s32

#define CA54_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void clear_object_slot(void* arg0);

M2C_UNK func_8002CA54(void* arg0) {
    u8* p;
    u8* q;
    u8 v;

    p = CA54_FIELD(arg0, u8**, 0x10);
    if (p != 0) {
        p[0] &= 0x70;
        q = CA54_FIELD(arg0, u8**, 0x10);
        v = q[3];
        if ((v & 0xF0) == 0x10) {
            q[3] = v & 0xF;
        }
    }
    clear_object_slot(arg0);
}

#undef CA54_FIELD

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

s32 func_8002CAB4(struct X4_BaseObj* arg0) {
    s32 x;
    s16 dy;
    s32 ret;
    s8 idx;

    idx = arg0->bg_offset;
    if (idx < 0) {
        x = arg0->x_pos.i.hi;
        dy = arg0->y_pos.i.hi;
    } else {
        x = (s16)(arg0->x_pos.i.hi - background_objects[idx].x_pos.i.hi);
        dy = arg0->y_pos.i.hi - background_objects[idx].y_pos.i.hi;
    }
    x += 0x40;
    if ((u16)x < 0x1C0) {
        ret = 0;
        if ((u16)(dy + 0x40) < 0x170) {
            return ret;
        }
    }
    return 1;
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern u16 g_screen_width;

s32 func_8002CB50(struct X4_BaseObj* arg0) {
    s16 dx;
    s16 dy;
    s8 idx;

    idx = arg0->bg_offset;
    arg0->on_screen = 0;
    if (idx < 0) {
        dx = arg0->x_pos.i.hi;
        dy = arg0->y_pos.i.hi;
    } else {
        dx = arg0->x_pos.i.hi - background_objects[idx].x_pos.i.hi;
        dy = arg0->y_pos.i.hi - background_objects[idx].y_pos.i.hi;
    }
    if ((u16)(dx + 0x20) < (u16)(g_screen_width + 0x40) &&
        (u16)(dy + 0x20) < 0x130) {
        arg0->on_screen = 1;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2) {
    s8 bg;
    s16 x;
    s16 y;

    bg = arg0->bg_offset;
    if (bg < 0) {
        x = arg0->x_pos.i.hi;
        y = arg0->y_pos.i.hi;
    } else {
        x = arg0->x_pos.i.hi - background_objects[bg].x_pos.i.hi;
        y = arg0->y_pos.i.hi - background_objects[bg].y_pos.i.hi;
    }
    if ((u16)(x + arg1) < (u16)(arg1 * 2 + 0x140) &&
        (u16)(y + arg2) < (u16)(arg2 * 2 + 0xF0)) {
        return 0;
    }
    return 1;
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern u16 g_screen_width;

void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2) {
    s16 dx;
    s16 dy;
    s8 idx;

    idx = arg0->bg_offset;
    arg0->on_screen = 0;
    if (idx < 0) {
        dx = arg0->x_pos.i.hi;
        dy = arg0->y_pos.i.hi;
    } else {
        dx = arg0->x_pos.i.hi - background_objects[idx].x_pos.i.hi;
        dy = arg0->y_pos.i.hi - background_objects[idx].y_pos.i.hi;
    }
    if ((u16)(dx + arg1) < (u16)(g_screen_width + arg1 + arg1) &&
        (u16)(dy + arg2) < (u16)(arg2 + 0xF0 + arg2)) {
        arg0->on_screen = 1;
    }
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_8002CD6C);
// clang-format on

/* Adapted from sozud/mmx4 @807a01b src/main/objects.c:func_8002B468, AGPL-3.0; proven shared with X6 by exact signature 824e92a3c988 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_EffectObj D_8009B7B0[0x20];

struct X4_EffectObj* func_8002CE18(s8 id, s8 arg1) {
    struct X4_EffectObj* effect;
    s8 i;

    i = 0;
    if (id >= 0) {
        do {
            effect = &D_8009B7B0[i];
            if (effect->active != 0 && effect->id == id &&
                effect->unk2 == arg1) {
                return effect;
            }
            i++;
        } while (i < 0x20);
    } else {
        id &= 0x7F;
        do {
            effect = &D_8009B7B0[i];
            if (effect->active != 0 && effect->id == id) {
                return effect;
            }
            i++;
        } while (i < 0x20);
    }
}

#include "common.h"

extern u8 D_800CCF36;

s32 func_8002CEF0(void) {
    return ((u8)D_800CCF36 >= 3U) * 2;
}

#include "common.h"

extern s8 g_enemies[];
extern s32 D_800C1220[];

void func_8002CF0C(s8* arg0) {
    s32 i;
    s32 j;
    s8* p;
    s32 idx;
    s32 mask;
    s32 off;
    s32 w;

    p = arg0;
    for (j = 0x9B; j != -1; j--) {
        *p++ = 0;
    }
    *(s32*)(arg0 + 0x50) = 0;
    *(s32*)(arg0 + 0x54) = 0;
    *(s32*)(arg0 + 0x68) = 0;
    idx = (u32)(arg0 - g_enemies) / 156;
    w = idx / 32;
    mask = ~(1 << (idx & 0x1F));
    for (i = 0; i < 80; i++) {
        off = i * 0xA4 + 0x98;
        *(s32*)((u8*)D_800C1220 + off + w * 4) &= mask;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
extern M2C_UNK g_Player;
#define PL_150 (*(s8*)(pl + 0x150))
#define PL_FC (*(s32*)(pl + 0xFC))

s32 func_8002CFB0(void* arg) {
    struct X4_PlayerObj* arg0 = arg;
    s32 vx;
    s32 vy;
    u8* pl = (u8*)&g_Player;

    if ((PL_150 != 0) && (arg0->unk15 != 0)) {
        vx = arg0->x_vel.val;
        vy = arg0->y_vel.val;
        arg0->y_pos.val = arg0->y_pos.val - vy;
        arg0->x_vel.val = vx + arg0->unk28;
        arg0->y_vel.val = vy - arg0->unk2C;
        arg0->x_pos.val = arg0->x_pos.val + ((vx * 0x56) / 100);
        vy = arg0->y_vel.val;
        if (vy < PL_FC) {
            arg0->y_vel.val = PL_FC;
        }
    } else {
        arg0->x_pos.val = arg0->x_pos.val + arg0->x_vel.val;
        arg0->y_pos.val = arg0->y_pos.val - arg0->y_vel.val;
        if (arg0->unk15 != 0) {
            arg0->x_vel.val = arg0->x_vel.val + arg0->unk28;
        } else {
            arg0->x_vel.val = arg0->x_vel.val - arg0->unk28;
        }
        arg0->y_vel.val = arg0->y_vel.val - arg0->unk2C;
        {
            u8* pl = (u8*)&g_Player;
            if (arg0->y_vel.val < PL_FC) {
                arg0->y_vel.val = PL_FC;
            }
        }
    }
}

#include "common.h"

extern u32 D_800737A8[];

s32 func_8002D0D8(s32 x, s32 y) {
    s32 sx;
    s32 sy;
    s32 q;
    // !FAKE: depin: dropping it breaks the match (2/86)
    register s32 v asm("$2");
    // !FAKE: depin: dropping it breaks the match (56/86)
    register s32 t asm("$3");
    s16 a;
    u32* p;

    v = y;
    if (x < 0) {
        sx = 1;
        x = -x;
    } else {
        sx = -1;
    }
    sy = 1;
    if (y < 0) {
        sy = -1;
        v = -y;
    }
    t = v >> 16;
    if (t != 0) {
        q = x / t;
        if (q <= 0xFFFF) {
            p = &D_800737A8[4];
            while (q < *p) {
                p--;
            }
            a = p - D_800737A8;
        } else {
            p = &D_800737A8[5];
            while (*p < q) {
                p++;
            }
            a = (p - D_800737A8) - 1;
        }
    } else {
        a = 8;
    }
    if (sy < 0) {
        if (sx > 0) {
            if (a == 8) {
                return 0;
            }
            return (u8)(a + 0x18);
        }
        return (u8)(0x18 - a);
    } else if (sx > 0) {
        return (u8)(8 - a);
    } else {
        return (u8)(a + 8);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern s32 D_8009719C;

M2C_UNK func_8002D230(struct X4_MainObj* self) {
    s32 vy;
    s32* vyp;

    self->x_pos.val += self->x_speed;
    self->y_pos.val -= self->y_speed;
    if (self->unk15 != 0) {
        self->x_speed = self->x_speed + self->x_accel;
    } else {
        self->x_speed = self->x_speed - self->x_accel;
    }
    vyp = &self->y_speed;
    vy = *vyp - self->gravity;
    *vyp = vy;
    if (vy < D_8009719C) {
        *vyp = D_8009719C;
    }
}
