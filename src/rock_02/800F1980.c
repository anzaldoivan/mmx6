#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK silence_sound(M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_8007523C;
extern M2C_UNK D_800752DC;
extern M2C_UNK D_8007537C;
extern M2C_UNK g_Player;
extern s8 D_8009711A;
extern u8 D_80097187;
extern void (*D_800FB850[])(void*);

#define SPAD (*(u8**)0x1F80004C)

void func_800F1980(void* arg0) {
    s32 v;
    s8 st;
    u8 c;
    u8* p;
    u8* q;
    u8* r;
    s32 t;
    s32 n;

    v = check_enemy_hits(arg0);
    if (v < 0) {
        silence_sound(0xFF, 0);
        play_sound(2, 0x14, arg0);
        play_sound(2, 0x3D, arg0);
        play_sound(2, 0x21, arg0);
        D_8009711A = 1;
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 5) = 0;
        return;
    }
    st = M2C_FIELD(arg0, s8*, 5);
    if (st == 0xC) {
        c = SPAD[0x8B];
        if (c == 0) {
            if (v != 0 && v != 0x7F) {
                M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
                if ((u32)(v - 0x19) < 2U) {
                    SPAD[0x8B] = 2;
                } else {
                    SPAD[0x8B] = 0x3C;
                }
            }
        } else {
            t = c - 1;
            SPAD[0x8B] = t;
            if (!(t & 0xFF)) {
                if (D_80097187 == 2) {
                    M2C_FIELD(arg0, void**, 0x58) = &D_8007537C;
                } else {
                    M2C_FIELD(arg0, void**, 0x58) = &D_800752DC;
                }
                M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
            } else if (!(SPAD[0x8B] & 3)) {
                M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
            } else {
                M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
            }
        }
    } else if (v != 0x7F) {
        if (st == 8) {
            if (M2C_FIELD(arg0, s8*, 6) == 0) {
                q = (u8*)&g_Player;
                if (M2C_FIELD(q, s8*, 2) != 0) {
                    if (v != 0) {
                        play_sound(2, 0x3D, arg0);
                        ((void (*)(void*, s32))set_animation)(arg0, 4);
                        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                        M2C_FIELD(arg0, s8*, 5) = 8;
                        M2C_FIELD(arg0, s8*, 6) = 1;
                        SPAD[0x8B] = 0x1E;
                    }
                } else if (q[0xE7] == 2) {
                    if ((u32)(v - 0x33) < 2U || v == 0x2F) {
                        play_sound(2, 0x3D, arg0);
                        ((void (*)(void*, s32))set_animation)(arg0, 4);
                        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                        M2C_FIELD(arg0, s8*, 5) = 8;
                        M2C_FIELD(arg0, s8*, 6) = 1;
                        SPAD[0x8B] = 0x64;
                    }
                } else if (v == 2 || v == 4 || v == 5 || v == 6 || v == 7 ||
                           v == 8 || v == 9 || v == 0xB || v == 0xC ||
                           v == 0xD || v == 0xE || v == 0xF || v == 0x10 ||
                           v == 0x11 || v == 0x12 || v == 0x36 || v == 0x2E ||
                           v == 0x35) {
                    play_sound(2, 0x3D, arg0);
                    ((void (*)(void*, s32))set_animation)(arg0, 4);
                    M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                    M2C_FIELD(arg0, s8*, 5) = 8;
                    M2C_FIELD(arg0, s8*, 6) = 1;
                    SPAD[0x8B] = 0x64;
                }
            }
        } else if (st != 0xC) {
            if ((u32)(v - 0x13) < 3U || v == 0x2F || v == 0x39 || v == 0x2C ||
                v == 0x22 || v == 0x23 || v == 0x24 || v == 0x25 || v == 0x2B ||
                v == 0x2D) {
                play_sound(2, 0x3D, arg0);
                play_sound(2, 0x14, arg0);
                SPAD[0x86] = M2C_FIELD(arg0, u8*, 5);
                SPAD[0x87] = M2C_FIELD(arg0, u8*, 6);
                SPAD[0x8B] = 0;
                if (D_80097187 == 2) {
                    M2C_FIELD(arg0, void**, 0x58) = &D_8007537C;
                } else {
                    M2C_FIELD(arg0, void**, 0x58) = &D_800752DC;
                }
                M2C_FIELD(arg0, s8*, 5) = 8;
                M2C_FIELD(arg0, s8*, 6) = 0;
            }
        }
    }
    D_800FB850[M2C_FIELD(arg0, s8*, 5)](arg0);
    ((void (*)(void*))func_80030ECC)(arg0);
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if (M2C_FIELD(arg0, s8*, 5) != 2) {
            M2C_FIELD(arg0, s32*, 0x90) += 1;
        }
        p = (u8*)&g_Player;
        if (M2C_FIELD(p, s8*, 0x5C) == -0x80) {
            M2C_FIELD(p, s8*, 0x5C) = 1;
        }
        n = 9;
        if (M2C_FIELD(arg0, s8*, 5) != n) {
            if ((M2C_FIELD(p, s8*, 0x5C) & 0x7F) < 2) {
                func_8003D308(0x14, p[0x15]);
                M2C_FIELD(p, s8*, 0x5C) = 1;
                goto block_73;
            }
            if (M2C_FIELD(arg0, s32*, 0x90) >= 0x385) {
                func_8003D308(0x14, p[0x15]);
            block_73:
                M2C_FIELD(arg0, s8*, 5) = n;
                M2C_FIELD(arg0, s8*, 6) = 0;
            }
        }
    }
    if (M2C_FIELD(SPAD, s8*, 0x89) != 0) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        r = SPAD;
        if (--M2C_FIELD(r, s8*, 0x89) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007523C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        } else if (!(SPAD[0x89] & 3)) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    if (M2C_FIELD(arg0, s8*, 5) != 2) {
        func_8002CCB0(arg0, 0x80, 0x80);
    }
}

#include "../shared/rock_02/func_800F1F50.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

void* alloc_class3_slot();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800FBC7C;

void func_800F205C(void* arg0) {
    void* child;
    s8 prev;

    if (g_Player.unk5 == 0x14) {
        child = alloc_class3_slot();
        if (child != 0) {
            M2C_FIELD(child, u8*, 0) = 1;
            M2C_FIELD(child, u8*, 1) = 0x18;
            M2C_FIELD(SPAD4C, void**, 0x80) = child;
        }
        prev = background_objects[0].unk48;
        background_objects[0].unk48 = 1;
        D_800FBC7C = prev;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            background_objects[0].unk24 = 0x17B0;
            background_objects[0].unk26 = 0x17B0;
            background_objects[0].unk4C = 1;
        }
        M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk26 + 0xF0;
        M2C_FIELD(arg0, s16*, 0xE) = background_objects[0].unk2A - 0x40;
        if (g_Player.x_pos.i.hi <= background_objects[0].unk26 + 0x40 &&
            g_Player.x_pos.i.hi >= background_objects[0].unk26 + 0x20) {
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
        } else {
            M2C_FIELD(arg0, s16*, 0x7C) = 1;
            if (g_Player.x_pos.i.hi > background_objects[0].unk26 + 0x30) {
                func_8003D308(0x1D, 0);
            } else {
                func_8003D308(0x1D, 0x40);
            }
        }
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
#undef g_Player

#include "../shared/rock_02/func_800F21B0.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_80017A04();
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800F22E8(void* arg0) {
    void* p;
    s8 k;

    move_object((s32)arg0);
    ((void (*)(void*))func_80017A04)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) > background_objects[0].unk2A + 0x60) {
        p = func_8002C458();
        if (p != 0) {
            M2C_FIELD(p, u8*, 0) = 0x41;
            M2C_FIELD(p, u8*, 1) = 0x15;
            M2C_FIELD(p, u8*, 2) = 3;
            M2C_FIELD(p, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(p, s16*, 0xE) = background_objects[0].unk22 + 0xC0;
            M2C_FIELD(p, s16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(p, s32*, 0x3C) =
                SPAD20 + *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 +
                                 SPAD20 + 4);
            M2C_FIELD(p, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
            M2C_FIELD(p, void**, 0x7C) = arg0;
        }
        k = M2C_FIELD(arg0, s8*, 2);
        if (k == 0) {
            open_text_box(4, 0xFF, 0);
        } else {
            if (k == 1) {
                u8* e = (u8*)&g_playthrough_state;
                open_text_box(1, 0xFF, e[0x2E]);
                e[0x2E] = 1;
            } else {
                u8* e = (u8*)&g_playthrough_state;
                open_text_box(0, 0xFF, e[0x2E]);
                e[0x2E] = 1;
            }
        }
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "../shared/rock_02/func_800F2438.c"

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
extern M2C_UNK D_8007433C;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800CCF5C;
extern u8 D_800FB810[];

#define SPAD (*(u8**)0x1F80004C)

void func_800F2584(void* arg0) {
    s8 st;
    u32 r;
    u8* p;

    r = random_byte() & 0xF;
    st = M2C_FIELD(arg0, s8*, 2);
    if (st == 0) {
        if (r < 2) {
            SPAD[0x84] = 0;
        } else if (r < 7) {
            SPAD[0x84] = 2;
        } else {
            SPAD[0x84] = 3;
        }
    } else if (st == 1) {
        u8* e = (u8*)&g_playthrough_state;
        if (M2C_FIELD(arg0, s8*, 0x5C) >= (s8)((s8)e[0x8C] / 3) * 2) {
            if (r < 8) {
                SPAD[0x84] = 4;
            } else {
                SPAD[0x84] = 6;
            }
        } else if (M2C_FIELD(arg0, s8*, 0x5C) >= (s8)((s8)e[0x8C] / 3)) {
            if (r < 5) {
                SPAD[0x84] = 4;
            } else if (r < 0xB) {
                SPAD[0x84] = 5;
            } else {
                SPAD[0x84] = 6;
            }
        } else {
            goto dead;
        }
        {
            u8* e2 = (u8*)&g_playthrough_state;
            if (M2C_FIELD(arg0, s8*, 0x5C) < (s8)((s8)e2[0x8C] / 3)) {
            dead:
                M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                SPAD[0x8B] = 0x3C;
                M2C_FIELD(arg0, u8*, 5) = 0xC;
                M2C_FIELD(arg0, u8*, 6) = 0;
                return;
            }
        }
    } else if (st == 2) {
        if (M2C_FIELD(arg0, s8*, 0x5C) >= (s8)((s8)D_800CCF5C / 3) * 2) {
            if (r < 5) {
                SPAD[0x84] = 7;
            } else if (r < 0xA) {
                SPAD[0x84] = 8;
            } else {
                SPAD[0x84] = 9;
            }
        } else if (M2C_FIELD(arg0, s8*, 0x5C) >= (s8)((s8)D_800CCF5C / 3)) {
            if (r < 3) {
                SPAD[0x84] = 8;
            } else if (r < 7) {
                SPAD[0x84] = 0xA;
            } else if (r < 0xC) {
                SPAD[0x84] = 0xB;
            } else {
                SPAD[0x84] = 0xC;
            }
        }
    }
    SPAD[0x85] = 0;
    p = SPAD;
    M2C_FIELD(arg0, u8*, 5) = D_800FB810[(p[0x85] & 3) + p[0x84] * 4];
    M2C_FIELD(arg0, u8*, 6) = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern s16 D_80097222;
extern s32 D_800FB2E8;

void func_800F2864(void* arg0) {
    u8* sp;
    u8 t;

    sp = SPAD4C;
    t = sp[0x8B];
    if (t != 0) {
        sp[0x8B] = t - 1;
        if (!(SPAD4C[0x8B] & 3)) {
            M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) | 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        }
    }
    if (D_80097222 + 0x20 < M2C_FIELD(arg0, s16*, 0xE)) {
        M2C_FIELD(arg0, void**, 0x68) = &D_800FB2E8;
    }
    ((void (*)(void*))func_80017A04)(arg0);
    ((void (*)(void*))func_8002D230)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        func_80012D9C(3);
        play_sound(2, 0x1B, arg0);
        play_sound(2, 0x21, arg0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x5A;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        func_80029478(0x5A, 2, 2);
        SPAD4C[0x8B] = 0x78;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];

void func_800F2984(void* arg0) {
    u8* sp;
    u8 t;

    sp = SPAD4C;
    t = sp[0x8B];
    if (t != 0) {
        sp[0x8B] = t - 1;
        if (!(SPAD4C[0x8B] & 3)) {
            M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) | 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        }
        sp = SPAD4C;
        if (sp[0x8B] == 0) {
            sp[0x8B] = 0x78;
        }
    }
    ((void (*)(void*))func_80017A04)(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        ((void (*)(void*))move_object)(arg0);
        if (background_objects[0].unk22 - 0x40 >= M2C_FIELD(arg0, s16*, 0xE)) {
            M2C_FIELD(arg0, s16*, 0xE) = background_objects[0].unk22 - 0x40;
            if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                M2C_FIELD(arg0, s16*, 0xA) =
                    background_objects[0].unk1C + 0x100;
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            } else {
                M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk1E + 0x40;
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            }
            M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
            SPAD4C[0x8B] = 0x78;
        }
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK move_object(s32);
extern u16 D_8009721A;
extern u8 D_800FB810[];

void func_800F2AC8(void* arg0) {
    u8 t;

    t = SPAD4C[0x8B];
    if (t != 0) {
        SPAD4C[0x8B] = t - 1;
        if (!(SPAD4C[0x8B] & 3)) {
            M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) | 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        }
        if (SPAD4C[0x8B] == 0) {
            SPAD4C[0x8B] = 0x78;
        }
    }
    ((void (*)(s32))move_object)((s32)arg0);
    {
        // !FAKE: depin: dropping it breaks the match (67/71)
        register s32 lim asm("$3") = (s16)D_8009721A + 0x40;
        // !FAKE: depin: dropping it breaks the match (64/71)
        register s32 c asm("$4") = M2C_FIELD(arg0, s16*, 0xE) < lim;
        if (!c) {
            M2C_FIELD(arg0, s16*, 0xE) = D_8009721A + 0x40;
            SPAD4C[0x89] = 0x3C;
            t = ++SPAD4C[0x85];
            M2C_FIELD(arg0, u8*, 5) = D_800FB810[(t & 3) + SPAD4C[0x84] * 4];
            M2C_FIELD(arg0, u8*, 6) = 0;
        }
    }
}

#include "../shared/rock_02/func_800F2BE4.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)
#define SPAD20 (*(s32*)0x1F800020)

s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK move_object(s32);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
M2C_UNK func_800F82C0();
extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];

void func_800F2D08(void* arg0) {
    void* child;
    s32 base;
    s32 r;

    move_object((s32)arg0);
    if ((M2C_FIELD(arg0, s16*, 0xA) <= background_objects[0].unk1E + 0x110 &&
         M2C_FIELD(arg0, s16*, 0xA) > background_objects[0].unk1E + 0xF0 &&
         M2C_FIELD(arg0, s16*, 0xE) <= background_objects[0].unk22 + 0x70 &&
         M2C_FIELD(arg0, s16*, 0xE) > background_objects[0].unk22 + 0x50) ||
        M2C_FIELD(SPAD4C, u8*, 0x88) != 0) {
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            child = func_8002C458();
            if (child != 0) {
                M2C_FIELD(child, u8*, 0) = 0x41;
                M2C_FIELD(child, u8*, 1) = 0x15;
                M2C_FIELD(child, u8*, 2) = 3;
                M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
                M2C_FIELD(child, s16*, 0xE) =
                    background_objects[0].unk22 + 0xC0;
                M2C_FIELD(child, u16*, 0x42) =
                    M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(child, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                r = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
                base = SPAD20;
                M2C_FIELD(child, s32*, 0x3C) = base + *(s32*)(r * 4 + base + 4);
                M2C_FIELD(child, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(child, void**, 0x7C) = arg0;
            }
            M2C_FIELD(SPAD4C, u8*, 0x88) = 1;
            M2C_FIELD(arg0, s16*, 0x7C) = 1;
        }
        func_800F82C0(arg0);
    }
    if (D_800970AA <= background_objects[0].unk1E + 0x70 &&
        D_800970AA >= background_objects[0].unk1E + 0x50) {
        func_8003D308(0x14, 0x40);
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK move_object(s32);
M2C_UNK func_800F82C0();
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800F2EBC(void* arg0) {
    void* p;
    s16 x;
    s16 y;

    move_object((s32)arg0);
    x = M2C_FIELD(arg0, s16*, 0xA);
    if ((background_objects[0].unk1E + 0x110 >= x &&
         background_objects[0].unk1E + 0xF0 < x &&
         (y = M2C_FIELD(arg0, s16*, 0xE),
          background_objects[0].unk22 + 0x70 >= y) &&
         background_objects[0].unk22 + 0x50 < y) ||
        SPAD4C[0x88] != 0) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            p = func_8002C458();
            if (p != 0) {
                M2C_FIELD(p, u8*, 0) = 0x41;
                M2C_FIELD(p, u8*, 1) = 0x15;
                M2C_FIELD(p, u8*, 2) = 3;
                M2C_FIELD(p, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
                M2C_FIELD(p, s16*, 0xE) = background_objects[0].unk22 + 0xC0;
                M2C_FIELD(p, s16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(p, s32*, 0x3C) =
                    SPAD20 +
                    *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 +
                            SPAD20 + 4);
                M2C_FIELD(p, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
                M2C_FIELD(p, void**, 0x7C) = arg0;
            }
        }
        func_800F82C0(arg0);
        {
            // !FAKE: depin: dropping it breaks the match (92/96)
            register void* e asm("$2") = &g_playthrough_state;
            M2C_FIELD(e, u8*, 0x24) = 0;
            M2C_FIELD(e, s32*, 0x20) = 0;
        }
        {
            // !FAKE: depin: dropping it breaks the match (93/96)
            register s32 t asm("$3") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
        open_text_box(5, 0xFF, 0);
    }
}

#include "../shared/rock_02/func_800F303C.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD4C (*(s8**)0x1F80004C)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];

void func_800F3164(void* arg0) {
    struct X4_MainObj* self = arg0;
    s8* p = SPAD4C;

    if (p[0x89] == 0) {
        p[0x89] = 0x78;
    }
    ((void (*)(void*))move_object)(arg0);
    if (self->x_speed < 0) {
        if (background_objects[0].unk1E + 0x70 >= self->x_pos.i.hi &&
            self->unk15 == 0) {
            self->unk15 = 0x40;
        }
        if (background_objects[0].unk1E + 0x40 >= self->x_pos.i.hi) {
            self->x_pos.i.hi = background_objects[0].unk1E + 0x40;
            self->unk15 = 0x40;
            ((void (*)(s32, s32, void*))play_sound)(2, 0x23, self);
            ((void (*)(void*, s32))set_animation)(self, 0x12);
            self->unk6++;
        }
    } else {
        if (self->x_pos.i.hi >= background_objects[0].unk1C + 0xD0 &&
            self->unk15 != 0) {
            self->unk15 = 0;
        }
        if (self->x_pos.i.hi >= background_objects[0].unk1C + 0x100) {
            self->x_pos.i.hi = background_objects[0].unk1C + 0x100;
            self->unk15 = 0;
            ((void (*)(s32, s32, void*))play_sound)(2, 0x23, self);
            ((void (*)(void*, s32))set_animation)(self, 0x12);
            self->unk6++;
        }
    }
}

#include "../shared/rock_02/func_800F32B8.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];

void func_800F33C0(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (46/51)
    register s32 x asm("$5");
    // !FAKE: depin: dropping it breaks the match (47/51)
    register s32 l asm("$4");

    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
        x = background_objects[0].unk1E;
        l = x - 0x140;
        if (M2C_FIELD(arg0, s16*, 0xA) >=
            x + (background_objects[0].unk1C - l) / 2) {
            return;
        }
    } else {
        x = background_objects[0].unk1E;
        l = x - 0x140;
        if (x + (background_objects[0].unk1C - l) / 2 >=
            M2C_FIELD(arg0, s16*, 0xA)) {
            return;
        }
    }
    play_sound(2, 0x23, arg0);
    set_animation(arg0, 7);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    {
        // !FAKE: depin: dropping it breaks the match (48/51)
        register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
        M2C_FIELD(arg0, u8*, 6) = t;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK func_800F82C0();

void func_800F348C(void* arg0) {
    void* child;
    // !FAKE: depin: dropping it breaks the match (87/94)
    register s32 t asm("$2");

    func_800F82C0();
    func_80017A04(arg0);
    t = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = t + 1;
    if ((s16)t >= 0x3D) {
        if (M2C_FIELD(arg0, s8*, 2) == 1) {
            play_sound(2, 0x3D, arg0);
            play_sound(2, 0x23, arg0);
            child = func_8002C458();
            if (child != 0) {
                M2C_FIELD(child, u8*, 0) = 0x41;
                M2C_FIELD(child, u8*, 1) = 0x15;
                M2C_FIELD(child, u8*, 2) = 7;
                M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
                M2C_FIELD(child, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                M2C_FIELD(child, u16*, 0x42) =
                    M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(child, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(child, s32*, 0x3C) =
                    SPAD20 + *(s32*)(func_8002A47C(0x37) * 4 + SPAD20 + 4);
                M2C_FIELD(child, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(child, void**, 0x7C) = arg0;
            }
        } else if (M2C_FIELD(arg0, s8*, 2) == 2 &&
                   M2C_FIELD(arg0, s8*, 7) == 0) {
            play_sound(2, 0x3D, arg0);
            play_sound(2, 0x23, arg0);
            M2C_FIELD(arg0, s8*, 7) = 1;
            child = func_8002C458();
            if (child != 0) {
                M2C_FIELD(child, u8*, 0) = 0x41;
                M2C_FIELD(child, u8*, 1) = 0x15;
                M2C_FIELD(child, u8*, 2) = 0xB;
                M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
                M2C_FIELD(child, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                M2C_FIELD(child, u16*, 0x42) =
                    M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(child, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(child, s32*, 0x3C) =
                    SPAD20 + *(s32*)(func_8002A47C(0x37) * 4 + SPAD20 + 4);
                M2C_FIELD(child, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(child, void**, 0x7C) = arg0;
            }
        }
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(s32);
extern u16 D_8009721A;
extern u8 D_800FB810[];

void func_800F3604(void* arg0) {
    s32 t;
    s32 v;

    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= (s16)D_8009721A + 0x40) {
        M2C_FIELD(arg0, s16*, 0xE) = D_8009721A + 0x40;
        if (SPAD4C[0x8A] != 0x11) {
            M2C_FIELD(arg0, u8*, 5) = 0xE;
            M2C_FIELD(arg0, u8*, 6) = 0;
            SPAD4C[0x85]++;
            return;
        }
        if (--M2C_FIELD(arg0, s16*, 0x7E) != 0) {
            set_animation(arg0, 7);
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
            M2C_FIELD(arg0, u8*, 6) = 1;
            return;
        }
        t = SPAD4C[0x85] + 1;
        SPAD4C[0x85] = t;
        v = D_800FB810[(t & 3) + SPAD4C[0x84] * 4];
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 5) = v;
    }
}

#include "../shared/rock_02/func_800F370C.c"

#include "common.h"
#include "psyq/libgte.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
extern s32 D_8007429C;
extern M2C_UNK D_8007433C;
extern s32 D_8007541C;
extern s32 D_800754BC;
extern s32 D_80075B9C;
extern M2C_UNK g_Player;
extern s32 D_800FB300;
extern M2C_UNK D_800FB304;
extern s32 D_800FB308;
extern s32 D_800FB30C;
extern s32 D_800FB314;
extern s32 D_800FB318;

void func_800F38F4(void* arg0) {
    void* s2;
    s8 t;
    s32 ang;
    s32 v;
    s32 c;
    s32 d;
    void* g;
    s32 a;
    s32 b;

    s2 = M2C_FIELD(arg0, void**, 0x7C);
    g = &g_Player;
    M2C_FIELD(arg0, u8*, 4) = 1;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, void**, 0x54) = 0;
    M2C_FIELD(arg0, void**, 0x50) = 0;
    M2C_FIELD(arg0, void**, 0x68) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = M2C_FIELD(g, u8*, 0x14);
    t = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, u8*, 0x16) = 4;
    M2C_FIELD(arg0, u8*, 0x15) = M2C_FIELD(s2, u8*, 0x15);
    if (t == 0) {
        M2C_FIELD(arg0, u8*, 0x60) = 6;
        M2C_FIELD(arg0, u8*, 0x5C) = 1;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007429C;
        M2C_FIELD(arg0, void**, 0x54) = &D_800FB300;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FB30C;
        M2C_FIELD(arg0, void**, 0x68) = &D_800FB318;
        ang = ratan2(M2C_FIELD(g, s16*, 0xE) - M2C_FIELD(arg0, s16*, 0xE),
                     M2C_FIELD(g, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0xA));
        if (M2C_FIELD(s2, s8*, 2) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) * 32;
            M2C_FIELD(arg0, s32*, 0x24) = -rsin(ang) * 32;
        } else {
            c = rcos(ang);
            v = c * 16;
            M2C_FIELD(arg0, s32*, 0x20) = c * 64 + v;
            d = -rsin(ang);
            v = d << 4;
            M2C_FIELD(arg0, s32*, 0x24) = (d << 6) + v;
        }
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0xA);
        M2C_FIELD(arg0, u8*, 5) = 0;
        M2C_FIELD(arg0, u8*, 0x8D) = 8;
    } else if (t == 1) {
        M2C_FIELD(arg0, u8*, 0x60) = 0xC;
        M2C_FIELD(arg0, u8*, 0x5C) = 8;
        M2C_FIELD(arg0, void**, 0x58) = &D_800754BC;
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0xC);
        M2C_FIELD(arg0, u8*, 5) = 1;
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        M2C_FIELD(arg0, s16*, 0x90) = 0;
        play_sound(2, 0x1F, arg0);
        if (M2C_FIELD(s2, s8*, 2) == 0) {
            M2C_FIELD(arg0, s16*, 0x42) =
                (((func_8002A47C(M2C_FIELD(s2, s8*, 1)) + 1) * 4 + 0x20) % 16) |
                (((func_8002A47C(M2C_FIELD(s2, s8*, 1)) + 9) / 4 + 0x1E0) << 6);
            a = func_8002A47C(M2C_FIELD(s2, s8*, 1)) * 4 + 0x20;
            load_palette(func_8002A47C(M2C_FIELD(s2, s8*, 1)) * 4 + 0x24,
                         (M2C_UNK*)(SPAD28 + a * 32), 4);
        } else {
            M2C_FIELD(arg0, s16*, 0x42) = 0x794C;
            load_palette(0x5C, (M2C_UNK*)(SPAD28 + 0xB00), 4);
        }
    } else if (t == 2) {
        M2C_FIELD(arg0, u8*, 0x60) = 0xC;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, void**, 0x54) = &D_800FB300;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FB30C;
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0xD);
        M2C_FIELD(arg0, u8*, 0x8D) = 0x14;
        M2C_FIELD(arg0, u8*, 5) = 2;
    } else if (t == 3) {
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0xE);
        M2C_FIELD(arg0, u8*, 5) = 4;
        M2C_FIELD(arg0, s16*, 0xA) += 8;
        play_sound(2, 0x1A, arg0);
    } else if (t == 4) {
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0xF);
        M2C_FIELD(arg0, u8*, 5) = 5;
        M2C_FIELD(arg0, u8*, 0x16) = 6;
    } else if (t == 5) {
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0x10);
        M2C_FIELD(arg0, u8*, 5) = 5;
    } else if (t == 6) {
        M2C_FIELD(arg0, u8*, 0x60) = 0xC;
        play_sound(2, 0x1F, arg0);
        M2C_FIELD(arg0, void**, 0x50) = &D_800FB30C;
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0x14);
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(s2, s16*, 0xA);
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(s2, s16*, 0xE) - 0x18;
        M2C_FIELD(arg0, u8*, 0x16) = 6;
        M2C_FIELD(arg0, u8*, 5) = 6;
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        M2C_FIELD(arg0, u8*, 3) = 1;
        play_sound(2, 0x1F, arg0);
        M2C_FIELD(arg0, s16*, 0x42) = 0x794C;
        load_palette(0x5C, (M2C_UNK*)(SPAD28 + 0xB00), 4);
    } else if (t == 7) {
        M2C_FIELD(arg0, u8*, 0x60) = 0xC;
        play_sound(2, 0x1F, arg0);
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0xC);
        M2C_FIELD(arg0, void**, 0x58) = &D_80075B9C;
        M2C_FIELD(arg0, void**, 0x54) = &D_800FB304;
        M2C_FIELD(arg0, u8*, 5) = 7;
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        M2C_FIELD(arg0, u8*, 3) = 1;
        M2C_FIELD(arg0, s16*, 0x42) = 0x794C;
        load_palette(0x5C, (M2C_UNK*)(SPAD28 + 0xB00), 4);
    } else if (t == 8) {
        M2C_FIELD(arg0, u8*, 0x60) = 0xC;
        M2C_FIELD(arg0, void**, 0x54) = &D_800FB300;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FB30C;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0xD);
        M2C_FIELD(arg0, u8*, 0x8D) = 0x18;
        M2C_FIELD(arg0, u8*, 5) = 7;
        M2C_FIELD(arg0, u8*, 6) = 2;
    } else if (t == 9) {
        M2C_FIELD(arg0, u8*, 0x60) = 0xC;
        M2C_FIELD(arg0, u8*, 0x5C) = 0x20;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007541C;
        M2C_FIELD(arg0, void**, 0x54) = &D_800FB308;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FB314;
        if (M2C_FIELD(s2, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(s2, s16*, 0xA) - 0x30;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(s2, s16*, 0xA) + 0x30;
        }
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(s2, s16*, 0xE);
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0x11);
        M2C_FIELD(arg0, u8*, 3) = 1;
        M2C_FIELD(arg0, u8*, 5) = 8;
    } else if (M2C_FIELD(arg0, s8*, 2) == 10) {
        M2C_FIELD(arg0, u8*, 0x60) = 0xC;
        M2C_FIELD(arg0, u8*, 0x5C) = 0x20;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007541C;
        M2C_FIELD(arg0, void**, 0x54) = &D_800FB308;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FB314;
        if (M2C_FIELD(s2, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(s2, s16*, 0xA) - 0x30;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(s2, s16*, 0xA) + 0x30;
        }
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(s2, s16*, 0xE);
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0x11);
        M2C_FIELD(arg0, u8*, 3) = 1;
        M2C_FIELD(arg0, u8*, 5) = 8;
    } else if (M2C_FIELD(arg0, s8*, 2) == 11) {
        M2C_FIELD(arg0, u8*, 0x60) = 0xC;
        M2C_FIELD(arg0, u8*, 0x5C) = 2;
        play_sound(2, 0x1F, arg0);
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0xC);
        M2C_FIELD(arg0, u8*, 5) = 9;
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        M2C_FIELD(arg0, u8*, 3) = 1;
        M2C_FIELD(arg0, void**, 0x58) = &D_80075B9C;
        M2C_FIELD(arg0, s16*, 0x42) = 0x794C;
        load_palette(0x5C, (M2C_UNK*)(SPAD28 + 0xB00), 4);
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 func_8002A47C(s32);
void* func_8002C458();
s32 random_byte();
s32 check_enemy_hits(void*);
extern void (*D_800FBA40[])(void*);

void func_800F3EE0(void* arg0) {
    void* child;
    void* p;
    s32 i;
    s32 r;
    s32 v;

    p = M2C_FIELD(arg0, void**, 0x7C);
    v = M2C_FIELD(p, s8*, 4);
    if (v == 2) {
        M2C_FIELD(arg0, s8*, 4) = v;
        play_sound(2, 0x14, arg0);
        return;
    }
    v = check_enemy_hits(arg0);
    if (v != 0x7F && v != 0) {
        if (M2C_FIELD(arg0, u8*, 0x8E) == 0) {
            M2C_FIELD(arg0, u8*, 0x8E) = 0x32;
        }
    }
    if (v < 0 && M2C_FIELD(arg0, s8*, 6) != 4) {
        r = random_byte() & 0x2D;
        for (i = 0; i < 4; i++) {
            child = func_8002C458();
            if (child != 0) {
                s16 ang;
                s32 t;
                s32 t2;
                s32 w;
                p = M2C_FIELD(arg0, void**, 0x7C);
                M2C_FIELD(child, u8*, 0) = 0x41;
                M2C_FIELD(child, u8*, 1) = 0x15;
                M2C_FIELD(child, u8*, 2) = 8;
                M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
                M2C_FIELD(child, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                if (M2C_FIELD(p, s8*, 2) == 0) {
                    M2C_FIELD(child, u16*, 0x42) =
                        ((func_8002A47C(M2C_FIELD(p, s8*, 1)) * 4 + 0x20) %
                         16) |
                        (((func_8002A47C(M2C_FIELD(p, s8*, 1)) + 8) / 4 + 0x1E0)
                         << 6);
                } else {
                    M2C_FIELD(child, u16*, 0x42) = 0x7948;
                }
                M2C_FIELD(child, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(child, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                M2C_FIELD(child, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(child, s32*, 0x7C) = M2C_FIELD(arg0, s32*, 0x7C);
                ang = ((i * 90 + r) << 12) / 360;
                t = rcos(ang);
                w = t * 16;
                M2C_FIELD(child, s32*, 0x20) = t * 32 + w;
                t2 = rsin(ang);
                w = t2 * 16;
                M2C_FIELD(child, s32*, 0x24) = t2 * 32 + w;
                M2C_FIELD(child, u8*, 7) = (i + 1) * 0x28;
            }
        }
        M2C_FIELD(arg0, u8*, 6) = 4;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s16*, 0x90) = 0;
        M2C_FIELD(arg0, u8*, 0x47) = 0xE;
        M2C_FIELD(arg0, u8*, 0) |= 0x10;
        play_sound(2, 0x14, arg0);
        play_sound(2, 0x7C, arg0);
    }
    D_800FBA40[M2C_FIELD(arg0, s8*, 6)](arg0);
}

#include "../shared/rock_02/func_800F4194.c"

#include "../shared/rock_02/func_800F4480.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_8009721A;

M2C_UNK move_object(s32);
void func_800F4620(void* arg0) {
    void* parent;
    u8 t;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())func_80017A04)();
    ((M2C_UNK(*)())move_object)(arg0);
    t = M2C_FIELD(arg0, u8*, 0x8D);
    if (t == 0) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        if (M2C_FIELD(parent, s8*, 5) == 0xF) {
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, u8*, 0x8D) = 0x3C;
            M2C_FIELD(arg0, s16*, 0xE) = D_8009721A + 0x68;
            M2C_FIELD(arg0, u8*, 6) += 1;
            return;
        }
        if (M2C_FIELD(parent, s8*, 5) == 0x10) {
            if (M2C_FIELD(arg0, s8*, 2) == 9) {
                if (M2C_FIELD(parent, u8*, 0x15) != 0) {
                    {
                        s16 v = background_objects[0].unk1E - 0x16;
                        M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
                        M2C_FIELD(arg0, s16*, 0xA) = v;
                    }
                } else {
                    goto right;
                }
            } else if (M2C_FIELD(parent, u8*, 0x15) == 0) {
                {
                    s16 v = background_objects[0].unk1E - 0x16;
                    M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
                    M2C_FIELD(arg0, s16*, 0xA) = v;
                }
            } else {
            right: {
                s16 v = background_objects[0].unk1C + 0x157;
                M2C_FIELD(arg0, s32*, 0x20) = 0xFFFD0000;
                M2C_FIELD(arg0, s16*, 0xA) = v;
            }
            }
            {
                s16 e = background_objects[0].unk22 + 0x68;
                M2C_FIELD(arg0, u8*, 0x8D) = 0x3A;
                M2C_FIELD(arg0, u8*, 6) = 3;
                M2C_FIELD(arg0, s16*, 0xE) = e;
            }
            return;
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        if (M2C_FIELD(parent, s8*, 6) >= 3) {
            {
                // !FAKE: depin: dropping it breaks the match (102/107)
                register s32 vel2 asm("$2");
                // !FAKE: depin: dropping it breaks the match (103/107)
                register s32 c asm("$2") = M2C_FIELD(parent, u8*, 0x15);
                if (c != 0) {
                    vel2 = 0x30000;
                } else {
                    vel2 = 0xFFFD0000;
                }
                M2C_FIELD(arg0, s32*, 0x20) = vel2;
            }
            M2C_FIELD(arg0, u8*, 0x8D) = 0;
            M2C_FIELD(arg0, u8*, 6) = 3;
        }
    } else {
        if (--M2C_FIELD(arg0, u8*, 0x8D) == 0 &&
            M2C_FIELD(parent, s8*, 5) == 0x11) {
            play_sound(2, 0x7F, arg0);
        }
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
extern s16 D_800970AA;
#define D_800970AA (*(u16*)&D_800970AA)
extern s32 D_800FB308;
extern s32 D_800FB314;

void func_800F47CC(void* arg0) {
    void* parent;
    u8 t;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())func_80017A04)();
    if (M2C_FIELD(arg0, s8*, 2) == 9) {
        if (M2C_FIELD(arg0, u8*, 0x8D) >= 0xB) {
            if (M2C_FIELD(parent, u8*, 0x15) != 0) {
                M2C_FIELD(arg0, s16*, 0xA) = D_800970AA - 0x30;
                M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
            } else {
                M2C_FIELD(arg0, s16*, 0xA) = D_800970AA + 0x30;
                M2C_FIELD(arg0, s32*, 0x20) = 0xFFFD0000;
            }
        }
    } else if (M2C_FIELD(arg0, u8*, 0x8D) >= 0xB) {
        if (M2C_FIELD(parent, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) = D_800970AA - 0x30;
            M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = D_800970AA + 0x30;
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFD0000;
        }
    }
    t = M2C_FIELD(arg0, u8*, 0x8D);
    if (t != 0) {
        M2C_FIELD(arg0, u8*, 0x8D) = t - 1;
        M2C_FIELD(arg0, u8*, 3) ^= 1;
        return;
    }
    M2C_FIELD(arg0, void**, 0x54) = &D_800FB308;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FB314;
    M2C_FIELD(arg0, u8*, 3) = 1;
    M2C_FIELD(arg0, u8*, 0x8D) = 8;
    M2C_FIELD(arg0, u8*, 6)++;
}
#undef D_800970AA

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK move_object(s32);

void func_800F48EC(void* arg0) {
    void* parent;
    void* p;
    s32 base;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())func_80017A04)();
    move_object((s32)arg0);
    if (M2C_FIELD(parent, s8*, 5) == 0x11) {
        if (M2C_FIELD(arg0, s8*, 2) == 9) {
            p = func_8002C458();
            if (p != 0 && (u8)(M2C_FIELD(arg0, u8*, 0x8D) % 20) == 0) {
                M2C_FIELD(p, s8*, 0) = 0x41;
                M2C_FIELD(p, s8*, 1) = 0x15;
                M2C_FIELD(p, s8*, 2) = 0;
                if (M2C_FIELD(parent, u8*, 0x15) == 0) {
                    M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) - 0x18;
                } else {
                    M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + 0x18;
                }
                M2C_FIELD(p, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                M2C_FIELD(p, s16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                base = func_8002A47C(0x37);
                M2C_FIELD(p, s32*, 0x3C) =
                    SPAD20 + *(s32*)(base * 4 + SPAD20 + 4);
                M2C_FIELD(p, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
                M2C_FIELD(p, void**, 0x7C) = parent;
                play_sound(2, 0x1C, parent);
            }
        }
        if ((u8)++M2C_FIELD(arg0, u8*, 0x8D) >= 0x4D) {
            M2C_FIELD(arg0, u8*, 0x8D) = 0x28;
            play_sound(2, 0x80, arg0);
            M2C_FIELD(arg0, u8*, 6) = 6;
        }
    } else {
        if ((u8)--M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            play_sound(2, 0x7F, arg0);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0xFFFD0000;
            M2C_FIELD(arg0, u8*, 6)++;
        }
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 check_enemy_hits(void*);
extern void (*D_800FBA70[])(void*);

void func_800F4AB8(void* arg0) {
    void* parent;
    s32 r;
    s8 k;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    r = check_enemy_hits(arg0);
    if (M2C_FIELD(parent, s8*, 6) == 5) {
        k = M2C_FIELD(parent, s8*, 5);
        if (k != 0xD && M2C_FIELD(arg0, s8*, 6) < 7) {
            if (k == 0x10) {
                M2C_FIELD(arg0, s8*, 6) = 8;
            } else {
                if (M2C_FIELD(arg0, s8*, 2) == 9) {
                    M2C_FIELD(parent, u8*, 0x8A) &= 0xF0;
                } else {
                    M2C_FIELD(parent, u8*, 0x8A) &= 0xF;
                }
                M2C_FIELD(arg0, s32*, 0x54) = 0;
                M2C_FIELD(arg0, s32*, 0x50) = 0;
                M2C_FIELD(arg0, u8*, 0x8D) = 0x5A;
                M2C_FIELD(arg0, s8*, 6) = 7;
            }
        }
    }
    if (r < 0 || M2C_FIELD(parent, s8*, 5) == 0xC) {
        if (M2C_FIELD(arg0, s8*, 6) != 7) {
            if (M2C_FIELD(arg0, s8*, 2) == 9) {
                M2C_FIELD(parent, u8*, 0x8A) &= 0xF0;
                M2C_FIELD(parent, u8*, 0x8D)--;
            } else {
                M2C_FIELD(parent, u8*, 0x8A) &= 0xF;
                M2C_FIELD(parent, u8*, 0x8E)--;
            }
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, u8*, 0x8D) = 0x5A;
            M2C_FIELD(arg0, s8*, 6) = 7;
        }
    }
    D_800FBA70[M2C_FIELD(arg0, s8*, 6)](arg0);
    if (M2C_FIELD(parent, s8*, 5) == 0xB) {
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 0x18);
        M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void* func_8002C458();
s32 random_byte();
s32 check_enemy_hits(void*);
extern u8 D_800CCF38;
extern void (*D_800FBA98[])(void*);

void func_800F4C44(void* arg0) {
    void* child;
    s32 i;
    s32 r;

    if (check_enemy_hits(arg0) < 0 && M2C_FIELD(arg0, s8*, 6) != 4) {
        r = random_byte() & 0x2D;
        if (D_800CCF38 >= 2) {
            for (i = 0; i < 6; i++) {
                child = func_8002C458();
                if (child != 0) {
                    s16 ang;
                    s32 t;
                    s32 v;
                    M2C_FIELD(child, u8*, 0) = 0x41;
                    M2C_FIELD(child, u8*, 1) = 0x15;
                    M2C_FIELD(child, u8*, 2) = 8;
                    M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
                    M2C_FIELD(child, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                    M2C_FIELD(child, u16*, 0x42) = 0x7948;
                    M2C_FIELD(child, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                    M2C_FIELD(child, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                    M2C_FIELD(child, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                    M2C_FIELD(child, s32*, 0x7C) = M2C_FIELD(arg0, s32*, 0x7C);
                    ang = ((i * 60 + r) << 12) / 360;
                    t = rcos(ang);
                    v = t * 16;
                    M2C_FIELD(child, s32*, 0x20) = t * 32 + v;
                    t = rsin(ang);
                    v = t * 16;
                    t = t * 32 + v;
                    M2C_FIELD(child, s32*, 0x24) = t;
                    M2C_FIELD(child, u8*, 7) = (i + 1) * 0x28;
                }
            }
        } else {
            for (i = 0; i < 4; i++) {
                child = func_8002C458();
                if (child != 0) {
                    s16 ang;
                    s32 t;
                    s32 v;
                    M2C_FIELD(child, u8*, 0) = 0x41;
                    M2C_FIELD(child, u8*, 1) = 0x15;
                    M2C_FIELD(child, u8*, 2) = 8;
                    M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
                    M2C_FIELD(child, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                    M2C_FIELD(child, u16*, 0x42) = 0x7948;
                    M2C_FIELD(child, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                    M2C_FIELD(child, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                    M2C_FIELD(child, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                    M2C_FIELD(child, s32*, 0x7C) = M2C_FIELD(arg0, s32*, 0x7C);
                    ang = ((i * 90 + r) << 12) / 360;
                    t = rcos(ang);
                    v = t * 16;
                    M2C_FIELD(child, s32*, 0x20) = t * 32 + v;
                    t = rsin(ang);
                    v = t * 16;
                    t = t * 32 + v;
                    M2C_FIELD(child, s32*, 0x24) = t;
                    M2C_FIELD(child, u8*, 7) = (i + 1) * 0x28;
                }
            }
        }
        M2C_FIELD(arg0, u8*, 6) = 2;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s16*, 0x90) = 0;
        M2C_FIELD(arg0, u8*, 0x47) = 0xE;
        M2C_FIELD(arg0, u8*, 0) |= 0x10;
        play_sound(2, 0x14, arg0);
        play_sound(2, 0x7C, arg0);
    }
    D_800FBA98[M2C_FIELD(arg0, s8*, 6)](arg0);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK clear_object_slot();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern M2C_UNK g_Player;
extern void (*D_800FBAA4[])(void*);

void func_800F4F44(void* arg0) {
    void* p;
    u8* g;
    s8 t;

    p = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    t = M2C_FIELD(p, s8*, 4);
    if (t == 2) {
        M2C_FIELD(arg0, s8*, 4) = t;
        play_sound(2, 0x14, arg0);
        return;
    }
    if (M2C_FIELD(p, s8*, 5) == 8 && M2C_FIELD(p, s8*, 6) > 0) {
        if (M2C_FIELD(arg0, s8*, 2) == 6 || M2C_FIELD(arg0, s8*, 2) == 9 ||
            M2C_FIELD(arg0, s8*, 2) == 10) {
            if (M2C_FIELD(arg0, s8*, 2) == 9) {
                M2C_FIELD(p, u8*, 0x8A) &= 0xF0;
            } else if (M2C_FIELD(arg0, s8*, 2) == 10) {
                M2C_FIELD(p, u8*, 0x8A) &= 0xF;
            }
            M2C_FIELD(arg0, s8*, 4) = 2;
            play_sound(2, 0x14, arg0);
            return;
        }
    }
    D_800FBAA4[M2C_FIELD(arg0, s8*, 5)](arg0);
    if (M2C_FIELD(arg0, s8*, 5) == 4 || M2C_FIELD(arg0, s8*, 5) == 5) {
        goto tail;
    }
    {
        ((void (*)(void*))func_80030ECC)(arg0);
        if (M2C_FIELD(p, s8*, 2) == 0) {
            g = (u8*)&g_Player;
            if (M2C_FIELD(g, s8*, 0x5C) == -0x80) {
                M2C_FIELD(g, s8*, 0x5C) = 1;
            }
            if ((M2C_FIELD(g, s8*, 0x5C) & 0x7F) < 2) {
                M2C_FIELD(g, s8*, 0x5C) = 1;
                func_8003D308(0x14, M2C_FIELD(g, u8*, 0x15));
                play_sound(2, 0x14, arg0);
                clear_object_slot(arg0);
                return;
            }
        }
        if (func_8002CBFC(arg0, 0x60, 0x40) == 0) {
            if (M2C_FIELD(arg0, s8*, 2) == 9 || M2C_FIELD(arg0, s8*, 2) == 10) {
                return;
            }
        tail:
            func_8002CCB0(arg0, 0x40, 0x40);
        } else {
            if (M2C_FIELD(arg0, s8*, 2) == 1 || M2C_FIELD(arg0, s8*, 2) == 6 ||
                M2C_FIELD(arg0, s8*, 2) == 7) {
                play_sound(2, 0x14, arg0);
            }
            if (M2C_FIELD(arg0, s8*, 2) != 9 && M2C_FIELD(arg0, s8*, 2) != 10) {
                M2C_FIELD(arg0, s8*, 4) = 2;
            }
        }
    }
}
