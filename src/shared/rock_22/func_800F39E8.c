#include "common.h"
#include "mmx6/x4.h"
extern struct X4_Unk_unk68* D_800FC644[4];
extern struct X4_Unk_unk68* D_800FC654[4];
extern struct X4_Unk_unk68* D_800FC664[4];
extern s16 D_800FC704[8];
extern s16 D_800FC714[8];
extern u8 D_800FC724[8];
extern u8 D_800FC72C[8];
s32 set_animation(void*, s32);

static inline void set_launch_39E8(struct X4_MainObj* self) {
    s32 index;
    index = (SP_CUR_MAIN_OBJ->ext.main_19.animation_index << 2) +
            SP_CUR_MAIN_OBJ->ext.main_19.unk80;
    self->x_speed = D_800FC704[index] << 16;
    self->y_speed = D_800FC714[index] << 16;
    self->unk15 = D_800FC724[index];
    set_animation(self, D_800FC72C[index]);
    self->hurt_box = D_800FC644[SP_CUR_MAIN_OBJ->ext.main_19.unk80];
    self->attack_box = D_800FC654[SP_CUR_MAIN_OBJ->ext.main_19.unk80];
    self->terrain_box = D_800FC664[SP_CUR_MAIN_OBJ->ext.main_19.unk80];
}

void func_800F39E8(struct X4_MainObj* self) {
    if (self->unk6 == 0) {
        set_launch_39E8(self);
        self->unk6 = 1;
        self->unk7C = 0x1E;
        return;
    }
    if (--self->unk7C == 0) {
        self->unk5 = 2;
        self->unk6 = 0;
    }
}
