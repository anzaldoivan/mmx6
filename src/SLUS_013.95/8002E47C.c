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
    if (a->unk15 == 0x40) {
        ax = a->x_pos.i.hi - a->unk68->unk0;
    } else {
        ax = a->x_pos.i.hi + a->unk68->unk0;
    }
    ay = a->y_pos.i.hi + a->unk68->unk1;
    if (b->unk15 == 0x40) {
        bx = b->x_pos.i.hi - b->unk68->unk0;
    } else {
        bx = b->x_pos.i.hi + b->unk68->unk0;
    }
    by = b->y_pos.i.hi + b->unk68->unk1;

    d = ay - by;
    if (d >= 0) {
        t = d;
    } else {
        t = by - ay;
    }
    dx = ax - bx;
    w1 = a->unk68->unk3;
    if (t == b->unk68->unk3 + w1) {
        if (dx >= 0) {
            t = dx;
        } else {
            t = bx - ax;
        }
        y = a->unk68->unk2 + b->unk68->unk2;
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
    w2 = a->unk68->unk2;
    if (t == b->unk68->unk2 + w2) {
        d = ay - by;
        if (d >= 0) {
            t = d;
        } else {
            t = by - ay;
        }
        y = a->unk68->unk3 + b->unk68->unk3;
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

    arg0->unk70 = 0;
    arg0->touching_spikes = 0;
    if (arg0->unk68 != 0) {
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

    box = arg0->unk68;
    arg0->unk70 = 0;
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
        if (arg0->unk15 == 0) {
            D_800E419E = x + D_800E4196;
        } else {
            D_800E419E = x - D_800E4196;
        }
        D_800E41A0 = D_800E419C + D_800E4198;
        if (func_80030B80(arg0, D_800E419E - D_800E4192 - 1) != 0) {
            arg0->unk70 |= 2;
        }
        if (func_80030B80(arg0, D_800E419E + D_800E4192) != 0) {
            arg0->unk70 |= 1;
        }
        if (func_800309F8(arg0, D_800E4194 + (D_800E419C + D_800E4198), 1) !=
            0) {
            arg0->unk70 |= 8;
        }
        if (func_800309F8(arg0, D_800E419C + D_800E4198 - D_800E4194 - 1, 0) !=
            0) {
            arg0->unk70 |= 4;
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
        if (arg0->unk15 != 0) {
            x = D_800E419A + D_800E41A2 + D_800E4196 + D_800E4192 - 1;
        } else {
            x = D_800E419A + D_800E41A2 - D_800E4196 + D_800E4192 - 1;
        }
    } else {
        if (arg0->unk15 != 0) {
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

#include "common.h"
#include "mmx6/x4.h"

s32 func_80028078(s32, s32, u32);

#define SCR_08 (*(u8**)0x1F800008)
#define SCR_0C (*(u8**)0x1F80000C)

s32 func_8002FD3C(void* arg0) {
    struct X4_MainObj* obj = arg0;
    u8* p = (u8*)obj->terrain_box;
    u32 a = obj->x_pos.u.hi << 16;
    u32 b = (u16)(obj->y_pos.u.hi + (s8)p[1] - p[3]) << 16;
    s32 x = (s32)a >> 24;
    s32 y = (s32)b >> 24;
    s32 sx = (a >> 20) & 0xF;
    s32 sy = (b >> 20) & 0xF;
    s32 ret;
    s32 v;

    ret = func_80028078(obj->bg_offset, x, y);
    if (ret == 0 || y < 0) {
        v = 0;
    } else if (x < 0) {
        v = 0;
    } else {
        v = SCR_0C[(*(u16*)(SCR_08 + ret * 512 + sy * 32 + sx * 2) & 0x3FFF) *
                   4];
    }
    if (v == 0x3B) {
        v = 0x38;
    }
    return v;
}
#undef SCR_08
#undef SCR_0C

#include "common.h"
#include "mmx6/x4.h"

s32 func_80028078(s32, s32, u32);

#define SCR_08 (*(s32*)0x1F800008)
#define SCR_0C (*(s32*)0x1F80000C)

s32 func_8002FE30(void* arg0) {
    struct X4_MainObj* self = arg0;
    struct X4_Unk_unk68* box;
    s32 h;
    s16 y;
    s16 x;
    s32 xi;
    s32 yi;
    s32 col;
    s32 row;
    s32 t;
    u8 r;

    box = self->terrain_box;
    h = 0xE;
    if (self->unk2 != 0) {
        h = 0x18;
    }
    x = self->x_pos.i.hi;
    y = self->y_pos.u.hi + box->unk1 - box->unk3 - h;
    xi = x >> 8;
    yi = y >> 8;
    col = (u32)(x & 0xF0) >> 4;
    row = (u32)(y & 0xF0) >> 4;
    t = func_80028078(self->bg_offset, xi, yi);
    if (t == 0 || yi < 0 || xi < 0) {
        r = 0;
    } else {
        self->unk6C = x & 0xF;
        self->unk6E = y & 0xF;
        r = *(u8*)(((*(u16*)((col << 1) + ((row << 5) + ((t << 9) + SCR_08))) &
                     0x3FFF)
                    << 2) +
                   SCR_0C);
    }
    if (r == 0x3B) {
        r = 0x38;
    }
    return r;
}
#undef SCR_08
#undef SCR_0C

#include "common.h"
#include "mmx6/x4.h"

s32 func_80028078(s32, s32, u32);

#define D_1F800008 (*(u8**)0x1F800008)
#define D_1F80000C (*(u8**)0x1F80000C)

s32 func_8002FF70(void* arg0) {
    struct X4_MainObj* obj = arg0;
    u8* p = (u8*)obj->terrain_box;
    u32 a = obj->x_pos.u.hi << 16;
    u32 b = (u16)(obj->y_pos.i.hi + (s8)p[1] + p[3] - 1) << 16;
    s32 x = (s32)a >> 24;
    s32 y = (s32)b >> 24;
    s32 sx = (a >> 20) & 0xF;
    s32 sy = (b >> 20) & 0xF;
    s32 ret;
    s32 v;

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

#include "common.h"
#include "mmx6/x4.h"

s32 func_80028078(s32, s32, u32);

#define SCR_08 (*(s32*)0x1F800008)
#define SCR_0C (*(s32*)0x1F80000C)

s32 func_80030068(void* arg0) {
    struct X4_MainObj* self = arg0;
    struct X4_Unk_unk68* box = self->terrain_box;
    u32 a = self->x_pos.u.hi << 16;
    u32 b = (u16)(self->y_pos.u.hi + box->unk1 + box->unk3) << 16;
    s32 x = (s32)a >> 24;
    s32 y = (s32)b >> 24;
    s32 sx = (a >> 20) & 0xF;
    s32 sy = (b >> 20) & 0xF;
    s32 t;
    u8 r;

    t = func_80028078(self->bg_offset, x, y);
    if (t == 0 || y < 0) {
        r = 0;
    } else if (x < 0) {
        r = 0;
    } else {
        r = *(u8*)(((*(u16*)((sx << 1) + ((sy << 5) + ((t << 9) + SCR_08))) &
                     0x3FFF)
                    << 2) +
                   SCR_0C);
    }
    if (r == 0x3B) {
        r = 0x38;
    }
    return r;
}
#undef SCR_08
#undef SCR_0C

#include "common.h"
#include "mmx6/x4.h"

#define D_1F800008 (*(u8**)0x1F800008)
#define D_1F80000C (*(u8**)0x1F80000C)

s32 func_80028078(s32, s32, u32);

s32 func_8003015C(struct X4_PlayerObj* obj) {
    u32 a = obj->x_pos.u.hi << 16;
    u32 b = obj->y_pos.u.hi << 16;
    s32 x = (s32)a >> 24;
    s32 y = (s32)b >> 24;
    s32 sx = (a >> 20) & 0xF;
    s32 sy = (b >> 20) & 0xF;
    s32 ret;
    s32 v;

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
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80030304);

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_8003040C);
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
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80030628);

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80030690);
// clang-format on

/* Adapted from sozud/mmx4 @807a01b src/main/1CF60.c:func_8002CC98, AGPL-3.0; proven shared with X6 by exact signature 8fa4d2d2edd1 (see THIRD_PARTY.md). */
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
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_800307CC);
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
    arg0->unk70 = 8;
    d = arg1 - (arg2 + (arg1 & ~0xF));
    arg0->y_pos.i.lo = 0;
    arg0->y_pos.i.hi -= d;
    return -1;
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_800308B8);

INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_8003091C);
// clang-format on

/* Adapted from sozud/mmx4 @807a01b src/main/1CF60.c:func_8002D32C, AGPL-3.0; proven shared with X6 by exact signature 42673ebd7e4e (see THIRD_PARTY.md). */
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
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80030AE8);
// clang-format on

/* Adapted from sozud/mmx4 @807a01b src/main/1CF60.c:func_8002D5E4, AGPL-3.0; proven shared with X6 by exact signature ca45eff14472 (see THIRD_PARTY.md). */
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
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80030C58);
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
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80030D80);
// clang-format on
