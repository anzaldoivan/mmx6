#include "common.h"

#define M2C_UNK s32

void* func_8002C32C();
s32 get_weapon_energy_cost(void* arg0, s32 arg1);
void use_weapon_energy(void*, s32);

#define F(T, o) (*(T*)((u8*)arg0 + (o)))
M2C_UNK func_801ECBE8(void* arg0) {
    u8* q;

    if (F(s8, 0xD3) != 0) {
        return 0;
    }
    if (!(F(u8, 0xC9) & 0x40)) {
        return 0;
    }
    if (F(s8, 0xA6) == 2) {
        return 0;
    }
    if (get_weapon_energy_cost(arg0, 4) > F(s16, 0xB0)) {
        return 0;
    }
    if (F(s8, 0x8E) != 0) {
        return 0;
    }
    q = func_8002C32C();
    if (q != 0) {
        F(s8, 0xA6) = 2;
        q[0] = 1;
        q[1] = 7;
        q[2] = 0;
        q[0x14] = F(u8, 0x14);
        F(u8, 0x93) = 4;
        use_weapon_energy(arg0, 4);
        {
            // !FAKE: register pin matches the target allocation
            register s32 b asm("$2");
            s32 a = F(u8, 0x98);
            b = F(u8, 0x99);
            F(u8, 0x98) = a + 1;
            F(u8, 0x99) = b + 1;
        }
    }
}
#undef F

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_801ECD3C(void*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))

s32 func_801ECCD4(void* arg0) {
    if (F_S8(arg0, 0x2) == 0) {
        return 0;
    }
    if (F_S8(arg0, 0xD3) != 0) {
        return 0;
    }
    if (!(F_U16(arg0, 0x80) & 0x10)) {
        return 0;
    }
    if (F_S8(arg0, 0x8E) != 0) {
        return 0;
    }
    func_801ECD3C(arg0);
    return 1;
}

#undef F_S8
#undef F_U16

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_801ECD3C(void* arg0) {
    ((u8*)arg0)[0xDD] = 1;
    ((u8*)arg0)[0x8E] = 1;
    ((u8*)arg0)[0xCB] = 0;
    ((u8*)arg0)[0x8C] = 0;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_801ECD90(void*, M2C_UNK);

M2C_UNK func_801ECD54(void* arg0, M2C_UNK arg1) {
    s8 b = arg1;

    if (((s8*)arg0)[0x45] & 0x80) {
        ((u8*)arg0)[0x45] = ((u8*)arg0)[0x45] & 0x7F;
        func_801ECD90(arg0, b);
    }
}

#include "common.h"
#define M2C_UNK s32

void* func_8002C32C();

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))

M2C_UNK func_801ECD90(void* arg0, M2C_UNK arg1) {
    s8 id = arg1;
    u8* obj;

    obj = func_8002C32C();
    {
        // !FAKE: keeps the constant 1 in the branch delay slot
        register s32 one asm("$2") = 1;
        if (obj != 0) {
            obj[0] = one;
            obj[1] = id;
            obj[2] = F_U8(arg0, 0xCB);
            obj[0x14] = F_U8(arg0, 0x14);
            *(s32*)(obj + 0x84) = F_U8(arg0, 0x17);
            obj[0x15] = F_U8(arg0, 0x15);
        }
    }
}

#include "common.h"
#define M2C_UNK s32

s32 check_crouch_input(void*);
s32 check_walk_start_input(void*);
s32 try_enter_ladder(void*);
M2C_UNK start_walk(void*);

s32 func_801ECE08(void* arg0) {
    if (try_enter_ladder(arg0) != 0) {
        return 1;
    }
    if (check_crouch_input(arg0) != 0) {
        return 1;
    }
    if (check_walk_start_input(arg0) == 0) {
        return 0;
    }
    start_walk(arg0);
    return 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_8003AAD0();
void func_8003AD18(void* arg0);
void func_8003B870(struct X4_PlayerObj* self);

void func_801ECE60(void* arg0) {
    s8* p = arg0;

    if (p[0x46] == 0) {
        p[0x8E] = 0;
        if (D_800CCEDF != 0) {
            func_8003B870((struct X4_PlayerObj*)p);
            return;
        }
        if (p[0xD0] != 0) {
            func_8003AAD0(p);
            return;
        }
        func_8003AD18(p);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_801ECD54(void*, M2C_UNK);

#define ECED4_U16(o) (*(u16*)(p + (o)))
#define ECED4_S32(o) (*(s32*)(p + (o)))

void func_801ECED4(s8* p) {
    ((void (*)(void*, s32))func_801ECD54)(p, 0x23);
    if (p[0xD3] == 0) {
        if (ECED4_U16(0x7C) & 2) {
            p[0x15] = 0;
        }
        if (ECED4_U16(0x7C) & 1) {
            p[0x15] = 0x40;
        }
    }
    if (((u8*)p)[0x45] & 0x10) {
        ECED4_S32(0x24) = 0xFFFD0000;
        p[0x45] = 0;
        ECED4_S32(0x20) = 0;
        ECED4_S32(0x28) = 0;
        p[0x67] = -1;
        ECED4_S32(0x2C) = ECED4_S32(0x100);
        p[6]++;
    }
}

#undef ECED4_U16
#undef ECED4_S32

#define func_800F2518 func_801ECF7C
#include "../shared/rock_11/func_800F2518.c"
#undef func_800F2518

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK end_dash(s32);
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK func_801ECD54(void*, M2C_UNK);
extern u16 D_800CCEDC;

void func_801ECF90(void* arg0) {
    s32 var_v1;

    ((void (*)())animate_object)();
    ((void (*)())func_801ECD54)(arg0, 0x24);
    var_v1 = 0xA;
    if (((u8*)arg0)[0x15] != 0) {
        var_v1 = 9;
    }
    if (((u8*)arg0)[0x89] & var_v1) {
        ((void (*)())play_sound)(1, 0x1A, arg0);
        var_v1 = ((s8*)arg0)[0xD3];
        if (var_v1 == 0) {
            ((u8*)arg0)[0x7A] = 0;
        }
        if (((u8*)arg0)[0x89] & 8) {
            if (D_800CCEDC == 0x104) {
                ((void (*)())func_80029478)(0x1E, 2, 1);
            } else {
                ((void (*)())func_8002943C)(0x1E, 2, 1);
            }
            ((void (*)())player_set_animation)(arg0, 0x66);
            ((u8*)arg0)[0xCB] = 1;
            ((void (*)())func_801ECD54)(arg0, 0x24);
            ((u8*)arg0)[0x67] = 0;
            ((u8*)arg0)[0x6]++;
            return;
        }
        ((u8*)arg0)[0x67] = 0;
        ((u8*)arg0)[0x8E] = 0;
        ((void (*)())end_dash)((s32)arg0);
        return;
    }
    ((void (*)())move_by_velocity)(arg0);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK end_dash(s32);

void func_801ED0A0(void* arg0) {
    ((void (*)())animate_object)(arg0);
    if (((s8*)arg0)[0x46] == 0) {
        ((u8*)arg0)[0x8E] = 0;
        end_dash((s32)arg0);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_01/nonmatchings/1EA000", func_801ED0E0);
// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);

void func_801ED150(u8* arg0) {
    if (arg0[0x45] & 0x40) {
        arg0[0xE1] = 0;
        arg0[6]++;
        play_sound(1, 0x1C, arg0);
    }
}

#include "common.h"
#define M2C_UNK s32

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))

void func_801EAA24(u8* arg0, s8 arg1);

void func_801ED198(u8* arg0) {
    u8 t;
    if (SB(arg0, 7) >= 0xB) {
        B(arg0, 0xE1) = 0;
        B(arg0, 6)++;
        return;
    }
    B(arg0, 0xE1)++;
    t = B(arg0, 0xE1);
    if (t % 10 == 1) {
        func_801EAA24(arg0, t / 10);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK player_set_animation(void*, M2C_UNK);

void func_801ED230(u8* arg0) {
    s32 t;

    t = arg0[0xE1] + 1;
    arg0[0xE1] = t;
    if ((u32)(t & 0xFF) >= 0x47U) {
        ((void (*)(void*, s32))player_set_animation)(arg0, 0x6F);
        arg0[6] = arg0[6] + 1;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_01/nonmatchings/1EA000", func_801ED288);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern struct X4_PlayerObj g_Player;
M2C_UNK animate_object();
M2C_UNK clear_object_slot();
M2C_UNK func_801ED3DC();
void func_801ED6F0(u8* self, u8* parent);

void func_801ED2A8(void* arg0) {
    struct X4_PlayerObj* p = &g_Player;
    s32 var_a1;
    u8 id;

    var_a1 = p->hp == 0;
    if (M2C_FIELD(p, s8*, 0xD3) != 0) {
        var_a1 = 1;
    }
    if (M2C_FIELD(p, s8*, 0xCF) != 0) {
        var_a1 = 1;
    }
    if (M2C_FIELD(arg0, s32*, 0x84) != p->unk17) {
        var_a1 = 1;
    }
    id = M2C_FIELD(arg0, u8*, 0x1);
    if (M2C_FIELD(arg0, u8*, 0x15) != p->facing && (u32)(id - 0x18) < 3) {
        var_a1 = 1;
    }
    if ((s8)id == 0x2A &&
        M2C_FIELD(arg0, s8*, 0x2) != M2C_FIELD(p, s8*, 0xCB)) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        // !FAKE: block order, release call placed before the init path
        goto release;
    }
    if (M2C_FIELD(arg0, s8*, 0x4) == 0) {
        // !FAKE: block order, init path placed after the release call
        goto init;
    }
    ((void (*)())animate_object)(arg0);
    if ((M2C_FIELD(arg0, s32*, 0x0) & 0xFFFF00) == 0x2400 ||
        M2C_FIELD(arg0, s8*, 0x46) != 0) {
        // !FAKE: block order, shares the update call tail
        goto update;
    }
release:
    clear_object_slot(arg0);
    return;
init:
    func_801ED3DC(arg0, p);
update:
    func_801ED6F0(arg0, p);
}

// clang-format off
INCLUDE_ASM("asm/rock_01/nonmatchings/1EA000", func_801ED3DC);
// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#include "mmx6/state.h"
extern s32 D_801EE2D4[];
extern s32 D_801EE414[];
extern s32 D_801EE580[];
extern u8 D_801EE68C[][4];

#define ED6F0_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define ED6F0_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define ED6F0_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define ED6F0_U32(p, o) (*(u32*)((u8*)(p) + (o)))
#define ED6F0_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_801ED6F0(u8* self, u8* parent) {
    s8 v = ED6F0_S8(self, 0x45);

    ED6F0_S32(self, 0x8) = ED6F0_S32(parent, 0x8);
    ED6F0_S32(self, 0xC) = ED6F0_S32(parent, 0xC);
    ED6F0_U8(self, 0x15) = ED6F0_U8(parent, 0x15);
    if (v == 0) {
        ED6F0_PTR(self, 0x50) = 0;
    } else if ((ED6F0_S32(parent, 0xEC) & 0x800000) &&
               !(ED6F0_S8(self, 0) & 0x80) &&
               D_801EE68C[ED6F0_S8(self, 1) - 0x18][2] != 0) {
        ED6F0_PTR(self, 0x50) = &D_801EE580[v];
    } else {
        ED6F0_PTR(self, 0x50) = &D_801EE414[ED6F0_S8(self, 0x45)];
    }
    if (ED6F0_S8(self, 1) == 0x24) {
        if (ED6F0_S8(self, 0x45) >= 0x4B && ED6F0_S8(self, 0x45) < 0x50) {
            ED6F0_PTR(self, 0x68) = &D_801EE2D4[ED6F0_S8(self, 0x45)];
        } else {
            ED6F0_PTR(self, 0x68) = 0;
        }
    }
    if (ED6F0_S8(self, 1) == 0x18 || ED6F0_S8(self, 1) == 0x19 ||
        ED6F0_S8(self, 1) == 0x25 || ED6F0_S8(self, 1) == 0x26 ||
        ED6F0_S8(self, 1) == 0x27 || ED6F0_S8(self, 1) == 0x28 ||
        ED6F0_S8(self, 1) == 0x29) {
        ED6F0_U8(self, 0x64) = ED6F0_U8(self, 2) + 1;
    } else if (ED6F0_S8(self, 1) == 0x1A || !(D_80097420.frame_counter & 3)) {
        ED6F0_U8(self, 0x64) = ED6F0_S8(self, 0x45);
    }
    if (ED6F0_S8(self, 1) == 0x23 || ED6F0_S8(self, 1) == 0x24) {
        if (ED6F0_S32(self, 0x90) != 0) {
            ED6F0_S32(self, 0x90)--;
            ED6F0_PTR(self, 0x50) = 0;
        }
        if (ED6F0_S8(self, 0x98) != 0) {
            ED6F0_S8(self, 0x98) = 0;
            ED6F0_S32(self, 0x90) = 2;
            ED6F0_PTR(self, 0x50) = 0;
            ED6F0_U32(self, 0x8C)++;
        }
        if (ED6F0_U32(self, 0x8C) >= 4) {
            ED6F0_PTR(self, 0x50) = 0;
        }
    }
    if (ED6F0_S8(self, 1) == 0x1A && ED6F0_S8(parent, 5) == 0x37) {
        ED6F0_PTR(self, 0x50) = 0;
    }
    func_8002CCB0(self, 0x80, 0x80);
}

#undef ED6F0_S8
#undef ED6F0_U8
#undef ED6F0_S32
#undef ED6F0_U32
#undef ED6F0_PTR

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK clear_object_slot();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
void set_velocity_from_angle(void*, s32);
M2C_UNK func_8002EE10(void*);
void load_buffered_palette(s32, s32, s32);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
extern struct X4_PlayerObj g_Player;
extern s32 D_801EE3E0;
extern s32 D_801EE3E4;
extern s32 D_801EE6F0;

#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801ED928(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    u8* t;
    s32 off;

    player = &g_Player;
    if (arg0->state == 0) {
        arg0->on_screen = 1;
        arg0->unk50 = &D_801EE3E0;
        arg0->unk68 = (struct X4_Unk_unk68*)&D_801EE3E4;
        t = SCRATCH_1C;
        off = *(s32*)(t + 0x34);
        arg0->animation_table = (u32**)&D_8007798C;
        arg0->unk40 = 0;
        arg0->unk42 = 0x7843;
        arg0->unk16 = 1;
        arg0->unk3C = t + off;
        load_buffered_palette(6, 0x13, 1);
        arg0->x_pos.i.hi = player->x_pos.i.hi;
        arg0->y_pos.i.hi = player->y_pos.i.hi + 0x18;
        set_velocity_from_angle(arg0, ((arg0->unk2 * 2) + 0x16) & 0xFE);
        arg0->x_vel.val *= 5;
        arg0->y_vel.val *= 5;
        ((void (*)(void*, s32))set_animation)(arg0, 3);
        arg0->state++;
    } else if (arg0->state == 1 && is_off_screen(arg0, 0x20, 0x20) == 0 &&
               arg0->unk98 == 0) {
        animate_object(arg0);
        ((void (*)(void*))move_object)(arg0);
        arg0->unk64 = arg0->unk2 + 1;
        if (arg0->unk70 == 0) {
            func_8002EE10(arg0);
        }
        if (arg0->unk70 != 0) {
            play_sound(1, 0x15, player);
            func_800477E4(6, &D_801EE6F0, arg0);
            arg0->state++;
            return;
        }
    } else {
        clear_object_slot(arg0);
        return;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
}

// clang-format off
INCLUDE_ASM("asm/rock_01/nonmatchings/1EA000", func_801EDAF4);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK clear_object_slot();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
M2C_UNK func_8002EE10(void*);
void func_800383F8(void*);
extern struct X4_PlayerObj g_Player;
extern s32 D_801EE3E8;
extern s32 D_801EE3FC;

#define SCRATCH_1C (*(u8**)0x1F80001C)
#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_801EDCC8(u8* arg0) {
    struct X4_PlayerObj* pl;
    u8* tbl;
    u8* sc;
    s32 v;
    s32 a;
    s32 b;
    s32 t;
    s8 state;

    pl = &g_Player;
    state = SB(arg0, 4);
    if (state == 0) {
        W(arg0, 0x68) = (s32)&D_801EE3E8;
        W(arg0, 0x50) = (s32)&D_801EE3FC;
        sc = SCRATCH_1C;
        t = W(sc, 0x30);
        W(arg0, 0x30) = (s32)&D_8007798C;
        H(arg0, 0x40) = 0;
        H(arg0, 0x42) = 0x7802;
        B(arg0, 0x16) = 1;
        W(arg0, 0x3C) = (s32)(sc + t);
        if (B(arg0, 0x15) == 0) {
            H(arg0, 0xA) = UH(pl, 0xA) - 0x30;
            if (W(pl, 0xEC) & 0x100) {
                W(arg0, 0x20) = 0xFFF34000;
            } else {
                W(arg0, 0x20) = 0xFFF74000;
            }
        } else {
            H(arg0, 0xA) = UH(pl, 0xA) + 0x30;
            v = 0x80000;
            if (W(pl, 0xEC) & 0x100) {
                v = 0xC0000;
            }
            W(arg0, 0x20) = v | 0xC000;
        }
        H(arg0, 0xE) = UH(pl, 0xE) - 6;
        W(arg0, 0x24) = 0;
        set_animation(arg0, 0);
        W(arg0, 0x84) = H(arg0, 0xA);
        B(arg0, 4)++;
        // !FAKE: shared tail call block placed last, as retail lays it out
        goto tail;
    } else if (state == 1) {
        if (B(arg0, 0x15) == 0) {
            v = UH(pl, 0xA) - 0x30;
        } else {
            v = UH(pl, 0xA) + 0x30;
        }
        H(arg0, 0xA) = v;
        H(arg0, 0xE) = UH(pl, 0xE) - 6;
        ((void (*)())animate_object)(arg0);
        if (SB(arg0, 0x45) & 0x80) {
            B(arg0, 4)++;
        }
        // !FAKE: shared tail call block placed last, as retail lays it out
        goto tail;
    } else if (state == 2) {
        if (is_off_screen(arg0, 0x10, 0x10) != 0 || SB(arg0, 0x98) != 0) {
            // !FAKE: shared dead-path call block before the tail, as retail lays it out
            goto dead;
        }
        W(arg0, 0x68) = (s32)(&D_801EE3E8 + (B(arg0, 0x45) & 0x7F));
        if (B(arg0, 0x70) != 0 || (func_8002EE10(arg0), B(arg0, 0x70) != 0)) {
            func_800383F8(arg0);
            // !FAKE: shared dead-path call block before the tail, as retail lays it out
            goto dead;
        }
        ((void (*)())animate_object)(arg0);
        W(arg0, 0x68) = (s32)(&D_801EE3E8 + (B(arg0, 0x45) & 0x7F));
        move_object(arg0);
        if (pl->action == 0x11) {
            // !FAKE: shared dead-path call block before the tail, as retail lays it out
            goto dead;
        }
        a = H(arg0, 0xA);
        b = W(arg0, 0x84);
        v = b - a;
        if (v >= 0) {
            if (v >= 0xA0) {
                // !FAKE: asymmetric range test keeps the two compares from cross-jumping
                goto inc;
            }
            // !FAKE: shared tail call block placed last, as retail lays it out
            goto tail;
        }
        if (a - b < 0xA0) {
            // !FAKE: shared tail call block placed last, as retail lays it out
            goto tail;
        }
    inc:
        B(arg0, 4)++;
        set_animation(arg0, 1);
        W(arg0, 0x68) = 0;
        W(arg0, 0x50) = 0;
        return;
    } else {
        animate_object(arg0);
        if (is_off_screen(arg0, 0x10, 0x10) != 0 || SB(arg0, 0x46) == 0) {
            // !FAKE: shared dead-path call block before the tail, as retail lays it out
            goto dead;
        }
        // !FAKE: shared tail call block placed last, as retail lays it out
        goto tail;
    }
dead:
    clear_object_slot(arg0);
    return;
tail:
    func_8002CCB0(arg0, 0x10, 0x10);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK clear_object_slot();
M2C_UNK move_object(void*);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_801EE3DC;

#define SCRATCH_1C (*(u8**)0x1F80001C)
#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_801EDFC8(u8* arg0) {
    struct X4_PlayerObj* pl = &g_Player;
    s16 d;
    u8* scr;

    if (SB(arg0, 4) == 0) {
        d = UH(arg0, 0xA) - background_objects[SB(arg0, 0x14)].x_pos.u.hi;
        if ((u16)(d + 0x10) < 0x161) {
            if (SB(arg0, 2) == 0) {
                B(pl, 7)++;
            }
            B(arg0, 3) = 1;
            scr = SCRATCH_1C;
            W(arg0, 0x3C) = (s32)(scr + W(scr, 0x3C));
            W(arg0, 0x30) = (s32)&D_8007798C;
            H(arg0, 0x40) = 0;
            H(arg0, 0x42) = 0x7802;
            B(arg0, 0x16) = 0x11;
            if (SB(arg0, 2) != 0) {
                H(arg0, 0xE) =
                    background_objects[SB(arg0, 0x14)].y_pos.u.hi - 0x120;
                set_animation(arg0, 0xC);
            } else {
                H(arg0, 0xE) =
                    background_objects[SB(arg0, 0x14)].y_pos.u.hi - 0x80;
                W(arg0, 0x50) = (s32)&D_801EE3DC;
                set_animation(arg0, 0xB);
            }
            W(arg0, 0x24) = 0xFFF80000;
            B(arg0, 0x64) = B(arg0, 0x45);
            B(arg0, 4)++;
            return;
        }
        // !FAKE: shared despawn call block
        goto block_16;
    }
    animate_object(arg0, pl);
    move_object(arg0);
    if (!(D_80097420.frame_counter & 7)) {
        B(arg0, 0x64)++;
    }
    if (SB(arg0, 0x98) != 0) {
        B(arg0, 0x98) = 0;
        W(arg0, 0x8C)++;
    }
    if ((u32)W(arg0, 0x8C) >= 4U) {
        W(arg0, 0x50) = 0;
    }
    if (SB(arg0, 2) != 0) {
        if (H(arg0, 0xE) >=
            background_objects[SB(arg0, 0x14)].y_pos.i.hi + 0x190) {
        block_16:
            clear_object_slot(arg0);
        }
    } else if (H(arg0, 0xE) >=
               background_objects[SB(arg0, 0x14)].y_pos.i.hi + 0x170) {
        clear_object_slot(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK clear_object_slot();
M2C_UNK move_object(void*);
extern struct X4_BackgroundObj background_objects[3];

#define SCRATCH_1C (*(u8**)0x1F80001C)
#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_801EE254(u8* arg0) {
    struct X4_BackgroundObj* bg;
    s16 d;
    u8* scr;
    s32 t;

    if (SB(arg0, 4) == 0) {
        {
            struct X4_BackgroundObj* p = background_objects;
            bg = p + SB(arg0, 0x14);
        }
        d = UH(arg0, 0xA) - bg->x_pos.u.hi;
        if ((u16)(d + 0x10) >= 0x161) {
            clear_object_slot(arg0);
            return;
        }
        B(arg0, 3) = 1;
        scr = SCRATCH_1C;
        t = W(scr, 0x3C);
        W(arg0, 0x30) = (s32)&D_8007798C;
        H(arg0, 0x40) = 0;
        H(arg0, 0x42) = 0x7802;
        B(arg0, 0x16) = 0x11;
        W(arg0, 0x3C) = (s32)(scr + t);
        H(arg0, 0xE) = bg->y_pos.u.hi - 0x120;
        ((void (*)())set_animation)(arg0, 0xC, bg);
        W(arg0, 0x24) = 0xFFF80000;
        B(arg0, 4)++;
        return;
    }
    animate_object(arg0);
    move_object(arg0);
    if (H(arg0, 0xE) >= background_objects[SB(arg0, 0x14)].y_pos.i.hi + 0x190) {
        clear_object_slot(arg0);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_01/nonmatchings/1EA000", func_801EE39C);
// clang-format on
