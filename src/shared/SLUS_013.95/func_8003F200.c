#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);

s32 func_8003F200(struct X4_PlayerObj* self) {
    u8 v;

    v = M2C_FIELD(self, u8*, 0xE7);
    if (v != 4) {
        return 0;
    }
    if (!(M2C_FIELD(self, u16*, 0x80) & 0x80)) {
        return 0;
    }
    M2C_FIELD(self, s32*, 0x20) = 0;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x24) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0;
    M2C_FIELD(self, u8*, 0x84) = 0;
    M2C_FIELD(self, u8*, 0x86) = v;
    M2C_FIELD(self, u8*, 0x8C) = 0;
    M2C_FIELD(self, u8*, 0xD9) = 0xB4;
    M2C_FIELD(self, u8*, 0xDA) = 0;
    player_set_animation_shooting(self, 0x15);
    self->unk5 = 0x21;
    self->unk6 = 0;
    return 1;
}
