#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
void func_80029F38(s16, s16, s16, s16, u8);

void func_80029D18(void) {
    struct X4_BackgroundObj* bg = background_objects;

    if (bg->unk14.i.hi != bg->x_pos.i.hi) {
        if (bg->unk14.i.hi < bg->x_pos.i.hi) {
            func_80029F38(bg->x_pos.i.hi + 0x150, bg->x_pos.i.hi + 0x170,
                          bg->y_pos.i.hi - 0x30, bg->y_pos.i.hi + 0x120, 1);
        } else {
            func_80029F38(bg->x_pos.i.hi - 0x30, bg->x_pos.i.hi - 0x10,
                          bg->y_pos.i.hi - 0x30, bg->y_pos.i.hi + 0x120, 2);
        }
    }
    if (bg->unk18.i.hi != bg->y_pos.i.hi) {
        if (bg->unk18.i.hi < bg->y_pos.i.hi) {
            func_80029F38(bg->x_pos.i.hi - 0x30, bg->x_pos.i.hi + 0x170,
                          bg->y_pos.i.hi + 0x100, bg->y_pos.i.hi + 0x120, 3);
        } else {
            func_80029F38(bg->x_pos.i.hi - 0x30, bg->x_pos.i.hi + 0x170,
                          bg->y_pos.i.hi - 0x30, bg->y_pos.i.hi - 0x10, 4);
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 func_80029E7C(struct X4_StageObjectRecord* rec, s16 arg1, s16 arg2,
                  s16 arg3) {
    u32 n;
    u8 g;
    u8 t;
    s32 hi;

    n = rec->object_type & 0xF;
    if (n >= 3 || (g = D_800CCF38) == 3) {
        return 0;
    }
    if (g < n) {
        return 1;
    }
    t = rec->object_type;
    hi = t & 0xF0;
    switch (hi) {
    case 0:
        rec->object_type = t + 0x10;
        return 0;
    case 0x20:
        rec->object_type = t + 0x10;
        return 1;
    case 0x40:
        if (g == 0) {
            return 1;
        }
        rec->object_type = (t & 0xF) + 0x10;
        return 0;
    case 0x60:
        if (g == 0) {
            return 1;
        }
        rec->object_type = (t & 0xF) + 0x30;
        return 1;
    }
    return 1;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800733B8[];
extern u32* D_80095098;
s32 func_80029E7C(struct X4_StageObjectRecord*, s16, s16, s16);
struct X4_AnimatedObj* func_8002A3AC(u8);
s32 func_8002A47C(s32);

#define SPAD20 (*(s32**)0x1F800020)

void func_80029F38(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4) {
    struct X4_StageObjectRecord* rec;
    struct X4_AnimatedObj* obj;
    s16 left, right, top, bottom;
    s16 x0, x1, y0, y1;
    s32 off;
    u32 type;

    rec = D_8007349C[g_playthrough_state.stage][g_playthrough_state.substage];
    left = background_objects[0].x_pos.i.hi - 0x30;
    right = background_objects[0].x_pos.i.hi + 0x170;
    top = background_objects[0].y_pos.i.hi - 0x30;
    bottom = background_objects[0].y_pos.i.hi + 0x120;
    while (rec->object_type != 0xF) {
        if (!(rec->flags & 0x81)) {
            x0 = arg0;
            x1 = arg1;
            y0 = arg2;
            y1 = arg3;
            if (rec->flags & 0x70) {
                off = D_800733B8[(rec->flags >> 4) - 1];
                switch (arg4) {
                case 1:
                    x1 += off;
                    {
                        // !FAKE: depin: dropping it breaks the match (233/257)
                        register s32 t asm("$3") = x0 + off;
                        x0 = t;
                    }
                    break;
                case 2:
                    x0 -= off;
                    {
                        // !FAKE: depin: dropping it breaks the match (236/257)
                        register s32 t asm("$3") = x1 - off;
                        x1 = t;
                    }
                    break;
                case 3:
                    y1 += off;
                    {
                        // !FAKE: depin: dropping it breaks the match (236/257)
                        register s32 t asm("$3") = y0 + off;
                        y0 = t;
                    }
                    break;
                case 4:
                    y0 -= off;
                    {
                        s32 t = y1 - off;
                        y1 = t;
                    }
                    break;
                }
            }
            if (x0 < rec->x && rec->x < x1 && y0 < rec->y && rec->y < y1) {
                if (func_80029E7C(rec, x0, x1, y0) == 0) {
                    obj = func_8002A3AC(rec->object_type);
                    if (obj != 0) {
                        obj->active = 0x41;
                        obj->id = rec->id;
                        obj->unk2 = rec->subtype;
                        obj->x_pos.i.hi = rec->x;
                        obj->y_pos.i.hi = rec->y;
                        obj->backref = rec;
                        if ((rec->object_type & 0xF) < 3) {
                            obj->unk40 =
                                D_80095098[func_8002A47C(rec->id)] >> 7;
                            obj->unk42 =
                                ((func_8002A47C(rec->id) * 4 + 0x20) % 16) |
                                (((func_8002A47C(rec->id) + 8) / 4 + 0x1E0)
                                 << 6);
                            obj->unk3C =
                                (u8*)SPAD20 + SPAD20[func_8002A47C(rec->id)];
                        }
                        rec->flags |= 1;
                    }
                }
            } else {
                // !FAKE: depin: dropping it breaks the match (202/257)
                register u32 t asm("$3") = rec->object_type;

                if ((t & 0xF) < 3 &&
                    (type = t, rec->x < left || right < rec->x ||
                                   rec->y < top || bottom < rec->y)) {
                    switch (rec->object_type & 0xF0) {
                    case 0x10:
                    case 0x30:
                    case 0x50:
                        rec->object_type = type + 0x10;
                        break;
                    }
                }
            }
        }
        rec++;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_EngineObj g_playthrough_state;

void func_8002A33C(void) {
    struct X4_StageObjectRecord* rec;
    u8 t;

    rec = D_8007349C[g_playthrough_state.stage][g_playthrough_state.substage];
    t = rec->object_type;
    while (t != 0xF) {
        rec->object_type = t & 0xF;
        rec->flags &= 0x70;
        rec++;
        t = rec->object_type;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_AnimatedObj* (*D_8007347C[])();

struct X4_AnimatedObj* func_8002A3AC(u8 arg0) {
    return D_8007347C[arg0 & 0xF]();
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/195B4.c:func_80028F58, AGPL-3.0; proven shared with X6 by exact signature a578409ab919 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_StageObjectRecord* D_80073554[13][2];
void func_80029F38(s16, s16, s16, s16, u8);
void func_8002A4E4(struct X4_StageObjectRecord*);

void func_8002A3E8(void) {
    func_80029F38(background_objects[0].x_pos.i.hi - 0x30,
                  background_objects[0].x_pos.i.hi + 0x170,
                  background_objects[0].y_pos.i.hi - 0x30,
                  background_objects[0].y_pos.i.hi + 0x120, 0);
    func_8002A4E4(
        D_80073554[g_playthrough_state.stage][g_playthrough_state.substage]);
}

#include "common.h"
#include "mmx6/x4.h"

extern u8* D_800733C4[][2];
extern struct X4_EngineObj g_playthrough_state;

s32 func_8002A47C(s32 arg0) {
    u8 id;
    s32 i;
    u8 c;

    id = arg0;
    i = 0;
    while (1) {
        c = D_800733C4[g_playthrough_state.stage][g_playthrough_state.substage]
                      [i];
        if (c == 0xFF || c == id) {
            return i;
        }
        i = (i + 1) & 0xFF;
    }
}

#include "common.h"
#include "mmx6/x4.h"

struct X4_AnimatedObj* func_8002A3AC(u8);

void func_8002A4E4(struct X4_StageObjectRecord* rec) {
    struct X4_AnimatedObj* obj;

    while (rec->object_type != 0xF) {
        obj = func_8002A3AC(rec->object_type);
        if (obj != 0) {
            obj->active = 1;
            obj->id = rec->id;
            obj->unk2 = rec->subtype;
            obj->x_pos.i.hi = rec->x;
            obj->y_pos.i.hi = rec->y;
            obj->backref = rec;
        }
        rec++;
    }
}
