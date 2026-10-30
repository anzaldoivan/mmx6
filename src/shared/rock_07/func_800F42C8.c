#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK silence_sound(M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;

void func_800F42C8(void* arg0) {
    struct X4_PlayerObj* g;

    silence_sound(2, 0x14);
    play_sound(2, 0x20, arg0);
    g = &g_Player;
    M2C_FIELD(g, u8*, 0xCA) = 0;
    func_8003D308(0x14, g->unk15);
    set_animation(arg0, 0x1C);
    M2C_FIELD(arg0, u8*, 5) = 1;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x7F;
    M2C_FIELD(arg0, s16*, 0x7E) = 0x19;
    M2C_FIELD(arg0, u8*, 0x61) = 0x19;
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
    func_8002CCB0(arg0, 0x60, 0x60);
}
