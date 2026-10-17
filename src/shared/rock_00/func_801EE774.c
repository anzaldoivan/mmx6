#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern s32 D_80077A80;
extern s32 D_801F37C4;
extern s32 D_801F37C8;
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8003D510(M2C_UNK, M2C_UNK, s8, M2C_UNK);
#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801EE774(struct X4_WeaponObj* arg0) {
    u8* temp_a0;
    u8* temp_v0;
    s32 temp_a2;

    arg0->active = 1;
    arg0->on_screen = 1;
    arg0->unk64 = 1;
    arg0->unk50 = &D_801F37C4;
    arg0->unk68 = (struct X4_Unk_unk68*)&D_801F37C8;
    temp_v0 = SCRATCH_14;
    arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x3C);
    temp_a0 = SCRATCH_1C;
    temp_a2 = *(s32*)(temp_a0 + 0x18);
    arg0->animation_table = (u32**)&D_80077A80;
    arg0->unk40 = 0x540;
    arg0->unk42 = 0x7802;
    arg0->unk16 = 1;
    arg0->unk3C = temp_a0 + temp_a2;
    if (arg0->unk15 != 0) {
        arg0->x_vel.val = 0xA0000;
    } else {
        arg0->x_vel.val = 0xFFF60000;
    }
    arg0->unk28.val = 0;
    arg0->y_vel.val = 0;
    arg0->unk2C = 0;
    func_800179A4(arg0, 0);
    arg0->unk5 = 0;
    arg0->state++;
    func_8003D510(1, 0x1B, 8, 0);
}
