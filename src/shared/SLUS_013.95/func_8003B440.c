#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80016C48(s32 a0, s32 a1, void* arg2);
void func_8003C964(void* arg0);
M2C_UNK func_8003CD9C();
M2C_UNK func_8003CFE0(void*, M2C_UNK);
void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);

void func_8003B440(void* arg0) {
    player_set_animation_shooting(arg0, 0xE);
    func_80016C48(1, 3, arg0);
    func_8003CFE0(arg0, 2);
    {
        s32 one = 1;
        // !FAKE: depin: dropping it breaks the match (58/66)
        register s32 t asm("$2");
        M2C_FIELD(arg0, s8*, 0x67) = one;
        t = M2C_FIELD(arg0, u16*, 0x7C) & 0x100;
        if (t) {
            M2C_FIELD(arg0, s8*, 0x84) = one;
            M2C_FIELD(arg0, s8*, 0x86) = one;
            M2C_FIELD(arg0, s8*, 0x8C) = one;
        } else {
            func_8003CD9C(arg0);
        }
    }
    if (M2C_FIELD(arg0, u8*, 0x89) & 1) {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
        if (M2C_FIELD(arg0, s8*, 0x84) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x108);
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0xF4);
        }
    } else {
        M2C_FIELD(arg0, s8*, 0x15) = 0;
        if (M2C_FIELD(arg0, s8*, 0x84) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x108);
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0xF4);
        }
    }
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s8*, 0x8A) = 0xA;
    M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x114);
    M2C_FIELD(arg0, s32*, 0x2C) = M2C_FIELD(arg0, s32*, 0x134);
    func_8003C964(arg0);
    M2C_FIELD(arg0, s8*, 5) = 0xA;
    M2C_FIELD(arg0, s8*, 6) = 0;
}
