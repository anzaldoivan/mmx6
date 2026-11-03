// clang-format off
INCLUDE_ASM("asm/rock_01/nonmatchings/1EA000", D_801EA000);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
s32 get_tile_attr_above(void*);
M2C_UNK start_jump(void*);
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK player_clear_dash();
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
s32 func_801ECCD4();

s32 func_801EA004(void* arg0) {
    s32 var_v0;

    if (func_801ECCD4(arg0) == 0) {
        return 0;
    }
    player_set_animation(arg0, 0x6A);
    play_sound(1, 7, arg0);
    if (random_byte() & 4) {
        play_sound_unless_low_health(arg0, 8);
    }
    ((void (*)(void*))player_clear_dash)(arg0);
    M2C_FIELD(arg0, u8*, 0x5) = 0x3D;
    M2C_FIELD(arg0, u8*, 0x6) = 1;
    if (M2C_FIELD(arg0, u16*, 0x80) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (M2C_FIELD(arg0, u16*, 0x80) & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    if (M2C_FIELD(arg0, s8*, 0xD3) == 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        if (M2C_FIELD(arg0, u16*, 0x80) & 0x80) {
            start_jump(arg0);
            return 1;
        }
        {
            s32 one = 1;
            M2C_FIELD(arg0, u8*, 0x8E) = one;
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        var_v0 = get_tile_attr_above(arg0);
        if (var_v0 == 0x2E) {
            var_v0 = 0x1B;
        } else {
            var_v0 = 0x1C;
        }
        M2C_FIELD(arg0, u8*, 0x5) = var_v0;
        M2C_FIELD(arg0, u8*, 0x6) = 1;
    }
    return 1;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
s32 get_tile_attr_above(void*);
s32 func_8003A814(void*, s32);
M2C_UNK start_jump(void*);
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK player_clear_dash();
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
s32 func_801ECCD4();

s32 func_801EA124(void* arg0) {
    u8* p = arg0;
    s32 v;

    if (func_801ECCD4() == 0) {
        return 0;
    }
    player_set_animation(p, func_8003A814(p, get_tile_attr_above(p) & 0xFF) +
                                0x6B);
    play_sound(1, 8, p);
    if (random_byte() & 4) {
        play_sound_unless_low_health(p, 8);
    }
    ((void (*)(void*))player_clear_dash)(p);
    {
        s32 t = 1;
        p[5] = 0x3D;
        p[6] = t;
    }
    if (*(u16*)(p + 0x80) & 2) {
        p[0x15] = 0;
    }
    if (*(u16*)(p + 0x80) & 1) {
        p[0x15] = 0x40;
    }
    if (*(s8*)(p + 0xD3) == 0) {
        p[0x8E] = 0;
        if (*(u16*)(p + 0x80) & 0x80) {
            start_jump(p);
            return 1;
        }
        p[0x8E] = 1;
    }
    if (*(s8*)(p + 0x46) == 0) {
        p[0x8E] = 0;
        v = get_tile_attr_above(p);
        if (v == 0x2E) {
            v = 0x1B;
        } else {
            v = 0x1C;
        }
        p[5] = v;
        p[6] = 1;
    }
    return 1;
}

#include "common.h"

#define M2C_UNK s32

void* func_8002C32C();
s32 get_weapon_energy_cost(void* arg0, s32 arg1);
void use_weapon_energy(void*, s32);

#define F(T, o) (*(T*)((u8*)arg0 + (o)))
M2C_UNK check_yammar_option_input(void* arg0) {
    s32 r;
    u8* q;

    if (!(F(u8, 0xC9) & 1)) {
        return 0;
    }
    if (!(F(u16, 0x7C) & 4)) {
        return 0;
    }
    if (!(F(u16, 0x80) & 0x20)) {
        return 0;
    }
    if (F(s8, 0xA6) == 1) {
        return 0;
    }
    if (get_weapon_energy_cost(arg0, 3) > F(s16, 0xAE)) {
        return 0;
    }
    if (F(s8, 0x8E) != 0) {
        return 0;
    }
    q = func_8002C32C();
    if (q != 0) {
        F(s8, 0xA6) = 1;
        q[0] = 1;
        q[1] = 1;
        q[2] = 0;
        q[0x14] = F(u8, 0x14);
        F(u8, 0x93) = 3;
        use_weapon_energy(arg0, 3);
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

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
M2C_UNK func_801EC440(void*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))

s32 func_801EA34C(void* arg0) {
    if (F_S8(arg0, 0xD3) != 0) {
        return 0;
    }
    if (!(F_U8(arg0, 0xC9) & 8)) {
        return 0;
    }
    if (!(F_U16(arg0, 0x7C) & 8)) {
        return 0;
    }
    if (!(F_U16(arg0, 0x80) & 0x10)) {
        return 0;
    }
    if (F_S8(arg0, 0x8E) != 0) {
        return 0;
    }
    F_U8(arg0, 0xDD) = 1;
    F_U8(arg0, 0x8E) = 1;
    F_U8(arg0, 0xCB) = 0;
    F_U8(arg0, 0x8C) = 0;
    player_set_animation(arg0, 0x62);
    play_sound_unless_low_health(arg0, 5);
    play_sound(1, 0x17, arg0);
    if (F_U16(arg0, 0x7C) & 2) {
        F_U8(arg0, 0x15) = 0;
    }
    if (F_U16(arg0, 0x7C) & 1) {
        F_U8(arg0, 0x15) = 0x40;
    }
    F_U8(arg0, 0x93) = 2;
    F_U8(arg0, 0x5) = 0x38;
    F_U8(arg0, 0x6) = 0;
    func_801EC440(arg0);
    return 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK player_set_animation(void*, M2C_UNK);
void player_load_weapon_palette(struct X4_PlayerObj* self);
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
M2C_UNK func_801EC4AC(void*);

#define FLD(t, o) (*(t*)((u8*)arg0 + (o)))

s32 check_sentsuizan_input(void* arg0) {
    if (FLD(s8, 0xD3) != 0) {
        return 0;
    }
    if (!(FLD(u8, 0xC9) & 0x10)) {
        return 0;
    }
    if (!(FLD(u16, 0x7C) & 4)) {
        return 0;
    }
    if (!(FLD(u16, 0x80) & 0x10)) {
        return 0;
    }
    if (FLD(s8, 0x8E) != 0) {
        return 0;
    }
    FLD(s8, 0xDD) = 1;
    FLD(s8, 0x8E) = 1;
    FLD(s8, 0xCB) = 0;
    FLD(s8, 0x8C) = 0;
    player_set_animation(arg0, 0x65);
    play_sound(1, 0x19, arg0);
    play_sound_unless_low_health(arg0, 9);
    FLD(s8, 0x61) = 0;
    FLD(s8, 0xA4) = 0;
    player_load_weapon_palette(arg0);
    FLD(s8, 0x5) = 0x39;
    FLD(s8, 0x7A) = 1;
    FLD(s8, 0x6) = 0;
    FLD(s32, 0x20) = 0xFFFD0000;
    if (FLD(u8, 0x15) != 0) {
        FLD(s32, 0x20) = 0x30000;
    }
    FLD(s32, 0x24) = 0xFFFB0000;
    func_801EC4AC(arg0);
    return 1;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK player_set_animation(void*, M2C_UNK);
void player_load_weapon_palette(struct X4_PlayerObj* self);
M2C_UNK player_clear_dash();
M2C_UNK play_sound_unless_low_health(void*, M2C_UNK);
void func_801EC504(void* arg0);
M2C_UNK func_801ECD90();

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))

s32 check_ensuizan_input(void* arg0) {
    if (F_S8(arg0, 0xD3) != 0 || F_S8(arg0, 0x86) == 8 ||
        !(F_U8(arg0, 0xC9) & 0x20) || !(F_U16(arg0, 0x7C) & 8) ||
        !(F_U16(arg0, 0x80) & 0x20)) {
        return 0;
    }
    if (F_S8(arg0, 0x8E) != 0) {
        return 0;
    }
    F_S8(arg0, 0xDD) = 1;
    F_S8(arg0, 0x8E) = 1;
    F_S8(arg0, 0xCB) = 0;
    F_S8(arg0, 0x8C) = 0;
    player_clear_dash(arg0);
    player_set_animation(arg0, 0x67);
    func_801ECD90(arg0, 0x2A);
    play_sound_unless_low_health(arg0, 5);
    play_sound(1, 0x18, arg0);
    F_S8(arg0, 0x61) = 0;
    F_S8(arg0, 0xA4) = 0;
    player_load_weapon_palette(arg0);
    F_S8(arg0, 0x7A) = 1;
    F_S8(arg0, 0x5) = 0x3A;
    F_S8(arg0, 0x6) = 0;
    F_S8(arg0, 0x86) = 8;
    func_801EC504(arg0);
    return 1;
}
