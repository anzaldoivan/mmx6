#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];

void func_800F5648(u8* self) {
    u16 x;
    if (*(s8*)(self + 0x45) == 1) {
        x = g_Player.x_pos.i.hi;
        *(s16*)(self + 0x84) = x;
        *(s16*)(self + 0x86) = g_Player.y_pos.i.hi - 0x70;
        if ((s16)x < background_objects[0].unk26 + 0x28) {
            *(s16*)(self + 0x84) = background_objects[0].unk26 + 0x28;
        } else if (background_objects[0].unk26 + 0x138 < (s16)x) {
            *(s16*)(self + 0x84) = background_objects[0].unk26 + 0x138;
        }
        if (*(s16*)(self + 0x86) < background_objects[0].unk2A + 0x30) {
            *(s16*)(self + 0x86) = background_objects[0].unk2A + 0x30;
        }
        self[6]++;
    }
}
