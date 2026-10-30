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
