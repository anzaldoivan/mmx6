#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK player_set_animation(void*, M2C_UNK);

void func_8003FAFC(void* arg0) {
    player_set_animation(arg0, 0x61);
    play_sound(1, 0x1A, arg0);
    ((u8*)arg0)[0x67] = 1;
    ((u8*)arg0)[0x5] = 0x28;
    ((u8*)arg0)[0x6] = 0;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK player_set_animation(void*, M2C_UNK);
void* player_spawn_weapon(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);

void func_8003FB48(void* arg0) {
    player_set_animation(arg0, 0x5F);
    M2C_FIELD(arg0, s8*, 0x67) = 1;
    player_spawn_weapon(1, 0xB, 0, 0);
    M2C_FIELD(arg0, s8*, 0xA6) = 1;
    player_spawn_visual(1, 0x1B, 9, 0);
    M2C_FIELD(arg0, s8*, 5) = 0x27;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 7) = 0;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK player_set_animation(void*, M2C_UNK);

void func_8003FBBC(void* arg0) {
    ((void (*)(void*, s32))player_set_animation)(arg0, 0x5F);
    ((u8*)arg0)[0x67] = 1;
    ((u8*)arg0)[5] = 0x2B;
    ((u8*)arg0)[6] = 0;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK player_set_animation_frame(void*, M2C_UNK, s8); /* extern */

void func_8003FBF8(void* arg0) {
    s32 var_v1;

    var_v1 = 1;
    M2C_FIELD(arg0, s8*, 0x8E) = 0;
    M2C_FIELD(arg0, s8*, 0x8F) = 0;
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        s32 temp = M2C_FIELD(arg0, u8*, 0x89) & 1;
        var_v1 = temp == 0;
    } else if (M2C_FIELD(arg0, u8*, 0x89) & 2) {
        var_v1 = 0;
    }
    M2C_FIELD(arg0, s8*, 5) = 0x2C;
    M2C_FIELD(arg0, s8*, 7) = 0;
    if (var_v1 != 0) {
        M2C_FIELD(arg0, s8*, 6) = 0;
        return;
    }
    ((void (*)(void*, M2C_UNK, s8))player_set_animation_frame)(arg0, 0x60, 2);
    M2C_FIELD(arg0, s8*, 6) = 2;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_EngineObj g_playthrough_state;

void func_8003FC88(void* arg0) {
    M2C_FIELD(arg0, s8*, 5) = 0x4B;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 7) = 0;
    g_playthrough_state.gameplay_locked = 1;
    M2C_FIELD(arg0, s8*, 0x67) = 1;
    M2C_FIELD(arg0, s8*, 0xE1) = 0;
    g_playthrough_state.unk16 = 1;
    g_playthrough_state.unk12 = 1;
    g_playthrough_state.unk13 = 1;
    g_playthrough_state.unk19 = 1;
    g_playthrough_state.unk18 = 1;
    g_playthrough_state.unk17 = 1;
    g_playthrough_state.unk14 = 1;
    g_playthrough_state.unk15 = 1;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK player_set_animation(void*, M2C_UNK);

void func_8003FCD4(void* arg0) {
    ((void (*)(void*, s32))player_set_animation)(arg0, 0x5F);
    M2C_FIELD(arg0, u8*, 0x67) = 1;
    M2C_FIELD(arg0, u8*, 0xA6) = 2;
    M2C_FIELD(arg0, u8*, 5) = 0x2A;
    M2C_FIELD(arg0, u8*, 6) = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK player_set_animation(void*, M2C_UNK);

void func_8003FD18(void* arg0) {
    // !FAKE: pins the shared constant one to the register retail uses
    register s32 one asm("$3");
    ((void (*)(void*, s32))player_set_animation)(arg0, 0x5F);
    one = 1;
    M2C_FIELD(arg0, u8*, 0xE0) = 2;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, u8*, 0x7A) = one;
    D_800CCEEC = one;
    M2C_FIELD(arg0, u8*, 0x67) = one;
    M2C_FIELD(arg0, u8*, 5) = 0x29;
    M2C_FIELD(arg0, u8*, 6) = 0;
}
