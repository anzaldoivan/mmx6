#include "common.h"
#include "mmx6/x4.h"

#define D_1F800008 (*(u8**)0x1F800008)
#define D_1F80000C (*(u8**)0x1F80000C)

s32 func_80028078(s32, s32, u32);

u8 func_80030234(struct X4_PlayerObj* obj, s16 px, s16 py) {
    u32 a = px << 16;
    u32 b = py << 16;
    s32 x = (s32)a >> 24;
    s32 y = (s32)b >> 24;
    s32 sx = (a >> 20) & 0xF;
    s32 sy = (b >> 20) & 0xF;
    s32 ret;
    u8 v;

    ret = func_80028078(obj->bg_offset, x, y);
    if (ret == 0 || y < 0) {
        v = 0;
    } else if (x < 0) {
        v = 0;
    } else {
        v = D_1F80000C[(*(u16*)(D_1F800008 + ret * 512 + sy * 32 + sx * 2) &
                        0x3FFF) *
                       4];
    }
    if (v == 0x3B) {
        v = 0x38;
    }
    return v;
}
#undef D_1F800008
#undef D_1F80000C

// clang-format off
#include "../shared/SLUS_013.95/func_80030304.c"

#include "../shared/SLUS_013.95/func_8003040C.c"
// clang-format on

#include "common.h"

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

extern s16 D_800E4192;
extern s16 D_800E4194;
extern s16 D_800E4196;
extern s16 D_800E4198;
extern s16 D_800E419A;
extern s16 D_800E419C;
extern s16 D_800E419E;
extern s16 D_800E41A0;

void func_800304D8(u8* arg0) {
    u8* p;
    u8 b;
    u16 x;

    p = M2C_FIELD(arg0, u8**, 0x68);
    b = p[0];
    D_800E4196 = (s8)b;
    x = M2C_FIELD(arg0, u16*, 0xA);
    D_800E4198 = (s8)p[1];
    D_800E4192 = p[2];
    {
        s32 c = p[3];
        s32 e = M2C_FIELD(arg0, u16*, 0xE);
        D_800E419A = x;
        D_800E419C = e;
        D_800E4194 = c;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        D_800E419E = x + D_800E4196;
    } else {
        D_800E419E = x - D_800E4196;
    }
    D_800E41A0 = D_800E419C + D_800E4198;
}

#include "common.h"

#define M2C_UNK s32

s32 func_8002FBEC(struct X4_PlayerObj* arg0); /* extern */
M2C_UNK func_800305F4(s32);                   /* extern */
s32 func_8003091C();                          /* extern */

void func_8003056C(s32 arg0) {
    if ((func_8003091C() != 0) && (func_8002FBEC(arg0) != 0)) {
        func_800305F4(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32

s32 func_8002FBEC(struct X4_PlayerObj* arg0); /* extern */
M2C_UNK func_800305F4(s32);                   /* extern */
s32 func_8003091C(s32);                       /* extern */

void func_800305B0(s32 arg0) {
    if ((((s32(*)())func_8002FBEC)() != 0) && (func_8003091C(arg0) != 0)) {
        func_800305F4(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32

extern s16 D_800E41A2;
extern s16 D_800E41A4;

M2C_UNK func_800305F4(s32 arg0) {
    u16* p = (u16*)arg0;
    s32 a = (u16)D_800E41A2;
    s32 b = (u16)D_800E41A4;

    p[4] = 0;
    p[6] = 0;
    p[5] += a;
    p[7] += b;
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/30234", func_80030628);

#include "../shared/SLUS_013.95/func_80030690.c"
// clang-format on

/* Adapted from sozud/mmx4 @4e16dfc src/main/1CF60.c:func_8002CC98, AGPL-3.0; proven shared with X6 by exact signature 8fa4d2d2edd1 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s16 D_800E4192;
extern s16 D_800E4194;
extern s16 D_800E419E;
extern s16 D_800E41A0;
u8 func_80030304(struct X4_PlayerObj*, s16, s16);
s32 func_800307CC(struct X4_PlayerObj* arg0, u8 arg1);

void func_800306F4(struct X4_PlayerObj* arg0) {
    s16 temp_v0;

    temp_v0 = D_800E41A0 - D_800E4194;
    if ((func_800307CC(arg0, func_80030304(arg0, D_800E419E, temp_v0)) == 0) &&
        (func_800307CC(arg0, func_80030304(arg0, D_800E419E - D_800E4192,
                                           temp_v0)) == 0)) {
        func_800307CC(
            arg0, func_80030304(arg0, D_800E419E + D_800E4192 - 1, temp_v0));
    }
}

// clang-format off
#include "../shared/SLUS_013.95/func_800307CC.c"
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

extern u8 D_800E4190;

s32 func_80030834(struct X4_PlayerObj* arg0, s16 arg1, s16 arg2, s32 arg3) {
    s16 d;

    D_800E4190 = 1;
    if (arg0->air_state != 0) {
        if ((arg3 == 0) && ((arg1 & 0xF) < arg2)) {
            return 0;
        }
    }
    arg0->collision_flags = 8;
    d = arg1 - (arg2 + (arg1 & ~0xF));
    arg0->y_pos.i.lo = 0;
    arg0->y_pos.i.hi -= d;
    return -1;
}

// clang-format off
#include "../shared/SLUS_013.95/func_800308B8.c"

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/30234", func_8003091C);
// clang-format on

/* Adapted from sozud/mmx4 @4e16dfc src/main/1CF60.c:func_8002D32C, AGPL-3.0; proven shared with X6 by exact signature 42673ebd7e4e (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s16 D_800E4192;
extern s16 D_800E419E;
u8 func_80030234(struct X4_PlayerObj*, s16, s16);

s32 func_800309F8(struct X4_PlayerObj* arg0, s16 arg1, s32 arg2) {
    if (func_80030AE8(arg0, func_80030234(arg0, D_800E419E, arg1), arg2) == 0) {
        if (func_80030AE8(arg0,
                          func_80030234(arg0, D_800E419E - D_800E4192, arg1),
                          arg2) == 0) {
            if (func_80030AE8(
                    arg0,
                    func_80030234(arg0, D_800E419E + D_800E4192 - 1, arg1),
                    arg2) == 0) {
                return 0;
            }
        }
    }
    return -1;
}

// clang-format off
#include "../shared/SLUS_013.95/func_80030AE8.c"
// clang-format on

/* Adapted from sozud/mmx4 @4e16dfc src/main/1CF60.c:func_8002D5E4, AGPL-3.0; proven shared with X6 by exact signature ca45eff14472 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s16 D_800E4194;
extern s16 D_800E41A0;
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
s32 func_80030C58(struct X4_PlayerObj* arg0, u8 arg1);

s32 func_80030B80(struct X4_PlayerObj* arg0, s16 arg1) {
    if (func_80030C58(
            arg0, func_80030234(arg0, arg1, D_800E41A0 - D_800E4194)) == 0) {
        if (func_80030C58(arg0, func_80030234(arg0, arg1, D_800E41A0)) == 0) {
            if (func_80030C58(
                    arg0, func_80030234(arg0, arg1,
                                        D_800E41A0 + D_800E4194 - 1)) == 0) {
                return 0;
            }
        }
    }
    return -1;
}

// clang-format off
#include "../shared/SLUS_013.95/func_80030C58.c"
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

extern s16 D_800E41A6;
extern s16 D_800E41B0[][4];

u8 func_80030234(struct X4_PlayerObj* obj, s16 px, s16 py);

s32 func_80030CCC(struct X4_PlayerObj* self, s16 x, s16 y) {
    s32 i;

    for (i = 0; i < D_800E41A6; i++) {
        if (x >= D_800E41B0[i][0] && D_800E41B0[i][1] >= x &&
            y >= D_800E41B0[i][2] && D_800E41B0[i][3] >= y) {
            return 0x38;
        }
    }
    return func_80030234(self, x, y);
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/30234", func_80030D80);
// clang-format on
