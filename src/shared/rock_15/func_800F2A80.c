#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
extern struct X4_EngineObj g_playthrough_state;

void func_800F2A80(void* arg0) {
    s8* e = (s8*)&g_playthrough_state;

    if (M2C_FIELD(e, u8*, 0x68) >= 2) {
        if (M2C_FIELD(e, s8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
            M2C_FIELD(arg0, s16*, 0x7E) = 2;
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
        }
    } else {
        if (M2C_FIELD(e, s8*, 0x8C) / 2 >= M2C_FIELD(arg0, s8*, 0x5C)) {
            M2C_FIELD(arg0, s16*, 0x7E) = 2;
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 1;
        }
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    set_animation(arg0, 1);
    play_sound(2, (random_byte() & 1) | 0x24, arg0);
    M2C_FIELD(arg0, u8*, 6) += 1;
}
