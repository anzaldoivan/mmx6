#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK player_set_animation(void*, M2C_UNK); /* extern */
M2C_UNK func_801EB02C(void*);                 /* extern */

void func_8003FE74(void* arg0, s32 arg1) {
    s8 var_v0;

    M2C_FIELD(arg0, s8*, 7) = 0;
    if (((M2C_FIELD(arg0, s32*, 4) & 0xFFFF00) == 0xB00) ||
        (M2C_FIELD(arg0, s8*, 5) == 0x2F)) {
        player_set_animation(arg0, 0xBB);
        var_v0 = 2;
        M2C_FIELD(arg0, s8*, 7) = var_v0;
    } else if (arg1 == 0) {
        player_set_animation(arg0, 0xB7);
        M2C_FIELD(arg0, s8*, 7) = 0;
    } else {
        player_set_animation(arg0, 0xB8);
        var_v0 = 1;
        M2C_FIELD(arg0, s8*, 7) = var_v0;
    }
    M2C_FIELD(arg0, s8*, 5) = 0x4C;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 0x67) = 1;
    func_801EB02C(arg0);
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);

void func_8003FF1C(void* arg0, s32 arg1) {
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = 0x26;
    if (arg1 == 0) {
        M2C_FIELD(arg0, u8*, 0x7) = 0;
        player_set_animation(arg0, 0xB9);
    } else {
        M2C_FIELD(arg0, u8*, 0x7) = 1;
        player_set_animation(arg0, 0xBA);
    }
    M2C_FIELD(arg0, u8*, 0x86) = 0xA;
    player_spawn_visual(1, 0x1B, 6, 0);
}
