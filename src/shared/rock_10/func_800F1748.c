#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);

extern struct X4_PlayerObj D_800970A0;
#define PLAYER (*(struct X4_PlayerObj*)&D_800970A0)

void func_800F1748(struct X4_BaseObj* self) {
    if (M2C_FIELD(self, s8*, 0x67) != 0) {
        return;
    }
    if (M2C_FIELD(self, u8*, 0x80) & 3) {
        return;
    }
    if (M2C_FIELD(self, u8*, 0x83) != 0) {
        M2C_FIELD(self, u8*, 0x83)--;
        return;
    }
    if ((self->y_pos.i.hi - PLAYER.y_pos.i.hi >= 0
             ? self->y_pos.i.hi - PLAYER.y_pos.i.hi
             : PLAYER.y_pos.i.hi - self->y_pos.i.hi) < 0x28) {
        if (self->unk15 != 0) {
            if (PLAYER.x_pos.i.hi < self->x_pos.i.hi + 0x50) {
                M2C_FIELD(self, u8*, 0x81)++;
            } else {
                M2C_FIELD(self, u8*, 0x81) = 0;
            }
        } else {
            if (self->x_pos.i.hi - 0x50 < PLAYER.x_pos.i.hi) {
                M2C_FIELD(self, u8*, 0x81)++;
            } else {
                M2C_FIELD(self, u8*, 0x81) = 0;
            }
        }
        if (M2C_FIELD(self, u8*, 0x81) >= 0x3D) {
            self->unk5 = 4;
            self->unk6 = 0;
            func_800179A4(self, 7);
            M2C_FIELD(self, u8*, 0x81) = 0;
            M2C_FIELD(self, u8*, 0x80) |= 2;
        }
    } else {
        M2C_FIELD(self, u8*, 0x81) = 0;
    }
}
