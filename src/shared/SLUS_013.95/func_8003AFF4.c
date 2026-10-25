#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);

M2C_UNK func_8003AFF4(s32 arg0) {
    u8* p = (u8*)arg0;

    player_set_animation_shooting((struct X4_PlayerObj*)p, 0xB);
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s8*)(p + 0x67) = -1;
    *(s32*)(p + 0x2C) = *(s32*)(p + 0x100);
    if (*(s8*)(p + 0x84) != 0) {
        *(s8*)(p + 0x84) = 0;
        *(s8*)(p + 0x8C) = -1;
    }
    p[5] = 7;
    p[6] = 0;
}
