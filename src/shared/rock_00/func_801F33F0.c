#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_80017B04(M2C_UNK*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002C9B0();
#define func_8002C9B0 ((void (*)())func_8002C9B0)
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
void func_8002D2B0(struct X4_MovingObj*);
void func_8003CF24(s32, s32, s32);
extern s32 D_80077ADC;
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern s32 D_80097420;
extern s32 D_801F3B1C;
extern u16 D_801F3B48[];

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_801F33F0(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    u8* temp_v0;
    u8* temp_v1;
    s32 temp_a2;
    s32 t;

    player = &D_800970A0;
    t = player->unk5 == 0x4D;
    if (!t) {
        func_8002C9B0();
        return;
    }
    if (arg0->state == 0) {
        arg0->bg_offset = player->bg_offset;
        arg0->unk15 = player->unk15;
        arg0->unk16 = 0x12;
        arg0->unk40 = 0x540;
        arg0->unk42 = 0x784B;
        temp_v0 = SCRATCH_14;
        arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x4C);
        temp_v1 = SCRATCH_1C;
        temp_a2 = *(s32*)(temp_v1 + 0x84);
        arg0->animation_table = (u32**)&D_80077ADC;
        arg0->unk64 = 1;
        arg0->unk3C = temp_v1 + temp_a2;
        func_800179A4(arg0, 0);
        F_U8(arg0, 0x48) = 0xFF;
        arg0->unk49 = 1;
        func_8003CF24(0x56, 0x1B, 1);
        func_80017B04((s32*)arg0, 0x140, 0x40);
        arg0->x_vel.val = 0x60000;
        arg0->unk50 = &D_801F3B1C;
        arg0->y_pos.u.hi = player->y_pos.u.hi;
        if (player->unk15 != 0) {
            arg0->x_pos.u.hi = player->x_pos.u.hi + D_801F3B48[arg0->unk2];
        } else {
            arg0->x_pos.u.hi = player->x_pos.u.hi - D_801F3B48[arg0->unk2];
        }
        if (arg0->unk15 == 0) {
            arg0->x_vel.val = -arg0->x_vel.val;
        }
        arg0->state++;
    } else {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        func_8002D2B0((struct X4_MovingObj*)arg0);
    }
    if (!(D_80097420 & 3)) {
        arg0->unk64++;
    }
    func_8002CCB0(arg0, 0x20, 0x30);
    if (arg0->on_screen == 0) {
        func_8002C9B0(arg0);
        F_U8(player, 0xE1)++;
    }
}
#undef D_800970A0
#undef func_800179A4
#undef func_8002C9B0
#undef func_8002CCB0
#undef SCRATCH_14
#undef SCRATCH_1C
#undef F_U8
