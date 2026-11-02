#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK end_dash(s32);
void func_8003CF54(void*, s32);
M2C_UNK player_spawn_weapon(M2C_UNK, s8, M2C_UNK, void*);
M2C_UNK func_801EC678(); /* extern */
extern s8 D_800CCEEC;

void func_801EC514(void* arg0) {
    if ((func_801EC678() != 0) && (M2C_FIELD(arg0, u8*, 0x45) & 0x40)) {
        if (M2C_FIELD(arg0, s8*, 0xD3) == 0) {
            M2C_FIELD(arg0, s8*, 0x7A) = 0;
        }
        M2C_FIELD(arg0, s8*, 0xE0) = 0;
        D_800CCEEC = 0;
        end_dash((s32)arg0);
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x45) & 0x20) {
        M2C_FIELD(arg0, u8*, 0x45) = 0;
        player_spawn_weapon(1, 0x16, 0, 0);
        func_8003CF54(arg0, 0x49);
        play_sound(1, 0x12, arg0);
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x80000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFF80000;
        }
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D5D0(void*);
M2C_UNK end_dash(s32);
M2C_UNK func_8003C4EC();
M2C_UNK func_801EC678();
extern s8 D_800CCEEC;

void func_801EC5F4(void* arg0) {
    s32 var_v0;
    u8 temp_v1;

    var_v0 = func_801EC678() != 0;
    temp_v1 = M2C_FIELD(arg0, u8*, 0xE1);
    if (temp_v1 == 0) {
        var_v0 = 1;
    }
    if (var_v0 != 0) {
        if (M2C_FIELD(arg0, s8*, 0xD3) == 0) {
            M2C_FIELD(arg0, s8*, 0x7A) = 0;
        }
        M2C_FIELD(arg0, s8*, 0xE0) = 0;
        D_800CCEEC = 0;
        func_8003C4EC(arg0);
        end_dash((s32)arg0);
        return;
    }
    M2C_FIELD(arg0, u8*, 0xE1) = temp_v1 - 1;
    func_8002D5D0(arg0);
}

// clang-format off
INCLUDE_ASM("asm/rock_00/nonmatchings/1EA000", func_801EC678);
// clang-format on

#include "common.h"

void* func_8002C32C();

void func_801EC6D0(void* arg0, s32 arg1) {
    u8* self = arg0;
    s8 id = arg1;
    u8* obj;

    if (((s8*)self)[0x45] & 0x80) {
        self[0x45] &= 0x7F;
        obj = func_8002C32C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = id;
            obj[0x14] = self[0x14];
            *(s32*)(obj + 0x84) = self[0x17];
            obj[0x15] = self[0x15];
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002D5D0(void*);
M2C_UNK end_dash(s32);
M2C_UNK func_8003B9AC(void*);
M2C_UNK func_8003CD9C();

void func_801EC754(u8* arg0) {
    s32 done;
    s32 bits;

    func_8002D5D0(arg0);
    arg0[0x85]--;
    if (((s8*)arg0)[0x85] < 8) {
        arg0[0x7A] = 0;
    }
    done = ((s8*)arg0)[0x85] == 0;
    if (M2C_FIELD(arg0, s32*, 0x24) > 0) {
        bits = arg0[0x89] & 4;
    } else if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
        bits = arg0[0x89] & 8;
    } else if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
        bits = arg0[0x89] & 1;
    } else {
        bits = arg0[0x89] & 2;
    }
    if (bits != 0) {
        done = 1;
    }
    if (done != 0) {
        play_sound(1, 6, arg0);
        arg0[0x7A] = 0;
        if (M2C_FIELD(arg0, s32*, 0x24) < 0 && (arg0[0x89] & 8) &&
            (M2C_FIELD(arg0, u16*, 0x7C) & 8)) {
            arg0[0x67] = 0;
            arg0[0x86] = 0;
            func_8003CD9C(arg0);
            func_8003B9AC(arg0);
            return;
        }
        end_dash((s32)arg0);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003D26C(void*);

void func_801EC878(void* arg0) {
    s32 v;

    if (*(s8*)((u8*)arg0 + 0x46) == 0) {
        v = *(s32*)((u8*)arg0 + 0x24);
        if (v > 0) {
            func_8003BA04(arg0, 0xAC);
        } else if (v < 0) {
            func_8003BA04(arg0, 0xAD);
        } else {
            func_8003BA04(arg0, 0xAB);
        }
        *(u8*)((u8*)arg0 + 0x8C) = 1;
        func_8003D26C(arg0);
        *(u8*)((u8*)arg0 + 6) = *(u8*)((u8*)arg0 + 6) + 1;
    }
}

#include "common.h"

#define M2C_UNK s32

s32 func_8003A0E8();        /* extern */
M2C_UNK func_8003AFF4(s32); /* extern */

void func_801EC908(s32 arg0) {
    if (func_8003A0E8() != 0) {
        func_8003AFF4(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003CCBC(void*); /* extern */
extern s8 D_800CCEEC;

void func_801EC93C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        if (M2C_FIELD(arg0, s8*, 0xD0) == 0) {
            M2C_FIELD(arg0, s8*, 0x7A) = 0;
            D_800CCEEC = 0;
        }
        M2C_FIELD(arg0, s8*, 0xE0) = 0;
        ((void (*)(void*))func_8003CCBC)(arg0);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK end_dash(s32);   /* extern */
M2C_UNK func_8003C4EC(); /* extern */

void func_801EC9A0(s32 arg0) {
    func_8003C4EC();
    end_dash(arg0);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002B2F8(s32);
M2C_UNK func_8002B36C(M2C_UNK);
M2C_UNK clear_object_slot();
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern s8 D_8009742C;
extern s16 D_80097430;
extern s8 D_800CF850;
extern s16 D_800CF854;

void func_801EC9CC(void* arg0) {
    u8 temp_v0;

    if (M2C_FIELD(arg0, s8*, 4) == 0) {
        func_8002B36C(0);
        D_80090D56 = 0;
        D_8009742C = 0;
        D_800CF850 = 0;
        D_800CF854 = 0x1F;
        D_80097430 = 0x3E0;
        D_80090D5C = 0x7C00;
        M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
        return;
    }
    temp_v0 = M2C_FIELD(arg0, u8*, 0x47);
    if (temp_v0 == 0 || (M2C_FIELD(arg0, u8*, 0x47) = --temp_v0) == 0) {
        func_8002B2F8(0);
        clear_object_slot(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK end_dash(s32);

void func_801ECA84(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        ((void (*)())end_dash)();
        return;
    }
    func_80017A04(arg0);
    if (M2C_FIELD(arg0, s8*, 0x99) == 0 || M2C_FIELD(arg0, s8*, 0x93) != 4) {
        end_dash((s32)arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void* func_8002C32C();
extern struct X4_BackgroundObj background_objects[3];

void func_801ECAF4(u8* arg0) {
    u8* obj;
    s32 i;
    s32 dx1;
    s32 dx2;

    func_80017A04((struct X4_AnimatedObj*)arg0);
    {
        // !FAKE: depin: dropping it breaks the match (75/81)
        register s32 one asm("$4");
        one = 1;
        if (((s8*)arg0)[0x46] == 0) {
            s32 k21;
            s32 k11;
            k21 = 0x21;
            k11 = 0x11;
            arg0[6]++;
            dx2 = -0x40;
            dx1 = -0x40;
            i = 4;
            play_sound(one, 0x25, obj);
            do {
                obj = func_8002C32C();
                if (obj != 0) {
                    obj[0] = k21;
                    obj[1] = k11;
                    obj[0x14] = arg0[0x14];
                    *(s16*)(obj + 0xA) = *(s16*)(arg0 + 0xA) + dx1;
                    *(s16*)(obj + 0xE) =
                        background_objects[0].y_pos.i.hi + 0x170;
                }
                obj = func_8002C32C();
                if (obj != 0) {
                    obj[0] = k21;
                    obj[1] = k11;
                    obj[2] = 1;
                    obj[0x14] = arg0[0x14];
                    *(s16*)(obj + 0xA) = *(s16*)(arg0 + 0xA) + dx2;
                    *(s16*)(obj + 0xE) =
                        background_objects[0].y_pos.i.hi + 0x210;
                }
                dx2 += 0x20;
                i--;
                dx1 += 0x20;
            } while (i >= 0);
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK end_dash(s32);        /* extern */
M2C_UNK func_8003CCBC(void*); /* extern */
extern s8 D_800CCEEC;

void func_801ECC38(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x99) == 0) {
        M2C_FIELD(arg0, s8*, 0xE0) = 0;
        if (M2C_FIELD(arg0, s8*, 0xD3) == 0) {
            D_800CCEEC = 0;
            M2C_FIELD(arg0, s8*, 0x7A) = 0;
        }
        func_8003CCBC(arg0);
        end_dash(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003BA04(void*, M2C_UNK);

void func_801ECC94(u8* arg0) {
    if (((s8*)arg0)[7] != 0) {
        ((void (*)(void*, s32))func_8003BA04)(arg0, 0x60);
        arg0[6] = arg0[6] + 1;
    }
}

#include "common.h"
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);

void func_801ECCDC(void* arg0) {
    func_80017A04((struct X4_AnimatedObj*)arg0);
    if (((s8*)arg0)[0x45] & 0x80) {
        ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/weapons/weapon_01_lightning_web.c:lightning_web_release, AGPL-3.0; proven shared with X6 by exact signature 9736cfd16dd5 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK end_dash(s32);
void func_80017A04(struct X4_AnimatedObj*);

void func_801ECD24(struct X4_WeaponObj* arg0) {
    func_80017A04(ANIMATED_OBJECT(arg0));
    if (arg0->animation_step.fields.relative_step == 0) {
        end_dash(arg0);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_801ECD60(void* arg0) {
    M2C_FIELD(arg0, u8*, 0xE1) = (u8)(M2C_FIELD(arg0, u8*, 0xE1) + 1);
    if (M2C_FIELD(arg0, s8*, 7) != 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

void func_801ECD8C(void* arg0) {
    s32 v;

    v = *(u8*)((u8*)arg0 + 0xE1) + 1;
    *(u8*)((u8*)arg0 + 0xE1) = v;
    if ((u32)(v & 0xFF) >= 0x3C) {
        g_playthrough_state.unk16 = 0;
        g_playthrough_state.unk12 = 0;
        g_playthrough_state.unk13 = 0;
        g_playthrough_state.unk19 = 0;
        g_playthrough_state.unk18 = 0;
        g_playthrough_state.unk17 = 0;
        g_playthrough_state.unk14 = 0;
        g_playthrough_state.unk15 = 0;
        g_playthrough_state.gameplay_locked = 0;
        *(u8*)((u8*)arg0 + 6) = *(u8*)((u8*)arg0 + 6) + 1;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK end_dash(); /* extern */

void func_801ECDEC(void) {
    ((M2C_UNK(*)())end_dash)();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK player_spawn_visual(M2C_UNK, M2C_UNK, s8, M2C_UNK);
void func_801EEB7C(struct X4_WeaponObj* arg0);
extern u32* D_8007789C[];
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3790;
extern s32 D_801F37B0;

#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801ECE0C(struct X4_WeaponObj* arg0) {
    u8* sc;
    struct X4_PlayerObj* src;
    struct X4_PlayerObj* player;
    s16 h;
    s32 v;

    arg0->active = 0x21;
    arg0->on_screen = 1;
    arg0->unk68 = (struct X4_Unk_unk68*)&D_801F37B0;
    arg0->unk50 = &D_801F3790;
    sc = SCRATCH_1C;
    v = *(s32*)(sc + 4);
    src = arg0->owner;
    arg0->unk40 = 0;
    arg0->unk16 = 1;
    arg0->animation_table = D_8007789C;
    arg0->unk3C = sc + v;
    player = &g_Player;
    h = 0x7802;
    if (M2C_FIELD(player, s32*, 0xEC) & 0x180) {
        h = 0x7844;
    }
    arg0->unk42 = h;
    if (M2C_FIELD(player, s32*, 0xEC) & 0x40000) {
        arg0->unk42 = 0x7844;
    }
    arg0->unk15 = src->unk15;
    arg0->unk84.word = 0;
    func_801EEB7C(arg0);
    arg0->x_pos.i.lo = 0;
    arg0->y_pos.i.lo = 0;
    if (M2C_FIELD(src, s32*, 0xEC) & 0x100) {
        arg0->x_vel.val = 0x8C000;
    } else {
        arg0->x_vel.val = 0x6C000;
    }
    if (arg0->unk15 == 0) {
        arg0->x_vel.val = -arg0->x_vel.val;
    }
    arg0->unk28.val = 0;
    arg0->y_vel.val = 0;
    arg0->unk2C = 0;
    set_animation(arg0, 0x15);
    arg0->state++;
    func_8002CCB0(arg0, 0xC, 8);
    player_spawn_visual(0x21, 2, 0, 0);
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern s32 D_8009718C;
extern s32 D_801F3794;
extern s32 D_801F37B4;

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_801ECF64(u8* arg0) {
    s32 t;

    B(arg0, 3) = 1;
    if (SB(arg0, 1) == 9) {
        SB(arg0, 2) = 0;
        if (D_8009718C & 0x100) {
            W(arg0, 0x20) = 0xA0000;
        } else {
            W(arg0, 0x20) = 0x80000;
        }
    } else {
        SB(arg0, 2) = 1;
        if (D_8009718C & 0x100) {
            W(arg0, 0x20) = 0xC0000;
        } else {
            W(arg0, 0x20) = 0xA0000;
        }
    }
    t = SB(arg0, 2) * 4;
    W(arg0, 0x68) = t + (s32)&D_801F37B4;
    W(arg0, 0x50) = t + (s32)&D_801F3794;
    if (B(arg0, 0x15) == 0) {
        W(arg0, 0x20) = -W(arg0, 0x20);
    }
    W(arg0, 0x28) = 0;
    W(arg0, 0x24) = 0;
    W(arg0, 0x2C) = 0;
    set_animation(arg0, SB(arg0, 2) + 0x1A);
    B(arg0, 4)++;
    func_8002CCB0(arg0, 0x20, 0x14);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
extern s32 D_80077A80;
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_801F37CC;

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_801ED058(u8* arg0) {
    u8* sc;
    u8* sc2;
    u32 r;
    s32 t;
    s32 x;

    B(arg0, 0) = 1;
    B(arg0, 3) = 1;
    B(arg0, 0x64) = 1;
    W(arg0, 0x50) = (s32)&D_801F37CC;
    sc2 = SCRATCH_14;
    W(arg0, 0x38) = (s32)(sc2 + W(sc2, 0x3C));
    sc = SCRATCH_1C;
    t = W(sc, 0x18);
    W(arg0, 0x30) = (s32)&D_80077A80;
    H(arg0, 0x40) = 0x540;
    H(arg0, 0x42) = 0x7802;
    B(arg0, 0x16) = 0;
    B(arg0, 0x15) = 0;
    W(arg0, 0x20) = 0;
    W(arg0, 0x28) = 0;
    W(arg0, 0x3C) = (s32)(sc + t);
    if (SB(arg0, 2) == 0) {
        W(arg0, 0x24) = 0xFFF40000;
        H(arg0, 0xE) = background_objects[0].y_pos.i.hi - 0x20;
        set_animation(arg0, 2);
    } else {
        W(arg0, 0x24) = 0xC0000;
        H(arg0, 0xE) = background_objects[0].y_pos.i.hi + 0x110;
        set_animation(arg0, 1);
    }
    W(arg0, 0x2C) = 0;
    r = random_byte();
    x = background_objects[0].x_pos.u.hi + 8;
    B(arg0, 5) = 0;
    B(arg0, 4)++;
    H(arg0, 0xA) = (u8)(r % 20) * 16 + x;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern u32* D_8007789C[];
extern s32 D_80077AC8;
extern s32 D_8009718C;
extern s32 D_801F37A4;
extern s32 D_801F37A8;
extern s32 D_801F37BC;

#define SCRATCH_1C (*(u8**)0x1F80001C)
#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_801ED1B8(u8* arg0) {
    u8* sc;
    u8* sc2;
    u8* sub;
    u8* src;
    s32 v;

    B(arg0, 3) = 1;
    sc = SCRATCH_1C;
    W(arg0, 0x3C) = (s32)(sc + W(sc, 0x30));
    sub = arg0 + 0x8C;
    W(arg0, 0x30) = (s32)D_8007789C;
    H(arg0, 0x40) = 0;
    H(arg0, 0x42) = 0x7802;
    if (SB(arg0, 1) == 0x14) {
        W(arg0, 0x50) = (s32)&D_801F37A4;
        B(arg0, 0x16) = 0;
        B(arg0, 0x64) = 1;
        W(arg0, 0x68) = (s32)&D_801F37BC;
        if (D_8009718C & 0x100) {
            W(arg0, 0x20) = 0xD0000;
        } else {
            W(arg0, 0x20) = 0xB0000;
        }
        if (B(arg0, 0x15) == 0) {
            W(arg0, 0x20) = -W(arg0, 0x20);
        }
        set_animation(arg0, 0x1D);
        B(sub, 2) = 0;
    } else {
        if (SB(arg0, 2) != 0) {
            src = *(u8**)(arg0 + 0x7C);
            H(arg0, 0xA) = H(src, 0xA);
            H(arg0, 0xE) = H(src, 0xE);
            B(arg0, 0x15) = B(src, 0x15);
            sc2 = SCRATCH_1C;
            v = W(sc2, 0x20);
            W(arg0, 0x30) = (s32)&D_80077AC8;
            H(arg0, 0x40) = 0;
            H(arg0, 0x42) = 0x784A;
            W(arg0, 0x3C) = (s32)(sc2 + v);
            set_animation(arg0, 2);
        } else {
            set_animation(arg0, 0x1E);
        }
        B(arg0, 0x16) = 1;
        W(arg0, 0x50) = (s32)&D_801F37A8;
        B(arg0, 0x64) = 2;
        W(arg0, 0x20) = 0;
        B(sub, 0) = 0x5A;
        B(sub, 1) = 8;
    }
    W(arg0, 0x28) = 0;
    W(arg0, 0x24) = 0;
    W(arg0, 0x2C) = 0;
    B(arg0, 5) = 0;
    B(arg0, 4)++;
    func_8002CCB0(arg0, 0x2A, 0x22);
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s8 D_800950A0[];
void* func_8002C32C();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
void move_object(struct X4_MovingObj*);
M2C_UNK func_8002EE10(void*);
void func_800383F8(void*);

void func_801ED36C(s8* arg0) {
    struct X4_PlayerObj* player = &g_Player;
    s8* sub;
    s8* p;
    s8* spawn;
    s32 i;
    s32 count;
    s32 c15;
    s32 c1;
    u32 max;

    sub = arg0 + 0x8C;
    move_object((struct X4_MovingObj*)arg0);
    max = 1;
    if (M2C_FIELD(player, u8*, 0xE7) == 4) {
        max = 3;
    }
    if (M2C_FIELD(arg0, s8*, 0x98) != 0) {
        count = 0;
        if (M2C_FIELD(sub, u8*, 2) < max) {
            c15 = 0x15;
            c1 = 1;
            p = D_800950A0;
            i = 0x1F;
            do {
                if ((p[0] != 0) && (p[1] == c15) && (p[4] == c1)) {
                    count++;
                }
                i--;
                p += 0xA0;
            } while (i >= 0);
            if (count < (s32)max) {
                spawn = func_8002C32C();
                if (spawn != 0) {
                    spawn[0] = 0x21;
                    spawn[1] = 0x15;
                    spawn[2] = 0;
                    M2C_FIELD(spawn, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
                    M2C_FIELD(spawn, s32*, 0x8) = M2C_FIELD(arg0, s32*, 0x8);
                    M2C_FIELD(spawn, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                    M2C_FIELD(spawn, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
                    M2C_FIELD(sub, u8*, 2)++;
                }
            }
        }
        if (M2C_FIELD(arg0, s8*, 0x98) < 0) {
            arg0[3] = 0;
            arg0[4] = 3;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x68) = 0;
            return;
        }
        M2C_FIELD(arg0, s8*, 0x98) = 0;
    }
    if ((M2C_FIELD(arg0, u8*, 0x70) != 0) ||
        (func_8002EE10(arg0), (M2C_FIELD(arg0, u8*, 0x70) != 0))) {
        func_800383F8(arg0);
        arg0[3] = 0;
        arg0[4] = 3;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
    }
    func_8002CCB0(arg0, 0x2A, 0x22);
}
#undef func_8002CCB0
#undef g_Player
