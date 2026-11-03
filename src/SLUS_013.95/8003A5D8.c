#include "common.h"
#define M2C_UNK s32

s32 get_tile_attr_origin();
M2C_UNK func_8003AFF4(s32);

s32 func_8003A5D8(u8* arg0) {
    if (get_tile_attr_origin(arg0) == 0x20 && !(*(u16*)(arg0 + 0x80) & 0x80)) {
        return 0;
    }
    func_8003AFF4((s32)arg0);
    return 1;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_8003AAD0();
void func_8003B870(struct X4_PlayerObj* self);

s32 func_8003A628(void* arg0) {
    if (D_800CCEDF != 0) {
        func_8003B870(arg0);
        return 1;
    }
    if (((s8*)arg0)[0xD0] <= 0) {
        return 0;
    }
    func_8003AAD0();
    return 1;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
M2C_UNK set_stand_animation_by_hp(void*); /* extern */

void func_8003A678(void* arg0) {
    s16 d;
    s32 var_a2;
    s32 t;

    var_a2 = 0;
    t = M2C_FIELD(arg0, u16*, 0xA) - 0x40;
    d = t - background_objects[M2C_FIELD(arg0, s8*, 0x14)].x_pos.i.hi;
    if (d != 0) {
        if (d > 0) {
            M2C_FIELD(arg0, s8*, 0x15) = 0;
            var_a2 = d < 3;
        } else {
            M2C_FIELD(arg0, s8*, 0x15) = 0x40;
            if (d >= -2) {
                var_a2 = 1;
            }
        }
    } else {
        var_a2 = 1;
    }
    if (var_a2 != 0) {
        set_stand_animation_by_hp(arg0);
        {
            u16 x = background_objects[M2C_FIELD(arg0, s8*, 0x14)].x_pos.u.hi;
            M2C_FIELD(arg0, s8*, 0xD0) = -1;
            M2C_FIELD(arg0, s8*, 0x15) = 0x40;
            M2C_FIELD(arg0, s8*, 0x5) = 0x14;
            M2C_FIELD(arg0, s16*, 0xA) = x + 0x40;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

s32 get_tile_attr_above(void*);

#define B(o) (*(s8*)((u8*)self + (o)))
#define H(o) (*(u16*)((u8*)self + (o)))

// 0x8003A764 func_8003A764: exit test of actions 27 and 28: leaves by tile attribute, timer +0xD0 or jump press; returns 1 when it leaves.
// basis: none
// callers: func_8003605C, func_800361D4
s32 func_8003A764(void* arg0) {
    void* self = arg0;
    // !FAKE: pin: the shared call's argument stays in the first argument register (C0161)
    register s32 a asm("$4");

    if (B(0xD0) > 0) {
        // !FAKE: repeated store keeps jump1 from hoisting it, so the call argument stays explicit
        a = (s32)self;
        a = (s32)self;
        // !FAKE: goto: positive-timer arm shares the out-of-range call (C0115)
        goto tail;
    }
    if ((u8)(get_tile_attr_above(self) - 0x25) >= 0xB) {
        B(0xE3) = 4;
        a = (s32)self;
    tail:
        func_8003AFF4(a);
        return 1;
    }
    if (!(H(0x80) & 0x80)) {
        return 0;
    }
    if (H(0x7C) & 8) {
        ((void (*)(void*))func_8003AFF4)(self);
    } else {
        start_jump(self);
    }
    B(0xE3) = 4;
    return 1;
}
#undef B
#undef H

#include "common.h"

// 0x8003A814 func_8003A814: maps a tile attribute and the facing to an animation offset 0, 1 or 2.
// basis: none
// callers: func_800361D4, func_80038CD0, rock_01 func_801EA124
s32 func_8003A814(void* arg0, s32 arg1) {
    s32 v;

    switch (arg1 & 0xFF) {
    case 0x2D:
        v = 0;
        break;
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
        v = 1;
        if (((u8*)arg0)[0x15] == 0) {
            v = 2;
        }
        break;
    default:
        v = 2;
        if (((u8*)arg0)[0x15] == 0) {
            v = 1;
        }
        break;
    }
    return v;
}
