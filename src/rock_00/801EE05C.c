#define func_80041AB8 func_801EE05C
#define D_80075FD8 D_801F37E4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_801EE098
#define D_80075FD8 D_801F37F4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_801EE0D4
#define D_80075FD8 D_801F3804
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_801EE110
#define D_80075FD8 D_801F381C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

/* Adapted from sozud/mmx4 @807a01b src/main/weapons/weapon_22_nova_strike_hitbox.c:nova_strike_hitbox_update, AGPL-3.0; proven shared with X6 by exact signature ab318e028ab5 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_Unk_unk68 D_801F37AC[];
M2C_UNK clear_object_slot();
#define clear_object_slot ((void (*)(struct X4_ObjectHeader * arg0)) clear_object_slot)

void func_801EE14C(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;
    u8 temp_v0;

    if (g_Player.unk17 != 0x6A) {
        clear_object_slot(OBJECT_HEADER(arg0));
        return;
    }
    if (arg0->state == 0) {
        arg0->unk50 = &D_801F37AC;
        arg0->unk64 = 1U;
        arg0->ext.raw[0] = 4U;
        arg0->state++;
    } else {
        temp_v0 = arg0->ext.raw[0];
        if (temp_v0 == 0) {
            arg0->ext.raw[0] = 4U;
            arg0->unk64++;
        } else {
            arg0->ext.raw[0] = temp_v0 - 1;
        }
    }
    arg0->x_pos.val = player->x_pos.val;
    arg0->y_pos.val = player->y_pos.val;
    arg0->unk15 = player->unk15;
}
#undef g_Player
#undef clear_object_slot

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_Unk_unk68 D_801F37C0[];
M2C_UNK clear_object_slot();
#define clear_object_slot ((void (*)(struct X4_ObjectHeader * arg0)) clear_object_slot)

void func_801EE210(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;
    u8 temp_v0;

    if (g_Player.unk5 != 0x23) {
        clear_object_slot(OBJECT_HEADER(arg0));
        return;
    }
    if (arg0->state == 0) {
        arg0->unk50 = &D_801F37C0;
        arg0->unk64 = 1U;
        arg0->ext.raw[0] = 4U;
        arg0->state++;
    } else {
        temp_v0 = arg0->ext.raw[0];
        if (temp_v0 == 0) {
            arg0->ext.raw[0] = 4U;
            arg0->unk64++;
        } else {
            arg0->ext.raw[0] = temp_v0 - 1;
        }
    }
    arg0->x_pos.val = player->x_pos.val;
    arg0->y_pos.val = player->y_pos.val;
    arg0->unk15 = player->unk15;
}
#undef g_Player
#undef clear_object_slot

#define func_80041AB8 func_801EE2D4
#define D_80075FD8 D_801F382C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_801EE310
#define D_80075FD8 D_801F3810
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "mmx6/x4.h"
extern s8 D_8007673C[];
extern s8 D_8007693C[];
extern s16 D_801F3894[][2];
extern u8 D_801F49F4[];

s32 func_801EE34C(struct X4_WeaponObj* arg0, struct X4_PlayerObj* arg1,
                  s32 arg2) {
    s32 idx;
    s16 dx;
    s16 dy;
    s8 i;

    i = arg2;
    idx = ((u8*)arg1)[0x47] * 2;
    if (D_801F49F4[arg1->unk17] == 0) {
        dx = D_8007673C[idx];
        dy = D_8007673C[idx + 1];
    } else {
        dx = D_8007693C[idx];
        dy = D_8007693C[idx + 1];
    }
    if (arg0->unk15 != 0) {
        arg0->x_pos.i.hi = arg1->x_pos.i.hi - dx;
        arg0->x_pos.i.hi -= D_801F3894[i][0];
    } else {
        arg0->x_pos.i.hi = dx + arg1->x_pos.i.hi;
        arg0->x_pos.i.hi += D_801F3894[i][0];
    }
    arg0->y_pos.i.hi = dy + arg1->y_pos.i.hi;
    arg0->y_pos.i.hi += D_801F3894[i][1];
}

#include "common.h"

extern s32 D_8009718C;

s32 func_801EE434(void) {
    s32 var_v1;

    var_v1 = 0x7802;
    if (D_8009718C & 0x180) {
        var_v1 = 0x7844;
    }
    return var_v1;
}

/* Adapted from sozud/mmx4 @807a01b src/main/weapons/weapon_00_lemon.c:lemon_main, AGPL-3.0; proven shared with X6 by exact signature e25d4c5c1482 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_801EE4DC(struct X4_AnimatedObj*);
void func_801EE538(struct X4_WeaponObj*);
void func_801EE638(void* arg0);
#define M2C_UNK s32
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);

void func_801EE458(struct X4_WeaponObj* arg0) {
    if (func_8002CBFC(BASE_OBJECT(arg0), 0xC, 8) == 0) {
        func_80017A04(ANIMATED_OBJECT(arg0));
        if (arg0->unk98 == 0) {
            func_801EE4DC(ANIMATED_OBJECT(arg0));
            func_8002CCB0(BASE_OBJECT(arg0), 0xC, 8);
            return;
        }
        func_801EE538(arg0);
        return;
    }
    func_801EE638(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void move_object(struct X4_MovingObj*);
M2C_UNK func_8002EE10(void*);
void func_800383F8(void*);
void func_801EE638(void* arg0);

void func_801EE4DC(struct X4_AnimatedObj* arg0) {
    move_object(MOVING_OBJECT(arg0));
    if (*((u8*)arg0 + 0x70) == 0) {
        func_8002EE10(arg0);
        if (*((u8*)arg0 + 0x70) == 0) {
            return;
        }
    }
    func_800383F8(arg0);
    func_801EE638(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
void func_801EE638(void* arg0);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 random_byte();

void func_801EE538(struct X4_WeaponObj* arg0) {
    arg0->unk50 = 0;
    arg0->unk68 = 0;
    if (arg0->unk98 > 0) {
        func_801EE638(arg0);
        return;
    }
    arg0->x_vel.val = -arg0->x_vel.val;
    if (random_byte() & 1) {
        arg0->y_vel.val = 0x40CCB;
    } else {
        arg0->y_vel.val = -0x40CCB;
    }
    arg0->state = 2;
    arg0->unk5 = 0;
    arg0->unk15 ^= 0x40;
    func_8002CCB0(arg0, 0xC, 8);
}

/* Adapted from sozud/mmx4 @807a01b src/main/weapons/weapon_00_lemon.c:lemon_deflected, AGPL-3.0; proven shared with X6 by exact signature 9c5292152b2a (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
void func_801EE638(void* arg0);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_80017A04(struct X4_AnimatedObj*);
void move_object(struct X4_MovingObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);

void func_801EE5D4(struct X4_WeaponObj* arg0) {
    if (func_8002CBFC(BASE_OBJECT(arg0), 0xC, 8) == 0) {
        func_80017A04(ANIMATED_OBJECT(arg0));
        move_object(MOVING_OBJECT(arg0));
        func_8002CCB0(BASE_OBJECT(arg0), 0xC, 8);
        return;
    }
    func_801EE638(arg0);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_801EE638(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s8*, 4) = 3;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_801EE650(void* arg0) {
    void* temp_v1;

    temp_v1 = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(temp_v1, u8*, 0x98) = (u8)(M2C_FIELD(temp_v1, u8*, 0x98) - 1);
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_80017A04(struct X4_AnimatedObj*);
void move_object(struct X4_MovingObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002EE10(void*);
void func_800383F8(void*);

#define B(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_801EE684(void* arg0) {
    if (func_8002CBFC(arg0, 0x20, 0x14) == 0 && B(arg0, 0x98) == 0) {
        func_80017A04(arg0);
        move_object(arg0);
        func_8002CCB0(arg0, 0x20, 0x14);
        {
            // !FAKE: first flag read lands in the first return register
            register s32 f asm("$2") = UB(arg0, 0x70);
            if (f == 0 && (func_8002EE10(arg0), UB(arg0, 0x70) == 0)) {
                return;
            }
        }
        func_800383F8(arg0);
    }
    UB(arg0, 3) = 0;
    UB(arg0, 4) = 3;
    W(arg0, 0x50) = 0;
    W(arg0, 0x68) = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
M2C_UNK clear_object_slot();

void func_801EE72C(struct X4_PlayerObj* arg0) {
    arg0->unk50 = 0;
    if (arg0->id != 0x15) {
        g_Player.shot_count--;
    }
    clear_object_slot();
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern s32 D_80077A80;
extern s32 D_801F37C4;
extern s32 D_801F37C8;
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK player_spawn_visual(M2C_UNK, M2C_UNK, s8, M2C_UNK);
#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801EE774(struct X4_WeaponObj* arg0) {
    u8* temp_a0;
    u8* temp_v0;
    s32 temp_a2;

    arg0->active = 1;
    arg0->on_screen = 1;
    arg0->unk64 = 1;
    arg0->unk50 = &D_801F37C4;
    arg0->unk68 = (struct X4_Unk_unk68*)&D_801F37C8;
    temp_v0 = SCRATCH_14;
    arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x3C);
    temp_a0 = SCRATCH_1C;
    temp_a2 = *(s32*)(temp_a0 + 0x18);
    arg0->animation_table = (u32**)&D_80077A80;
    arg0->unk40 = 0x540;
    arg0->unk42 = 0x7802;
    arg0->unk16 = 1;
    arg0->unk3C = temp_a0 + temp_a2;
    if (arg0->unk15 != 0) {
        arg0->x_vel.val = 0xA0000;
    } else {
        arg0->x_vel.val = 0xFFF60000;
    }
    arg0->unk28.val = 0;
    arg0->y_vel.val = 0;
    arg0->unk2C = 0;
    set_animation(arg0, 0);
    arg0->unk5 = 0;
    arg0->state++;
    player_spawn_visual(1, 0x1B, 8, 0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
void move_object(struct X4_MovingObj*);
M2C_UNK func_8002EE10(void*);
void func_800383F8(void*);
#include "mmx6/state.h"

void func_801EE860(void* arg0) {
    if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
        func_80017A04(arg0);
        move_object(arg0);
        if (!(D_80097420.frame_counter & 3)) {
            M2C_FIELD(arg0, u8*, 0x64) = (u8)(M2C_FIELD(arg0, u8*, 0x64) + 1);
        }
        if ((M2C_FIELD(arg0, u8*, 0x70) != 0) ||
            (func_8002EE10(arg0), (M2C_FIELD(arg0, u8*, 0x70) != 0)) ||
            (M2C_FIELD(arg0, s8*, 0x98) != 0)) {
            if (M2C_FIELD(arg0, s8*, 0x98) == 0) {
                func_800383F8(arg0);
            }
            M2C_FIELD(arg0, u8*, 3) = 0;
            M2C_FIELD(arg0, u8*, 4) = 2;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x68) = 0;
        }
    } else {
        M2C_FIELD(arg0, u8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = 2;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK clear_object_slot();
extern M2C_UNK g_Player;

void func_801EE940(void) {
    u8* p = (u8*)&g_Player;

    p[0x98]--;
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
void move_object(struct X4_MovingObj*);

void func_801EE974(void* arg0) {
    if (func_8002CBFC(arg0, 0x20, 0x40) == 0) {
        func_80017A04(arg0);
        move_object(arg0);
        if (!(D_80097420.frame_counter & 3)) {
            M2C_FIELD(arg0, u8*, 0x64) = (u8)(M2C_FIELD(arg0, u8*, 0x64) + 1);
        }
    } else {
        M2C_FIELD(arg0, u8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = 2;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_801EE9F0(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
void func_801ED36C(s8* arg0);
void func_801EEA8C(void* arg0);

void func_801EEA10(void* arg0) {
    if (func_8002CBFC((struct X4_BaseObj*)arg0, 0x2A, 0x22) == 0) {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        if (M2C_FIELD(arg0, s8*, 1) == 0x14) {
            func_801ED36C(arg0);
            return;
        }
        func_801EEA8C(arg0);
        return;
    }
    M2C_FIELD(arg0, u8*, 3) = 0;
    M2C_FIELD(arg0, u8*, 4) = 3;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);          /* extern */
M2C_UNK set_animation_frame(void*, M2C_UNK, s8);      /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */

void func_801EEA8C(void* arg0) {
    u8 temp_v0;
    u8 temp_v0_2;
    void* temp_a0;

    if (M2C_FIELD(arg0, s8*, 5) == 0) {
        temp_v0 = M2C_FIELD(arg0, u8*, 0x8C);
        temp_a0 = arg0 + 0x8C;
        if (temp_v0 == 0) {
            if (M2C_FIELD(arg0, s8*, 2) != 0) {
                set_animation_frame(arg0, 3, M2C_FIELD(arg0, s8*, 0x45));
            } else {
                set_animation(arg0, 0x1F);
            }
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s8*, 5) = 1;
        } else {
            M2C_FIELD(arg0, u8*, 0x8C) = (u8)(temp_v0 - 1);
            temp_v0_2 = M2C_FIELD(temp_a0, u8*, 1);
            if (temp_v0_2 == 0) {
                M2C_FIELD(temp_a0, u8*, 1) = 8U;
                M2C_FIELD(arg0, u8*, 0x64) =
                    (u8)(M2C_FIELD(arg0, u8*, 0x64) + 1);
            } else {
                M2C_FIELD(temp_a0, u8*, 1) = (u8)(temp_v0_2 - 1);
            }
        }
        goto block_12;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 3;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        return;
    }
block_12:
    func_8002CCB0(arg0, 0x2A, 0x22);
}

/* Adapted from sozud/mmx4 @807a01b src/main/weapons/weapon_20_plasma_shot.c:buster_shot_follow_muzzle, AGPL-3.0; proven shared with X6 by exact signature 06aa2f0ae247 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_801EEB7C(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* owner;

    if (arg0->unk84.word == 0) {
        owner = arg0->owner;
        if (owner->attacking == 0) {
            arg0->unk84.word = 1;
        }
        if (owner->unk15 != arg0->unk15) {
            arg0->unk84.word = 1;
        }
        if (arg0->unk84.word == 0) {
            func_801EE34C(VISUAL_OBJECT(arg0), owner, arg0->id);
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void move_object(struct X4_MovingObj*);
M2C_UNK func_8002EE10(void*);
void func_800383F8(void*);

void func_801EEBF4(void* arg0) {
    if (func_8002CBFC(arg0, 0x10, 0x10) == 0) {
        func_80017A04(arg0);
        if (M2C_FIELD(arg0, s8*, 0x98) == 0) {
            move_object(arg0);
            if ((M2C_FIELD(arg0, u8*, 0x70) != 0) ||
                (func_8002EE10(arg0), (M2C_FIELD(arg0, u8*, 0x70) != 0))) {
                func_800383F8(arg0);
                // !FAKE: shared reset block reached from the 0x70 arm
                goto block_6;
            }
            func_8002CCB0(arg0, 0x10, 0x10);
            return;
        }
    }
block_6:
    M2C_FIELD(arg0, u8*, 3) = 0;
    M2C_FIELD(arg0, u8*, 4) = 3;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

M2C_UNK clear_object_slot();
void func_801EECA4(struct X4_WeaponObj* arg0) {
    if (arg0->unk2 == 0) {
        g_Player.shot_count--;
    }
    ((void (*)())clear_object_slot)(arg0);
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern void (*D_801F397C[])(struct X4_WeaponObj*);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK collide_solid_object();

void func_801EECE8(struct X4_WeaponObj* arg0) {
    s32 var_a0;
    u8 temp_s0;
    s32 temp_s1;
    struct X4_PlayerObj* player = &g_Player;

    arg0->unk18 = arg0->x_pos;
    arg0->unk1C = arg0->y_pos;
    var_a0 = M2C_FIELD(player, s8*, 0xD3) != 0;
    if (player->ride_animation != 0) {
        var_a0 = 1;
    }
    if (player->weapon != 2) {
        var_a0 = 1;
    }
    if (player->shot_type == 0xB) {
        var_a0 = 1;
    }
    if (var_a0 != 0) {
        arg0->state = 3;
    }
    M2C_FIELD(arg0, u8*, 0x8C) = arg0->unk70 | arg0->unk71;
    D_801F397C[arg0->state](arg0);
    if (arg0->id == 2) {
        if (arg0->unk75 != 0 && M2C_FIELD(player, u8*, 0xE5) == 0) {
            temp_s1 = M2C_FIELD(player, u8*, 0x72);
            M2C_FIELD(player, u8*, 0x72) = 8;
            temp_s0 = arg0->unk72;
            collide_solid_object(arg0);
            temp_s1 |= arg0->unk72 & 8;
            M2C_FIELD(player, u8*, 0x72) = temp_s1;
            if ((temp_s0 & 8) && !(arg0->unk72 & 8)) {
                M2C_FIELD(player, u8*, 0x72) = temp_s1 | 8;
            }
        }
        func_8002F288((M2C_UNK*)arg0);
        arg0->unk71 = 0;
    }
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern s32 D_800779D8;
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3964;
extern s32 D_801F3968[];
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_8003CF24(s32, s32, s32);
M2C_UNK player_spawn_visual(M2C_UNK, M2C_UNK, s8, M2C_UNK);
s32 func_801EE34C();
#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801EEE40(struct X4_WeaponObj* arg0) {
    s8 temp_v1;
    u8* temp_a0;
    u8* temp_v0;
    s32 var_a0;

    temp_v0 = SCRATCH_14;
    arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x40);
    temp_a0 = SCRATCH_1C;
    var_a0 = *(s32*)(temp_a0 + 0x74);
    arg0->animation_table = (u32**)&D_800779D8;
    arg0->unk40 = 0x520;
    arg0->unk42 = 0x7801;
    arg0->unk16 = 1;
    arg0->unk3C = temp_a0 + var_a0;
    arg0->unk15 = g_Player.unk15;
    temp_v1 = arg0->id;
    arg0->unk67 = 1;
    arg0->unk64 = 0;
    if (temp_v1 == 2) {
        if (arg0->unk2 == 0) {
            arg0->unk50 = 0;
            arg0->unk68 = 0;
            M2C_FIELD(arg0, u8*, 0x9D) = 1;
            func_801EE34C(arg0, &g_Player, 2);
            set_animation(arg0, 0);
            play_sound(1, 0x14, arg0);
            M2C_FIELD(arg0, u8*, 0x8D) = 0;
            arg0->state = 1;
            arg0->unk5 = 0;
        } else {
            arg0->state = 3;
        }
        func_8002CCB0(arg0, 0x10, 0x10);
    } else if (temp_v1 == 0x34) {
        func_8002CCB0(arg0, 0x10, 0x10);
        set_animation(arg0, arg0->unk2 + 3);
        {
            // !FAKE: depin: dropping it breaks the match (91/96)
            register s32* t50 asm("$2") = &D_801F3964;
            // !FAKE: depin: dropping it breaks the match (92/96)
            register s32* t68 asm("$3") = D_801F3968;
            arg0->unk50 = t50;
            arg0->unk68 = (struct X4_Unk_unk68*)t68;
        }
        arg0->state = 2;
    }
    func_8003CF24(7, 1, 1);
    player_spawn_visual(1, 0x1B, 1, 0);
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern void (*D_801F398C[])(void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_80049E50(void*);

void func_801EEFC0(struct X4_WeaponObj* arg0) {
    s8 temp_v1;
    // !FAKE: depin: dropping it breaks the match (39/79)
    register s32 t asm("$4");

    if (func_8002CBFC((struct X4_BaseObj*)arg0, 0x10, 0x10) == 0) {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        D_801F398C[arg0->unk5](arg0);
        temp_v1 = arg0->unk5;
        if (temp_v1 == 2) {
            return;
        }
        if (M2C_FIELD(arg0, s8*, 0x98) != 0) {
            M2C_FIELD(arg0, u8*, 0x3) = 0;
            M2C_FIELD(arg0, u8*, 0x4) = 3;
            return;
        }
        if (temp_v1 == 0) {
            return;
        }
        t = M2C_FIELD(arg0, u8*, 0x8C);
        if (((t & 0xC) == 0xC) || ((t & 3) == 3)) {
            func_80049E50(arg0);
            goto block_11;
        }
        if ((t & 0xFF) == 8) {
            set_animation(arg0, 2);
            {
                // !FAKE: depin: dropping it breaks the match (76/79)
                register s32 c1 asm("$2") = 1;
                M2C_FIELD(arg0, u8*, 0x75) = c1;
            }
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, u8*, 0x9D) = 0;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s16*, 0x88) = 0xB4;
            arg0->unk5 = 2;
            return;
        }
        {
            // !FAKE: depin: dropping it breaks the match (77/79)
            register s32 m asm("$2") = t & 7;
            if (m != 0) {
                func_80049E50(arg0);
                M2C_FIELD(arg0, u8*, 0x75) = 0;
                M2C_FIELD(arg0, u8*, 0x3) = 0;
                M2C_FIELD(arg0, u8*, 0x4) = 3;
            }
        }
        return;
    }
block_11:
    M2C_FIELD(arg0, u8*, 0x75) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = 3;
}

#include "common.h"

s32 random_byte();
void func_801EFB5C(void*, u8, u8);
extern u8 D_801F3998[];
extern u8 D_801F39AC[];

void func_801EF0FC(u8* arg0) {
    if (arg0[0x8D] < 3) {
        if (arg0[0x8D] == 0) {
            arg0[0x8E] = random_byte() % 6;
            arg0[0x8F] = random_byte() % 6;
            arg0[0x90] = random_byte() & 1;
        }
        if (arg0[0x15] == 0x40) {
            func_801EFB5C(
                arg0, (D_801F3998[arg0[0x8D] + arg0[0x8F] * 3] + arg0[0x90]),
                D_801F39AC[D_801F3998[arg0[0x8D] + arg0[0x8E] * 3]]);
        } else {
            // !FAKE: depin: dropping it breaks the match (39/98)
            register u8* b asm("$7");

            func_801EFB5C(
                arg0, (D_801F3998[arg0[0x8D] + arg0[0x8F] * 3] + arg0[0x90]),
                (b = D_801F39AC,
                 b -= -D_801F3998[arg0[0x8D] + arg0[0x8E] * 3])[3]);
        }
        arg0[0x8D]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern s32 D_800779F4;
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_8003CF24(s32, s32, s32);
#define set_animation ((void (*)(void*, s32))set_animation)
#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801EF284(struct X4_WeaponObj* arg0) {
    s8 temp_a2;
    u8* temp_a0;
    u8* temp_v0;
    s32 var_a0;

    temp_a2 = arg0->unk2;
    if (temp_a2 == 0) {
        play_sound(1, 0x15, arg0);
        M2C_FIELD(arg0, s16*, 0x8C) = 0x168;
        arg0->state++;
        return;
    }
    temp_v0 = SCRATCH_14;
    arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x34);
    temp_a0 = SCRATCH_1C;
    var_a0 = *(s32*)(temp_a0 + 0x54);
    arg0->animation_table = (u32**)&D_800779F4;
    arg0->unk40 = 0x520;
    arg0->unk42 = 0x7801;
    arg0->unk16 = 1;
    arg0->unk64 = 1;
    arg0->unk3C = temp_a0 + var_a0;
    switch (temp_a2) {
    case 1:
        set_animation(arg0, 0);
        arg0->y_vel.val = 0x10000;
        break;
    case 2:
        set_animation(arg0, 1);
        arg0->y_vel.val = 0x10000;
        break;
    case 3:
        set_animation(arg0, 2);
        arg0->x_vel.val = 0x10000;
        break;
    case 4:
        set_animation(arg0, 2);
        arg0->unk15 = 0x40;
        arg0->x_vel.val = 0x10000;
        break;
    }
    func_8003CF24(0xA, 1, 1);
    play_sound(1, 0x16, arg0);
    func_8002CCB0(arg0, 0x20, 0x20);
    {
        // !FAKE: depin: dropping it breaks the match (13/99)
        register s32 st asm("$2") = (u8)arg0->state;
        arg0->unk5 = 2;
        arg0->state = st + 1;
    }
}
#undef set_animation

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* func_8002C32C();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_801EF410(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_WeaponObj* obj;
    s32 mode;
    s32 i;
    s32 d;

    player = &g_Player;
    mode = 0;
    if (player->unk5 != F_S8(arg0, 0x92)) {
        arg0->unk5--;
        return;
    }
    if (player->unk5 != 0x4A) {
        if (((player->x_pos.i.hi - F_U16(arg0, 0x8E)) >= 0
                 ? (player->x_pos.i.hi - F_U16(arg0, 0x8E))
                 : (F_U16(arg0, 0x8E) - player->x_pos.i.hi)) >= 0x20) {
            mode = 1;
        }
    } else {
        if (((player->x_pos.i.hi - F_U16(arg0, 0x8E)) >= 0
                 ? (player->x_pos.i.hi - F_U16(arg0, 0x8E))
                 : (F_U16(arg0, 0x8E) - player->x_pos.i.hi)) >= 0x20) {
            mode = 1;
        } else {
            if (((player->y_pos.i.hi - F_U16(arg0, 0x90)) >= 0
                     ? (player->y_pos.i.hi - F_U16(arg0, 0x90))
                     : (F_U16(arg0, 0x90) - player->y_pos.i.hi)) >= 0x20) {
                mode = 3;
            }
        }
    }
    if (mode != 0) {
        if (mode == 1) {
            if (F_U16(arg0, 0x8E) < player->x_pos.i.hi) {
                F_U16(arg0, 0x8E) = F_U16(arg0, 0x8E) + 0x20;
            } else {
                F_U16(arg0, 0x8E) = F_U16(arg0, 0x8E) - 0x20;
            }
            F_U16(arg0, 0x90) = player->y_pos.u.hi;
        } else {
            if (player->y_pos.i.hi > F_U16(arg0, 0x90)) {
                F_U16(arg0, 0x90) = F_U16(arg0, 0x90) + 0x20;
            } else {
                F_U16(arg0, 0x90) = F_U16(arg0, 0x90) - 0x20;
            }
            F_U16(arg0, 0x8E) = player->x_pos.u.hi;
        }
        i = 0;
        do {
            obj = func_8002C32C();
            if (obj != 0) {
                obj->active = arg0->active;
                obj->id = arg0->id;
                obj->unk2 = mode + i;
                obj->bg_offset = arg0->bg_offset;
                obj->x_pos.u.hi = F_U16(arg0, 0x8E);
                obj->y_pos.u.hi = F_U16(arg0, 0x90);
                F_PTR(obj, 0x7C) = arg0;
                arg0->unk6++;
            }
            i++;
        } while (i < 2);
    }
}
#undef g_Player

#include "common.h"
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
extern s32 D_801F3968[];

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_801EF618(void* arg0) {
    if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
        F_S8(arg0, 3) = 1;
        func_80017A04(arg0);
        if (F_S8(arg0, 6) == 0) {
            if (F_S8(arg0, 0x45) & 0x80) {
                F_S8(arg0, 6)++;
                F_PTR(arg0, 0x50) = &D_801F3968[F_S8(arg0, 2)];
                switch (F_S8(arg0, 2)) {
                case 1:
                    F_U16(arg0, 0xE) -= 0x10;
                    break;
                case 2:
                    F_U16(arg0, 0xE) += 0x10;
                    break;
                case 3:
                    F_U16(arg0, 0xA) -= 0x10;
                    break;
                case 4:
                    F_U16(arg0, 0xA) += 0x10;
                    break;
                }
            }
        } else {
            switch (F_S8(arg0, 2)) {
            case 1:
                F_S32(arg0, 0xC) -= F_S32(arg0, 0x24);
                break;
            case 2:
                F_S32(arg0, 0xC) += F_S32(arg0, 0x24);
                break;
            case 3:
                F_S32(arg0, 0x8) -= F_S32(arg0, 0x20);
                break;
            case 4:
                F_S32(arg0, 0x8) += F_S32(arg0, 0x20);
                break;
            }
            F_S32(arg0, 0x20) += 0x10000;
            if (F_S32(arg0, 0x20) > 0x60000) {
                F_S32(arg0, 0x20) = 0x60000;
            }
            F_S32(arg0, 0x24) += 0x10000;
            if (F_S32(arg0, 0x24) > 0x60000) {
                F_S32(arg0, 0x24) = 0x60000;
            }
        }
    } else {
        F_S8(arg0, 3) = 0;
        F_S8(arg0, 4) = 3;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
void func_80017A04(struct X4_AnimatedObj*);
void move_object(struct X4_MovingObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80049D90(void*);

#define F818_B(p, o) (*(s8*)((u8*)(p) + (o)))
#define F818_UB(p, o) (*(u8*)((u8*)(p) + (o)))

void func_801EF818(void* arg0) {
    if (func_8002CBFC(arg0, 0x10, 0x10) == 0) {
        F818_UB(arg0, 3) = 1;
        func_80017A04(arg0);
        move_object(arg0);
        if (F818_B(arg0, 0x98) == 0) {
            if (F818_UB(arg0, 0x70) == 0 &&
                (func_8002EE10(arg0), F818_UB(arg0, 0x70) == 0)) {
                return;
            }
            func_80049D90(arg0);
        }
    }
    F818_UB(arg0, 3) = 0;
    F818_UB(arg0, 4) = 3;
}

#undef F818_B
#undef F818_UB

#include "common.h"
#define M2C_UNK s32

M2C_UNK clear_object_slot();
extern M2C_UNK g_Player;

void func_801EF8B0(s8* arg0) {
    s8 t;
    u8* p;
    u8* q;

    t = arg0[1];
    *(s32*)(arg0 + 0x50) = 0;
    *(s32*)(arg0 + 0x68) = 0;
    arg0[3] = 0;
    arg0[0x9D] = 0;
    if (t == 0x2) {
        if (*(s16*)(arg0 + 0x8A) == 0) {
            p = (u8*)&g_Player;
            p[0x98]--;
            p[0x99]--;
            clear_object_slot(arg0);
        }
    } else if (t == 0x34) {
        q = *(u8**)(arg0 + 0x7C);
        (*(s16*)(q + 0x8A))--;
        clear_object_slot(arg0);
    }
}

#include "common.h"

extern s8 D_800970A5;
extern void (*D_801F39B4[])(u8*);

void func_801EF944(u8* arg0) {
    D_801F39B4[((s8*)arg0)[5]](arg0);
    if (((s8*)arg0)[2] == 0 && D_800970A5 != 0x27) {
        if (--*(u16*)(arg0 + 0x8C) == 0) {
            arg0[4] = 3;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3954;
extern s32 D_801F395C;
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_80049E50(void*);
s32 func_801EE34C();

void func_801EF9C8(struct X4_WeaponObj* arg0) {
    arg0->unk15 = g_Player.unk15;
    func_801EE34C(arg0, &g_Player, arg0->id);
    if (arg0->animation_step.fields.event == 1) {
        set_animation(arg0, 1);
        arg0->unk88.half = 3;
        if (arg0->unk15 != 0) {
            arg0->x_vel.val = 0x40000;
            arg0->x_pos.i.hi += 8;
        } else {
            arg0->x_vel.val = 0xFFFC0000;
            arg0->x_pos.i.hi -= 8;
        }
        arg0->unk50 = &D_801F3954;
        arg0->unk68 = (struct X4_Unk_unk68*)&D_801F395C;
        arg0->unk28.val = 0;
        arg0->y_vel.val = 0;
        arg0->unk2C = 0x2800;
        arg0->unk5 = 1;
        func_8002F288((M2C_UNK*)arg0);
        if (arg0->unk70 & 7) {
            func_80049E50(arg0);
            arg0->on_screen = 0;
            arg0->state = 3;
        }
    }
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002D230(void*);
void func_801EF0FC(u8* arg0);

void func_801EFAB4(u8* arg0) {
    s32 t;

    ((void (*)(void*))func_8002D230)(arg0);
    t = *(u16*)(arg0 + 0x88) - 1;
    *(u16*)(arg0 + 0x88) = t;
    if ((t << 0x10) == 0) {
        func_801EF0FC(arg0);
        *(u16*)(arg0 + 0x88) = 3;
    }
}

#include "common.h"

void func_801EFB04(u8* arg0) {
    if (*(s16*)(arg0 + 0x88) < 0x1E) {
        if (*(u16*)(arg0 + 0x88) & 1) {
            arg0[3] = 0;
        } else {
            arg0[3] = 1;
        }
    }
    if (--*(s16*)(arg0 + 0x88) == 0) {
        arg0[0x75] = 0;
        arg0[3] = 0;
        arg0[4] = 3;
    }
}

#include "common.h"

void* func_8002C32C();
void set_velocity_from_angle(void*, s32);

#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_801EFB5C(void* arg0, u8 arg1, u8 arg2) {
    u8* obj;

    obj = func_8002C32C();
    if (obj != 0) {
        obj[0] = 1;
        obj[1] = 0x34;
        obj[2] = arg1;
        F_U8(obj, 0x14) = F_U8(arg0, 0x14);
        F_S32(obj, 0x8) = F_S32(arg0, 0x8);
        F_S32(obj, 0xC) = F_S32(arg0, 0xC);
        F_U8(obj, 0x15) = F_U8(arg0, 0x15);
        F_PTR(obj, 0x7C) = arg0;
        set_velocity_from_angle(obj, arg2);
        F_S32(obj, 0x20) = F_S32(obj, 0x20) * 250 / 100;
        F_S32(obj, 0x24) = F_S32(obj, 0x24) * 250 / 100;
        F_U16(arg0, 0x8A)++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;

void func_801EFC70(u8* arg0) {
    struct X4_PlayerObj* p = &g_Player;
    if (p->unk6 == 0) {
        if (p->unk5 != 0x23) {
            if (p->unk5 < 0x24) {
                if (p->unk5 < 0xE) {
                    if (p->unk5 < 0xC) {
                        // !FAKE: jump to the shared exit keeps the range test unfolded
                        goto end;
                    }
                    // !FAKE: jump to the shared store block keeps the retail block order
                    goto block_7;
                }
            } else if (p->unk5 == 0x4A) {
                // !FAKE: shared store block reached from the 0x4A arm
                goto block_7;
            }
        } else {
        block_7:
            *(u16*)(arg0 + 0x8E) = p->x_pos.u.hi;
            *(u16*)(arg0 + 0x90) = p->y_pos.u.hi;
            arg0[0x92] = p->unk5;
            arg0[5]++;
        }
    }
end:;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(void*);    /* extern */
M2C_UNK func_8003C4EC(M2C_UNK*); /* extern */
extern M2C_UNK g_Player;

void func_801EFCF4(void* arg0) {
    void* temp_v1;

    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if (M2C_FIELD(arg0, s8*, 6) == 0) {
            func_8003C4EC(&g_Player);
            M2C_FIELD(&g_Player, u8*, 0x98) =
                (u8)(M2C_FIELD(&g_Player, u8*, 0x98) - 1);
            M2C_FIELD(&g_Player, u8*, 0x99) =
                (u8)(M2C_FIELD(&g_Player, u8*, 0x99) - 1);
            if (M2C_FIELD(&g_Player, s8*, 0xA6) == 1) {
                M2C_FIELD(&g_Player, s8*, 0xA6) = 0;
            }
            clear_object_slot(arg0);
        }
    } else {
        temp_v1 = M2C_FIELD(arg0, void**, 0x7C);
        if (M2C_FIELD(temp_v1, s8*, 6) != 0) {
            M2C_FIELD(temp_v1, s8*, 6) =
                (s8)((u8)M2C_FIELD(temp_v1, s8*, 6) - 1);
        }
        clear_object_slot(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern void (*D_801F39C0[])(struct X4_PlayerObj*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_801EFDA8(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;
    s32 var_a1;

    *(s32*)&arg0->unk18 = *(s32*)&arg0->x_pos;
    *(s32*)&arg0->unk1C = *(s32*)&arg0->y_pos;
    var_a1 = F_S8(player, 0xD3) != 0;
    if (F_S8(player, 0xD4) != 0) {
        var_a1 = 1;
    }
    if (player->weapon != 2) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        arg0->state = 3;
    }
    D_801F39C0[arg0->state](arg0);
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
M2C_UNK func_80017B04(M2C_UNK*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
void func_8003CF24(s32, s32, s32);
extern s32 D_80077A00;
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F39D0;
extern s32 D_801F39D4;

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_801EFE34(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;

    player = &g_Player;
    if (arg0->unk2 == 0) {
        u8* temp_v0;
        u8* temp_a3;
        s32 var_v1;

        F_U8(arg0, 0x48) = 0xFF;
        F_U8(arg0, 0x47) = 0;
        arg0->unk49 = 1;
        temp_v0 = SCRATCH_14;
        arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0xC);
        temp_a3 = SCRATCH_1C;
        var_v1 = *(s32*)(temp_a3 + 0x2C);
        arg0->unk42 = 0x7801;
        temp_a3 = temp_a3 + var_v1;
        arg0->unk3C = temp_a3;
        func_8003CF24(0xB, 1, 1);
        func_80017B04((s32*)arg0, 0x140, 0x20);
        F_U8(arg0, 0x8C) = player->unk5;
        arg0->state++;
        return;
    }
    {
        u8* temp_v0;
        u8* temp_a0;
        s32 var_a1;

        arg0->unk50 = &D_801F39D0;
        arg0->unk68 = (struct X4_Unk_unk68*)&D_801F39D4;
        arg0->unk64 = 1;
        temp_v0 = SCRATCH_14;
        arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0xC);
        temp_a0 = SCRATCH_1C;
        var_a1 = *(s32*)(temp_a0 + 0x2C);
        arg0->animation_table = (u32**)&D_80077A00;
        arg0->unk40 = 0x520;
        arg0->unk42 = 0x7801;
        arg0->unk16 = 0;
        arg0->unk3C = temp_a0 + var_a1;
    }
    if ((arg0->unk15 = player->unk15) != 0) {
        arg0->x_vel.val = 0x50000;
    } else {
        arg0->x_vel.val = -0x50000;
    }
    set_animation(arg0, 0);
    arg0->unk5 = 1;
    arg0->state++;
    func_8002CCB0(arg0, 0x30, 0x30);
}
#undef g_Player
#undef set_animation
#undef func_8002CCB0

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* func_8002C32C();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_801EFFAC(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_WeaponObj* obj;
    s8 st;

    player = &g_Player;
    if (player->unk5 != F_U8(arg0, 0x8C) || player->unk5 == 0x11) {
        arg0->state = 3;
        return;
    }
    st = arg0->unk6;
    if (st == 0) {
        if (F_U8(player, 0x45) & 2) {
            obj = func_8002C32C();
            if (obj != 0) {
                obj->active = arg0->active;
                obj->id = arg0->id;
                obj->unk2 = 1;
                obj->bg_offset = arg0->bg_offset;
                obj->x_pos.u.hi = player->x_pos.u.hi - 0x20;
                obj->y_pos.u.hi = player->y_pos.u.hi;
                if (player->unk15 != 0) {
                    obj->x_pos.u.hi = player->x_pos.u.hi + 0x20;
                }
                F_U8(player, 0x98)++;
                F_U8(player, 0x99)++;
            }
            F_U8(arg0, 0x8E) = 8;
            F_U8(arg0, 0x8D) = 1;
            arg0->unk6++;
        }
    } else if (st == 1) {
        if (--F_U8(arg0, 0x8E) == 0) {
            obj = func_8002C32C();
            if (obj != 0) {
                obj->active = arg0->active;
                obj->id = arg0->id;
                obj->unk2 = st;
                obj->bg_offset = arg0->bg_offset;
                obj->x_pos.u.hi = player->x_pos.u.hi - 0x20;
                obj->y_pos.u.hi = player->y_pos.u.hi;
                if (player->unk15 != 0) {
                    obj->x_pos.u.hi = player->x_pos.u.hi + 0x20;
                }
                F_U8(player, 0x98)++;
                F_U8(player, 0x99)++;
            }
            arg0->unk6++;
            F_U8(arg0, 0x8D)++;
        }
    }
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
M2C_UNK func_80017B04(M2C_UNK*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
s32 random_byte();
void set_velocity_from_angle(void*, s32);
void func_8003CF24(s32, s32, s32);
extern s32 D_80077A08;
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F39D8;

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_801F01A8(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    s32 mul;

    player = &g_Player;
    if (arg0->unk2 == 0) {
        u8* temp_v0;
        u8* temp_a0;
        s32 var_a1;

        F_U8(arg0, 0x48) = 0xFF;
        F_U8(arg0, 0x47) = 0;
        arg0->unk49 = 1;
        temp_v0 = SCRATCH_14;
        arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x30);
        temp_a0 = SCRATCH_1C;
        var_a1 = *(s32*)(temp_a0 + 0x64);
        arg0->animation_table = (u32**)&D_80077A08;
        arg0->unk40 = 0x520;
        arg0->unk42 = 0x7801;
        arg0->unk3C = temp_a0 + var_a1;
        func_8003CF24(0xE, 1, 1);
        func_80017B04((s32*)arg0, 0x140, 0x20);
        F_U8(arg0, 0x8C) = player->unk5;
        F_U8(arg0, 0x8F) = player->unk15;
        arg0->state++;
        return;
    }
    {
        u8* temp_v0;
        u8* temp_a0;
        s32 var_a1;

        arg0->unk50 = &D_801F39D8;
        arg0->unk64 = 1;
        temp_v0 = SCRATCH_14;
        arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x30);
        temp_a0 = SCRATCH_1C;
        var_a1 = *(s32*)(temp_a0 + 0x64);
        arg0->animation_table = (u32**)&D_80077A08;
        arg0->unk40 = 0x520;
        arg0->unk42 = 0x7801;
        arg0->unk16 = 0x11;
        arg0->unk3C = temp_a0 + var_a1;
    }
    switch (random_byte() % 3) {
    case 0:
        set_velocity_from_angle(arg0, 1);
        break;
    case 1:
        set_velocity_from_angle(arg0, 0);
        break;
    case 2:
        set_velocity_from_angle(arg0, 0x1F);
        break;
    }
    mul = (random_byte() % 3) + 3;
    arg0->x_vel.val *= mul;
    arg0->y_vel.val *= mul;
    if (arg0->unk15 == 0) {
        arg0->x_vel.val = -arg0->x_vel.val;
    }
    set_animation(arg0, 0);
    play_sound(1, 0x18, arg0);
    arg0->unk5 = 1;
    arg0->state++;
    func_8002CCB0(arg0, 0x40, 0x40);
}
#undef g_Player
#undef set_animation
#undef func_8002CCB0

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* func_8002C32C();
s32 random_byte();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_BackgroundObj background_objects[3];

#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_801F0410(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_WeaponObj* obj;
    s32 state;
    s32 r;

    state = arg0->unk6;
    player = &g_Player;
    if (state == 0) {
        if (player->unk5 != F_U8(arg0, 0x8C) || player->unk5 == 0x11) {
            goto end3;
        }
        if (!(F_S8(player, 0x45) & 0x80)) {
            return;
        }
        obj = func_8002C32C();
        if (obj != 0) {
            obj->active = arg0->active;
            obj->id = arg0->id;
            obj->unk2 = 1;
            obj->bg_offset = arg0->bg_offset;
            obj->x_pos.u.hi = player->x_pos.u.hi;
            obj->y_pos.u.hi = player->y_pos.u.hi;
            obj->unk15 = player->unk15;
            F_PTR(obj, 0x7C) = arg0;
            arg0->unk7++;
        }
        arg0->unk6++;
        player->unk6 = 1;
        F_U8(arg0, 0x8E) = 0x14;
        F_U8(arg0, 0x8D) = 1;
    } else if (state == 1) {
        if (--F_U8(arg0, 0x8E) != 0) {
            return;
        }
        obj = func_8002C32C();
        if (obj != 0) {
            obj->active = arg0->active;
            obj->id = arg0->id;
            obj->unk2 = state;
            obj->bg_offset = arg0->bg_offset;
            obj->unk15 = F_U8(arg0, 0x8F);
            if (obj->unk15 != 0) {
                obj->x_pos.u.hi =
                    background_objects[arg0->bg_offset].x_pos.u.hi - 0x20;
            } else {
                obj->x_pos.u.hi =
                    background_objects[arg0->bg_offset].x_pos.u.hi + 0x160;
            }
            r = random_byte();
            obj->y_pos.u.hi = player->y_pos.u.hi + (r % 64) - 0x20;
            F_PTR(obj, 0x7C) = arg0;
            arg0->unk7++;
        }
        F_U8(arg0, 0x8E) = 0x14;
        if (++F_U8(arg0, 0x8D) >= 8) {
        end3:
            arg0->state = 3;
        }
    }
}
#undef g_Player

#include "common.h"

#define M2C_UNK s32

extern M2C_UNK g_Player;
extern void (*D_801F39E0[])(s8*);

void func_801F0664(s8* arg0) {
    u8* p;
    s32 f;

    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    p = (u8*)&g_Player;
    f = *(s8*)(p + 0xD3) != 0;
    if (*(s8*)(p + 0xD4) != 0) {
        f = 1;
    }
    if (*(s8*)(p + 0x93) != 3) {
        f = 1;
    }
    if (*(s8*)(p + 0x96) == 0xC) {
        f = 1;
    }
    if (f != 0) {
        arg0[4] = 3;
    }
    D_801F39E0[arg0[4]](arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern void (*D_801F3A00[])(struct X4_PlayerObj*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_801F0700(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;
    s32 var_a1;

    *(s32*)&arg0->unk18 = *(s32*)&arg0->x_pos;
    *(s32*)&arg0->unk1C = *(s32*)&arg0->y_pos;
    var_a1 = F_S8(player, 0xD3) != 0;
    if (F_S8(player, 0xD4) != 0) {
        var_a1 = 1;
    }
    if (player->weapon != 3) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        arg0->state = 3;
    }
    D_801F3A00[arg0->state](arg0);
}
#undef g_Player

#define func_80041AB8 func_801F0788
#define D_80075FD8 D_801F39F0
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_801F0858(void* arg0);

void func_801F07C4(void* arg0) {
    func_80017A04(arg0);
    if (((s8*)arg0)[0x46] == 0) {
        func_801F0858(arg0);
        return;
    }
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x30, 0x30);
}

/* Adapted from sozud/mmx4 @807a01b src/main/weapons/weapon_02_frost_tower.c:frost_tower_despawn, AGPL-3.0; proven shared with X6 by exact signature d5fdc58f219e (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

M2C_UNK clear_object_slot(void*);
void func_801F0814(struct X4_WeaponObj* arg0) {
    arg0->unk50 = 0;
    arg0->unk68 = 0;
    g_Player.shot_count--;
    g_Player.special_shot_count--;
    clear_object_slot(OBJECT_HEADER(arg0));
}
#undef g_Player

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_801F0858(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s8*, 4) = 3;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void move_object(struct X4_MovingObj*);
M2C_UNK func_8002EE10(void*);
void func_801F0858(void* arg0);

void func_801F0870(void* arg0) {
    // !FAKE: second 0x70 read lands in the second return register
    register s32 t asm("$3");

    if (func_8002CBFC(arg0, 0x30, 0x30) == 0) {
        func_80017A04(arg0);
        move_object(arg0);
        if ((M2C_FIELD(arg0, u8*, 0x70) != 0) ||
            (((void (*)(void*))func_8002EE10)(arg0),
             ((t = M2C_FIELD(arg0, u8*, 0x70)) != 0))) {
            ((void (*)(void*, s32))set_animation)(arg0, 1);
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x68) = 0;
            M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
        }
        ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x30, 0x30);
        return;
    }
    func_801F0858(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void move_object(struct X4_MovingObj*);

void func_801F0918(void* arg0) {
    if (func_8002CBFC(arg0, 0x40, 0x40) == 0) {
        func_80017A04(arg0);
        move_object(arg0);
        ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x40, 0x40);
        return;
    }
    ((u8*)arg0)[3] = 0;
    ((u8*)arg0)[4] = 3;
    *(s32*)((u8*)arg0 + 0x50) = 0;
    *(s32*)((u8*)arg0 + 0x68) = 0;
}

#define func_80041AB8 func_801F0984
#define D_80075FD8 D_801F39F8
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern M2C_UNK g_Player;

void func_801F09C0(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        void* pl;

        if (M2C_FIELD(arg0, s8*, 7) != 0) {
            return;
        }
        pl = &g_Player;
        M2C_FIELD(pl, u8*, 0x98) -= 1;
        M2C_FIELD(pl, u8*, 0x99) -= 1;
    } else {
        void* p = M2C_FIELD(arg0, void**, 0x7C);

        if (M2C_FIELD(p, s8*, 7) != 0) {
            M2C_FIELD(p, u8*, 7) -= 1;
        }
    }
    ((M2C_UNK(*)())clear_object_slot)(arg0, arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
M2C_UNK func_80017B04(M2C_UNK*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
void func_8003CF24(s32, s32, s32);
s32 func_801EE34C();
extern s32 D_80077A20;
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_801F0A40(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    u8* temp_v0;
    u8* temp_v1;
    s32 temp_a2;
    u8 b15;
    // !FAKE: depin: dropping it breaks the match (78/84)
    register s32 k asm("$7");

    player = &g_Player;
    if ((F_S32(player, 4) & 0xFFFF00) != 0x2C00) {
        arg0->state = 2;
        return;
    }
    F_U8(arg0, 0x14) = F_U8(player, 0x14);
    b15 = player->unk15;
    arg0->unk16 = 1;
    k = 0x7801;
    arg0->unk40 = 0x520;
    arg0->unk42 = k;
    arg0->unk15 = b15;
    temp_v0 = SCRATCH_14;
    arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x18);
    temp_v1 = SCRATCH_1C;
    temp_a2 = *(s32*)(temp_v1 + 0x38);
    arg0->animation_table = (u32**)&D_80077A20;
    arg0->unk64 = 1;
    arg0->unk3C = temp_v1 + temp_a2;
    set_animation(arg0, 0);
    func_801EE34C(arg0, player, arg0->id);
    F_S16(arg0, 0x8C) = arg0->x_pos.i.hi - player->x_pos.i.hi;
    F_S16(arg0, 0x8E) = arg0->y_pos.i.hi - player->y_pos.i.hi;
    F_U8(arg0, 0x48) = 0xFF;
    arg0->unk49 = 1;
    func_8003CF24(0x13, 1, 1);
    func_80017B04((s32*)arg0, 0x140, 0x20);
    arg0->state++;
    play_sound(1, 0x20, arg0);
    func_8002CCB0(arg0, 0x18, 0x18);
}
#undef g_Player
#undef set_animation
#undef func_8002CCB0

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern void (*D_801F3A28[])(struct X4_WeaponObj*);

void func_801F0B90(struct X4_WeaponObj* arg0) {
    s32 var_a1;
    struct X4_PlayerObj* player = &g_Player;

    arg0->unk18 = arg0->x_pos;
    arg0->unk1C = arg0->y_pos;
    var_a1 = M2C_FIELD(player, s8*, 0xD3) != 0;
    if (player->ride_animation != 0) {
        var_a1 = 1;
    }
    if (player->weapon != 5) {
        var_a1 = 1;
    }
    if (player->shot_type == 0xE) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        arg0->state = 2;
    }
    D_801F3A28[arg0->state](arg0);
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern void (*D_801F3A40[])(struct X4_PlayerObj*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_801F0C30(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;
    s32 var_a1;

    *(s32*)&arg0->unk18 = *(s32*)&arg0->x_pos;
    *(s32*)&arg0->unk1C = *(s32*)&arg0->y_pos;
    var_a1 = F_S8(player, 0xD3) != 0;
    if (F_S8(player, 0xD4) != 0) {
        var_a1 = 1;
    }
    if (player->weapon != 5) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        arg0->state = 2;
    }
    D_801F3A40[arg0->state](arg0);
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
void func_80017A04(struct X4_AnimatedObj*);

void func_801F0CBC(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* p = &g_Player;

    if (p->unk5 != 0x2C) {
        arg0->state = 2;
        return;
    }
    func_80017A04(ANIMATED_OBJECT(arg0));
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        p->unk7 = 1;
        arg0->unk5++;
    }
    arg0->x_pos.u.hi = M2C_FIELD(arg0, u16*, 0x8C) + p->x_pos.u.hi;
    arg0->y_pos.u.hi = M2C_FIELD(arg0, u16*, 0x8E) + p->y_pos.u.hi;
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3A10;
extern s32 D_801F3A14;
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);

void func_801F0D58(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* p = &g_Player;

    if (p->unk5 != 0x2C) {
        arg0->state = 2;
        return;
    }
    if (p->unk6 == 2) {
        play_sound(1, 0x22, arg0);
        if (p->input.buttons.held & 4) {
            arg0->x_vel.val = 0x8000;
            arg0->y_vel.val = 0x18000;
            arg0->unk2C = 0x800;
        } else {
            arg0->x_vel.val = 0x10000;
            arg0->y_vel.val = 0x10000;
            arg0->unk2C = 0x800;
        }
        if (p->unk15 == 0) {
            arg0->x_vel.val = -arg0->x_vel.val;
        }
        arg0->unk50 = &D_801F3A10;
        M2C_FIELD(arg0, void**, 0x68) = &D_801F3A14;
        arg0->unk5++;
    }
    arg0->x_pos.u.hi = M2C_FIELD(arg0, u16*, 0x8C) + p->x_pos.u.hi;
    arg0->y_pos.u.hi = M2C_FIELD(arg0, u16*, 0x8E) + p->y_pos.u.hi;
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80049E50(void*);

void func_801F0E6C(void* arg0) {
    if (func_8002CBFC(arg0, 0x18, 0x18) == 0) {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        func_8002D230(arg0);
        {
            // !FAKE: first flag read lands in the first return register
            register s32 flag asm("$2") = M2C_FIELD(arg0, u8*, 0x70);
            if (flag == 0) {
                func_8002EE10(arg0);
                if (M2C_FIELD(arg0, u8*, 0x70) == 0) {
                    return;
                }
            }
        }
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        func_80049E50(arg0);
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    } else {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern void (*D_801F3A1C[])(s8*);

void func_801F0F08(s8* arg0) {
    D_801F3A1C[arg0[5]](arg0);
    func_8002CCB0(arg0, 0x18, 0x18);
}

#include "../shared/rock_00/func_801F0F5C.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
M2C_UNK func_80017B04(M2C_UNK*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
void func_8003CF24(s32, s32, s32);
s32 func_801EE34C();
extern s32 D_80077A20;
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_801F0F98(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    u8* temp_v0;
    u8* temp_v1;
    s32 temp_a2;
    u8 b15;
    // !FAKE: depin: dropping it breaks the match (61/67)
    register s32 k asm("$7");

    player = &g_Player;
    F_U8(arg0, 0x14) = F_U8(player, 0x14);
    b15 = player->unk15;
    arg0->unk16 = 1;
    k = 0x7801;
    arg0->unk40 = 0x520;
    arg0->unk42 = k;
    arg0->unk15 = b15;
    temp_v0 = SCRATCH_14;
    arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x38);
    temp_v1 = SCRATCH_1C;
    temp_a2 = *(s32*)(temp_v1 + 0x6C);
    arg0->animation_table = (u32**)&D_80077A20;
    arg0->unk64 = 1;
    arg0->unk3C = temp_v1 + temp_a2;
    set_animation(arg0, 1);
    func_801EE34C(arg0, player, arg0->id);
    F_U8(arg0, 0x48) = 0xFF;
    arg0->unk49 = 1;
    func_8003CF24(0x16, 1, 1);
    func_80017B04((s32*)arg0, 0x140, 0x20);
    arg0->state++;
    play_sound(1, 0x21, arg0);
    func_8002CCB0(arg0, 0x28, 0x28);
}
#undef g_Player
#undef set_animation
#undef func_8002CCB0

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
s32 func_801EE34C(struct X4_WeaponObj* arg0, struct X4_PlayerObj* arg1,
                  s32 arg2);
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_801F10A4(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;

    func_80017A04((struct X4_AnimatedObj*)arg0);
    if (arg0->animation_step.fields.relative_step == 0) {
        player->unk7 = 1;
        arg0->unk5++;
    }
    func_801EE34C(arg0, player, arg0->id);
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3A18;
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 func_801EE34C(struct X4_WeaponObj* arg0, struct X4_PlayerObj* arg1,
                  s32 arg2);

void func_801F110C(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;

    if (player->unk6 == 2) {
        play_sound(1, 0x23, arg0);
        arg0->x_vel.val = 0x80000;
        arg0->y_vel.val = 0x40000;
        arg0->unk2C = 0x4000;
        if (player->unk15 == 0) {
            arg0->x_vel.val = 0xFFF80000;
        }
        arg0->unk50 = &D_801F3A18;
        arg0->unk5++;
    }
    func_801EE34C(arg0, player, arg0->id);
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002D230(void*);

void func_801F11B0(struct X4_BaseObj* arg0) {
    if (func_8002CBFC(arg0, 0x18, 0x18) == 0) {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        func_8002D230(arg0);
        return;
    }
    arg0->state++;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern void (*D_801F3A34[])(void*);

void func_801F120C(void* arg0) {
    D_801F3A34[((s8*)arg0)[5]](arg0);
    func_8002CCB0(arg0, 0x28, 0x28);
}

#define func_801F0F5C func_801F1260
#define g_Player g_Player
#include "../shared/rock_00/func_801F0F5C.c"
#undef func_801F0F5C
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
s32 func_801EE34C();
extern s32 D_80077A28[];
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3A4C[];
extern s32 D_801F3A50;

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801F129C(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_WeaponObj* parent;
    u8* temp_v0;
    u8* temp_a0;
    s32 var_a0;
    s8 kind;

    arg0->on_screen = 1;
    arg0->unk67 = 1;
    temp_v0 = SCRATCH_14;
    arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x1C);
    temp_a0 = SCRATCH_1C;
    var_a0 = *(s32*)(temp_a0 + 0x3C);
    arg0->animation_table = (u32**)D_80077A28;
    arg0->unk40 = 0x520;
    arg0->unk42 = 0x7801;
    arg0->unk16 = 2;
    arg0->unk3C = temp_a0 + var_a0;
    player = &g_Player;
    arg0->unk15 = player->unk15;
    kind = arg0->unk2;
    arg0->unk64 = 1;
    if (kind == 0) {
        play_sound(1, 0x1B, arg0);
        func_801EE34C(arg0, player, arg0->id);
        set_animation(arg0, 0);
    } else if (kind == 1) {
        parent = (struct X4_WeaponObj*)arg0->owner;
        arg0->x_pos.i.hi = parent->x_pos.i.hi;
        arg0->y_pos.i.hi = parent->y_pos.i.hi - 8;
        arg0->y_vel.val = 0x40000;
        arg0->unk50 = D_801F3A4C;
        arg0->unk68 = (struct X4_Unk_unk68*)&D_801F3A50;
        arg0->unk5 = parent->unk5 + 1;
        set_animation(arg0, 1);
    } else if (kind == 2) {
        parent = (struct X4_WeaponObj*)arg0->owner;
        arg0->x_pos.i.hi = parent->x_pos.i.hi;
        arg0->y_pos.i.hi = parent->y_pos.i.hi + 0x11;
        arg0->y_vel.val = -0x40000;
        arg0->unk50 = parent->unk50;
        arg0->unk68 = parent->unk68;
        arg0->unk5 = parent->unk5 + 1;
        set_animation(arg0, 3);
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    arg0->state++;
}
#undef g_Player
#undef set_animation
#undef func_8002CCB0

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
void move_object(struct X4_MovingObj*);
void func_8002E974(void*);
extern struct X4_BackgroundObj background_objects[3];

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_801F1450(struct X4_WeaponObj* arg0) {
    s32 flag;
    u8 bits;

    if (F_S8(arg0->owner, 0x45) & 0x80) {
        F_S8(arg0, 0x8D) = 1;
    }
    if (F_S8(arg0, 0x8D) != 0) {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        move_object((struct X4_MovingObj*)arg0);
    }
    flag = 0;
    if (arg0->unk70 == 0) {
        func_8002E974(arg0);
    }
    bits = arg0->unk70;
    if ((bits & 0xC) == 0xC) {
        arg0->y_pos.i.hi += 9;
        set_animation(arg0, 4);
        arg0->unk50 = 0;
        arg0->unk68 = 0;
        arg0->unk5 = 4;
        return;
    }
    if (bits & 4) {
        flag = 1;
    }
    if (arg0->y_pos.i.hi - background_objects[arg0->bg_offset].y_pos.i.hi <
        0x10) {
        flag = 1;
    }
    if (flag != 0) {
        set_animation(arg0, 2);
        arg0->unk5++;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    if (arg0->on_screen == 0 && F_S8(arg0, 0x8C) == 0) {
        arg0->state = 2;
    }
}
#undef set_animation
#undef func_8002CCB0

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
s32 random_byte();
s32 func_801EE34C();
extern s32 D_80077A28[];
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_801F3A4C[];

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_90(p) (((X4_f32*)((u8*)(p) + 0x90))->i)
#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define BG (background_objects[player->bg_offset])

void func_801F15B0(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_WeaponObj* parent;
    s16 a;
    s16 b;
    s32 c;

    arg0->unk38 = SCRATCH_14 + *(s32*)(SCRATCH_14 + 0x1C);
    arg0->unk3C = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x3C);
    arg0->animation_table = (u32**)D_80077A28;
    arg0->unk40 = 0x520;
    c = 0x7801;
    arg0->unk42 = c;
    arg0->on_screen = c;
    arg0->unk64 = c;
    arg0->unk16 = 2;
    player = &g_Player;
    if (arg0->unk2 == 0) {
        play_sound(1, 0x1B, arg0);
        arg0->unk15 = player->unk15;
        F_90(arg0).lo = player->x_pos.i.hi - BG.x_pos.i.hi;
        F_90(arg0).hi = player->y_pos.i.hi - BG.y_pos.i.hi;
        func_801EE34C(arg0, player, arg0->id);
        set_animation(arg0, 0);
        F_S8(player, 0xA6) = 3;
    } else if (arg0->unk2 == 1) {
        parent = (struct X4_WeaponObj*)arg0->owner;
        arg0->unk15 = parent->unk15;
        arg0->x_pos.i.hi = parent->x_pos.i.hi;
        arg0->y_pos.i.hi = parent->y_pos.i.hi - 8;
        F_90(arg0).lo = F_90(parent).lo;
        F_90(arg0).hi = F_90(parent).hi;
        arg0->y_vel.val = 0x40000;
        arg0->unk50 = D_801F3A4C;
        arg0->unk5 = parent->unk5 + 1;
        set_animation(arg0, 1);
    } else if (arg0->unk2 == 0x10) {
        play_sound(1, 0x1C, arg0);
        parent = (struct X4_WeaponObj*)arg0->owner;
        arg0->unk15 = parent->unk15;
        arg0->unk5 = 3;
        arg0->unk50 = D_801F3A4C;
        arg0->unk16 = 0x12;
        set_animation(arg0, 5);
        a = F_90(parent).lo;
        b = F_90(parent).hi;
        if (random_byte() & 4) {
            if (arg0->unk15 != 0) {
                a = (a * (random_byte() % 11)) / 10;
            } else {
                a = 0x140 - ((0x140 - a) * (random_byte() % 11)) / 10;
            }
            arg0->x_pos.i.hi = a + BG.x_pos.i.hi;
            arg0->y_pos.i.hi = BG.y_pos.i.hi - 0x20;
        } else {
            if (arg0->unk15 != 0) {
                arg0->x_pos.i.hi = BG.x_pos.i.hi - 0x24;
            } else {
                arg0->x_pos.i.hi = BG.x_pos.i.hi + 0x164;
            }
            b = (b * (random_byte() % 11)) / 10;
            arg0->y_pos.i.hi = b + BG.y_pos.i.hi;
        }
        arg0->x_vel.val = 0x54D9E;
        arg0->y_vel.val = -0x54D9E;
        if (arg0->unk15 == 0) {
            arg0->x_vel.val = -0x54D9E;
        }
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    arg0->state++;
}
#undef g_Player
#undef set_animation
#undef func_8002CCB0

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern void (*D_801F3A84[])(struct X4_PlayerObj*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_801F1A58(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;
    s32 var_a1;

    var_a1 = F_S8(player, 0xD3) != 0;
    if (F_S8(player, 0xD4) != 0) {
        var_a1 = 1;
    }
    if (player->weapon != 6) {
        var_a1 = 1;
    }
    if (F_S8(player, 0x96) == 0xF) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        arg0->state = 2;
    }
    D_801F3A84[arg0->state](arg0);
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern void (*D_801F3AA0[])(struct X4_PlayerObj*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_801F1AE8(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;
    s32 var_a1;

    var_a1 = F_S8(player, 0xD3) != 0;
    if (F_S8(player, 0xD4) != 0) {
        var_a1 = 1;
    }
    if (player->weapon != 6) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        arg0->state = 2;
    }
    D_801F3AA0[arg0->state](arg0);
}
#undef g_Player

#include "../shared/rock_00/func_801F1B64.c"

#define func_801F1B64 func_801F1C1C
#include "../shared/rock_00/func_801F1B64.c"
#undef func_801F1B64

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
void move_object(struct X4_MovingObj*);
M2C_UNK func_8002EE10(void*);

void func_801F1CD4(void* arg0) {
    s32 var_s1;

    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 0x45) & 0x80) {
        M2C_FIELD(arg0, s8*, 0x8D) = 1;
    }
    if (M2C_FIELD(arg0, s8*, 0x8D) != 0) {
        func_80017A04(arg0);
        move_object(arg0);
    }
    var_s1 = 0;
    if (M2C_FIELD(arg0, u8*, 0x70) == 0) {
        func_8002EE10(arg0);
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        var_s1 = 1;
    }
    if (var_s1 != 0) {
        M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE) + 9;
        set_animation(arg0, 4);
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, u8*, 5) = M2C_FIELD(arg0, u8*, 5) + 1;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    if ((M2C_FIELD(arg0, s8*, 3) == 0) && (M2C_FIELD(arg0, s8*, 0x8C) == 0)) {
        M2C_FIELD(arg0, u8*, 4) = 2;
    }
}
#undef func_8002CCB0
#undef set_animation

#include "common.h"
#define M2C_UNK s32

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_801F1DD0(s8* arg0) {
    ((void (*)())func_80017A04)();
    if (arg0[0x46] == 0) {
        arg0[4] = 2;
    }
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
    if ((arg0[3] == 0) && (arg0[0x8C] == 0)) {
        arg0[4] = 2;
    }
}

#define func_80041AB8 func_801F1E3C
#define D_80075FD8 D_801F3A70
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_801F1E78(struct PlayerObj* arg0) {
    if (arg0->afterimage == 0) {
        struct X4_PlayerObj* p = &g_Player;
        M2C_FIELD(p, u8*, 0x98)--;
        M2C_FIELD(p, u8*, 0x99)--;
    }
    ((M2C_UNK(*)())clear_object_slot)(arg0, arg0);
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
void* func_8003D480(M2C_UNK, s8, s8, void*);

#define F_45(p) (*(u8*)((u8*)(p) + 0x45))
#define F_46(p) (*(s8*)((u8*)(p) + 0x46))
#define F_8C(p) (*(s8*)((u8*)(p) + 0x8C))

void func_801F1EC8(struct X4_WeaponObj* arg0) {
    func_80017A04(ANIMATED_OBJECT(arg0));
    if (F_45(arg0) & 0x40) {
        F_45(arg0) = 0;
        if (func_8003D480(arg0->active, arg0->id, arg0->unk2 + 1, arg0) != 0) {
            F_8C(arg0)++;
        }
    }
    if (F_46(arg0) == 0) {
        arg0->state = 2;
    }
}
#undef F_45
#undef F_46
#undef F_8C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
void move_object(struct X4_MovingObj*);
extern struct X4_BackgroundObj background_objects[3];

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_S16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_801F1F4C(struct X4_WeaponObj* arg0) {
    if (F_S8(arg0->owner, 0x45) & 0x80) {
        F_S8(arg0, 0x8D) = 1;
    }
    if (F_S8(arg0, 0x8D) != 0) {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        move_object((struct X4_MovingObj*)arg0);
    }
    if (arg0->y_pos.i.hi - background_objects[arg0->bg_offset].y_pos.i.hi <
        -0x10) {
        arg0->on_screen = 0;
        F_S16(arg0, 0x8E) = 0x1E;
        arg0->unk5++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* func_8003D480(M2C_UNK, s8, s8, void*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_S16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_801F2000(struct X4_WeaponObj* arg0) {
    if (--F_S16(arg0, 0x8E) == 0) {
        F_S16(arg0, 0x8E) = 0x14;
        if (func_8003D480(arg0->active, arg0->id, 0x10, arg0) != 0) {
            arg0->unk6++;
        }
        if (++F_S8(arg0, 0x8C) >= 0xA) {
            arg0->state = 2;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void move_object(struct X4_MovingObj*);
extern struct X4_BackgroundObj background_objects[3];

void func_801F2094(struct X4_WeaponObj* arg0) {
    s32 off;
    s16 dx;
    s16 dy;

    func_80017A04((struct X4_AnimatedObj*)arg0);
    move_object((struct X4_MovingObj*)arg0);
    off = 0;
    dx = arg0->x_pos.i.hi - background_objects[arg0->bg_offset].x_pos.i.hi;
    dy = arg0->y_pos.i.hi - background_objects[arg0->bg_offset].y_pos.i.hi;
    if (arg0->unk15 != 0) {
        {
            s32 t = dx - 0x20;
            off = t > 0x140;
        }
    } else if (dx + 0x20 < 0) {
        off = 1;
    }
    if (dy - 0x38 > 0xF0) {
        off = 1;
    }
    if (off != 0) {
        arg0->unk50 = 0;
        arg0->on_screen = 0;
        arg0->state = 2;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
}

#define func_80041AB8 func_801F2170
#define D_80075FD8 D_801F3A90
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_801F21AC(void* arg0, u8 arg1) {
    s32 flag;
    s8* sub;
    s8 kind;

    flag = 0;
    kind = M2C_FIELD(arg0, s8*, 2);
    if (kind == 16) {
        sub = M2C_FIELD(arg0, s8**, 0x7C);
        if (sub[6] != 0) {
            sub[6]--;
        }
    } else if (kind == 0) {
        if (M2C_FIELD(arg0, s8*, 0x8C) == 0) {
            flag = 1;
        }
    } else if (kind == 1) {
        flag = 1;
        if (M2C_FIELD(arg0, s8*, 6) != 0) {
            return;
        }
    }
    if (flag != 0) {
        struct X4_PlayerObj* p = &g_Player;
        if (p->stock_charge == 3) {
            p->stock_charge = 0;
        }
        M2C_FIELD(p, u8*, 0x98)--;
        M2C_FIELD(p, u8*, 0x99)--;
    }
    clear_object_slot(arg0);
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
s32 func_801EE34C();
extern s32 D_80077A64[];
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801F226C(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_WeaponObj* parent;
    u8* temp_v0;
    u8* temp_a0;
    s32 var_a0;
    s8 sub;

    temp_v0 = SCRATCH_14;
    arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x24);
    temp_a0 = SCRATCH_1C;
    var_a0 = *(s32*)(temp_a0 + 0x44);
    arg0->animation_table = (u32**)D_80077A64;
    arg0->unk40 = 0x520;
    arg0->unk42 = 0x7801;
    player = &g_Player;
    arg0->unk16 = 1;
    arg0->unk3C = temp_a0 + var_a0;
    arg0->unk15 = player->unk15;
    sub = arg0->unk2;
    arg0->on_screen = 1;
    arg0->unk64 = 1;
    if (sub == 0) {
        play_sound(1, 0x24, arg0);
        arg0->x_vel.val = 0x6C000;
        func_801EE34C(arg0, player, arg0->id);
        set_animation(arg0, 0);
        arg0->state++;
        return;
    }
    parent = (struct X4_WeaponObj*)arg0->owner;
    arg0->x_pos.i.hi = parent->x_pos.i.hi;
    arg0->y_pos.i.hi = parent->y_pos.i.hi;
    arg0->state = 2;
    arg0->on_screen = 1;
    if (sub == 1) {
        set_animation(arg0, 4);
        return;
    }
    if (sub == 2) {
        set_animation(arg0, 5);
        arg0->y_pos.i.hi -= 8;
    } else {
        set_animation(arg0, 6);
        arg0->y_pos.i.hi += 8;
    }
}
#undef g_Player
#undef set_animation

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
void move_object(struct X4_MovingObj*);
s32 func_801EE34C();
void func_8002F06C(void*);
void* func_8003D480(M2C_UNK, s8, s8, void*);
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3AB0[];
extern s32 D_801F3AB8[];

#define F_8C(p) (*(s16*)((u8*)(p) + 0x8C))

void func_801F23C8(struct X4_WeaponObj* arg0) {
    s32 x;
    s32 mask;
    struct X4_PlayerObj* player;
    // !FAKE: depin: dropping it breaks the match (114/117)
    register s32 t asm("$3");

    func_80017A04(ANIMATED_OBJECT(arg0));
    move_object(MOVING_OBJECT(arg0));
    player = &g_Player;
    x = arg0->x_pos.val;
    if (arg0->unk6 == 0) {
        switch (player->unk5) {
        case 9:
        case 10:
        case 11:
        case 14:
        case 15:
        case 16:
        case 27:
        case 28:
        case 32:
            arg0->unk6 = 1;
            F_8C(arg0) = arg0->y_pos.i.hi - player->y_pos.i.hi;
            break;
        }
    }
    if (arg0->unk6 != 0) {
        arg0->y_pos.i.hi = g_Player.y_pos.i.hi + F_8C(arg0);
    } else {
        func_801EE34C(arg0, player, arg0->id);
    }
    arg0->x_pos.val = x;
    mask = 2;
    if (arg0->unk15 != 0) {
        mask = 1;
    }
    func_8002F06C(arg0);
    t = arg0->unk70 & mask;
    if (t) {
        if (func_8003D480(arg0->active, arg0->id, 1, arg0) != 0) {
            arg0->unk7++;
        }
        arg0->unk70 = 0;
        arg0->unk50 = D_801F3AB0;
        arg0->unk68 = (struct X4_Unk_unk68*)D_801F3AB8;
        set_animation(arg0, 1);
        if (g_Player.input.buttons.held & 8) {
            arg0->y_vel.val = -0x6C000;
        } else {
            arg0->y_vel.val = 0x6C000;
        }
        arg0->x_vel.val = 0;
        arg0->unk5++;
    } else {
        func_8002CCB0(arg0, 0x20, 0x20);
        if (arg0->on_screen == 0) {
            arg0->state = 3;
            arg0->unk50 = 0;
            arg0->unk68 = 0;
        }
    }
}
#undef g_Player
#undef set_animation
#undef func_8002CCB0
#undef F_8C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
void move_object(struct X4_MovingObj*);
void func_8002F06C(void*);
void* func_8003D480(M2C_UNK, s8, s8, void*);
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)

void func_801F259C(struct X4_WeaponObj* arg0) {
    s32 mask;
    // !FAKE: depin: dropping it breaks the match (67/70)
    register s32 t asm("$3");

    func_80017A04(ANIMATED_OBJECT(arg0));
    move_object(MOVING_OBJECT(arg0));
    mask = 8;
    if (arg0->y_vel.val > 0) {
        mask = 4;
    }
    func_8002F06C(arg0);
    t = arg0->unk70 & mask;
    if (t) {
        arg0->unk50 = 0;
        arg0->unk68 = 0;
        if (arg0->y_vel.val > 0) {
            if (func_8003D480(arg0->active, arg0->id, 2, arg0) != 0) {
                arg0->unk7++;
            }
            set_animation(arg0, 2);
        } else {
            if (func_8003D480(arg0->active, arg0->id, 3, arg0) != 0) {
                arg0->unk7++;
            }
            set_animation(arg0, 3);
        }
        arg0->state = 2;
    } else {
        func_8002CCB0(arg0, 0x20, 0x20);
        if (arg0->on_screen == 0) {
            arg0->state = 3;
            arg0->unk50 = 0;
            arg0->unk68 = 0;
        }
    }
}
#undef set_animation
#undef func_8002CCB0

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern void (*D_801F3ACC[])(struct X4_WeaponObj*);

void func_801F26B4(struct X4_WeaponObj* arg0) {
    s32 var_a1;
    struct X4_PlayerObj* player = &g_Player;

    var_a1 = M2C_FIELD(player, s8*, 0xD3) != 0;
    if (player->ride_animation != 0) {
        var_a1 = 1;
    }
    if (player->weapon != 8) {
        var_a1 = 1;
    }
    if (player->shot_type == 0x11) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        arg0->state = 3;
    }
    arg0->unk18 = arg0->x_pos;
    arg0->unk1C = arg0->y_pos;
    D_801F3ACC[arg0->state](arg0);
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
extern void (*D_801F3AE0[])(void*);

void func_801F2758(struct ObjectHeader* arg0) {
    s8* p = (s8*)&g_Player;
    s32 var_a1;

    var_a1 = p[0xD3] != 0;
    if (p[0xD4] != 0) {
        var_a1 = 1;
    }
    if (p[0x93] != 8) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        arg0->state = 3;
    }
    D_801F3AE0[arg0->state](arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
s32 func_801EE34C();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3AAC;
extern s32 D_801F3AB4;

void func_801F27D4(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;

    player = &g_Player;
    if (arg0->unk6 != 0) {
        goto set;
    }
    switch (player->unk5) {
    case 9:
    case 10:
    case 11:
    case 14:
    case 15:
    case 16:
    case 27:
    case 28:
    case 32:
        arg0->unk6 = 1;
        *(s16*)((u8*)arg0 + 0x8C) = arg0->y_pos.i.hi - player->y_pos.i.hi;
        break;
    }
    if (arg0->unk6 != 0) {
    set:
        arg0->y_pos.i.hi = g_Player.y_pos.i.hi + *(s16*)((u8*)arg0 + 0x8C);
    } else {
        func_801EE34C(arg0, player, arg0->id);
    }
    func_80017A04((struct X4_AnimatedObj*)arg0);
    if (((s8*)arg0)[0x45] & 0x80) {
        arg0->unk50 = &D_801F3AAC;
        arg0->unk68 = (struct X4_Unk_unk68*)&D_801F3AB4;
        if (arg0->unk15 == 0) {
            arg0->x_vel.val = -arg0->x_vel.val;
        }
        arg0->unk5++;
    }
}
#undef g_Player

#include "common.h"

extern s8 D_80097131;
extern void (*D_801F3AC0[])(s8*);

void func_801F28F4(s8* arg0) {
    D_801F3AC0[arg0[5]](arg0);
    if (arg0[6] == 0) {
        D_80097131 = 5;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_801F2950(void* arg0) {
    // !FAKE: pin the incremented counter to the first return register
    register s32 temp_v0 asm("$2");

    func_80017A04((struct X4_AnimatedObj*)arg0);
    func_8002CCB0(arg0, 0x20, 0x20);
    temp_v0 = F_U16(arg0, 0x8E) + 1;
    F_U16(arg0, 0x8E) = temp_v0;
    if ((F_S8(arg0, 0x46) == 0) || ((s16)temp_v0 >= 0xA)) {
        F_S8(arg0, 0x3) = 0;
        F_S8(arg0, 0x4) = 3;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

M2C_UNK clear_object_slot(void*);
void func_801F29B8(struct X4_WeaponObj* arg0) {
    struct X4_WeaponObj* owner;

    if (arg0->unk2 == 0) {
        if (arg0->unk7 != 0) {
            return;
        }
        g_Player.special_shot_count--;
        g_Player.shot_count--;
    } else {
        owner = (struct X4_WeaponObj*)arg0->owner;
        if (owner->unk7 != 0) {
            owner->unk7--;
        }
    }
    ((void (*)())clear_object_slot)(OBJECT_HEADER(arg0));
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_1C (*(u8**)0x1F80001C)

M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
extern M2C_UNK g_Player;
extern s32 D_8007798C;
extern s32 D_801F3ABC;

void func_801F2A38(void* arg0) {
    u8* p;
    u8* player;
    s32 off;

    M2C_FIELD(arg0, s8*, 3) = 1;
    p = SCRATCH_1C;
    off = M2C_FIELD(p, s32*, 0x68);
    M2C_FIELD(arg0, s32*, 0x30) = (s32)&D_8007798C;
    M2C_FIELD(arg0, s16*, 0x40) = 0;
    M2C_FIELD(arg0, s16*, 0x42) = 0x7802;
    M2C_FIELD(arg0, s8*, 0x16) = 0x11;
    M2C_FIELD(arg0, s32*, 0x24) = 0x100000;
    M2C_FIELD(arg0, s8*, 0x64) = 1;
    M2C_FIELD(arg0, u8**, 0x3C) = p + off;
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        set_animation(arg0, 0xB);
        M2C_FIELD(arg0, s32*, 0x50) = (s32)&D_801F3ABC;
    } else {
        set_animation(arg0, 0xC);
    }
    player = (u8*)&g_Player;
    M2C_FIELD(arg0, u8*, 4)++;
    player[0x99]++;
    player[0x98]++;
}
#undef set_animation
#undef SCRATCH_1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
void move_object(struct X4_MovingObj*);
extern struct X4_BackgroundObj background_objects[3];

void func_801F2AFC(struct X4_WeaponObj* arg0) {
    s16 d;
    s32 flag;

    func_80017A04((struct X4_AnimatedObj*)arg0);
    move_object((struct X4_MovingObj*)arg0);
    flag = 0;
    d = arg0->y_pos.i.hi - background_objects[arg0->bg_offset].y_pos.i.hi;
    if (arg0->unk2 == 0) {
        flag = d < -0x80;
    } else if (d < -0x20) {
        flag = 1;
    }
    if (flag != 0) {
        arg0->state = 3;
    }
}

#define func_80041AB8 func_801F2B90
#define D_80075FD8 D_801F3ADC
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#define func_801F0F5C func_801F2BCC
#define g_Player g_Player
#include "../shared/rock_00/func_801F0F5C.c"
#undef func_801F0F5C
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_80077AB0;
extern s32 D_801F3AF0;
extern s16 D_801F3AF4[];
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK clear_object_slot();
void func_8003CF24(s32, s32, s32);
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801F2C08(u8* arg0) {
    struct X4_PlayerObj* player = &g_Player;
    u8* scr;
    s32 i;

    if (M2C_FIELD(player, s8*, 5) != 0x4A) {
        clear_object_slot(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 4) == 0) {
        if (player->spike_immune == 0) {
            return;
        }
        if (!(M2C_FIELD(player, s8*, 0x45) & 0x80)) {
            return;
        }
        M2C_FIELD(arg0, s8*, 6) = M2C_FIELD(player, u8*, 0xD9) / 30;
        M2C_FIELD(arg0, u8*, 0x64) = 1;
        M2C_FIELD(arg0, s32**, 0x50) = &D_801F3AF0;
        scr = SCRATCH_1C;
        scr += M2C_FIELD(scr, s32*, 0x18);
        M2C_FIELD(arg0, s32**, 0x30) = &D_80077AB0;
        M2C_FIELD(arg0, s16*, 0x40) = 0;
        M2C_FIELD(arg0, s16*, 0x42) = 0x784A;
        M2C_FIELD(arg0, u8*, 0x16) = 0;
        M2C_FIELD(arg0, u8**, 0x3C) = scr;
        func_8003CF24(0x54, 0x1A, 1);
        if (M2C_FIELD(player, s32*, 0x24) != 0) {
            if (M2C_FIELD(player, s32*, 0x24) > 0) {
                set_animation(arg0, 0);
                M2C_FIELD(arg0, s8*, 5) = 0;
            } else {
                set_animation(arg0, 1);
                M2C_FIELD(arg0, s8*, 5) = 1;
            }
        } else {
            set_animation(arg0, 2);
            M2C_FIELD(arg0, s8*, 5) = 2;
            if (M2C_FIELD(player, u8*, 0x15) != 0) {
                M2C_FIELD(arg0, s8*, 5) = 3;
            }
        }
        M2C_FIELD(arg0, u8*, 3) = 1;
        M2C_FIELD(arg0, s8*, 4)++;
    } else {
        if (player->spike_immune == 0) {
            clear_object_slot(arg0);
            return;
        }
        func_80017A04((struct X4_AnimatedObj*)arg0);
        if (M2C_FIELD(arg0, u8*, 0x8C) == 0) {
            M2C_FIELD(arg0, u8*, 0x8C) = 4;
            M2C_FIELD(arg0, u8*, 0x64)++;
        } else {
            M2C_FIELD(arg0, u8*, 0x8C)--;
        }
    }
    i = M2C_FIELD(arg0, s8*, 5) * 4;
    M2C_FIELD(arg0, s16*, 0xA) =
        M2C_FIELD(player, s16*, 0xA) + *(s16*)(i + (u8*)D_801F3AF4);
    M2C_FIELD(arg0, s16*, 0xE) =
        M2C_FIELD(player, s16*, 0xE) + ((s16*)((u8*)D_801F3AF4 + i))[1];
    M2C_FIELD(arg0, u8*, 0x15) = M2C_FIELD(player, u8*, 0x15);
}
#undef g_Player
#undef set_animation

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_80077AB0;
extern s16 D_801F3B20[];
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK clear_object_slot();
void func_8003CF24(s32, s32, s32);
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801F2E0C(u8* arg0) {
    struct X4_PlayerObj* player = &g_Player;
    u8* scr;
    s32 i;

    if (M2C_FIELD(player, s8*, 5) != 0x4A) {
        clear_object_slot(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 4) == 0) {
        scr = SCRATCH_1C;
        scr += M2C_FIELD(scr, s32*, 0x88);
        M2C_FIELD(arg0, s32**, 0x30) = &D_80077AB0;
        M2C_FIELD(arg0, s16*, 0x40) = 0;
        M2C_FIELD(arg0, s16*, 0x42) = 0x784A;
        M2C_FIELD(arg0, u8*, 0x16) = 0;
        M2C_FIELD(arg0, u8**, 0x3C) = scr;
        M2C_FIELD(arg0, u8*, 0x15) = M2C_FIELD(player, u8*, 0x15);
        func_8003CF24(0x54, 0x1A, 1);
        if (M2C_FIELD(player, s32*, 0x24) != 0) {
            if (M2C_FIELD(player, s32*, 0x24) > 0) {
                set_animation(arg0, 3);
                M2C_FIELD(arg0, s8*, 5) = 0;
            } else {
                set_animation(arg0, 4);
                M2C_FIELD(arg0, s8*, 5) = 1;
            }
        } else {
            set_animation(arg0, 5);
            M2C_FIELD(arg0, s8*, 5) = 2;
            if (M2C_FIELD(player, u8*, 0x15) != 0) {
                M2C_FIELD(arg0, s8*, 5) = 3;
            }
        }
        {
            // !FAKE: depin: dropping it breaks the match (87/92)
            register s32 one asm("$3") = 1;
            M2C_FIELD(arg0, u8*, 3) = one;
        }
        {
            // !FAKE: depin: dropping it breaks the match (88/92)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 4) + 1;
            M2C_FIELD(arg0, u8*, 4) = t;
        }
        {
            // !FAKE: depin: dropping it breaks the match (87/92)
            register s32 j asm("$5");
            j = M2C_FIELD(arg0, s8*, 5) * 4;
            M2C_FIELD(arg0, s16*, 0xA) =
                M2C_FIELD(player, s16*, 0xA) + *(s16*)(j + (u8*)D_801F3B20);
            M2C_FIELD(arg0, s16*, 0xE) =
                M2C_FIELD(player, s16*, 0xE) + ((s16*)((u8*)D_801F3B20 + j))[1];
        }
        return;
    }
    func_80017A04((struct X4_AnimatedObj*)arg0);
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        clear_object_slot(arg0);
    }
}
#undef g_Player
#undef set_animation

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
void func_8003CF24(s32, s32, s32);
s32 func_801EE34C();
extern s32 D_80077AC8;
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3B04;
extern s32 D_801F3B08[];

#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801F2F7C(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    u8* t;
    s32 o;
    u8 b;
    // !FAKE: depin: dropping it breaks the match (71/77)
    register s32 v asm("$2");

    player = &g_Player;
    b = player->unk15;
    arg0->active = 0x21;
    arg0->unk15 = b;
    t = SCRATCH_1C;
    o = *(s32*)(t + 0x1C);
    arg0->animation_table = (u32**)&D_80077AC8;
    arg0->unk40 = 0;
    arg0->unk42 = 0x784A;
    arg0->unk16 = 2;
    arg0->unk64 = 1;
    t = t + o;
    arg0->unk3C = t;
    ((void (*)(s32, s32, s32, void*))func_8003CF24)(0x54, 0x1A, 1, t);
    v = 0xA0000;
    if (*(s32*)((u8*)player + 0xEC) & 0x100) {
        v = 0xC0000;
        arg0->x_vel.val = v;
    } else {
        arg0->x_vel.val = v;
    }
    arg0->unk68 = (struct X4_Unk_unk68*)&D_801F3B04;
    arg0->unk50 = D_801F3B08;
    if (arg0->unk15 == 0) {
        arg0->x_vel.val = -arg0->x_vel.val;
    }
    arg0->unk28.val = 0;
    arg0->y_vel.val = 0;
    arg0->unk2C = 0;
    set_animation(arg0, 0);
    func_801EE34C(arg0, &g_Player, arg0->id);
    arg0->state++;
    func_8002CCB0(arg0, 0x20, 0x14);
    play_sound(1, 0xA, arg0);
}
#undef g_Player
#undef set_animation
#undef func_8002CCB0

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void move_object(struct X4_MovingObj*);
M2C_UNK func_8002EE10(void*);
void func_800383F8(void*);
void* func_8003D480(M2C_UNK, s8, s8, void*);

void func_801F30B0(void* arg0) {
    s8 temp_v1;

    if (func_8002CBFC(arg0, 0x20, 0x14) == 0) {
        temp_v1 = M2C_FIELD(arg0, s8*, 0x98);
        if (temp_v1 == 0) {
            func_80017A04(arg0);
            move_object(arg0);
            func_8002CCB0(arg0, 0x20, 0x14);
            {
                // !FAKE: depin: dropping it breaks the match (82/84)
                register s32 f asm("$2") = M2C_FIELD(arg0, u8*, 0x70);
                if ((f != 0) ||
                    (func_8002EE10(arg0), (M2C_FIELD(arg0, u8*, 0x70) != 0))) {
                    func_800383F8(arg0);
                    M2C_FIELD(arg0, u8*, 4) = 2;
                    M2C_FIELD(arg0, s32*, 0x50) = 0;
                    M2C_FIELD(arg0, s32*, 0x68) = 0;
                    set_animation_frame(arg0, 1, M2C_FIELD(arg0, s8*, 0x45));
                }
            }
            goto block_9;
        }
        if (temp_v1 != -1) {
            if (M2C_FIELD(arg0, s8*, 7) == 1) {
                func_8003D480(0x21, 0x15, 1, arg0);
                goto block_12;
            }
            goto block_9;
        }
        M2C_FIELD(arg0, u8*, 4) = 2;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        set_animation_frame(arg0, 1, M2C_FIELD(arg0, s8*, 0x45));
    block_9:
        if (!(D_80097420.frame_counter & 3)) {
            M2C_FIELD(arg0, u8*, 0x64) = (u8)(M2C_FIELD(arg0, u8*, 0x64) + 1);
        }
        M2C_FIELD(arg0, u8*, 0x98) = 0;
        return;
    }
block_12:
    M2C_FIELD(arg0, u8*, 3) = 0;
    M2C_FIELD(arg0, u8*, 4) = 3;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_80077AD8;
extern s32 D_801F3B08[];
extern s16 D_801F3B40[];
M2C_UNK set_animation(void*, M2C_UNK);
void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_80017B04(M2C_UNK*, M2C_UNK, M2C_UNK);
M2C_UNK clear_object_slot();
void func_8003CF24(s32, s32, s32);
#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801F3200(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    u8* temp_v0;
    u8* temp_v1;
    s32 temp_a2;
    s8 idx;
    u8 dir;
    s32 t;

    player = &g_Player;
    t = player->unk5;
    if ((t ^ 0x4C) != 0) {
        clear_object_slot(arg0);
        return;
    }
    if (arg0->state != 0) {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            clear_object_slot(arg0);
            return;
        }
    } else {
        arg0->bg_offset = player->bg_offset;
        dir = player->unk15;
        arg0->unk16 = 1;
        arg0->unk40 = 0x540;
        arg0->unk42 = 0x784B;
        arg0->unk15 = dir;
        temp_v0 = SCRATCH_14;
        arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x3C);
        temp_v1 = SCRATCH_1C;
        temp_a2 = *(s32*)(temp_v1 + 0x80);
        arg0->animation_table = (u32**)&D_80077AD8;
        arg0->unk64 = 1;
        M2C_FIELD(arg0, s8*, 0x9C) = 1;
        arg0->unk3C = temp_v1 + temp_a2;
        set_animation(arg0, 0);
        arg0->previous_animation_index = 0xFF;
        arg0->unk49 = 1;
        func_8003CF24(0x55, 0x1B, 1);
        func_80017B04((s32*)arg0, 0x140, 0x40);
        {
            // !FAKE: depin: dropping it breaks the match (121/124)
            register s32 s asm("$2") = (u8)arg0->state + 1;
            arg0->state = s;
        }
    }
    idx = M2C_FIELD(arg0, s8*, 0x45);
    if (idx == 0) {
        arg0->unk50 = 0;
    } else {
        arg0->unk50 = &D_801F3B08[idx];
    }
    if (!(D_80097420.frame_counter & 3)) {
        arg0->unk64++;
    }
    arg0->y_pos.u.hi = player->y_pos.u.hi;
    if (player->unk15 != 0) {
        arg0->x_pos.u.hi = player->x_pos.u.hi + D_801F3B40[player->unk7];
    } else {
        arg0->x_pos.u.hi = player->x_pos.u.hi - D_801F3B40[player->unk7];
    }
    arg0->on_screen = 1;
}
#undef g_Player
#undef SCRATCH_14
#undef SCRATCH_1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_80017B04(M2C_UNK*, M2C_UNK, M2C_UNK);
M2C_UNK clear_object_slot();
#define clear_object_slot ((void (*)())clear_object_slot)
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
void move_object(struct X4_MovingObj*);
void func_8003CF24(s32, s32, s32);
extern s32 D_80077ADC;
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3B1C;
extern u16 D_801F3B48[];

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_801F33F0(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    u8* temp_v0;
    u8* temp_v1;
    s32 temp_a2;
    s32 t;

    player = &g_Player;
    t = player->unk5 == 0x4D;
    if (!t) {
        clear_object_slot();
        return;
    }
    if (arg0->state == 0) {
        arg0->bg_offset = player->bg_offset;
        arg0->unk15 = player->unk15;
        arg0->unk16 = 0x12;
        arg0->unk40 = 0x540;
        arg0->unk42 = 0x784B;
        temp_v0 = SCRATCH_14;
        arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x4C);
        temp_v1 = SCRATCH_1C;
        temp_a2 = *(s32*)(temp_v1 + 0x84);
        arg0->animation_table = (u32**)&D_80077ADC;
        arg0->unk64 = 1;
        arg0->unk3C = temp_v1 + temp_a2;
        set_animation(arg0, 0);
        F_U8(arg0, 0x48) = 0xFF;
        arg0->unk49 = 1;
        func_8003CF24(0x56, 0x1B, 1);
        func_80017B04((s32*)arg0, 0x140, 0x40);
        arg0->x_vel.val = 0x60000;
        arg0->unk50 = &D_801F3B1C;
        arg0->y_pos.u.hi = player->y_pos.u.hi;
        if (player->unk15 != 0) {
            arg0->x_pos.u.hi = player->x_pos.u.hi + D_801F3B48[arg0->unk2];
        } else {
            arg0->x_pos.u.hi = player->x_pos.u.hi - D_801F3B48[arg0->unk2];
        }
        if (arg0->unk15 == 0) {
            arg0->x_vel.val = -arg0->x_vel.val;
        }
        arg0->state++;
    } else {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        move_object((struct X4_MovingObj*)arg0);
    }
    if (!(D_80097420.frame_counter & 3)) {
        arg0->unk64++;
    }
    func_8002CCB0(arg0, 0x20, 0x30);
    if (arg0->on_screen == 0) {
        clear_object_slot(arg0);
        F_U8(player, 0xE1)++;
    }
}
#undef g_Player
#undef set_animation
#undef clear_object_slot
#undef func_8002CCB0
#undef SCRATCH_14
#undef SCRATCH_1C
#undef F_U8

#define func_80041AB8 func_801F3604
#define D_80075FD8 D_801F3B30
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);

void func_801F3640(u8* arg0) {
    func_80017A04(ANIMATED_OBJECT(arg0));
    if (*(s8*)(arg0 + 0x46) == 0) {
        arg0[4] = 3;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_801F3678(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

// clang-format off
INCLUDE_ASM("asm/rock_00/nonmatchings/1EA000", func_801F3698);
// clang-format on
