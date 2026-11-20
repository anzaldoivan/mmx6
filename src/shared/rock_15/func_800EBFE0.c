// rolefeed (3.1 T4): func_800EBFE0 of src/rock_15/E9860.c
// clang-format off

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
void func_800EC478(void*);
void func_800EC648(void*);

extern struct X4_EngineObj g_playthrough_state;

void func_800EBFE0(void* arg0) {
    animate_object();
    if ((s8)(s32)g_playthrough_state.controlled_player !=
        (M2C_FIELD(arg0, s32*, 0x84) & 1)) {
        set_animation(arg0, 2);
    } else {
        set_animation(arg0, 1);
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if ((M2C_FIELD(arg0, s32*, 0x84) == 2) &&
            ((s8)(s32)g_playthrough_state.controlled_player == 0)) {
            play_sound(2, 0x56, arg0);
            func_800EC648(arg0);
        } else {
            play_sound(2, 0x56, arg0);
            func_800EC478(arg0);
        }
    } else {
        play_sound(2, 0x56, arg0);
        func_800EC478(arg0);
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 0x4B;
    if (M2C_FIELD(arg0, s8*, 2) == 2) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
    }
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
