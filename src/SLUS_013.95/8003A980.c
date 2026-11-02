#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003CDBC();        /* extern */
void func_8003CE30(void* arg0); /* extern */

void func_8003A980(void* arg0) {
    M2C_FIELD(arg0, s8*, 0xCF) = 1;
    M2C_FIELD(arg0, s8*, 0x84) = 0;
    M2C_FIELD(arg0, s8*, 0x8C) = 0;
    func_8003CDBC();
    func_8003CE30(arg0);
}

void func_8003A9BC(void) {
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
M2C_UNK func_8003CFE0(void*, M2C_UNK);
void func_8003D18C(void* arg0);
void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);
extern u8 D_80073CE4[];

void func_8003A9C4(struct X4_PlayerObj* self) {
    s8 state;

    self->dash_momentum = 1;
    self->air_action = 1;
    if (self->pressed_input & 0x80) {
        s32 temp = M2C_FIELD(self, s32*, 0xF8);
        self->air_state = 1;
        {
            // !FAKE: depin: dropping it breaks the match (63/67)
            register s32 one asm("$3") = 1;
            self->afterimage = one;
        }
        self->air_action = 2;
        M2C_FIELD(self, s32*, 0x20) = 0;
        M2C_FIELD(self, s32*, 0x28) = 0;
        M2C_FIELD(self, s8*, 0x8B) = 0xA;
        M2C_FIELD(self, s32*, 0x24) = temp;
        M2C_FIELD(self, s32*, 0x2C) = M2C_FIELD(self, s32*, 0x134);
        ((void (*)())player_set_animation_shooting)(self, 0xA, temp);
        if (random_byte() & 4) {
            func_8003CFE0(self, D_80073CE4[(random_byte() & 3) +
                                           M2C_FIELD(self, s8*, 2) * 4]);
        }
        func_8003D18C(self);
        state = 6;
    } else {
        player_set_animation_shooting(self, 0x10);
        M2C_FIELD(self, s32*, 0x24) = 0;
        M2C_FIELD(self, s32*, 0x2C) = 0;
        M2C_FIELD(self, s32*, 0x28) = M2C_FIELD(self, s32*, 0x10C);
        if (M2C_FIELD(self, s32*, 0xEC) & 0x10) {
            self->dash_timer = 0xF;
        } else {
            self->dash_timer = 0x1E;
        }
        state = 0xC;
    }
    M2C_FIELD(self, s8*, 5) = state;
    do {
    } while (0);
    M2C_FIELD(self, s8*, 6) = 0;
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_8003AAD0);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8003A628(void*);                  /* extern */
M2C_UNK func_8003BB94(void*, M2C_UNK, s8); /* extern */
M2C_UNK func_8003CD9C();                   /* extern */
M2C_UNK func_8003D10C(void*);              /* extern */

void func_8003AD18(void* arg0) {
    s32 var_a2;
    u8 temp_v0;
    u8 temp_v1;

    func_8003CD9C();
    if (func_8003A628(arg0) == 0) {
        M2C_FIELD(arg0, s8*, 5) = 2;
        M2C_FIELD(arg0, s8*, 6) = 0;
        if ((M2C_FIELD(arg0, s8*, 2) == 0) &&
            (M2C_FIELD(arg0, s8*, 0x8E) != 0)) {
            temp_v0 = M2C_FIELD(arg0, u8*, 0x91);
            var_a2 = temp_v0 < 9U;
            if (temp_v0 < 5U) {
                var_a2 = 2;
            }
            func_8003BB94(arg0, 0x5E, var_a2);
            temp_v1 = M2C_FIELD(arg0, u8*, 0x91);
            if (temp_v1 >= 9U) {
                M2C_FIELD(arg0, s8*, 0x44) = (s8)(temp_v1 - 8);
            }
        } else {
            func_8003D10C(arg0);
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8003A628(void*);                  /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK);     /* extern */
M2C_UNK func_8003BB94(void*, M2C_UNK, s8); /* extern */
M2C_UNK func_8003CD9C();                   /* extern */
M2C_UNK func_8003D10C(void*);              /* extern */

void func_8003ADB4(void* arg0) {
    s32 var_a2;
    u8 temp_v0;
    u8 temp_v1;

    if (func_8003A628(arg0) == 0) {
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            func_8003CD9C(arg0);
            if (func_8003A628(arg0) == 0) {
                M2C_FIELD(arg0, s8*, 5) = 2;
                M2C_FIELD(arg0, s8*, 6) = 0;
                if ((M2C_FIELD(arg0, s8*, 2) == 0) &&
                    (M2C_FIELD(arg0, s8*, 0x8E) != 0)) {
                    temp_v0 = M2C_FIELD(arg0, u8*, 0x91);
                    var_a2 = temp_v0 < 9U;
                    if (temp_v0 < 5U) {
                        var_a2 = 2;
                    }
                    func_8003BB94(arg0, 0x5E, var_a2);
                    temp_v1 = M2C_FIELD(arg0, u8*, 0x91);
                    if (temp_v1 >= 9U) {
                        M2C_FIELD(arg0, s8*, 0x44) = (s8)(temp_v1 - 8);
                    }
                } else {
                    func_8003D10C(arg0);
                }
            }
        } else {
            ((void (*)(void*, s32))func_8003BA04)(arg0, 9);
            M2C_FIELD(arg0, s8*, 5) = 5;
            M2C_FIELD(arg0, s8*, 6) = 0;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002D5D0(void*);
void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);

M2C_UNK func_8003AE8C(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    player_set_animation_shooting(self, 7);
    self->y_vel.val = 0;
    self->unk28 = 0;
    self->unk2C = 0;
    func_8002D5D0(self);
    self->unk5 = 3;
    self->unk6 = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002D5D0(void*);
void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);

M2C_UNK func_8003AED4(void* arg0) {
    u8* p = arg0;

    player_set_animation_shooting(arg0, 8);
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2C) = 0;
    func_8002D5D0(p);
    p[5] = 4;
    p[6] = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
M2C_UNK func_8003CFE0(void*, M2C_UNK);
void func_8003D18C(void* arg0);
void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);
extern u8 D_80073CE4[];

M2C_UNK func_8003AF1C(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x67) = 1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0xF8);
    M2C_FIELD(arg0, s32*, 0x2C) = M2C_FIELD(arg0, s32*, 0x134);
    if (M2C_FIELD(arg0, s8*, 0x84) != 0 ||
        (M2C_FIELD(arg0, u16*, 0x7C) & 0x100)) {
        M2C_FIELD(arg0, s8*, 0x84) = 1;
        M2C_FIELD(arg0, s8*, 0x86) = 2;
        M2C_FIELD(arg0, s8*, 0x8C) = 1;
    }
    M2C_FIELD(arg0, s8*, 0x8B) = 0xA;
    player_set_animation_shooting(arg0, 0xA);
    if (random_byte() & 4) {
        func_8003CFE0(
            arg0,
            D_80073CE4[(random_byte() & 3) + M2C_FIELD(arg0, s8*, 2) * 4]);
    }
    func_8003D18C(arg0);
    M2C_FIELD(arg0, s8*, 5) = 6;
    M2C_FIELD(arg0, s8*, 6) = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);

M2C_UNK func_8003AFF4(s32 arg0) {
    u8* p = (u8*)arg0;

    player_set_animation_shooting((struct X4_PlayerObj*)p, 0xB);
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s8*)(p + 0x67) = -1;
    *(s32*)(p + 0x2C) = *(s32*)(p + 0x100);
    if (*(s8*)(p + 0x84) != 0) {
        *(s8*)(p + 0x84) = 0;
        *(s8*)(p + 0x8C) = -1;
    }
    p[5] = 7;
    p[6] = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2);
s32 player_check_dash_jump_walk(struct X4_PlayerObj* self);
s32 func_8003A628(void*);
M2C_UNK func_8003CD9C();
s32 func_8003F13C(void*);
void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);
s32 func_801EBE04(void*);
s32 func_801EBE54(void*);

M2C_UNK func_8003B054(void* arg0) {
    play_sound(1, 2, arg0);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    func_8003CD9C(arg0);
    if ((func_8003A628(arg0) == 0) && (func_8003F13C(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) || (func_801EBE04(arg0) == 0)) &&
        (player_check_dash_jump_walk(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) || (func_801EBE54(arg0) == 0))) {
        player_set_animation_shooting(arg0, 0xC);
        M2C_FIELD(arg0, u8*, 5) = 8;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
