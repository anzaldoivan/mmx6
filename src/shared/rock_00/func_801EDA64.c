#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_80077A8C;
extern s32 D_80097420;
extern s32 D_801F3848;
M2C_UNK func_800179A4(void*, M2C_UNK);
void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8002C9B0();
s32 func_80065944(s32);
s32 func_80065A14(s32);
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801EDA64(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    u8* temp_v0;
    u8* temp_a0;
    s32 temp_a2;
    s32 angle;
    u8 dir;

    player = &g_Player;
    if (player->unk5 != 0x25) {
        func_8002C9B0(arg0);
        return;
    }
    if (arg0->state == 0) {
        arg0->state++;
        arg0->active = 1;
        arg0->on_screen = 1;
        temp_v0 = SCRATCH_14;
        arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0xC);
        temp_a0 = SCRATCH_1C;
        temp_a2 = *(s32*)(temp_a0 + 0x20);
        arg0->animation_table = (u32**)&D_80077A8C;
        arg0->unk40 = 0x540;
        arg0->unk42 = 0x7848;
        arg0->unk16 = 0;
        M2C_FIELD(arg0, s8*, 0x9C) = 1;
        arg0->unk3C = temp_a0 + temp_a2;
        dir = player->unk15;
        M2C_FIELD(arg0, s16*, 0x92) = 0;
        M2C_FIELD(arg0, s16*, 0x8C) = -0x30;
        arg0->unk15 = dir;
        if (dir != 0) {
            M2C_FIELD(arg0, s16*, 0x8C) = 0x30;
        }
        M2C_FIELD(arg0, s16*, 0x8E) = -0x30;
        if (arg0->unk2 != 0) {
            M2C_FIELD(arg0, s16*, 0x8E) = 0x30;
        }
        func_800179A4(arg0, 2);
        arg0->unk50 = &D_801F3848;
    } else {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            func_8002C9B0(arg0);
            return;
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, s16*, 0x92) =
            (s16)(M2C_FIELD(arg0, s16*, 0x92) + 1) % 66;
    } else {
        M2C_FIELD(arg0, s16*, 0x92) = 0;
    }
    angle = (M2C_FIELD(arg0, s16*, 0x92) << 12) / 66;
    M2C_FIELD(arg0, s16*, 0x90) = angle;
    arg0->x_pos.u.hi = player->x_pos.u.hi + func_80065A14((s16)angle) *
                                                M2C_FIELD(arg0, s16*, 0x8C) /
                                                4096;
    M2C_FIELD(arg0, s16*, 0xE) =
        player->y_pos.u.hi + func_80065944(M2C_FIELD(arg0, s16*, 0x90)) *
                                 M2C_FIELD(arg0, s16*, 0x8E) / 4096;
    if (!(D_80097420 & 7)) {
        arg0->unk64++;
    }
}
#undef g_Player
#undef func_800179A4
#undef SCRATCH_14
#undef SCRATCH_1C
