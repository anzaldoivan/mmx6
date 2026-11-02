/* Adapted from sozud/mmx4 @807a01b src/main/visuals/visual_00_wall_slide_dust.c:wall_slide_dust_init, AGPL-3.0; proven shared with X6 by exact signature 4a86628af3e4 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern u32* D_8007789C[];
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
M2C_UNK set_animation(void* arg0, M2C_UNK arg1);

void func_800494DC(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1) {
    arg0->on_screen = 1;
    arg0->unk38 = 0;
    arg0->unk3C = (void*)((s8*)SP_SPRITE_FRAMES + SP_SPRITE_FRAMES[1]);
    arg0->animation_table = &D_8007789C;
    arg0->unk40 = WEAPON_TEXTURE_BASE;
    arg0->unk42 = WEAPON_PALETTE_4;
    arg0->unk16 = VISUAL_SATURN_LAYER(1);
    func_800496C0(arg0, arg1);
    set_animation(arg0, 3);
    arg0->state++;
    func_8002CCB0(arg0, 0x20, 0x20);
}
