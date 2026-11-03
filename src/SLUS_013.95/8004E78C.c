#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
extern struct X4_EngineObj g_playthrough_state;

M2C_UNK func_8004E78C(M2C_UNK arg0) {
    u8 v = arg0;
    u8* e = (u8*)&g_playthrough_state;

    e[0x10] = v;
    e[0x11] = v;
    e[0x12] = v;
    e[0x13] = v;
    e[0x14] = v;
    e[0x15] = v;
    e[0x16] = v;
    e[0x17] = v;
    e[0x19] = v;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8004DCB8(); /* extern */

void func_8004E7C0(struct ObjectHeader* arg0) {
    arg0->on_screen = 0;
    func_8004DCB8(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8004E7E0(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_8004E800 (*(s32**)0x1F800020)
#define F(type, off) M2C_FIELD(arg0, type*, off)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
void func_8002F288(struct X4_PlayerObj*);
M2C_UNK func_8004FE8C();
s32 get_reploid_status(s32);
extern s32 D_80078910;
extern s32 D_8007891C;
extern s32 D_80078BEC;
extern u32* D_80095098;

void func_8004E800(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (41/158)
    register s32 t asm("$5");

    if (F(u8, 2) != 0x80 && (u32)(get_reploid_status(F(u8, 2)) - 2) < 3) {
        F(u8, 4) = 8;
        return;
    }
    if ((F(s8, 2) & 0xF0) == 0x10) {
        F(u8, 0x84) = 1;
    } else {
        F(u8, 0x84) = 0;
    }
    t = D_800970B4;
    F(u8, 0) = 0x41;
    F(void*, 0x58) = &D_800743DC;
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    F(u8, 0x16) = 2;
    F(void*, 0x30) = &D_80078BEC;
    F(u8, 0x14) = t;
    F(u16, 0x40) = D_80095098[((s32(*)())func_8002A47C)(0x8D, t)] >> 7;
    F(u8*, 0x3C) = (u8*)SPAD20_8004E800 + SPAD20_8004E800[func_8002A47C(0x8D)];
    F(s16, 0x42) = ((func_8002A47C(0x8D) * 4 + 0x20) % 16) |
                   (((func_8002A47C(0x8D) + 8) / 4 + 0x1E0) << 6);
    F(u8, 0x15) = 0;
    F(s32, 0x18) = F(s32, 0x8);
    F(s32, 0x1C) = F(s32, 0xC);
    func_8004FE8C(arg0);
    if (F(u8, 0x84) == 0) {
        F(void*, 0x68) = &D_80078910;
        func_8002F288(arg0);
        if (F(u8, 0x70) & 8) {
            F(u8, 0x7E) = 0;
            if (F(u8, 0x82) == 0) {
                set_animation(arg0, 0);
            } else {
                set_animation(arg0, 0xB);
            }
        } else {
            F(u8, 0x7E) = 1;
            F(u16, 0x7C) = F(u16, 0xE);
            if (F(u8, 0x82) == 0) {
                set_animation(arg0, 5);
            } else {
                set_animation(arg0, 0xE);
            }
        }
    } else {
        F(void*, 0x68) = &D_8007891C;
        func_8002F288(arg0);
        if (F(u8, 0x82) == 0) {
            set_animation(arg0, 0x17);
        } else {
            set_animation(arg0, 0x1E);
        }
    }
    F(u8, 4) = 1;
    F(u8, 7) = 1;
    F(u8, 5) = 0;
    if (F(u8, 2) == 0x80) {
        F(u8, 7) = 0;
    }
}

#undef F
#undef SPAD20_8004E800

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
s32 is_off_screen(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
s32 rescue_reploid(void*);
s32 func_8004FE8C();
void set_reploid_status(u8, s32);
#include "mmx6/state.h"

void func_8004EA78(u8* arg0) {
    s8 temp_s1;

    ((M2C_UNK(*)())animate_object)();
    if (func_8004FE8C(arg0) != 0) {
        if (arg0[0x84] == 0) {
            if (arg0[0x7E] == 0) {
                if (arg0[0x82] == 0) {
                    set_animation(arg0, 0);
                } else {
                    set_animation(arg0, 0xB);
                }
            } else if (arg0[0x82] == 0) {
                set_animation(arg0, 5);
            } else {
                set_animation(arg0, 0xE);
            }
        } else if (arg0[0x82] == 0) {
            set_animation(arg0, 0x17);
        } else {
            set_animation(arg0, 0x1E);
        }
    }
    if (rescue_reploid(arg0) == 0) {
        temp_s1 = ((s8*)arg0)[7];
        if (temp_s1 == 2) {
            set_reploid_status(arg0[2], 4);
            arg0[4] = 6;
            arg0[5] = temp_s1;
            arg0[6] = 0;
            arg0[7] = 0;
            return;
        }
        if (arg0[0x7E] == 1) {
            *(s16*)(arg0 + 0xE) =
                *(u16*)(arg0 + 0x7C) +
                (rsin((D_80097420.frame_counter & 0x7F) << 5) >> 0xA);
        }
        if (is_off_screen(arg0, 0x30, 0x30) == 0) {
            if (arg0[0x84] == 0) {
                func_8002CCB0(arg0, 0x10, 0x20);
            } else {
                func_8002CCB0(arg0, 0x20, 0x20);
            }
            return;
        }
        if (arg0[2] != 0x80) {
            arg0[3] = 0;
            arg0[4] = 7;
            arg0[7] = 0;
        }
    } else {
        arg0[7] = 0;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK animate_object();
#define animate_object ((M2C_UNK(*)())animate_object)
void func_8004FE58(s32, s8);
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;

void func_8004EC30(u8* arg0) {
    u8* p;
    u8* q;
    u8 t;
    // !FAKE: depin: dropping it breaks the match (66/71)
    register s32 f asm("$2");

    animate_object();
    p = arg0 + 0x7C;
    f = ((s8*)arg0)[6];
    if (f == 0) {
        p[4] = t = arg0[0x80] - 1;
        q = p;
        if (t == 0) {
            u8* pl;
            // !FAKE: depin: dropping it breaks the match (68/71)
            register u8* e asm("$3");
            s8* tbl;
            s8 sign;
            // !FAKE: depin: dropping it breaks the match (67/71)
            register s32 x asm("$4");

            pl = (u8*)&g_Player;
            e = (u8*)&g_playthrough_state;
            tbl = (s8*)(e + 0x5B);
            arg0[0x80] = 4;
            sign = pl[0x5C] & 0x80;
            x = (s8)pl[2];
            if ((pl[0x5C] & 0x7F) >= tbl[x]) {
                arg0[6] = 1;
                pl[0x5C] = sign | tbl[(s8)pl[2]];
            } else {
                pl[0x5C] = sign | (pl[0x5C] + 1);
            }
            play_sound(0, 0xD, 0);
            p = 0;
            if ((u8)(q[3] = arg0[0x7F] - 1) == 0) {
                arg0[6] = 1;
            }
        }
    } else {
        ((void (*)())func_8004FE58)(0);
        arg0[4] = 3;
        arg0[5] = 0;
        arg0[0] &= 0xF7;
    }
}
#undef animate_object

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
s32 play_sound(s32 a0, s32 a1, void* arg2);
void func_8004FE58(s32, s8);

#define ENG ((u8*)&g_playthrough_state)
#define ENG5B                                                                  \
    (((struct X4_EngineObj*)(ENG - -g_Player.character))->sub_tanks[-1])

void func_8004ED4C(u8* arg0, u8 arg1, u8 a2) {
    // !FAKE: depin: dropping it breaks the match (90/96)
    register s32 arg2 asm("$20") = a2;
    u8 hi;
    s8 i;
    u8* p;
    s32 v;
    u8* base;

    hi = (u8)g_Player.hp & 0x80;
    if (((u8)g_Player.hp & 0x7F) < ENG5B) {
        func_8004FE58(1, ENG5B);
        arg0[0x80] = 4;
        arg0[0x7F] = arg1;
        arg0[4] = 2;
        arg0[5] = 0;
        arg0[6] = 0;
        arg0[0] |= 8;
    } else {
        arg0[4] = 3;
    }
    base = ENG;
    if (((u8)g_Player.hp & 0x7F) >= ENG5B) {
        g_Player.hp = (u8)ENG5B | hi;
    }
    for (i = 0; i < 2; i++) {
        p = &base[i + 0x63];
        if (*(volatile u16*)(base + 0x6A) & (0x1000 << i)) {
            v = *p & 0x7F;
            if (v < 0x20) {
                // !FAKE: depin: dropping it breaks the match (94/96)
                register s32 c asm("$3");
                {
                    // !FAKE: depin: dropping it breaks the match (80/96)
                    register s32 t asm("$2") = arg2 + v;
                    v = (s8)t;
                }
                if ((c = v < 0x20, c) == 0) {
                    v = 0x20;
                    play_sound(0, 0x18, 0);
                }
                *p = v | 0x80;
                return;
            }
        }
    }
#undef ENG5B
}
