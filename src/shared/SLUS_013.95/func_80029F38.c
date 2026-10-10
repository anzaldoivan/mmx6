#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_EngineObj D_800CCED0;
extern struct X4_StageObjectRecord* D_8007349C[][2];
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
    register s32 off asm("$4");
    u32 type;

    rec = D_8007349C[D_800CCED0.stage][D_800CCED0.substage];
    left = D_800971F8[0].x_pos.i.hi - 0x30;
    right = D_800971F8[0].x_pos.i.hi + 0x170;
    top = D_800971F8[0].y_pos.i.hi - 0x30;
    bottom = D_800971F8[0].y_pos.i.hi + 0x120;
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
                        register s32 t asm("$3") = x0 + off;
                        x0 = t;
                    }
                    break;
                case 2:
                    x0 -= off;
                    {
                        register s32 t asm("$3") = x1 - off;
                        x1 = t;
                    }
                    break;
                case 3:
                    y1 += off;
                    {
                        register s32 t asm("$3") = y0 + off;
                        y0 = t;
                    }
                    break;
                case 4:
                    y0 -= off;
                    {
                        register s32 t asm("$3") = y1 - off;
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
