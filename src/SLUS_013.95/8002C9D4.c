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
#include "mmx6/globals.h"

extern struct X4_BackgroundObj background_objects[3];

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
