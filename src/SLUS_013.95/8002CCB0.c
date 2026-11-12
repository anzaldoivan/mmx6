#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_BackgroundObj background_objects[3];

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
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/21BF4", func_8002CD6C);
// clang-format on

/* Adapted from sozud/mmx4 @4e16dfc src/main/objects.c:func_8002B468, AGPL-3.0; proven shared with X6 by exact signature 824e92a3c988 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

struct X4_EffectObj* func_8002CE18(s8 id, s8 arg1) {
    struct X4_EffectObj* effect;
    s8 i;

    i = 0;
    if (id >= 0) {
        do {
            effect = &g_class3_slots[i];
            if (effect->active != 0 && effect->id == id &&
                effect->unk2 == arg1) {
                return effect;
            }
            i++;
        } while (i < 0x20);
    } else {
        id &= 0x7F;
        do {
            effect = &g_class3_slots[i];
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
#include "mmx6/globals.h"

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
        *(s32*)((u8*)g_class4_slots + off + w * 4) &= mask;
    }
}
