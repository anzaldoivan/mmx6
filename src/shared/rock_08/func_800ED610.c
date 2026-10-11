#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
extern M2C_UNK D_800743DC;
extern struct X4_PlayerObj D_800970A0;
extern s32 D_800F5888;
extern s32 D_800F588C;
extern s32 D_800F5890;
extern s32 D_800F58D8;

void func_800ED610(struct X4_BaseObj* self) {
    struct X4_PlayerObj* pl = &D_800970A0;
    s32 x;
    s32 y;
    u8 b;

    M2C_FIELD(self, u8*, 0x5C) = 0x20;
    M2C_FIELD(self, u8*, 0x60) = 4;
    M2C_FIELD(self, u8*, 0x61) = 0;
    M2C_FIELD(self, void**, 0x58) = &D_800743DC;
    b = M2C_FIELD(pl, u8*, 0x14);
    x = self->x_pos.val;
    y = self->y_pos.val;
    M2C_FIELD(self, u8*, 0x67) = 0;
    M2C_FIELD(self, u8*, 0x70) = 0;
    M2C_FIELD(self, u8*, 0x14) = b;
    M2C_FIELD(self, s32*, 0x18) = x;
    M2C_FIELD(self, s32*, 0x1C) = y;
    if (pl->x_pos.val < x) {
        self->unk15 = 0;
    } else {
        self->unk15 = 0x40;
    }
    M2C_FIELD(self, s32*, 0x20) = 0;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x24) = 0;
    {
        register s32 c asm("$3") = 6;
        M2C_FIELD(self, void**, 0x30) = &D_800F58D8;
        self->unk16 = c;
    }
    M2C_FIELD(self, s32*, 0x2C) = 0x4200;
    M2C_FIELD(self, void**, 0x68) = &D_800F5888;
    M2C_FIELD(self, void**, 0x54) = &D_800F5890;
    M2C_FIELD(self, void**, 0x50) = &D_800F588C;
    ((void (*)(void*, s32))func_800179A4)(self, 1);
    self->unk5 = 1;
    M2C_FIELD(self, s16*, 0x7C) = 0;
    self->state = 1;
    self->unk6 = 0;
}
