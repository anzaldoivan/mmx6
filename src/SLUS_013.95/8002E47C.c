#include "common.h"
#include "mmx6/x4.h"

s32 func_8002E47C(struct X4_PlayerObj* a, struct X4_PlayerObj* b) {
    s16 ax, ay, bx, by;
    u8 r;
    s16 y;
    s32 w1;
    s32 w2;
    s32 d;
    s32 dx;
    s16 t;

    r = 0;
    if (a->facing == 0x40) {
        ax = a->x_pos.i.hi - a->terrain_box->unk0;
    } else {
        ax = a->x_pos.i.hi + a->terrain_box->unk0;
    }
    ay = a->y_pos.i.hi + a->terrain_box->unk1;
    if (b->facing == 0x40) {
        bx = b->x_pos.i.hi - b->terrain_box->unk0;
    } else {
        bx = b->x_pos.i.hi + b->terrain_box->unk0;
    }
    by = b->y_pos.i.hi + b->terrain_box->unk1;

    d = ay - by;
    if (d >= 0) {
        t = d;
    } else {
        t = by - ay;
    }
    dx = ax - bx;
    w1 = a->terrain_box->unk3;
    if (t == b->terrain_box->unk3 + w1) {
        if (dx >= 0) {
            t = dx;
        } else {
            t = bx - ax;
        }
        y = a->terrain_box->unk2 + b->terrain_box->unk2;
        if (t < y) {
            r = 8;
            if (ay < by) {
                r = 4;
            }
        }
    }
    if (dx >= 0) {
        t = dx;
    } else {
        t = bx - ax;
    }
    w2 = a->terrain_box->unk2;
    if (t == b->terrain_box->unk2 + w2) {
        d = ay - by;
        if (d >= 0) {
            t = d;
        } else {
            t = by - ay;
        }
        y = a->terrain_box->unk3 + b->terrain_box->unk3;
        if (t < y) {
            if (ax < bx) {
                r |= 2;
            } else {
                r |= 1;
            }
        }
    }
    b->unk71 |= r;
    return r;
}

#include "common.h"

#define HB_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define HB_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define HB_BOX(p) (*(s8**)((u8*)(p) + 0x68))
#define HB_X(p) (HB_BOX(p)[0])
#define HB_Y(p) (HB_BOX(p)[1])
#define HB_W(p) (((u8*)HB_BOX(p))[2])
#define HB_H(p) (((u8*)HB_BOX(p))[3])

s32 func_8002E664(void* arg0, void* arg1) {
    u8 res;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
    s32 d;
    s16 sum;

    res = 0;
    if (HB_U8(arg0, 0x15) == 0x40) {
        x0 = HB_S16(arg0, 0xA) - HB_X(arg0);
    } else {
        x0 = HB_S16(arg0, 0xA) + HB_X(arg0);
    }
    y0 = HB_S16(arg0, 0xE) + HB_Y(arg0);
    if (HB_U8(arg1, 0x15) == 0x40) {
        x1 = HB_S16(arg1, 0xA) - HB_X(arg1);
    } else {
        x1 = HB_S16(arg1, 0xA) + HB_X(arg1);
    }
    y1 = HB_S16(arg1, 0xE) + HB_Y(arg1);
    d = (s16)((y0 - y1 < 0) ? y1 - y0 : y0 - y1);
    sum = HB_H(arg0) + HB_H(arg1);
    if (d == sum) {
        d = (s16)((x0 - x1 < 0) ? x1 - x0 : x0 - x1);
        sum = HB_W(arg0) + HB_W(arg1);
        if (d < sum) {
            res = 8;
            if (y0 < y1) {
                res = 4;
            }
        }
    }
    d = (s16)((x0 - x1 < 0) ? x1 - x0 : x0 - x1);
    sum = HB_W(arg0) + HB_W(arg1);
    if (d == sum) {
        d = (s16)((y0 - y1 < 0) ? y1 - y0 : y0 - y1);
        sum = HB_H(arg0) + HB_H(arg1);
        if (d < sum) {
            if (x0 < x1) {
                res |= 2;
            } else {
                res |= 1;
            }
        }
    }
    HB_U8(arg1, 0x70) = res | HB_U8(arg1, 0x70);
    return res;
}

#undef HB_U8
#undef HB_S16
#undef HB_BOX
#undef HB_X
#undef HB_Y
#undef HB_W
#undef HB_H

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_8002E84C);

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_8002E974);

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_8002EE10);

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_8002F06C);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern u8 D_800E4190;
extern u8 D_800E4191;
extern s16 D_800E41A4;
void func_8002F418(struct X4_PlayerObj* arg0);
void func_8002F5FC(struct X4_PlayerObj* arg0);
void func_8002F71C(struct X4_PlayerObj* arg0);
void func_8002F840(struct X4_PlayerObj* arg0);
s32 func_8002FBEC(struct X4_PlayerObj* arg0);
void func_800304D8();
void func_8003056C(s32 arg0);
void func_800305B0(s32 arg0);
void func_800306F4(struct X4_PlayerObj* arg0);
s32 func_8003091C();

void func_8002F288(struct X4_PlayerObj* arg0) {
    s32 temp_v1;

    arg0->collision_flags = 0;
    arg0->touching_spikes = 0;
    if (arg0->terrain_box != 0) {
        func_800304D8();
        D_800E4190 = 0;
        D_800E4191 = 0;
        temp_v1 = arg0->x_pos.val - arg0->unk18.val;
        if (temp_v1 != 0) {
            if (temp_v1 > 0) {
                func_8002F71C(arg0);
            } else {
                func_8002F5FC(arg0);
            }
        }
        if ((arg0->y_pos.val - arg0->unk1C.val) >= 0) {
            if ((arg0 != &g_Player) || !(arg0->unk72 & 8)) {
                func_8002F840(arg0);
                if (D_800E4190 != 0) {
                    return;
                }
            }
        } else {
            func_800306F4(arg0);
        }
        if (D_800E4191 & 0xC) {
            if (D_800E4191 & 4) {
                D_800E4191 |= 4;
            }
            if (D_800E4191 & 3) {
                if ((D_800E4191 & 4) || (D_800E41A4 >= -8)) {
                    func_8003056C((s32)arg0);
                } else {
                    func_800305B0((s32)arg0);
                }
            } else {
                func_8003091C(arg0);
            }
        } else if (D_800E4191 & 3) {
            func_8002FBEC(arg0);
        }
        func_8002F418(arg0);
    }
}

#undef g_Player

#include "common.h"
#include "mmx6/x4.h"

extern s16 D_800E4192;
extern s16 D_800E4194;
extern s16 D_800E4196;
extern s16 D_800E4198;
extern s16 D_800E419A;
extern s16 D_800E419C;
extern s16 D_800E419E;
extern s16 D_800E41A0;
s32 func_800309F8(struct X4_PlayerObj* arg0, s16 arg1, s32 arg2);
s32 func_80030B80(struct X4_PlayerObj* arg0, s16 arg1);

void func_8002F418(struct X4_PlayerObj* arg0) {
    struct X4_Unk_unk68* box;
    u16 x;

    box = arg0->terrain_box;
    arg0->collision_flags = 0;
    arg0->touching_spikes = 0;
    if (box != 0) {
        D_800E4196 = box->unk0;
        x = arg0->x_pos.u.hi;
        D_800E4198 = box->unk1;
        D_800E4192 = box->unk2;
        {
            // !FAKE: depin: dropping it breaks the match (116/121)
            register s32 h asm("$7") = box->unk3;
            D_800E4194 = h;
        }
        D_800E419A = x;
        D_800E419C = arg0->y_pos.i.hi;
        if (arg0->facing == 0) {
            D_800E419E = x + D_800E4196;
        } else {
            D_800E419E = x - D_800E4196;
        }
        D_800E41A0 = D_800E419C + D_800E4198;
        if (func_80030B80(arg0, D_800E419E - D_800E4192 - 1) != 0) {
            arg0->collision_flags |= 2;
        }
        if (func_80030B80(arg0, D_800E419E + D_800E4192) != 0) {
            arg0->collision_flags |= 1;
        }
        if (func_800309F8(arg0, D_800E4194 + (D_800E419C + D_800E4198), 1) !=
            0) {
            arg0->collision_flags |= 8;
        }
        if (func_800309F8(arg0, D_800E419C + D_800E4198 - D_800E4194 - 1, 0) !=
            0) {
            arg0->collision_flags |= 4;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"
extern s16 D_800E4192;
extern s16 D_800E4194;
extern s16 D_800E419E;
extern s16 D_800E41A0;
u8 func_80030304(struct X4_PlayerObj*, s16, s16);
s32 func_80030628(struct X4_PlayerObj* arg0, u8 arg1);

void func_8002F5FC(struct X4_PlayerObj* arg0) {
    s16 temp_v0;
    u8 var_v0;

    temp_v0 = D_800E419E - D_800E4192;
    if (func_80030628(arg0, func_80030304(arg0, temp_v0, D_800E41A0)) == 0) {
        if (arg0->unk71 & 8) {
            var_v0 = func_80030304(arg0, temp_v0, D_800E41A0 - D_800E4194 - 1);
        } else {
            var_v0 = func_80030304(arg0, temp_v0, D_800E41A0 - D_800E4194);
        }
        if (func_80030628(arg0, var_v0) == 0) {
            func_80030628(arg0, func_80030304(arg0, temp_v0,
                                              D_800E41A0 + D_800E4194 - 1));
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"
extern s16 D_800E4192;
extern s16 D_800E4194;
extern s16 D_800E419E;
extern s16 D_800E41A0;
u8 func_80030304(struct X4_PlayerObj*, s16, s16);
s32 func_80030690(struct X4_PlayerObj* arg0, u8 arg1);

void func_8002F71C(struct X4_PlayerObj* arg0) {
    s16 temp_v0;
    u8 var_v0;

    temp_v0 = D_800E419E + D_800E4192 - 1;
    if (func_80030690(arg0, func_80030304(arg0, temp_v0, D_800E41A0)) == 0) {
        if (arg0->unk71 & 8) {
            var_v0 = func_80030304(arg0, temp_v0, D_800E41A0 - D_800E4194 - 1);
        } else {
            var_v0 = func_80030304(arg0, temp_v0, D_800E41A0 - D_800E4194);
        }
        if (func_80030690(arg0, var_v0) == 0) {
            func_80030690(arg0, func_80030304(arg0, temp_v0,
                                              D_800E41A0 + D_800E4194 - 1));
        }
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/1CF60.c:func_8002CDD4, AGPL-3.0; proven shared with X6 by exact signature 35842cc5ea2e (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s16 D_800E4192;
extern s16 D_800E4194;
extern s16 D_800E419E;
extern s16 D_800E41A0;
s32 func_8002F9DC(struct X4_PlayerObj*, u8, s16, s16);
u8 func_80030304(struct X4_PlayerObj*, s16, s16);

void func_8002F840(struct X4_PlayerObj* arg0) {
    u8 temp_s3;
    u8 temp_s4;
    u8 temp_s5;
    u8 temp_v0_4;
    s32 var_s0;
    s16 temp_v0 = D_800E41A0 + D_800E4194;

    temp_s3 = func_80030304(arg0, D_800E419E - D_800E4192, temp_v0);
    temp_s4 = func_80030304(arg0, D_800E419E + D_800E4192 - 1, temp_v0);
    temp_s5 = func_80030304(arg0, D_800E419E, temp_v0);

    if (func_8002F9DC(arg0, temp_s5, D_800E419E, temp_v0) == 0) {
        if (arg0->air_state == 0) {
            var_s0 = 0;
            if (temp_s3 > 0 && temp_s3 < 0x20) {
                var_s0 = 1;
            }
            if (temp_s4 > 0 && temp_s4 < 0x20) {
                var_s0 = 1;
            }

            temp_v0_4 = func_80030304(arg0, D_800E419E, (temp_v0 + 0x10));
            if (temp_v0_4 > 0 && temp_v0_4 < 0x20) {
                var_s0 = 1;
            }

            if (var_s0) {
                arg0->y_pos.i.hi += 0x10;
                if (func_8002F9DC(arg0, temp_v0_4, D_800E419E,
                                  temp_v0 + 0x10)) {
                    return;
                }
            }
        }

        if (func_800308B8(arg0, temp_s3, temp_v0) == 0) {
            func_800308B8(arg0, temp_s4, temp_v0);
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_8002F9DC);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

extern u8 D_800E4191;
extern s16 D_800E4192;
extern s16 D_800E4196;
extern s16 D_800E419A;
extern s16 D_800E41A2;
s32 func_80030B80(struct X4_PlayerObj* arg0, s16 arg1);

s32 func_8002FBEC(struct X4_PlayerObj* arg0) {
    s16 x;

    if (D_800E4191 & 1) {
        if (arg0->facing != 0) {
            x = D_800E419A + D_800E41A2 + D_800E4196 + D_800E4192 - 1;
        } else {
            x = D_800E419A + D_800E41A2 - D_800E4196 + D_800E4192 - 1;
        }
    } else {
        if (arg0->facing != 0) {
            x = D_800E419A + D_800E41A2 + D_800E4196 - D_800E4192;
        } else {
            x = D_800E419A + D_800E41A2 - D_800E4196 - D_800E4192;
        }
    }
    if (func_80030B80(arg0, x) == 0) {
        arg0->x_pos.u.lo = 0;
        arg0->x_pos.u.hi += D_800E41A2;
        return 0;
    }
    return -1;
}
