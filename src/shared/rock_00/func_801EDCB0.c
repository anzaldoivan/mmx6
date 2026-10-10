#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern s32 D_80077A98;
extern s32 D_801F3858[];
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_80017B04(M2C_UNK*, M2C_UNK, M2C_UNK);
void* func_8002C32C();
M2C_UNK func_8002C9B0();
#define func_8002C9B0 ((void (*)(struct X4_ObjectHeader * arg0)) func_8002C9B0)
s32 func_8002D2D4();
M2C_UNK func_8003CFE0(void*, M2C_UNK);
#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801EDCB0(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player = &D_800970A0;
    s32 var_a1;
    u8* temp_v0;
    u8* temp_v1;
    u8* temp_v1_2;
    u8* temp_v0_2;
    s32 var_a0;
    u8 temp_v0_4;
    s8* spawn;

    var_a1 = player->hp == 0;
    if ((M2C_FIELD(player, s8*, 0xD3) != 0) &&
        (M2C_FIELD(player, s8*, 0xE0) != 2)) {
        var_a1 = 1;
    }
    if (M2C_FIELD(player, s8*, 0xCF) != 0) {
        var_a1 = 1;
    }
    if (arg0->unk84.word != player->unk17) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        goto block_30;
    }
    {
        if (arg0->state == 0) {
            arg0->state++;
            arg0->on_screen = 1;
            arg0->unk40 = 0x590;
            if ((player->weapon != 3) || (player->unk5 == 0x4C)) {
                if (player->unk5 == 0x25) {
                    func_80016C48(1, 0x12, player);
                } else if (player->unk5 == 0x26) {
                    func_80016C48(1, 9, player);
                } else if (player->unk5 == 0x4D) {
                } else {
                    func_80016C48(1, 0xE, player);
                }
                temp_v0 = SCRATCH_14;
                arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 4);
                temp_v1 = SCRATCH_1C;
                var_a0 = *(s32*)(temp_v1 + 0x50);
                arg0->unk42 = 0x7848;
                arg0->unk3C = temp_v1 + var_a0;
            } else {
                func_80016C48(1, 0x17, arg0);
                temp_v1_2 = SCRATCH_14;
                arg0->unk38 = temp_v1_2 + *(s32*)(temp_v1_2 + 0x48);
                temp_v0_2 = SCRATCH_1C;
                var_a0 = *(s32*)(temp_v0_2 + 0x7C);
                arg0->unk42 = 0x7849;
                arg0->unk3C = temp_v0_2 + var_a0;
            }
            arg0->animation_table = (u32**)&D_80077A98;
            arg0->unk16 = 2;
            M2C_FIELD(arg0, u32*, 0x8C) = 0;
            M2C_FIELD(arg0, s32*, 0x90) = 0;
            arg0->unk49 = 0;
            if (player->unk5 == 0x2F) {
                if (func_8002D2D4() & 4) {
                    func_8003CFE0(player, 8);
                }
                if (M2C_FIELD(player, u8*, 0xE7) != 2) {
                    func_800179A4(arg0, 4);
                } else {
                    func_800179A4(arg0, 5);
                }
            } else if (M2C_FIELD(player, u8*, 0xE7) != 2) {
                func_800179A4(arg0, arg0->id - 0x32);
            } else {
                func_800179A4(arg0, arg0->id - 0x30);
            }
        } else {
            func_80017A04(ANIMATED_OBJECT(arg0));
            if (arg0->animation_step.fields.relative_step == 0) {
            block_30:
                func_8002C9B0(OBJECT_HEADER(arg0));
                return;
            }
        }
        arg0->x_pos.val = player->x_pos.val;
        arg0->y_pos.val = player->y_pos.val;
        arg0->unk15 = player->unk15;
        func_80017B04((M2C_UNK*)arg0, 0x140, 0x90);
        if ((player->unk5 == 0x4D) &&
            (arg0->animation_step.fields.event & 0x40)) {
            spawn = func_8002C32C();
            if (spawn != 0) {
                spawn[0] = 1;
                spawn[1] = 0x39;
                spawn[2] = arg0->id - 0x32;
                spawn[0x14] = player->bg_offset;
            }
            func_80016C48(1, 0x12, player);
        }
        temp_v0_4 = arg0->animation_step.fields.event & 0x3F;
        arg0->animation_step.fields.event = temp_v0_4;
        if (temp_v0_4 == 0) {
            arg0->unk50 = 0;
        } else {
            arg0->unk50 = &D_801F3858[temp_v0_4];
        }
        arg0->unk64 = arg0->animation_step.fields.event;
        if (M2C_FIELD(arg0, s32*, 0x90) != 0) {
            M2C_FIELD(arg0, s32*, 0x90)--;
            arg0->unk50 = 0;
        }
        if (arg0->unk98 != 0) {
            arg0->unk98 = 0;
            M2C_FIELD(arg0, s32*, 0x90) = 4;
            arg0->unk50 = 0;
            M2C_FIELD(arg0, u32*, 0x8C)++;
        }
        if (M2C_FIELD(arg0, u32*, 0x8C) >= 4U) {
            arg0->unk50 = 0;
        }
    }
}
#undef D_800970A0
#undef func_8002C9B0
