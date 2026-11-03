// prog SLUS_013.95 | system graphics | range 0x8003D10C-0x8003D188
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK player_set_animation(void*, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;

M2C_UNK set_stand_animation_by_hp(void* arg0) {
    u8* p = arg0;
    s32 t;
    s32 i = *(s8*)(p + 2);
    u8* e = (u8*)&g_playthrough_state;
    t = (s8)(e - -i)[0x5B] / 3;
    if (*(s8*)(p + 0x5C) >= (s8)t) {
        player_set_animation(p, 5);
    } else {
        player_set_animation(p, 6);
    }
}
