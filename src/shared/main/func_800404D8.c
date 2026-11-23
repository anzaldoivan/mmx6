#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_20 (*(s32**)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_800429D4();
void func_80042C18(struct X4_MainObj* self);
s16 func_80042C48(void*);
extern M2C_UNK D_800743DC;
extern s32 D_80075EDC;
extern s32 D_80075EE4;
extern s32 D_80075FB0;
extern u32* D_80095098;
extern u8 D_800970B4;
extern u8 D_800CCF38;

void func_800404D8(struct X4_MainObj* self) {
    s32 v;
    s32 k;
    u8 bg;
    u8* bp;
    void* f;
    void* e;

    self->contact_damage = 4;
    self->hp = 10;
    switch (D_800CCF38) {
    case 0:
        self->hp = 2;
        break;
    case 1:
        break;
    case 2:
    default:
        self->hp += 8;
        break;
    }
    e = &D_80075FB0;
    self->animation_table = e;
    e = &D_80075EE4;
    f = &D_80075EDC;
    do {
    } while (0);
    self->hurt_box = e;
    do {
    } while (0);
    bp = &D_800970B4;
    self->invincibility_timer = 0;
    self->on_screen = 0;
    self->terrain_box = 0;
    self->attack_box = f;
    bg = *bp;
    self->unk15 = 0;
    self->unk16 = 3;
    self->air_state = 0;
    self->collision_data = &D_800743DC;
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->bg_offset = bg;
    self->unk18.val = self->x_pos.val;
    self->unk1C.val = self->y_pos.val;
    func_80042C18(self);
    M2C_FIELD(self, u8*, 0x8D) = 0;
    M2C_FIELD(self, s16*, 0x8A) = 0;
    M2C_FIELD(self, u8*, 0x8F) = 0;
    M2C_FIELD(self, u8*, 0x8E) = 0;
    M2C_FIELD(self, u8*, 0x4) = 1;
    M2C_FIELD(self, u8*, 0x6) = 0;
    k = M2C_FIELD(self, s8*, 2) & 0xF0;
    if (k == 0) {
        M2C_FIELD(self, s16*, 0x88) = func_80042C48(self);
        func_800429D4(self);
    } else if (k == 0x10) {
        M2C_FIELD(self, u8*, 0x16) = 1;
        M2C_FIELD(self, u16*, 0x40) =
            D_80095098[func_8002A47C(M2C_FIELD(self, s8*, 1))] >> 7;
        M2C_FIELD(self, void**, 0x3C) =
            (void*)((s32)SCRATCH_20 +
                    SCRATCH_20[func_8002A47C(M2C_FIELD(self, s8*, 1))]);
        M2C_FIELD(self, u16*, 0x42) =
            ((func_8002A47C(M2C_FIELD(self, s8*, 1)) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(self, s8*, 1)) + 8) / 4 + 0x1E0) << 6);
        M2C_FIELD(self, u8*, 0x60) = 0;
        M2C_FIELD(self, u8*, 0x8E) = 1;
        M2C_FIELD(self, void**, 0x50) = 0;
        M2C_FIELD(self, u8*, 0x8D) = 1;
        switch (M2C_FIELD(self, u8*, 2) & 0xF) {
        case 0:
            func_800179A4(self, 8);
            v = 200;
            break;
        case 1:
            func_800179A4(self, 9);
            v = 100;
            break;
        default:
            return;
        }
        k = 7;
        M2C_FIELD(self, s16*, 0x8A) = v;
        M2C_FIELD(self, u8*, 0x5) = k;
    } else if (k == 0x20) {
        M2C_FIELD(self, s16*, 0x88) = func_80042C48(self);
        M2C_FIELD(self, u8*, 0x8C) = 1;
        M2C_FIELD(self, u8*, 0x5) = 6;
    } else if (k == 0x30) {
        M2C_FIELD(self, u16*, 0x40) =
            D_80095098[func_8002A47C(M2C_FIELD(self, s8*, 1))] >> 7;
        M2C_FIELD(self, void**, 0x3C) =
            (void*)((s32)SCRATCH_20 +
                    SCRATCH_20[func_8002A47C(M2C_FIELD(self, s8*, 1))]);
        M2C_FIELD(self, u16*, 0x42) =
            ((func_8002A47C(M2C_FIELD(self, s8*, 1)) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(self, s8*, 1)) + 8) / 4 + 0x1E0) << 6);
        M2C_FIELD(self, u8*, 0x60) = 0;
        M2C_FIELD(self, u8*, 0x8E) = 1;
        M2C_FIELD(self, void**, 0x50) = 0;
        M2C_FIELD(self, u8*, 0x5) = 5;
    }
}
