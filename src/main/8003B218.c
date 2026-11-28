#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void silence_sound(u8, u8);
void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);

M2C_UNK func_8003B218(void* arg0) {
    player_set_animation_shooting(arg0, 0x11);
    silence_sound(1, 5);
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x108);
    } else {
        M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x108);
    }
    M2C_FIELD(arg0, s8*, 0x8C) = -1;
    M2C_FIELD(arg0, s8*, 0x84) = 0;
    M2C_FIELD(arg0, s8*, 0x86) = 0;
    M2C_FIELD(arg0, s8*, 0x6) = 2;
    M2C_FIELD(arg0, s32*, 0x28) = M2C_FIELD(arg0, s32*, 0x10C);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK player_set_animation(void*, M2C_UNK);
void player_clear_attack();

M2C_UNK func_8003B298(void* arg0) {
    u8* p = arg0;
    s8 v;
    s32 t;
    s32 u;

    player_set_animation(arg0, 0x12);
    u = *(s32*)(p + 0x10C);
    t = *(s32*)(p + 0xEC) & 0x10;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x2C) = 0;
    *(s8*)(p + 0x84) = -1;
    *(s32*)(p + 0x28) = u;
    do {
    } while (0);
    v = 0x12;
    if (t) {
        v = 0xA;
    }
    *(s8*)(p + 0x85) = v;
    do {
    } while (0);
    {
        // !FAKE: pin the call argument so the join store issues first
        register u8* a asm("$4") = p;
        *(s8*)(p + 0x86) = 3;
        ((void (*)())player_clear_attack)(a);
    }
    *(s8*)(p + 5) = 0xD;
    *(s8*)(p + 6) = 0;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK player_set_animation(void*, M2C_UNK);

M2C_UNK func_8003B30C(void* arg0) {
    s32 t;

    ((void (*)(void*, s32))player_set_animation)(arg0, 0x13);
    t = M2C_FIELD(arg0, s32*, 0x100);
    M2C_FIELD(arg0, s8*, 0x67) = -1;
    M2C_FIELD(arg0, s8*, 0x8C) = -1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s8*, 0x84) = 0;
    M2C_FIELD(arg0, s8*, 0x6) = 2;
    M2C_FIELD(arg0, s32*, 0x2C) = t;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK player_set_animation(void*, M2C_UNK);

// 0x8003B360 func_8003B360: enters action 7 with velocities cleared, gravity from +0x100 and animation 0x84.
// basis: none
// callers: func_80037130
void func_8003B360(void* arg0) {
    u8* p = arg0;

    ((void (*)(void*, s32))player_set_animation)(arg0, 0x84);
    *(s8*)(p + 0x67) = -1;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x24) = 0;
    *(u8*)(p + 0x84) = 0;
    *(u8*)(p + 0x8C) = 0;
    *(u8*)(p + 0x5) = 7;
    *(u8*)(p + 0x6) = 0;
    *(s32*)(p + 0x2C) = *(s32*)(p + 0x100);
}
