#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK func_80017A04();
M2C_UNK func_8002D230(void*);
M2C_UNK func_8002F288(M2C_UNK*);
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
void func_800F40E0(struct X4_MainObj* self);
extern u8 D_800FC6FC[];

void func_800F35BC(struct X4_MainObj* self) {
    s16 x;
    s16 y;
    u8 hit;
    u8 dir;
    u8 mask;
    struct X4_Unk_unk68* box;

    if (self->unk6 == 0) {
        func_800F40E0(self);
        self->unk6 = 1;
        return;
    }
    x = self->x_pos.i.hi;
    y = self->y_pos.i.hi;
    if (SP_CUR_MAIN_OBJ->ext.main_19.animation_index == 0) {
        u8 d = SP_CUR_MAIN_OBJ->ext.main_19.unk80;
        if (d == 2) {
            y -= 2;
        }
        if (d == 3) {
            x -= 2;
            y -= 2;
        }
    } else {
        u8 d = SP_CUR_MAIN_OBJ->ext.main_19.unk80;
        if (d == 1) {
            x += 2;
            y -= 2;
        }
        if (d == 2) {
            x -= 2;
            y -= 2;
        }
        if (d == 3) {
            x -= 2;
            y += 2;
        }
    }
    hit = func_80030234((struct X4_PlayerObj*)self, x, y);
    SP_CUR_MAIN_OBJ->ext.main_19.unk82 = hit;
    dir = SP_CUR_MAIN_OBJ->ext.main_19.unk80;
    mask =
        D_800FC6FC[(SP_CUR_MAIN_OBJ->ext.main_19.animation_index << 2) + dir];
    if (hit < 0x38) {
        self->x_pos.i.hi = SP_CUR_MAIN_OBJ->ext.main_19.unk86;
        self->y_pos.i.hi = SP_CUR_MAIN_OBJ->ext.main_19.unk88;
        SP_CUR_MAIN_OBJ->ext.main_19.unk83 ^= 1;
        if (SP_CUR_MAIN_OBJ->ext.main_19.animation_index != 0) {
            SP_CUR_MAIN_OBJ->ext.main_19.unk80--;
        } else {
            SP_CUR_MAIN_OBJ->ext.main_19.unk80++;
        }
        SP_CUR_MAIN_OBJ->ext.main_19.unk80 &= 3;
        func_800F40E0(self);
    } else if (self->collision_flags & mask) {
        switch (mask) {
        case 1:
            box = self->terrain_box;
            self->x_pos.i.hi += box->unk0 + box->unk2;
            self->y_pos.i.hi += box->unk1;
            SP_CUR_MAIN_OBJ->ext.main_19.unk80 = mask;
            break;
        case 2:
            box = self->terrain_box;
            self->x_pos.i.hi -= box->unk0 + box->unk2;
            self->y_pos.i.hi += box->unk1;
            SP_CUR_MAIN_OBJ->ext.main_19.unk80 = 3;
            break;
        case 4:
            if (dir == 1) {
                self->x_pos.i.hi -= self->terrain_box->unk0;
            } else {
                self->x_pos.i.hi += self->terrain_box->unk0;
            }
            box = self->terrain_box;
            self->y_pos.i.hi -= box->unk1 + box->unk3;
            SP_CUR_MAIN_OBJ->ext.main_19.unk80 = 2;
            break;
        case 8:
            if (dir == 1) {
                self->x_pos.i.hi -= self->terrain_box->unk0;
            } else {
                self->x_pos.i.hi += self->terrain_box->unk0;
            }
            box = self->terrain_box;
            self->y_pos.i.hi += box->unk1 + box->unk3;
            SP_CUR_MAIN_OBJ->ext.main_19.unk80 = 0;
            break;
        default:
            func_80017A04(self);
            break;
        }
        func_800F40E0(self);
    } else {
        func_80017A04(self);
    }
    SP_CUR_MAIN_OBJ->ext.main_19.unk86 = self->x_pos.i.hi;
    SP_CUR_MAIN_OBJ->ext.main_19.unk88 = self->y_pos.i.hi;
    func_8002D230(self);
    func_8002F288((M2C_UNK*)self);
}
