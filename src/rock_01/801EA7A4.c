#include "common.h"

extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern s8 D_8009742C;
extern s16 D_80097430;
extern s8 D_800CF850;
extern s16 D_800CF854;
extern s32 D_801EF974[];

void func_801EA7A4(u8* self) {
    s16* a;
    s16* b;
    s16* c;
    s8* p;
    s8* q;
    s8* r;
    u32 v;
    s32 t;
    s32 i;

    a = &D_800CF854;
    v = (u16)a[1];
    if (v < 0x1F) {
        b = &D_80097430;
        c = &D_80090D5C;
        t = v + 2;
        a[1] = t;
        b[1] += 0x40;
        c[1] += 0x800;
        if ((u16)t >= 0x1F) {
            a[1] = 0x1F;
            b[1] = 0x3E0;
            c[1] = 0x7C00;
            self[6]++;
            for (i = 0; i < 16; i++) {
                D_801EF974[i] = D_80090C90[i + 16];
                D_80090C90[i + 16] = -1;
            }
            p = &D_80090D56;
            q = &D_8009742C;
            r = &D_800CF850;
            p[1] = 0;
            q[1] = 0;
            r[1] = 0;
            self[0xE1] = 0;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_VisualObj* find_free_visual_obj(void);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern struct X4_PlayerObj g_Player;
extern s8 D_8009742C;
extern s8 D_800CF850;
extern s32 D_801EF974[];

void func_801EA888(u8* arg0) {
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s32 kind;
    struct X4_PlayerObj* player;
    u8* obj;

    if (++arg0[0xE1] >= 2) {
        arg0[0xE1] = 0;
        for (i = 0; i < 16; i++) {
            D_80090C90[i + 16] = D_801EF974[i];
        }
        {
            s8* p0 = &D_80090D56;
            s8* p1 = &D_8009742C;
            s8* p2 = &D_800CF850;
            p0[1] = 1;
            p1[1] = 1;
            p2[1] = 1;
        }
        player = &g_Player;
        kind = 0;
        if (player->character != 0) {
            a = 0x53;
            b = 0x54;
        } else {
            a = 0x55;
            b = 0x56;
        }
        j = 0;
        do {
            j++;
            obj = (u8*)find_free_visual_obj();
            if (obj != 0) {
                // !FAKE: pin the halfword constant to the first return register
                register s32 x asm("$2") = 0x80;
                // !FAKE: pin the shifted counter to the second return register
                register s32 y asm("$3") = j << 6;
                obj[0] = 1;
                obj[1] = 0x11;
                obj[2] = kind;
                obj[0x47] = a;
                M2C_FIELD(obj, s16*, 0xA) = x;
                M2C_FIELD(obj, s16*, 0xE) = y;
                obj[5] = player->action;
            }
            obj = (u8*)find_free_visual_obj();
            if (obj != 0) {
                // !FAKE: pin the halfword constant to the first return register
                register s32 x asm("$2") = 0x180;
                // !FAKE: pin the shifted counter to the second return register
                register s32 y asm("$3") = j << 6;
                obj[0] = 1;
                obj[1] = 0x11;
                obj[2] = kind;
                obj[0x47] = b;
                M2C_FIELD(obj, s16*, 0xA) = x;
                M2C_FIELD(obj, s16*, 0xE) = y;
                obj[5] = player->action;
            }
        } while (j < 5);
        arg0[6]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void* func_8002C32C();
struct X4_VisualObj* find_free_visual_obj(void);

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(u16*)((u8*)(p) + (o)))

void func_801EAA24(u8* arg0, s8 arg1) {
    u8* v;
    u8* w;

    if (SB(arg0, 7) == 0) {
        w = func_8002C32C();
        if (w != 0) {
            B(w, 0) = 0x21;
            B(w, 1) = 0x2C;
            H(w, 0xA) = H(arg0, 0xA);
            B(w, 0x14) = B(arg0, 0x14);
        }
        v = (u8*)find_free_visual_obj();
        if (v != 0) {
            B(v, 0) = 0x21;
            B(v, 1) = 0x1A;
            H(v, 0xA) = H(arg0, 0xA);
            B(v, 0x14) = B(arg0, 0x14);
        }
    } else {
        w = func_8002C32C();
        if (w != 0) {
            B(w, 0) = 0x21;
            B(w, 1) = 0x2C;
            H(w, 0xA) = H(arg0, 0xA) - (arg1 << 5);
            B(w, 0x14) = B(arg0, 0x14);
        }
        v = (u8*)find_free_visual_obj();
        if (v != 0) {
            B(v, 0) = 0x21;
            B(v, 1) = 0x1A;
            H(v, 0xA) = H(arg0, 0xA) - (arg1 << 5);
            B(v, 0x14) = B(arg0, 0x14);
        }
        w = func_8002C32C();
        if (w != 0) {
            B(w, 0) = 0x21;
            B(w, 1) = 0x2C;
            H(w, 0xA) = H(arg0, 0xA) + (arg1 << 5);
            B(w, 0x14) = B(arg0, 0x14);
        }
        v = (u8*)find_free_visual_obj();
        if (v != 0) {
            B(v, 0) = 0x21;
            B(v, 1) = 0x1A;
            H(v, 0xA) = H(arg0, 0xA) + (arg1 << 5);
            B(v, 0x14) = B(arg0, 0x14);
        }
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK set_pose_size();
extern s16 D_80090D5C;
extern s16 D_80097430;
extern s16 D_800CF854;

void func_801EABB4(u8* arg0) {
    u16* q0 = (u16*)&D_800CF854;
    u16 t = q0[1];
    u16* q3;
    if (t != 0) {
        u16* q1;
        u16* q2;
        q0[1] = t - 8;
        q1 = (u16*)&D_80097430;
        q2 = (u16*)&D_80090D5C;
        q1[1] -= 0x100;
        q2[1] -= 0x2000;
        if ((u16)(t - 8) < 8) {
            q2[1] = 0;
            q1[1] = 0;
            q0[1] = 0;
            arg0[0xE4] &= 0xFE;
            D_800C4560 |= 1;
        }
    }
    if (((s8*)arg0)[0x46] != 0) {
        return;
    }
    q3 = (u16*)&D_800CF854;
    if (q3[1] == 0) {
        arg0[0x93] = 0;
        arg0[0x8E] = 0;
        arg0[0xE0] = 0;
        if (((s8*)arg0)[0xD3] == 0) {
            D_800CCEEC = 0;
            arg0[0x7A] = 0;
        }
        set_pose_size(arg0);
        arg0[6]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
void* func_8002C32C();
s32 player_check_dash_jump_walk(struct X4_PlayerObj* self);
void func_801ECE60(void* arg0);

void func_801EACAC(u8* arg0) {
    u8* obj;
    s8 flag;
    s8 state;

    state = ((s8*)arg0)[6];
    if (state == 0) {
        arg0[6]++;
    } else if (state == 1) {
        ((void (*)())animate_object)(arg0);
        if (((s8*)arg0)[0x45] & 0x80) {
            obj = func_8002C32C();
            if (obj != 0) {
                obj[0] = 0x21;
                obj[1] = 0x3A;
                obj[0x14] = arg0[0x14];
                obj[0x15] = arg0[0x15];
            }
            if (*(s32*)(arg0 + 0x144) != 6) {
                arg0[6] += 2;
            } else {
                arg0[7] = 0;
                arg0[6]++;
            }
            play_sound(1, 0xE, arg0);
        }
    } else if (state == 2) {
        arg0[7]++;
        if ((s8)(((s8)arg0[7]) % 3) == 0) {
            obj = func_8002C32C();
            if (obj != 0) {
                obj[0] = 0x21;
                obj[1] = 0x3A;
                obj[0x14] = arg0[0x14];
                obj[0x15] = arg0[0x15];
                play_sound(1, 0xE, arg0);
            }
        }
        if (((s8*)arg0)[7] >= 0xC) {
            arg0[6]++;
        }
    } else {
        flag = ((s8*)arg0)[0x45];
        if (flag == 1 && ((s8*)arg0)[0xD3] == 0) {
            arg0[0x8E] = 0;
            if (player_check_dash_jump_walk((struct X4_PlayerObj*)arg0) != 0) {
                return;
            }
            arg0[0x8E] = flag;
        }
        animate_object(arg0);
        func_801ECE60(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
s32 random_byte();
s32 func_80039C40(void*);
s32 check_crouch_input(void*);
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK player_clear_dash();
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
s32 func_801EB12C(void*);
M2C_UNK func_801EC95C(void*);
s32 func_801ECCD4(void*);
M2C_UNK func_801ECD3C(void*);
M2C_UNK func_801ECD54(void*, M2C_UNK);
M2C_UNK func_801ECD90(void*, M2C_UNK);
s32 func_801ECE08(void*);
void func_801ECE60(void* arg0);
void func_801EAE7C(void* arg0);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))

s32 start_rekkoha(u8* arg0);
static inline s32 func_801EAE7C_try_a(void* arg0) {
    if (F_S8(arg0, 0xD3) != 0) {
        return 0;
    }
    if (!(F_U8(arg0, 0xC9) & 4)) {
        return 0;
    }
    if (!(F_U16(arg0, 0x7C) & 4)) {
        return 0;
    }
    if (!(F_U16(arg0, 0x80) & 0x10)) {
        return 0;
    }
    F_U8(arg0, 0x8E) = 1;
    player_set_animation(arg0, 0x5A);
    func_801ECD90(arg0, 0x1A);
    func_801ECD90(arg0, 0x22);
    play_sound(1, 7, arg0);
    play_sound(1, 0x16, arg0);
    play_sound_unless_low_health(arg0, 5);
    player_clear_dash(arg0);
    F_U8(arg0, 5) = 0x37;
    F_U8(arg0, 6) = 0;
    func_801ECD3C(arg0);
    func_801EC95C(arg0);
    return 1;
}

static inline s32 func_801EAE7C_try_b(void* arg0) {
    if (F_S8(arg0, 0xD3) == 0) {
        F_U8(arg0, 0xDD) = 1;
        if (((s32(*)())start_rekkoha)(arg0) != 0) {
            return 1;
        }
        F_U8(arg0, 0xDD) = 0;
    }
    return 0;
}

static inline s32 func_801EAE7C_try_c(void* arg0) {
    if (func_801ECCD4(arg0) == 0) {
        return 0;
    }
    player_set_animation(arg0, 0x58);
    play_sound(1, 7, arg0);
    if (random_byte() & 4) {
        play_sound_unless_low_health(arg0, 3);
    }
    F_U8(arg0, 0x84) = 0;
    F_U8(arg0, 0x86) = 0;
    F_U8(arg0, 5) = 0x30;
    F_U8(arg0, 6) = 0;
    func_801EAE7C(arg0);
    return 1;
}

void func_801EAE7C(void* arg0) {
    if (F_S8(arg0, 6) == 0) {
        F_S8(arg0, 6)++;
    } else {
        animate_object(arg0);
        if (F_U8(arg0, 0x17) == 0x5C) {
            func_801ECD54(arg0, 0x1C);
        } else {
            func_801ECD54(arg0, 0x18);
        }
        if (!(F_U8(arg0, 0x45) & 1) && F_S8(arg0, 0xCB) < 2 &&
            func_801EAE7C_try_a(arg0)) {
            return;
        }
        if (func_801EB12C(arg0) != 0) {
            return;
        }
    }
    if (F_S8(arg0, 0xD3) == 0) {
        F_U8(arg0, 0x8E) = 0;
        if (!(F_U8(arg0, 0x45) & 1)) {
            if (func_80039C40(arg0) != 0) {
                return;
            }
            if (F_S8(arg0, 0xCB) < 2) {
                if (check_crouch_input(arg0) != 0) {
                    return;
                }
                if (F_U8(arg0, 0x45) & 0x40) {
                    if (func_801EAE7C_try_b(arg0)) {
                        return;
                    }
                    if (func_801EAE7C_try_c(arg0)) {
                        return;
                    }
                    if (func_801ECE08(arg0) != 0) {
                        return;
                    }
                }
            }
        }
        F_U8(arg0, 0x8E) = 1;
    }
    func_801ECE60(arg0);
}

#undef F_S8
#undef F_U8
#undef F_U16

// clang-format off
INCLUDE_ASM("asm/rock_01/nonmatchings/1EA000", func_801EB12C);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
s32 select_air_dash(void*);
s32 try_enter_wall_cling(void*);
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK player_set_animation_frame(void*, M2C_UNK, s8);
s32 func_801ECCD4(void*);
M2C_UNK func_801ECD54(void*, M2C_UNK);
void func_801EB324(s8* p);

#define U8(o) (((u8*)p)[o])
#define U16(o) (*(u16*)((u8*)p + (o)))
#define S32(o) (*(s32*)((u8*)p + (o)))

static inline s32 try_switch_801EB324(s8* p) {
    if (func_801ECCD4(p) == 0) {
        return 0;
    }
    if (p[0x86] == 6) {
        player_set_animation(p, 0x60);
        play_sound(1, 7, p);
        p[5] = 0x35;
    } else {
        player_set_animation(p, 0x5B);
        play_sound(1, 8, p);
        p[5] = 0x31;
    }
    p[6] = 0;
    func_801EB324(p);
    return 1;
}

void func_801EB324(s8* p) {
    s8 saved;

    if (func_80039984(p) != 0) {
        return;
    }
    if (p[6] == 0) {
        U8(6)++;
    } else {
        animate_object(p);
        if (p[5] == 0x35) {
            func_801ECD54(p, 0x1D);
        }
        if (p[5] == 0x31) {
            func_801ECD54(p, 0x1B);
        }
    }
    if (p[0xD3] != 0) {
        S32(0x24) = 0;
    }
    if (U8(0x89) & 4) {
        S32(0x24) = 0;
    }
    if (!(U16(0x7C) & 0x80)) {
        S32(0x24) = 0;
    }
    if (p[0x8E] != 0 && p[0x46] == 0) {
        p[0x8E] = 0;
    }
    if (try_switch_801EB324(p) != 0) {
        return;
    }
    saved = p[0x8E];
    p[0x8E] = 0;
    if (U8(0x45) & 0x40) {
        if (try_switch_801EB324(p) != 0) {
            return;
        }
    }
    if (p[0x8B] == 0) {
        if (try_grab_ladder_from_air(p) != 0) {
            return;
        }
        if (try_enter_wall_cling(p) != 0) {
            return;
        }
        if (select_air_dash(p) != 0) {
            return;
        }
    } else {
        U8(0x8B)--;
    }
    p[0x8E] = saved;
    set_air_x_velocity(p);
    func_8003D394(p);
    if (S32(0x24) <= 0) {
        if (p[0x8E] != 0) {
            if (p[5] == 0x31) {
                p[5] = 0x32;
            } else {
                p[5] = 0x36;
            }
            p[6] = 1;
        } else {
            ((void (*)(void*, s32, s8))player_set_animation_frame)(p, 0xB, 5);
            p[0x8A] = 0;
            p[5] = 7;
            p[6] = 0;
        }
        p[0x67] = -1;
    }
}

#undef U8
#undef U16
#undef S32

// clang-format off
INCLUDE_ASM("asm/rock_01/nonmatchings/1EA000", func_801EB5F8);
// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
s32 random_byte();
s32 func_8003A5D8();
M2C_UNK player_enter_ladder_climb_up(void*);
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK player_set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
s32 func_801ECCD4(void*);
void func_801EB934(s8* p);

#define U8(o) (((u8*)p)[o])
#define U16(o) (*(u16*)((u8*)p + (o)))

M2C_UNK func_801ECD54(void*, M2C_UNK);
static inline s32 try_fall_801EB934(s8* p) {
    if (func_801ECCD4(p) == 0) {
        return 0;
    }
    player_set_animation(p, 0x5D);
    play_sound(1, 7, p);
    if (random_byte() & 4) {
        play_sound_unless_low_health(p, 8);
    }
    p[0x84] = 0;
    p[0x86] = 0;
    p[5] = 0x33;
    p[6] = 0;
    func_801EB934(p);
    return 1;
}

void func_801EB934(s8* p) {
    if (func_8003A5D8(p) != 0) {
        p[0x8E] = 0;
        return;
    }
    if (p[6] == 0) {
        p[6]++;
    } else {
        animate_object(p);
    }
    ((void (*)())func_801ECD54)(p, 0x1E);
    if (U8(0x45) & 0x40) {
        p[0x8E] = 0;
        if (try_fall_801EB934(p) != 0) {
            return;
        }
        p[0x8E] = 1;
    }
    if (U16(0x80) & 2) {
        p[0x15] = 0;
    }
    if (U16(0x80) & 1) {
        p[0x15] = 0x40;
    }
    if (p[0x46] == 0) {
        p[0x8E] = 0;
        player_set_animation_frame(p, 0x1F, 2);
        player_enter_ladder_climb_up(p);
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

void* func_8002C32C();
s32 apply_player_motion(void* arg);
s32 select_air_dash(void*);
s32 try_enter_wall_cling(void*);
M2C_UNK player_set_animation(void*, M2C_UNK);
s32 get_weapon_energy_cost(void* arg0, s32 arg1);
void use_weapon_energy(void*, s32);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);

#define F(T, o) (*(T*)((u8*)arg0 + (o)))

void func_801EBA7C(void* arg0) {
    s16 y;
    s16 x;
    u16 t;
    // !FAKE: register pin matches the target's allocation
    register s32 e asm("$2");
    s32 c;
    u8* p;

    if (F(u8, 0x89) & 8) {
        player_set_animation(arg0, 0x63);
        y = F(s16, 0xE);
        e = F(u16, 0xE);
        t = F(u16, 0xA);
        F(u16, 0xE) = e + 0x13;
        do {
        } while (0);
        c = F(u8, 0x15);
        x = F(s16, 0xA);
        if (c != 0) {
            F(u16, 0xA) = t + 0xB;
        } else {
            F(u16, 0xA) = t - 0xB;
        }
        func_80049EBC(arg0, 0, 0xF, 0xF);
        func_80049EBC(arg0, 0, 0xF, 0xF);
        func_80049EBC(arg0, 0, 0xF, 0xF);
        func_80049EBC(arg0, 0, 0xF, 0xF);
        F(s16, 0xA) = x;
        F(s16, 0xE) = y;
        F(u8, 0x67) = 0;
        F(u8, 0x84) = 0;
        F(u8, 0x86) = 0;
        F(u8, 0x8C) = 0;
        if (F(s8, 0xD3) == 0 &&
            get_weapon_energy_cost(arg0, 2) <= F(s16, 0xAC)) {
            F(u8, 0x93) = 2;
            use_weapon_energy(arg0, 2);
            p = func_8002C32C();
            if (p != 0) {
                p[0] = 1;
                p[1] = 4;
                p[0x14] = F(u8, 0x14);
                p[2] = 0;
            }
        }
        F(u8, 6)++;
        return;
    }
    F(u8, 0x8E) = 0;
    if (try_grab_ladder_from_air(arg0) == 0 &&
        try_enter_wall_cling(arg0) == 0 && select_air_dash(arg0) == 0) {
        F(u8, 0x8E) = 1;
        F(s32, 0x20) = 0;
        if (F(s8, 0xD3) == 0) {
            if (F(u16, 0x7C) & 2) {
                F(s32, 0x20) = 0xFFFE8000;
            }
            if (F(u16, 0x7C) & 1) {
                F(s32, 0x20) = 0x18000;
            }
        }
        apply_player_motion(arg0);
        func_8003D394(arg0);
    }
}

#undef F

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
s32 func_80039C40(void*);
s32 check_crouch_input(void*);
s32 check_walk_start_input(void*);
s32 try_enter_ladder(void*);
void func_8003AAD0();
void func_8003AD18(void* arg0);
M2C_UNK start_walk(void*);
void func_8003B870(struct X4_PlayerObj* self);
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
s32 start_rekkoha(u8* arg0);
void func_801EAE7C(void* arg0);
s32 func_801ECCD4(void*);

static inline s32 func_801EBC60_h1(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD3) == 0) {
        M2C_FIELD(arg0, u8*, 0xDD) = 1;
        if (start_rekkoha(arg0) != 0) {
            return 1;
        }
        M2C_FIELD(arg0, u8*, 0xDD) = 0;
    }
    return 0;
}

static inline s32 func_801EBC60_h2(void* arg0) {
    if (func_801ECCD4(arg0) == 0) {
        return 0;
    }
    player_set_animation(arg0, 0x58);
    play_sound(1, 7, arg0);
    if (random_byte() & 4) {
        play_sound_unless_low_health(arg0, 3);
    }
    M2C_FIELD(arg0, u8*, 0x84) = 0;
    M2C_FIELD(arg0, u8*, 0x86) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = 0x30;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    func_801EAE7C(arg0);
    return 1;
}

static inline s32 func_801EBC60_h3(void* arg0) {
    if (try_enter_ladder(arg0) != 0) {
        return 1;
    }
    if (check_crouch_input(arg0) != 0) {
        return 1;
    }
    if (check_walk_start_input(arg0) != 0) {
        start_walk(arg0);
        return 1;
    }
    return 0;
}

void func_801EBC60(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD3) == 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        if (func_80039C40(arg0) != 0) {
            return;
        }
        if (M2C_FIELD(arg0, u8*, 0x45) & 0x40) {
            if (func_801EBC60_h1(arg0) != 0) {
                return;
            }
            if (func_801EBC60_h2(arg0) != 0) {
                return;
            }
            if (func_801EBC60_h3(arg0) != 0) {
                return;
            }
        }
        M2C_FIELD(arg0, u8*, 0x8E) = 1;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        if (D_800CCEDF != 0) {
            func_8003B870(arg0);
            return;
        }
        if (M2C_FIELD(arg0, s8*, 0xD0) != 0) {
            func_8003AAD0(arg0);
            return;
        }
        func_8003AD18(arg0);
    }
}

#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 start_rekkoha(u8* arg0);

s32 try_start_rekkoha(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        return 0;
    }
    M2C_FIELD(arg0, u8*, 0xDD) = 1;
    if (start_rekkoha(arg0) != 0) {
        return 1;
    }
    M2C_FIELD(arg0, u8*, 0xDD) = 0;
    return 0;
}

#include "common.h"
#define M2C_UNK s32

s32 func_801ECCD4(void*);
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
void func_801EAE7C(void* arg0);

s32 func_801EBE54(u8* arg0) {
    if (func_801ECCD4(arg0) == 0) {
        return 0;
    }
    player_set_animation(arg0, 0x58);
    play_sound(1, 7, arg0);
    if (random_byte() & 4) {
        play_sound_unless_low_health(arg0, 3);
    }
    arg0[0x84] = 0;
    arg0[0x86] = 0;
    arg0[5] = 0x30;
    arg0[6] = 0;
    func_801EAE7C(arg0);
    return 1;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK player_clear_dash();
M2C_UNK player_set_animation(void*, M2C_UNK);
s32 random_byte();
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
void func_801EACAC(u8* arg0);

s32 func_801EBEDC(u8* arg0) {
    if (((s8*)arg0)[0xD3] != 0) {
        return 0;
    }
    if (!(*(u16*)(arg0 + 0x80) & 0x20)) {
        return 0;
    }
    if (((s8*)arg0)[0x8E] != 0) {
        return 0;
    }
    arg0[0x8E] = 1;
    arg0[0xCB] = 0;
    player_clear_dash(arg0);
    player_set_animation(arg0, 0x6E);
    if (random_byte() & 4) {
        play_sound_unless_low_health(arg0, 9);
    }
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x24) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    arg0[5] = 0x3E;
    arg0[6] = 0;
    func_801EACAC(arg0);
    return 1;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK player_set_animation(void*, M2C_UNK);
void func_801EB324(s8* p);
s32 func_801ECCD4(void*);

s32 func_801EBF94(void* arg0) {
    s8* p = arg0;
    // !FAKE: pin the arm value to the register retail uses at the join
    register s32 v asm("$3");

    if (func_801ECCD4(p) == 0) {
        return 0;
    }
    if (p[0x86] == 6) {
        player_set_animation(p, 0x60);
        play_sound(1, 7, p);
        v = 0x35;
    } else {
        player_set_animation(p, 0x5B);
        play_sound(1, 8, p);
        v = 0x31;
    }
    p[5] = v;
    p[6] = 0;
    do {
        func_801EB324(p);
    } while (0);
    return 1;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK player_set_animation(void*, M2C_UNK);
s32 func_801EA34C(void* arg0);
void func_801EB5F8(void*);
s32 func_801ECCD4(void*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

s32 func_801EC028(void* arg0) {
    s8 v;

    if (F_S8(arg0, 2) == 0) {
        return 0;
    }
    if (F_S8(arg0, 0xD3) != 0) {
        return 0;
    }
    if (func_801EA34C(arg0) != 0) {
        return 1;
    }
    if (func_801ECCD4(arg0) == 0) {
        return 0;
    }
    v = F_S8(arg0, 0x86);
    if (v == 6) {
        player_set_animation(arg0, 0x60);
        play_sound(1, 7, arg0);
        v = 0x36;
    } else {
        player_set_animation(arg0, 0x5B);
        play_sound(1, 8, arg0);
        v = 0x32;
    }
    F_S8(arg0, 5) = v;
    F_S8(arg0, 6) = 0;
    do {
        func_801EB5F8(arg0);
    } while (0);
    return 1;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
void func_801EB934(s8* p);
s32 func_801ECCD4(void*);

s32 func_801EC0F0(void* arg0) {
    u8* p = arg0;

    if (func_801ECCD4(p) == 0) {
        return 0;
    }
    player_set_animation(p, 0x5D);
    play_sound(1, 7, p);
    if (random_byte() & 4) {
        play_sound_unless_low_health(p, 8);
    }
    p[0x84] = 0;
    p[0x86] = 0;
    p[5] = 0x33;
    p[6] = 0;
    func_801EB934((s8*)p);
    return 1;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
void func_801EC334(u8* arg0);
s32 func_801ECCD4(void*);

s32 func_801EC178(void* arg0) {
    u8* p = arg0;

    if (func_801ECCD4(p) == 0) {
        return 0;
    }
    player_set_animation(p, 0x5E);
    play_sound(1, 7, p);
    if (random_byte() & 4) {
        play_sound_unless_low_health(p, 8);
    }
    p[5] = 0x34;
    p[6] = 0;
    func_801EC334(p);
    return 1;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
void func_801EC68C(void*);
s32 func_801ECCD4(void*);

s32 func_801EC1F8(s8* p) {
    if (!(*(u16*)(p + 0x7C) & 8)) {
        return 0;
    }
    if (func_801ECCD4(p) == 0) {
        return 0;
    }
    player_set_animation(p, 0x69);
    play_sound(1, 7, p);
    if (random_byte() & 4) {
        play_sound_unless_low_health(p, 3);
    }
    p[0x84] = 0;
    p[0x86] = 0;
    p[5] = 0x3C;
    p[6] = 0;
    func_801EC68C(p);
    return 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);

s32 try_start_air_jump(void* arg0) {
    if (!(M2C_FIELD(arg0, u16*, 0x80) & 0x80)) {
        return 0;
    }
    player_set_animation(arg0, 0x5F);
    play_sound(1, 1, arg0);
    play_sound_unless_low_health(arg0, 7);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, u8*, 0x84) = 0;
    M2C_FIELD(arg0, u8*, 0x86) = 6;
    M2C_FIELD(arg0, u8*, 0x8C) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0xF8);
    M2C_FIELD(arg0, s32*, 0x2C) = M2C_FIELD(arg0, s32*, 0x134);
    set_air_x_velocity(arg0);
    M2C_FIELD(arg0, u8*, 0x5) = 6;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    return 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK func_801ECD54(void*, M2C_UNK);

void func_801EC334(u8* arg0) {
    s32 bits;
    s32 flag;

    bits = arg0[0x89];
    if (bits & 8) {
        arg0[0x8E] = 0;
        player_land(arg0);
        return;
    }
    flag = ((s8*)arg0)[0xD3] != 0;
    if (!(bits & 3)) {
        flag = 1;
    }
    if (flag != 0) {
        arg0[0x8E] = 0;
        func_8003AFF4((s32)arg0);
        return;
    }
    if (try_wall_jump(arg0) != 0) {
        arg0[0x8E] = 0;
        return;
    }
    if (is_pressing_into_wall(arg0) != 0) {
        if (((s8*)arg0)[6] == 0) {
            arg0[6]++;
        } else {
            animate_object((struct X4_AnimatedObj*)arg0);
        }
        func_801ECD54(arg0, 0x1F);
        move_by_velocity(arg0);
        func_8003D394(arg0);
        if (((s8*)arg0)[0x46] == 0) {
            arg0[0x8E] = 0;
            ((void (*)(void*, s32))player_set_animation)(arg0, 0xF);
            arg0[5] = 0xB;
            arg0[6] = 0;
        }
    } else {
        arg0[0x8E] = 0;
        func_8003B5B8(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK end_dash(s32);
extern void (*D_801EE3C4[])(void*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

M2C_UNK func_801EC440(void* arg0) {
    if (F_S8(arg0, 0xD3) != 0) {
        F_S8(arg0, 0x8E) = 0;
        end_dash((s32)arg0);
    } else {
        ((void (*)())animate_object)(arg0);
        D_801EE3C4[F_S8(arg0, 0x6)](arg0);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK end_dash(s32);
extern void (*D_801EE3D0[])(void*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

M2C_UNK func_801EC4AC(void* arg0) {
    if (F_S8(arg0, 0xD3) != 0) {
        F_S8(arg0, 0x8E) = 0;
        end_dash((s32)arg0);
        return;
    }
    D_801EE3D0[F_S8(arg0, 0x6)](arg0);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK end_dash(s32);
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK func_801ECD90(void*, M2C_UNK);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_801EC504(void* arg0) {
    if (F_S8(arg0, 0xD3) != 0) {
        F_S8(arg0, 0x8E) = 0;
        end_dash((s32)arg0);
        return;
    }
    if (F_S8(arg0, 0x6) == 0) {
        F_S8(arg0, 0x6) = F_U8(arg0, 0x6) + 1;
    } else {
        ((void (*)())animate_object)(arg0);
        if (!(F_U8(arg0, 0x71) & 8) && (F_U8(arg0, 0x45) & 0x40)) {
            if (F_S8(arg0, 0x7A) != 0) {
                F_S8(arg0, 0x7A) = 0;
            }
            if ((F_U16(arg0, 0x7C) & 8) && (F_U16(arg0, 0x80) & 0x20) &&
                (F_S8(arg0, 0xCB) < 2)) {
                F_S8(arg0, 0xCB) = F_U8(arg0, 0xCB) + 1;
                player_set_animation(arg0, 0x67);
                func_801ECD90(arg0, 0x2A);
            }
        }
    }
    if (F_S8(arg0, 0x46) == 0) {
        F_S8(arg0, 0x8E) = 0;
        F_S8(arg0, 0x7A) = 0;
        end_dash((s32)arg0);
    }
}
