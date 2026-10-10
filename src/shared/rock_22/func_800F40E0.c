/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_19_surface_hopper.c:surface_hopper_set_launch, AGPL-3.0; proven shared with X6 by exact signature 636a950af3be (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_Unk_unk68* D_800FC644[4];
extern struct X4_Unk_unk68* D_800FC654[4];
extern struct X4_Unk_unk68* D_800FC664[4];
extern s16 D_800FC704[8];
extern s16 D_800FC714[8];
extern u8 D_800FC724[8];
extern u8 D_800FC72C[8];
s32 func_800179A4(void*, s32);

void func_800F40E0(struct X4_MainObj* self) {
    s32 index;

    index = (SP_CUR_MAIN_OBJ->ext.main_19.animation_index << 2) +
            SP_CUR_MAIN_OBJ->ext.main_19.unk80;
    self->x_speed = D_800FC704[index] << 16;
    self->y_speed = D_800FC714[index] << 16;
    self->unk15 = D_800FC724[index];
    func_800179A4(self, D_800FC72C[index]);
    self->hurt_box = D_800FC644[SP_CUR_MAIN_OBJ->ext.main_19.unk80];
    self->attack_box = D_800FC654[SP_CUR_MAIN_OBJ->ext.main_19.unk80];
    self->terrain_box = D_800FC664[SP_CUR_MAIN_OBJ->ext.main_19.unk80];
}
