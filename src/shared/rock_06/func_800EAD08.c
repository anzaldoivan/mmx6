#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
extern M2C_UNK D_800743DC;
extern M2C_UNK g_Player;
extern M2C_UNK D_800F3698;
extern M2C_UNK D_800F369C;
extern M2C_UNK D_800F36A4;
extern M2C_UNK D_800F379C;

void func_800EAD08(void* arg0) {
    struct X4_AnimatedObj* self = arg0;
    s32 x;
    s32 f;
    s32 m;
    self->state++;
    self->unk5 = 1;
    x = self->x_pos.val;
    self->bg_offset = (*(struct X4_PlayerObj*)&g_Player).bg_offset;
    self->unk18.val = x;
    self->unk1C.val = self->y_pos.val;
    f = ((*(struct X4_PlayerObj*)&g_Player).x_pos.val >= x) << 6;
    self->animation_table = (u32**)&D_800F379C;
    self->unk16 = 6;
    M2C_FIELD(arg0, M2C_UNK**, 0x68) = &D_800F3698;
    M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800F36A4;
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800F369C;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800743DC;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x70) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 3;
    M2C_FIELD(arg0, u8*, 0x60) = 1;
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_vel.val = 0;
    self->unk2C = 0;
    M2C_FIELD(arg0, u8*, 0x80) = 0;
    M2C_FIELD(arg0, u8*, 0x82) = 0;
    M2C_FIELD(arg0, u8*, 0x81) = 0;
    M2C_FIELD(arg0, u8*, 0x83) = 0;
    self->unk15 = f;
    if ((u32)(M2C_FIELD(arg0, u8*, 2) - 2) < 2U) {
        self->state = 3;
        M2C_FIELD(arg0, void**, 0x54) = 0;
        M2C_FIELD(arg0, void**, 0x50) = 0;
        m = -0x10;
        self->x_pos.u.hi = (self->x_pos.u.hi & m) + 8;
        self->y_pos.u.hi = (self->y_pos.u.hi & m) + 0x14;
        func_800179A4(arg0, 0);
    } else {
        func_800179A4(arg0, 1);
    }
}
