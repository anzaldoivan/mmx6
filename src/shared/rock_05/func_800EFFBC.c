#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SCRATCH_9C (*(s32**)0x1F80009C)
#define SCRATCH_4C (*(u8**)0x1F80004C)
#define SCRATCH_20 (*(s32**)0x1F800020)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002A47C(s32);
extern M2C_UNK D_8007433C;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj D_800CCED0;
extern s32 D_800F4150;
extern s32 D_800F4158;
extern s32 D_800F4330;
extern s16 D_800F4484;

void func_800EFFBC(struct X4_MainObj* self) {
    s32 a;
    s32 b;
    u8 t;

    t = SCRATCH_4C[0x8B];
    if (t == 1) {
        background_objects[1].y_pos.u.hi -= 2;
        if ((s16)background_objects[1].y_pos.u.hi <= D_800F4484 + 0x900) {
            self->unk7C = 0;
            SCRATCH_4C[0x8B] = 0;
            func_80016C48(2, 3, self);
        }
    } else if (t == 2) {
        background_objects[1].y_pos.u.hi += 2;
        if ((s16)background_objects[1].y_pos.u.hi >= D_800F4484 + 0xBA0) {
            self->unk7C = 0;
            SCRATCH_4C[0x8B] = 0;
            func_80016C48(2, 3, self);
        }
    }
    if (self->unk7C == 0) {
        self->unk7E = 3;
        self->contact_damage = 8;
        self->hurt_box = &D_800F4150;
        self->attack_box = &D_800F4158;
        self->collision_data = &D_8007433C;
        self->unk40 += 0x300;
        if (D_800CCED0.stage == 0xC) {
            self->sprite_frames = (u8*)SCRATCH_9C + SCRATCH_9C[1];
            self->unk42 = 0x794C;
        } else {
            a = func_8002A47C(self->id);
            b = func_8002A47C(self->id);
            a = (a + 1) * 4;
            self->unk42 = (a + 0x20) % 16 | (((b + 9) / 4 + 0x1E0) << 6);
            self->sprite_frames =
                (u8*)SCRATCH_20 + SCRATCH_20[func_8002A47C(self->id) + 1];
        }
        self->animation_table = &D_800F4330;
        self->on_screen = 1;
        func_800179A4(self, 4);
        self->unk7C = 0x32;
        ((void (*)(s32, s32, s32))func_80029478)(0x78, 4, 2);
        self->unk6++;
    }
}
