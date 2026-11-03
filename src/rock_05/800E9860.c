// clang-format off
INCLUDE_ASM("asm/rock_05/nonmatchings/E9860", D_800E9860);
// clang-format on

#include "../shared/rock_05/func_800E98C0.c"

#include "common.h"
#define M2C_UNK s32

#define SCRATCH_4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
extern u8 D_800F3CD0[];

void func_800E9A04(u8* arg0) {
    if (SCRATCH_4C[0x84] != 0) {
        if (!(*(s8*)(arg0 + 2) & 0xF0)) {
            set_animation(arg0, 1);
        } else {
            set_animation(arg0, 3);
        }
        SCRATCH_4C[0x85] = 1;
        *(s16*)(arg0 + 0x7E) = 0xC8;
        arg0[6]++;
    } else if (--*(s16*)(arg0 + 0x7C) == 0) {
        if (!(*(s8*)(arg0 + 2) & 0xF0)) {
            set_animation(arg0, 1);
        } else {
            set_animation(arg0, 3);
        }
        arg0[6]++;
    }
    if (!(*(s8*)(arg0 + 2) & 0xF0)) {
        SCRATCH_4C[0x81] = -D_800F3CD0[arg0[0x47]];
        SCRATCH_4C[0x83] = D_800F3CD0[arg0[0x47]];
        return;
    }
    SCRATCH_4C[0x81] = 0;
    SCRATCH_4C[0x83] = D_800F3CD0[arg0[0x47]];
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern u8 D_800F3CD0[];

#define SPAD (*(u8**)0x1F80004C)
#define F(type, off) (*(type*)((u8*)self + (off)))

void func_800E9B6C(void* self) {
    u8* p;
    s32 t;

    if (F(s8, 0x45) == 1) {
        p = SPAD;
        if ((u8)--p[0x85] == 0) {
            F(s8, 5) = 3;
            F(s8, 6) = 0;
            return;
        }
        play_sound(2, 0x16, self);
        if (!(F(s8, 2) & 0xF0)) {
            set_animation(self, 0);
        } else {
            set_animation(self, 2);
        }
        t = F(u8, 2) & 0xF;
        if (t == 0) {
            F(s16, 0x7C) = 0xB4;
        } else if (t < 8) {
            F(s16, 0x7C) = 0xE;
        } else {
            F(s16, 0x7C) = 0xE;
        }
        F(s8, 6) = 1;
        return;
    }
    if (!(F(s8, 2) & 0xF0)) {
        SPAD[0x81] = -D_800F3CD0[F(u8, 0x47)];
        SPAD[0x83] = D_800F3CD0[F(u8, 0x47)];
        return;
    }
    SPAD[0x81] = 0;
    SPAD[0x83] = D_800F3CD0[F(u8, 0x47)];
}

#undef F
#undef SPAD

#define func_80041AB8 func_800E9CBC
#define D_80075FD8 D_800F3CEC
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern s32 D_800F3CBC;

#define SPADP ((s8**)0x1F80004C)

void func_800E9CF8(struct X4_MainObj* self) {
    u8 a;
    s32 x;
    s32 y;
    u8 t;
    s8** sp;

    sp = SPADP;
    {
        // !FAKE: depin: dropping it breaks the match (47/50)
        register s32 c asm("$2") = 0xC;
        self->hp = c;
    }
    a = *(u8*)&self->active;
    self->animation_table = (const u8* const*)&D_800F3CBC;
    x = self->x_pos.val;
    y = self->y_pos.val;
    self->contact_damage = 0x10;
    do {
        self->invincibility_timer = 0;
    } while (0);
    self->on_screen = 0;
    self->unk18.val = x;
    self->active = a | 0x10;
    self->unk1C.val = y;
    t = D_800970B4;
    self->unk16 = 7;
    self->air_state = 0;
    self->unk15 = 0;
    self->collision_data = &D_800743DC;
    self->hurt_box = 0;
    self->attack_box = 0;
    self->terrain_box = 0;
    self->x_speed = 0;
    self->x_accel = 0;
    self->y_speed = 0;
    self->gravity = 0;
    self->bg_offset = t;
    (*sp)[0x84] = 0;
    (*sp)[0x80] = -8;
    (*sp)[0x82] = 0x10;
    self->unk15 = 0;
    self->state = 1;
    self->action = 2;
    self->action_phase = 0;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800E9DC0(void) {
    func_8002CA54();
}

#include "common.h"

void func_800E9DE0(void) {
}

#define func_8003744C func_800E9DE8
#define D_80073C1C D_800F3D18
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_05/func_800E9E24.c"

#include "../shared/rock_05/func_800E9E80.c"

#define func_8003744C func_800E9EAC
#define D_80073C1C D_800F3D08
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_05/func_800E9EE8.c"

#include "common.h"

#define SCRATCH_4C (*(u8**)0x1F80004C)

extern u8 D_800F3CD0[];

void func_800E9FD4(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) == 1) {
        arg0[6]++;
        return;
    }
    if (!(*(s8*)(arg0 + 2) & 0xF0)) {
        SCRATCH_4C[0x81] = -D_800F3CD0[arg0[0x47]];
        SCRATCH_4C[0x83] = D_800F3CD0[arg0[0x47]];
        return;
    }
    SCRATCH_4C[0x81] = 0;
    SCRATCH_4C[0x83] = D_800F3CD0[arg0[0x47]];
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define FP(p, o) (*(void**)((u8*)(p) + (o)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK clear_object_slot();
s32 random_byte();

extern u8 D_800E9860[];
/* linker symbol at the same address as D_800E9860: a distinct symbol keeps cse from
   deriving the second table address from the first (the original had two rodata labels) */
extern u8 rock_05_RODATA_START[];
extern u8 D_800746FC;
extern u8 D_800F3D24;
extern u8 D_800F3D28;
extern u8 D_800F3D44;

void func_800EA07C(void* arg0) {
    u16 a[8];
    u16 b[3];
    s8 mode;
    u16 t;
    u16* src;

    __builtin_memcpy(a, D_800E9860 + 4, 16);
    src = (u16*)(rock_05_RODATA_START + 0x14);
    __builtin_memcpy(b, src, 6);
    mode = D_800CD30A;
    if (mode != 1) {
        clear_object_slot();
        return;
    }
    F8(arg0, 0x5C) = 8;
    F8(arg0, 0x60) = 2;
    FP(arg0, 0x58) = &D_800746FC;
    F8(arg0, 0x61) = 0;
    F8(arg0, 0x14) = D_800970B4;
    FP(arg0, 0x30) = &D_800F3D44;
    F8(arg0, 0x16) = 5;
    F32(arg0, 0x20) = 0;
    F32(arg0, 0x24) = 0;
    F8(arg0, 0x67) = 0;
    F8(arg0, 0x70) = 0;
    F8(arg0, 0x15) = 0;
    F32(arg0, 0x68) = 0;
    FP(arg0, 0x54) = &D_800F3D28;
    FP(arg0, 0x50) = &D_800F3D24;
    F16(arg0, 0x80) = a[random_byte() & 7];
    t = b[random_byte() % 3];
    F8(arg0, 0x85) = 0;
    F16(arg0, 0x82) = t;
    set_animation(arg0, 0);
    F8(arg0, 4) = mode;
    F8(arg0, 5) = mode;
    F8(arg0, 6) = 0;
}

#include "../shared/rock_05/func_800EA224.c"

#define func_80048DC8 func_800EA3D4
#define D_80077BC0 D_800F3D48
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "../shared/rock_05/func_800EA420.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EA51C(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800EA53C(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 < 0x3C) {
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        return;
    }
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();   /* extern */
M2C_UNK move_object(void*); /* extern */

void func_800EA590(struct MainObj* arg0) {
    arg0->x_speed = 0;
    arg0->y_speed = 0x50000;
    animate_object();
    move_object(arg0);
}

// clang-format off
INCLUDE_ASM("asm/rock_05/nonmatchings/E9860", func_800EA5C8);
// clang-format on

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK func_8002CA14();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002F288(M2C_UNK*);
s32 check_enemy_hits(void*);
M2C_UNK collide_solid_object();
M2C_UNK func_80031F4C();
M2C_UNK func_8003208C();
M2C_UNK func_80032BE8();
M2C_UNK func_80049E50(void*);
extern s32 D_800F3DB4;
extern void (*D_800F3DCC[])(s8*);

void func_800EA750(s8* arg0) {
    s8 temp_s1;
    s32 var_v0;

    ((void (*)())animate_object)();
    if (arg0[0x45] != 0) {
        *(s32**)(arg0 + 0x68) = &D_800F3DB4;
    } else {
        *(s32**)(arg0 + 0x68) = 0;
    }
    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    temp_s1 = arg0[0x5C];
    D_800F3DCC[arg0[5]](arg0);
    if (check_enemy_hits(arg0) < 0) {
        func_80049E50(arg0);
        *(s16*)(arg0 + 0x7C) = 0;
        arg0[4] = 2;
        return;
    }
    if (arg0[0x5C] != temp_s1) {
        *(u16*)(arg0 + 0x42) |= 0x8000;
    }
    func_80032BE8(arg0);
    func_8003208C(arg0);
    if (is_off_screen(arg0, 0x40, 0xF0) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
    }
    if (D_800CCEED >= arg0[2]) {
        arg0[3] = 0;
        func_8002CA14(arg0);
        return;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    ((void (*)(M2C_UNK*))func_8002F288)((M2C_UNK*)arg0);
    if (D_80097185 == 0) {
        collide_solid_object(arg0);
    }
    func_80031F4C(arg0);
    if ((u8)arg0[0x70] & 8) {
        arg0[0x67] = 0;
        return;
    }
    var_v0 = *(s32*)(arg0 + 0x24);
    if (var_v0 < 0) {
        var_v0 = -1;
    } else {
        var_v0 = 1;
    }
    arg0[0x67] = var_v0;
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
extern void (*D_800F3DBC[])(s8*);

void func_800EA8E8(s8* arg0) {
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    if (D_80097180 != 2 && is_off_screen(arg0, 0x40, 0xF0) != 1) {
        D_800F3DBC[arg0[4]](arg0);
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EA964(void) {
    func_8002CA54();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*);                            /* extern */
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800EA984(void* arg0) {
    s32 var_s0;
    u16 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x42) = (u16)(M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v1 + 1);
    if ((s16)temp_v1 < 0x3C) {
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        return;
    }
    M2C_FIELD(arg0, u8*, 3) = 0U;
    var_s0 = 3;
    do {
        func_80049EBC(arg0, 1, 0x10, 0x10);
        var_s0 -= 1;
    } while (var_s0 >= 0);
    func_8002CA14(arg0);
}

#include "../shared/rock_05/func_800EAA18.c"

#include "../shared/rock_05/func_800EAAA4.c"

#include "../shared/rock_05/func_800EAADC.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_20 (*(s32**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
void* func_8002BCCC(void*, s32);
void* func_8002C458();
M2C_UNK clear_object_slot();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern M2C_UNK D_8007433C;
extern s32 D_800748DC;
extern u32* D_80095098;
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800F3DD8;
extern s32 D_800F3DDC;
extern s32 D_800F3DE0;
extern s32 D_800F3DE4[];
extern s32 D_800F3ED8;

void func_800EAB28(void* self) {
    s8 t;
    s32 i;
    s32 a;
    s32 b;
    // !FAKE: depin: dropping it breaks the match (499/503)
    register s32 flag asm("$6");
    s32 x;
    void* o;
    void* ob;

    t = M2C_FIELD(self, s8*, 2);
    if ((t == 4 && D_800970AE < 0x950) || (t == 5 && D_800CCEED != 0)) {
        return;
    }
    M2C_FIELD(self, u8*, 0x5C) = 0x20;
    M2C_FIELD(self, u8*, 0x60) = 8;
    M2C_FIELD(self, u8*, 0x61) = 0;
    M2C_FIELD(self, u8*, 0x14) = g_Player.bg_offset;
    M2C_FIELD(self, void**, 0x30) = &D_800F3ED8;
    M2C_FIELD(self, s32*, 0x20) = 0;
    M2C_FIELD(self, s32*, 0x24) = 0;
    M2C_FIELD(self, u8*, 0x15) = 0;
    M2C_FIELD(self, u8*, 0x70) = 0;
    M2C_FIELD(self, u8*, 0x16) = 5;
    M2C_FIELD(self, u8*, 0x8D) = 0;
    M2C_FIELD(self, u8*, 0x8E) = 0;
    if (t >= 4) {
        if (t == 4) {
            if (D_800CCEED >= 3) {
                clear_object_slot(self);
                return;
            }
            M2C_FIELD(self, u16*, 0x40) =
                D_80095098[func_8002A47C(M2C_FIELD(self, s8*, 1))] >> 7;
            M2C_FIELD(self, void**, 0x3C) =
                (void*)((s32)SCRATCH_20 +
                        SCRATCH_20[func_8002A47C(M2C_FIELD(self, s8*, 1))]);
            M2C_FIELD(self, u16*, 0x42) =
                ((func_8002A47C(M2C_FIELD(self, s8*, 1)) * 4 + 0x20) % 16) |
                (((func_8002A47C(M2C_FIELD(self, s8*, 1)) + 8) / 4 + 0x1E0)
                 << 6);
            M2C_FIELD(self, u8*, 0x8D) = 1;
            M2C_FIELD(self, s16*, 0xA) = 0x430;
            M2C_FIELD(self, s16*, 0xE) = 0xAC0;
            func_8003D308(0x14, 0);
        } else if (t == 5) {
            if (g_Player.x_pos.i.hi < 0x16B && g_Player.y_pos.i.hi < 0x1D0) {
                return;
            }
            M2C_FIELD(self, u16*, 0x40) =
                D_80095098[func_8002A47C(M2C_FIELD(self, s8*, 1))] >> 7;
            M2C_FIELD(self, void**, 0x3C) =
                (void*)((s32)SCRATCH_20 +
                        SCRATCH_20[func_8002A47C(M2C_FIELD(self, s8*, 1))]);
            M2C_FIELD(self, u16*, 0x42) =
                ((func_8002A47C(M2C_FIELD(self, s8*, 1)) * 4 + 0x20) % 16) |
                (((func_8002A47C(M2C_FIELD(self, s8*, 1)) + 8) / 4 + 0x1E0)
                 << 6);
            M2C_FIELD(self, u8*, 0x8D) = 1;
            M2C_FIELD(self, s16*, 0xA) = 0x240;
            M2C_FIELD(self, s16*, 0xE) = 0x248;
            func_8003D308(0x14, 0x40);
        } else if (t == 6) {
            M2C_FIELD(self, s16*, 0xA) = 0xA50;
            M2C_FIELD(self, u8*, 0x8D) = 1;
            M2C_FIELD(self, s16*, 0xE) = 0x900;
            M2C_FIELD(self, u8*, 0x8C) = 0;
            func_8003D308(0x14, 0x40);
        } else if (t == 7) {
            M2C_FIELD(self, s16*, 0xA) = 0xA50;
            M2C_FIELD(self, s16*, 0xE) = 0xB80;
            M2C_FIELD(self, u8*, 0x8D) = 1;
            func_8003D308(0x14, 0x40);
        } else if (t == 8) {
            o = &g_Player;
            if (D_800CCEED == 5) {
                clear_object_slot(self);
                return;
            }
            flag = 0;
            background_objects[0].unk28 = background_objects[0].unk2A = 0xB00;
            if (((struct X4_PlayerObj*)o)->y_pos.i.hi < 0xAF0) {
                ((struct X4_PlayerObj*)o)->y_pos.i.hi = 0xAF0;
            }
            if (g_Player.x_pos.i.hi < 0xB80 && g_Player.y_pos.i.hi < 0xB60) {
                flag = 1;
            }
            if (g_Player.x_pos.i.hi > 0xBC0 && g_Player.x_pos.i.hi < 0xC00 &&
                g_Player.y_pos.i.hi < 0xB40) {
                flag = 1;
            }
            if (flag == 0) {
                return;
            }
            M2C_FIELD(self, s16*, 0xA) = 0xBD0;
            M2C_FIELD(self, s16*, 0xE) = background_objects[0].unk2A + 0x160;
            background_objects[2].unk3 = 1;
            *(s16*)&background_objects[2].unk40 = -0x120;
            background_objects[2].unk4C = 1;
            func_8003D308(0x14, g_Player.facing);
        } else if (t == 9) {
            if (D_800CCEED == 4) {
                clear_object_slot(self);
                return;
            }
            background_objects[0].unk28 = background_objects[0].unk2A = 0x870;
            M2C_FIELD(self, s16*, 0xA) = 0xBD0;
            M2C_FIELD(self, s16*, 0xE) = background_objects[0].unk2A + 0x160;
            background_objects[2].unk3 = 1;
            *(s16*)&background_objects[2].unk40 = -0x120;
            background_objects[2].unk4C = 1;
            func_8003D308(0x14, 0x40);
        } else if (t == 10) {
            if (M2C_FIELD(self, u8*, 0x90) == 0) {
                background_objects[0].unk2E -= 0x40;
                for (i = 0; i < 4; i++) {
                    o = func_8002C458();
                    if (o != NULL) {
                        M2C_FIELD(o, u8*, 0) = 0x41;
                        M2C_FIELD(o, u8*, 1) = 0x1D;
                        M2C_FIELD(o, u8*, 2) = 7;
                        M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(self, u16*, 0x40);
                        M2C_FIELD(o, u16*, 0x42) =
                            M2C_FIELD(self, u16*, 0x42) & 0x7FFF;
                        M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(self, s32*, 0x3C);
                        M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(self, s32*, 0x30);
                        M2C_FIELD(o, u8*, 0x14) = M2C_FIELD(self, u8*, 0x14);
                        M2C_FIELD(o, s16*, 0xA) = i * 0xA0 + 0xCE0;
                        M2C_FIELD(o, s16*, 0xE) = 0x518;
                    }
                }
                background_objects[2].unk3 = 1;
                background_objects[2].unk4 = 2;
                *(s16*)&background_objects[2].unk40 = -0x8E0;
                background_objects[2].unk42 = 0x260;
                background_objects[2].unk4C = 1;
                M2C_FIELD(self, s16*, 0xA) = 0xE20;
                M2C_FIELD(self, s16*, 0xE) =
                    background_objects[0].unk2A + 0x160;
                M2C_FIELD(self, u8*, 0x90) = 1;
            }
            if (g_Player.x_pos.i.hi < 0xD10) {
                return;
            }
            func_8003D308(0x14, 0x40);
        }
        background_objects[1].x_pos.i.hi = 0x200 - M2C_FIELD(self, u16*, 0xA);
        background_objects[1].y_pos.i.hi = 0x200 - M2C_FIELD(self, u16*, 0xE);
        background_objects[1].unk4C = 1;
        for (i = 0; i < 4; i++) {
            ob = func_8002BCCC(self, 0);
            if (ob != NULL) {
                M2C_FIELD(ob, u8*, 0) = 0x41;
                M2C_FIELD(ob, u8*, 1) = M2C_FIELD(self, u8*, 1);
                M2C_FIELD(ob, u8*, 2) = i;
                M2C_FIELD(ob, s32*, 0x10) = 0;
                M2C_FIELD(ob, u16*, 0x40) = M2C_FIELD(self, u16*, 0x40);
                M2C_FIELD(ob, u16*, 0x42) =
                    M2C_FIELD(self, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(ob, s32*, 0x3C) = M2C_FIELD(self, s32*, 0x3C);
                M2C_FIELD(ob, s32*, 0x30) = M2C_FIELD(self, s32*, 0x30);
                M2C_FIELD(ob, u8*, 0x14) = M2C_FIELD(self, u8*, 0x14);
                M2C_FIELD(ob, u16*, 0xA) = M2C_FIELD(self, u16*, 0xA);
                M2C_FIELD(ob, u16*, 0xE) = M2C_FIELD(self, u16*, 0xE);
                M2C_FIELD(ob, void**, 0x80) = self;
            }
            o = func_8002C458();
            if (o != NULL) {
                M2C_FIELD(o, u8*, 0) = 0x41;
                M2C_FIELD(o, u8*, 1) = 0x1D;
                M2C_FIELD(o, u8*, 2) = i;
                M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(self, u16*, 0x40);
                M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(self, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(self, s32*, 0x3C);
                M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(self, s32*, 0x30);
                M2C_FIELD(o, u8*, 0x14) = M2C_FIELD(self, u8*, 0x14);
                M2C_FIELD(o, s32*, 0x8) = M2C_FIELD(self, s32*, 0x8);
                M2C_FIELD(o, s32*, 0xC) = M2C_FIELD(self, s32*, 0xC);
                M2C_FIELD(o, void**, 0x7C) = self;
            }
        }
        background_objects[1].unk3 = 1;
        background_objects[1].pad52[0] = 0;
        if (M2C_FIELD(self, s8*, 2) < 8) {
            M2C_FIELD(self, void**, 0x68) = &D_800F3DD8;
            M2C_FIELD(self, u8*, 5) = 9;
        } else if (M2C_FIELD(self, s8*, 2) == 10) {
            M2C_FIELD(self, u8*, 5) = 9;
        } else {
            M2C_FIELD(self, void**, 0x68) = 0;
            M2C_FIELD(self, u8*, 5) = 10;
        }
        if (M2C_FIELD(self, s8*, 2) == 4) {
            background_objects[1].unk3 = 0;
        }
        M2C_FIELD(self, void**, 0x54) = &D_800F3DE0;
        M2C_FIELD(self, void**, 0x50) = &D_800F3DDC;
        M2C_FIELD(self, void**, 0x58) = &D_8007433C;
        M2C_FIELD(self, u8*, 3) = 0;
        g_playthrough_state.character_state.bytes[0] = 0;
    } else {
        M2C_FIELD(self, void**, 0x68) = 0;
        M2C_FIELD(self, void**, 0x50) = 0;
        M2C_FIELD(self, void**, 0x54) = &D_800F3DE4[t];
        M2C_FIELD(self, void**, 0x58) = &D_800748DC;
        ((void (*)(void*, s32))set_animation)(self, t);
        M2C_FIELD(self, u8*, 5) = 1;
    }
    M2C_FIELD(self, s16*, 0x7C) = 0;
    M2C_FIELD(self, u8*, 4) = 1;
    M2C_FIELD(self, s16*, 0x7E) = 0;
    M2C_FIELD(self, u8*, 7) = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);

extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800E9860[];
extern void (*D_800F3F2C[])(void*);

void func_800EB304(void* self) {
    s16 offs[4][2];
    void* parent;
    s32 r;

    __builtin_memcpy(offs, D_800E9860 + 0x1C, 0x10);
    parent = M2C_FIELD(self, void**, 0x80);
    D_800F3F2C[M2C_FIELD(self, s8*, 5)](self);
    r = check_enemy_hits(self);
    if (M2C_FIELD(self, s8*, 2) >= 4) {
        if ((u32)(M2C_FIELD(self, u8*, 5) - 9) >= 2) {
            M2C_FIELD(self, u8*, 0x5C) = 0;
        }
        if (M2C_FIELD(self, s8*, 7) >= 4) {
            M2C_FIELD(self, s16*, 0x7E) = 0;
            M2C_FIELD(self, s8*, 5) = 8;
            M2C_FIELD(self, s8*, 6) = 0;
            M2C_FIELD(self, s8*, 7) = 0;
            M2C_FIELD(self, s32*, 0x54) = 0;
            M2C_FIELD(self, s32*, 0x50) = 0;
        }
        func_80030ECC(self);
        func_8002F288(self);
        if (is_off_screen(self, 0x80, 0x80) == 0) {
            func_8002CCB0(self, 0x60, 0x60);
        }
        background_objects[1].unk3 = M2C_FIELD(self, u8*, 3);
        M2C_FIELD(self, u8*, 3) = 0;
        background_objects[1].x_pos.i.hi = 0x200 - M2C_FIELD(self, s16*, 0xA);
        background_objects[1].y_pos.i.hi = 0x200 - M2C_FIELD(self, s16*, 0xE);
        background_objects[1].unk4C = 1;
        return;
    }
    if ((u32)(M2C_FIELD(parent, u8*, 5) - 9) >= 2) {
        M2C_FIELD(parent, u8*, 0x5C) += M2C_FIELD(self, u8*, 0x5C);
        if (M2C_FIELD(parent, s8*, 0x5C) == -0x80) {
            M2C_FIELD(parent, u8*, 0x5C) = 0x7F;
        }
    }
    if (r < 0) {
        func_80049E50(self);
        M2C_FIELD(self, s8*, 4) = 2;
        M2C_FIELD(parent, u8*, 7)++;
        return;
    }
    if (is_off_screen(self, 0x40, 0x40) == 0) {
        func_8002CCB0(self, 0x20, 0x20);
    }
    M2C_FIELD(self, s16*, 0xA) =
        M2C_FIELD(parent, s16*, 0xA) + offs[M2C_FIELD(self, s8*, 2)][0];
    M2C_FIELD(self, s16*, 0xE) =
        M2C_FIELD(parent, s16*, 0xE) + offs[M2C_FIELD(self, s8*, 2)][1];
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
void* func_8002C458();
s32 random_byte();
#include "mmx6/state.h"
#include "mmx6/globals.h"
extern struct X4_EngineObj g_playthrough_state;

void func_800EB538(void* arg0) {
    u8* e;
    void* p;
    void* o;
    s32 v;

    e = (u8*)&g_playthrough_state;
    p = M2C_FIELD(arg0, void**, 0x80);
    if (M2C_FIELD(e, u8*, 0x68) != 0 && M2C_FIELD(p, s8*, 5) < 8 &&
        M2C_FIELD(p, s8*, 0x8D) != 0 &&
        (u32)D_80097420.frame_counter ==
            ((u32)D_80097420.frame_counter / 120) * 120) {
        o = func_8002C458();
        if (o != 0) {
            M2C_FIELD(o, u8*, 0) = 0x41;
            M2C_FIELD(o, u8*, 1) = 0x1D;
            if (M2C_FIELD(e, u8*, 0x68) != 1 && D_800970A2 == 0) {
                v = (random_byte() & 1) + 4;
            } else {
                v = 4;
            }
            M2C_FIELD(o, u8*, 2) = v;
            M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(o, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(o, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(o, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(o, void**, 0x7C) = arg0;
            play_sound(2, 0x1F, arg0);
        }
    }
    animate_object(arg0);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);

void func_800EB694(void* self) {
    s8 old;
    s32 dir;

    if (M2C_FIELD(self, s16*, 0x7C) != 0) {
        M2C_FIELD(self, s16*, 0x7C)--;
        return;
    }
    if (M2C_FIELD(self, s32*, 0x20) > 0x1FFFF) {
        M2C_FIELD(self, s32*, 0x20) = 0x20000;
    }
    if (M2C_FIELD(self, s32*, 0x24) <= -0x20000) {
        M2C_FIELD(self, s32*, 0x24) = -0x20000;
    }
    ((void (*)(void*))apply_object_motion)(self);
    if (M2C_FIELD(self, s16*, 0xA) > 0x7A0 && M2C_FIELD(self, s8*, 0x8C) == 0) {
        M2C_FIELD(self, s8*, 0x8C)++;
        M2C_FIELD(self, s32*, 0x2C) = 0xD00;
        M2C_FIELD(self, s32*, 0x24) = 0x2D000;
        play_sound(2, 0x18, self);
        start_pad_vibration(3);
        func_8002943C(0x3C, 2, 1);
    }
    if (M2C_FIELD(self, s16*, 0xA) > 0x8C0 && M2C_FIELD(self, s8*, 0x8C) == 1) {
        M2C_FIELD(self, s8*, 0x8C)++;
        M2C_FIELD(self, s32*, 0x2C) = 0xD00;
        M2C_FIELD(self, s32*, 0x24) = 0x2D000;
        play_sound(2, 0x18, self);
        start_pad_vibration(3);
        func_8002943C(0x3C, 2, 1);
    }
    if ((M2C_FIELD(self, u8*, 0x70) & 1) &&
        M2C_FIELD(self, s16*, 0xA) > 0xA60) {
        play_sound(2, 0x18, self);
        start_pad_vibration(3);
        M2C_FIELD(self, s16*, 0x7C) = 0x3C;
        func_8002943C(0x3C, 2, 1);
        M2C_FIELD(self, s8*, 6) = 0;
    }
    old = M2C_FIELD(self, s8*, 0x67);
    if (M2C_FIELD(self, u8*, 0x70) & 8) {
        M2C_FIELD(self, s8*, 0x67) = 0;
    } else {
        dir = M2C_FIELD(self, s32*, 0x24);
        if (dir < 0) {
            dir = -1;
        } else {
            dir = 1;
        }
        M2C_FIELD(self, s8*, 0x67) = dir;
    }
    if (M2C_FIELD(self, s8*, 0x67) == 0 && old != 0) {
        play_sound(2, 0x18, self);
        start_pad_vibration(3);
        func_8002943C(0x1E, 2, 1);
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EB898(void* self) {
    s8 old;
    s32 dir;

    if (F(s16, 0x7C) != 0) {
        F(s16, 0x7C)--;
        return;
    }
    if (F(s32, 0x20) <= -0x20000) {
        F(s32, 0x20) = -0x20000;
    }
    if (F(s32, 0x24) <= -0x20000) {
        F(s32, 0x24) = -0x20000;
    }
    ((void (*)(void*))apply_object_motion)(self);
    if (F(s16, 0xA) < 0x960 && F(s8, 0x8C) == 0) {
        F(s8, 0x8C)++;
        F(s32, 0x2C) = 0xD00;
        F(s32, 0x24) = 0x2D000;
        play_sound(2, 0x18, self);
        start_pad_vibration(3);
        func_8002943C(0x3C, 2, 1);
    }
    if (F(s16, 0xA) < 0x840 && F(s8, 0x8C) == 1) {
        F(s8, 0x8C)++;
        F(s32, 0x2C) = 0xD00;
        F(s32, 0x24) = 0x2D000;
        play_sound(2, 0x18, self);
        start_pad_vibration(3);
        func_8002943C(0x3C, 2, 1);
    }
    if ((F(u8, 0x70) & 2) && F(s16, 0xA) < 0x680) {
        play_sound(2, 0x18, self);
        start_pad_vibration(3);
        F(s32, 0x20) = 0x10000;
        F(s32, 0x28) = -0x1000;
        F(s32, 0x24) = 0;
        F(s32, 0x2C) = 0;
        F(s16, 0x7C) = 0x3C;
        play_sound(2, 0x18, self);
        start_pad_vibration(3);
        func_8002943C(0x3C, 2, 1);
        F(s8, 0x8C) = 0;
        F(u8, 6) = 1;
    }
    old = F(s8, 0x67);
    if (F(u8, 0x70) & 8) {
        F(s8, 0x67) = 0;
    } else {
        dir = F(s32, 0x24);
        if (dir < 0) {
            dir = -1;
        } else {
            dir = 1;
        }
        F(s8, 0x67) = dir;
    }
    if (F(s8, 0x67) == 0 && old != 0) {
        play_sound(2, 0x18, self);
        start_pad_vibration(3);
        func_8002943C(0x1E, 2, 1);
    }
}

#undef F

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern void (*D_800F3F9C[])(void*);

void func_800EBAD0(void* arg0) {
    void* s2;
    void* s3;

    D_800F3F9C[M2C_FIELD(arg0, s8*, 6)](arg0);
    s2 = M2C_FIELD(arg0, void**, 0x84);
    s3 = M2C_FIELD(arg0, void**, 0x88);
    if (g_Player.nova_strike_active == 0) {
        if (background_objects[0].unk2A > 0x3B0) {
            if (!(D_80097420.frame_counter & 3)) {
                background_objects[0].unk2A--;
                background_objects[0].unk28--;
                M2C_FIELD(arg0, s16*, 0xE)--;
            }
        } else {
            play_sound(5, 3, arg0);
        }
    }
    if (g_Player.y_pos.i.hi < background_objects[0].unk2A - 0x10) {
        g_Player.y_pos.i.hi = background_objects[0].unk2A - 0x10;
    }
    M2C_FIELD(s2, s16*, 0x90) = background_objects[0].unk2A + 0xC0;
    M2C_FIELD(s3, s16*, 0x90) = background_objects[0].unk2A + 0xC0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002B36C(M2C_UNK);
struct X4_VisualObj* find_free_visual_obj(void);
s32 func_8002D30C();
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_8009742C;
extern s16 D_80097430;
extern s8 D_800CF850;
extern s16 D_800CF854;

void func_800EBBF4(void* arg0) {
    struct X4_VisualObj* obj;
    s32 r;
    s32 t;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_8002B36C(0);
        D_80090D56 = 0;
        D_8009742C = 0;
        D_800CF850 = 0;
        D_80090D5C = 0;
        D_80097430 = 0;
        D_800CF854 = 0;
        D_800C4560 |= 1;
        M2C_FIELD(arg0, u8*, 6)++;
        return;
    }
    if (!(M2C_FIELD(arg0, u8*, 0x7C) & 7)) {
        obj = find_free_visual_obj();
        if (obj != 0) {
            obj->active = 0x21;
            obj->id = 4;
            obj->unk2 = 0;
            obj->state = 0;
            obj->unk5 = 0;
            obj->unk6 = 0;
            if (M2C_FIELD(arg0, s8*, 2) == 0) {
                r = func_8002D30C() % 64 - 0x20;
                obj->x_pos.i.hi = M2C_FIELD(arg0, s16*, 0xA) + r;
            } else {
                r = func_8002D30C() % 64 - 0x20;
                obj->x_pos.i.hi = M2C_FIELD(arg0, s16*, 0xA) - r;
            }
            r = func_8002D30C() % 64 - 0x20;
            obj->y_pos.i.hi = M2C_FIELD(arg0, s16*, 0xE) + r;
            t = M2C_FIELD(arg0, u8*, 0x14);
            obj->unk16 = 0x13;
            obj->bg_offset = t;
        }
    }
    background_objects[1].unk3 ^= 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void* func_8002C458();
extern struct X4_BackgroundObj background_objects[3];

void func_800EBDA8(void* arg0) {
    void* o;
    void* o2;
    u8* g;
    s32 t;

    if (D_800970A5 == 0x14) {
        o = func_8002C458();
        if (o != 0) {
            M2C_FIELD(o, u8*, 0) = 0x41;
            M2C_FIELD(o, u8*, 1) = 0x1D;
            M2C_FIELD(o, u8*, 2) = 6;
            M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            t = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(o, s16*, 0xA) = 0xB80;
            M2C_FIELD(o, u8*, 0x14) = t;
            M2C_FIELD(o, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(arg0, void**, 0x84) = o;
        }
        o2 = func_8002C458();
        if (o2 != 0) {
            M2C_FIELD(o2, u8*, 0) = 0x41;
            M2C_FIELD(o2, u8*, 1) = 0x1D;
            M2C_FIELD(o2, u8*, 2) = 6;
            M2C_FIELD(o2, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(o2, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(o2, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(o2, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            t = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(o2, s16*, 0xA) = 0xC20;
            M2C_FIELD(o2, u8*, 0x14) = t;
            M2C_FIELD(o2, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(arg0, void**, 0x88) = o2;
        }
        g = (u8*)background_objects;
        M2C_FIELD(g, u8*, 0xAC) = 9;
        M2C_FIELD(g, s16*, 0xB2) = 0x3C0;
        M2C_FIELD(g, s16*, 0xB6) = 0x640;
        M2C_FIELD(g, u8*, 0xF4) = 1;
        M2C_FIELD(arg0, u8*, 6)++;
        play_sound(5, 1, arg0);
        start_pad_vibration(4);
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007433C;
extern struct X4_PlayerObj g_Player;
extern s32 D_800F3FF4;
extern s32 D_800F3FF8;
extern s32 D_800F3FFC;
extern s32 D_800F4000;
extern s32 D_800F4004;

#define BF_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define BF_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define BF_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define BF_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define BF_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_800EBF1C(void* arg0) {
    s32 ang;
    s8 t;

    BF_U8(arg0, 0x16) = 4;
    t = BF_S8(arg0, 0x2);
    BF_U8(arg0, 0x6) = 0;
    BF_S16(arg0, 0x8C) = 0;
    BF_PTR(arg0, 0x68) = 0;
    BF_PTR(arg0, 0x54) = 0;
    BF_PTR(arg0, 0x50) = 0;
    BF_U8(arg0, 0x4)++;
    if (t == 0) {
        set_animation(arg0, 0xA);
        BF_U8(arg0, 0x5) = 0;
        BF_U8(arg0, 0x15) = 0x40;
    } else if (t == 1) {
        set_animation(arg0, 0xA);
        BF_U8(arg0, 0x5) = 0;
        BF_U8(arg0, 0x15) = 0;
    } else if (t == 2) {
        set_animation(arg0, 0xB);
        BF_U8(arg0, 0x5) = 0;
        BF_U8(arg0, 0x15) = 0;
    } else if (t == 3) {
        set_animation(arg0, 0xC);
        BF_U8(arg0, 0x5) = 0;
        BF_U8(arg0, 0x15) = 0;
    } else if (t == 4) {
        BF_U8(arg0, 0x60) = 4;
        BF_U8(arg0, 0x5C) = 2;
        ang = ratan2(g_Player.y_pos.i.hi - BF_S16(arg0, 0xE),
                     g_Player.x_pos.i.hi - BF_S16(arg0, 0xA));
        BF_S32(arg0, 0x20) = rcos(ang) << 6;
        BF_S32(arg0, 0x24) = -rsin(ang) << 6;
        BF_PTR(arg0, 0x50) = &D_800F3FF4;
        BF_PTR(arg0, 0x54) = &D_800F3FF8;
        BF_PTR(arg0, 0x68) = &D_800F3FFC;
        BF_PTR(arg0, 0x58) = &D_800743DC;
        set_animation(arg0, 9);
        BF_U8(arg0, 0x5) = 1;
    } else if (t == 5) {
        BF_U8(arg0, 0x60) = 4;
        BF_U8(arg0, 0x5C) = 2;
        ang = ratan2(g_Player.y_pos.i.hi - BF_S16(arg0, 0xE),
                     g_Player.x_pos.i.hi - BF_S16(arg0, 0xA));
        BF_S32(arg0, 0x20) = rcos(ang) << 6;
        BF_S32(arg0, 0x24) = -rsin(ang) << 6;
        BF_PTR(arg0, 0x50) = &D_800F3FF4;
        BF_PTR(arg0, 0x54) = &D_800F3FF8;
        BF_PTR(arg0, 0x68) = &D_800F3FFC;
        BF_PTR(arg0, 0x58) = &D_8007433C;
        set_animation(arg0, 9);
        BF_U8(arg0, 0x5) = 1;
    } else if (t == 6) {
        BF_U8(arg0, 0x60) = 0x7F;
        BF_PTR(arg0, 0x50) = &D_800F4000;
        BF_U8(arg0, 0x5) = 2;
    } else if (t == 7) {
        BF_U8(arg0, 0x60) = 0x7F;
        BF_PTR(arg0, 0x50) = &D_800F4004;
        BF_U8(arg0, 0x5) = 2;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();

extern u8 D_800E9860[];

void func_800EC148(void* self) {
    s16 offs[4][2];
    void* parent;
    s8 idx;

    __builtin_memcpy(offs, D_800E9860 + 0x2C, 0x10);
    parent = M2C_FIELD(self, void**, 0x7C);
    animate_object(self);
    idx = M2C_FIELD(self, s8*, 2);
    M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(parent, s16*, 0xA) + offs[idx][0];
    M2C_FIELD(self, s16*, 0xE) = M2C_FIELD(parent, s16*, 0xE) + offs[idx][1];
    M2C_FIELD(self, u8*, 3) = 0;
    if ((idx == 0 && M2C_FIELD(parent, s8*, 6) == 1) ||
        (idx == 1 && M2C_FIELD(parent, s8*, 6) == 3) ||
        (idx == 2 && M2C_FIELD(parent, s8*, 6) == idx) ||
        (idx == 3 && M2C_FIELD(parent, s8*, 6) == 4)) {
        M2C_FIELD(self, u8*, 3) = 1;
    }
    if (M2C_FIELD(parent, s8*, 5) >= 8 || M2C_FIELD(parent, s16*, 0x7C) != 0) {
        M2C_FIELD(self, u8*, 3) = 0;
    }
    if (!(D_80097420.frame_counter & 0x1F) && M2C_FIELD(self, s8*, 3) != 0) {
        play_sound(2, 3, self);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_05.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);

extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];
extern void (*D_800F4014[])(void*);

void func_800EC2D0(void* self) {
    struct ObjectHeader* parent;
    s32 r;

    parent = M2C_FIELD(self, void**, 0x7C);
    r = check_enemy_hits(self);
    D_800F4014[M2C_FIELD(self, s8*, 5)](self);
    if (M2C_FIELD(self, s8*, 5) == 1) {
        if (func_80030ECC(self) != 0) {
            ((void (*)(void*))func_80049E50)(self);
            // !FAKE: goto shares the state store in the next arm; an else-if chain moved bytes
            goto set;
        }
        if (M2C_FIELD(self, u8*, 0x70) != 0) {
            func_80049E50(self);
            // !FAKE: goto shares the state store in the next arm; an else-if chain moved bytes
            goto set;
        }
        if (r < 0) {
            ((long long (*)(void*))func_80049E50)(self);
            // !FAKE: goto shares the state store in the next arm; an else-if chain moved bytes
            goto set;
        }
        if (is_off_screen(self, 0x60, 0x60) == 0) {
            func_8002CCB0(self, 0x40, 0x40);
            return;
        }
        // !FAKE: goto shares the state store in the next arm; an else-if chain moved bytes
        goto set;
    } else if (M2C_FIELD(self, s8*, 5) == 0) {
        if (parent->state == 3) {
        set:
            M2C_FIELD(self, s8*, 4) = 2;
        }
    } else {
        if (M2C_FIELD(self, s8*, 2) == 6) {
            M2C_FIELD(self, u16*, 0xE) = M2C_FIELD(self, u16*, 0x90);
            if (M2C_FIELD(self, s16*, 0xA) == 0xB80) {
                if ((u32)D_80097420.frame_counter % 10 == 0) {
                    M2C_FIELD(self, u8*, 0x92) =
                        (M2C_FIELD(self, u8*, 0x92) + 1) & 3;
                    background_objects[2].unk40 =
                        D_800F3F0C[M2C_FIELD(self, u8*, 0x92)] - 0xB20;
                }
                background_objects[2].unk4C = 1;
            }
        } else {
            if (M2C_FIELD(self, s16*, 0xA) == 0xCE0) {
                if ((u32)D_80097420.frame_counter % 10 == 0) {
                    M2C_FIELD(self, u8*, 0x92) =
                        (M2C_FIELD(self, u8*, 0x92) + 1) & 3;
                    background_objects[2].unk40 =
                        D_800F3F0C[M2C_FIELD(self, u8*, 0x92)] - 0xCA0;
                }
                background_objects[2].unk4C = 1;
            }
            if (D_800970AA > 0xEF0) {
                background_objects[0].unk2E += 0x40;
                M2C_FIELD(self, s8*, 4) = 2;
                return;
            }
        }
        func_80030ECC(self);
    }
}
