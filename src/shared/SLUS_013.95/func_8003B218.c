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
