#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern s32 D_80077A8C;
extern s32 D_80097420;
extern s32 D_801F3838;
M2C_UNK func_800179A4(void*, M2C_UNK);
void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8002C9B0();
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801ED898(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    u8* temp_v0;
    u8* temp_a0;
    s32 temp_a2;
    s32 kill;
    s16 dx;
    s8 idx;

    player = &D_800970A0;
    kill = player->hp == 0;
    if (M2C_FIELD(player, s8*, 0xD3) != 0) {
        kill = 1;
    }
    if (M2C_FIELD(player, s8*, 0xCF) != 0) {
        kill = 1;
    }
    if (M2C_FIELD(arg0, s32*, 0x84) != player->unk17) {
        kill = 1;
    }
    if (kill != 0) {
        goto block_14;
    }
    if (arg0->state == 0) {
        arg0->state++;
        arg0->active = 1;
        arg0->on_screen = 1;
        temp_v0 = SCRATCH_14;
        arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0xC);
        temp_a0 = SCRATCH_1C;
        temp_a2 = *(s32*)(temp_a0 + 0x1C);
        arg0->animation_table = (u32**)&D_80077A8C;
        arg0->unk40 = 0x540;
        arg0->unk42 = 0x7848;
        arg0->unk16 = 0;
        M2C_FIELD(arg0, s8*, 0x9C) = 1;
        arg0->unk3C = temp_a0 + temp_a2;
        arg0->x_pos.val = player->x_pos.val;
        arg0->y_pos.val = player->y_pos.val;
        arg0->unk15 = player->unk15;
        dx = -0x20;
        if (player->unk7 == 0) {
            dx = -0x40;
        }
        if (arg0->unk15 != 0) {
            dx = -dx;
        }
        M2C_FIELD(arg0, s16*, 0xA) += dx;
        func_800179A4(arg0, 1);
    } else {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        block_14:
            func_8002C9B0(arg0);
            return;
        }
    }
    idx = M2C_FIELD(arg0, s8*, 0x45);
    if (idx == 0) {
        arg0->unk50 = 0;
    } else {
        arg0->unk50 = &(&D_801F3838)[idx];
    }
    if (!(D_80097420 & 7)) {
        arg0->unk64++;
    }
}
#undef D_800970A0
#undef func_800179A4
