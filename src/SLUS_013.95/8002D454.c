/* Adapted from sozud/mmx4 @807a01b src/main/object_motion.c:func_8002B9F0, AGPL-3.0; proven shared with X6 by exact signature 5e8e8871519a (see THIRD_PARTY.md). */
#include "common.h"
extern s32 D_80073760[];
extern s32 D_80073784[];

void func_8002D454(s32* arg0, s32* arg1, u8 arg2) {
    s16 var_a3, var_v0;
    s16 var_v1;

    if (arg2 < 0x10) {
        var_a3 = 1;
        if (arg2 < 8) {
            var_v1 = 8 - arg2;
            var_v0 = 1;
        } else {
            var_v1 = arg2 - 8;
            var_v0 = -1;
        }
    } else {
        var_a3 = -1;
        if (arg2 < 0x18) {
            var_v1 = 0x18 - arg2;
            var_v0 = -1;
        } else {
            var_v1 = arg2 - 0x18;
            var_v0 = 1;
        }
    }
    *arg0 = D_80073760[var_v1] * var_v0;
    *arg1 = D_80073784[var_v1] * var_a3;
}

#include "common.h"

extern u16 D_80097120;

s32 func_8002D4F4(void) {
    s32 var_v0;

    var_v0 = (D_80097120 & 0xF) != 0;
    if (D_80097120 & 0x1B0) {
        var_v0 += 1;
    }
    return var_v0;
}

/* Adapted from sozud/mmx4 @807a01b src/main/object_motion.c:get_layout_screen, AGPL-3.0; proven shared with X6 by exact signature b57657e8090d (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj background_objects[3];
extern u8 g_tilemap_width;
extern u16 g_tilemap_layer_stride;

s16 func_8002D51C(s16 arg0, s16 arg1, s16 arg2) {
    struct X4_BackgroundObj* temp_v1 = &background_objects[arg0];
    s16 var_x, var_y;
    s16 temp;

    var_x = (temp_v1->x_pos.i.hi + arg1) / 256;
    var_y = (temp_v1->y_pos.i.hi + arg2) / 256;
    temp = var_x + (arg0 * g_tilemap_layer_stride + g_tilemap_width * var_y);

    return SP_BG_TILEMAP[temp];
}

#include "common.h"

#define M2C_UNK s32

extern s8 D_800971F0;

M2C_UNK func_8002D5D0(void* arg) {
    u8* arg0 = arg;
    s32 t;
    s32 v;
    s32 q;

    if (D_800971F0 != 0 && arg0[0x15] != 0) {
        t = *(s32*)(arg0 + 0x20);
        v = t * 3;
        q = v / 4;
        *(s32*)(arg0 + 0x20) = t;
        *(s32*)(arg0 + 0x8) += q;
        *(s32*)(arg0 + 0xC) -= *(s32*)(arg0 + 0x24);
    } else {
        *(s32*)(arg0 + 0x8) += *(s32*)(arg0 + 0x20);
        *(s32*)(arg0 + 0xC) -= *(s32*)(arg0 + 0x24);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_80097202;
#define D_80097202 (*(s16*)&D_80097202)
extern s16 D_80097206;

s32 func_8002D654(void* arg0, void* arg1) {
#define H0 M2C_FIELD(arg0, u8**, 0x50)
#define H1 M2C_FIELD(arg1, u8**, 0x54)
    u8 w0;
    u8 w1;
    s32 sum;
    s32 x0;
    s32 x1;
    s32 d;

    if (M2C_FIELD(arg1, s8*, 0x61) != 0) {
        return 0;
    }
    if (H0 == 0) {
        return 0;
    }
    if (H1 == 0) {
        return 0;
    }
    w0 = H0[2];
    w1 = H1[2];
    {
        s32 a = *(volatile u8*)&H0[2];
        s32 b = *(volatile u8*)&H1[2];
        sum = a;
        sum += b;
    }
    if (M2C_FIELD(arg0, s8*, 0x14) < 0) {
        if (M2C_FIELD(arg0, u8*, 0x15) & 0x40) {
            x0 = M2C_FIELD(arg0, s16*, 0xA) - (s8)H0[0] + D_80097202;
        } else {
            x0 = M2C_FIELD(arg0, s16*, 0xA) + (s8)H0[0] + D_80097202;
        }
    } else {
        if (M2C_FIELD(arg0, u8*, 0x15) & 0x40) {
            x0 = M2C_FIELD(arg0, s16*, 0xA) - (s8)H0[0];
        } else {
            x0 = M2C_FIELD(arg0, s16*, 0xA) + (s8)H0[0];
        }
    }
    if (M2C_FIELD(arg1, u8*, 0x15) & 0x40) {
        x1 = M2C_FIELD(arg1, s16*, 0xA) - (s8)H1[0];
    } else {
        x1 = M2C_FIELD(arg1, s16*, 0xA) + (s8)H1[0];
    }
    d = x1 - x0;
    if (d < 0) {
        d = x0 - x1;
    }
    if (x1 < x0) {
        if (M2C_FIELD(arg0, u8*, 0x15) & 0x40) {
            if (M2C_FIELD(arg1, u8*, 0x15) & 0x40) {
                if (d >= w0) {
                    return 0;
                }
            } else {
                if (d >= sum) {
                    return 0;
                }
            }
        } else {
            if (M2C_FIELD(arg1, u8*, 0x15) & 0x40) {
                return 0;
            }
            if (d >= w1) {
                return 0;
            }
        }
    } else {
        if (M2C_FIELD(arg0, u8*, 0x15) & 0x40) {
            if (!(M2C_FIELD(arg1, u8*, 0x15) & 0x40)) {
                return 0;
            }
            if (d >= w1) {
                return 0;
            }
        } else if (M2C_FIELD(arg1, u8*, 0x15) & 0x40) {
            if (d >= sum) {
                return 0;
            }
        } else {
            if (d >= w0) {
                return 0;
            }
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x14) < 0) {
        x0 = M2C_FIELD(arg0, s16*, 0xE) + (s8)H0[1] + D_80097206;
    } else {
        x0 = M2C_FIELD(arg0, s16*, 0xE) + (s8)H0[1];
    }
    x1 = M2C_FIELD(arg1, s16*, 0xE) + (s8)H1[1];
    d = x1 - x0;
    if (d < 0) {
        d = x0 - x1;
    }
    if (x1 < x0) {
        if (d >= H1[3]) {
            return 0;
        }
    } else {
        if (d >= H0[3]) {
            return 0;
        }
    }
    return 1;
}
#undef D_80097202
