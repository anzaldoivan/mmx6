#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
M2C_UNK func_80017B04(M2C_UNK*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
s32 func_8002D2D4();
void func_8002D3B4(void*, s32);
void func_8003CF24(s32, s32, s32);
extern s32 D_80077A08;
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern s32 D_801F39D8;

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_801F01A8(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    s32 mul;

    player = &D_800970A0;
    if (arg0->unk2 == 0) {
        u8* temp_v0;
        u8* temp_a0;
        s32 var_a1;

        F_U8(arg0, 0x48) = 0xFF;
        F_U8(arg0, 0x47) = 0;
        arg0->unk49 = 1;
        temp_v0 = SCRATCH_14;
        arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x30);
        temp_a0 = SCRATCH_1C;
        var_a1 = *(s32*)(temp_a0 + 0x64);
        arg0->animation_table = (u32**)&D_80077A08;
        arg0->unk40 = 0x520;
        arg0->unk42 = 0x7801;
        arg0->unk3C = temp_a0 + var_a1;
        func_8003CF24(0xE, 1, 1);
        func_80017B04((s32*)arg0, 0x140, 0x20);
        F_U8(arg0, 0x8C) = player->unk5;
        F_U8(arg0, 0x8F) = player->unk15;
        arg0->state++;
        return;
    }
    {
        u8* temp_v0;
        u8* temp_a0;
        s32 var_a1;

        arg0->unk50 = &D_801F39D8;
        arg0->unk64 = 1;
        temp_v0 = SCRATCH_14;
        arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x30);
        temp_a0 = SCRATCH_1C;
        var_a1 = *(s32*)(temp_a0 + 0x64);
        arg0->animation_table = (u32**)&D_80077A08;
        arg0->unk40 = 0x520;
        arg0->unk42 = 0x7801;
        arg0->unk16 = 0x11;
        arg0->unk3C = temp_a0 + var_a1;
    }
    switch (func_8002D2D4() % 3) {
    case 0:
        func_8002D3B4(arg0, 1);
        break;
    case 1:
        func_8002D3B4(arg0, 0);
        break;
    case 2:
        func_8002D3B4(arg0, 0x1F);
        break;
    }
    mul = (func_8002D2D4() % 3) + 3;
    arg0->x_vel.val *= mul;
    arg0->y_vel.val *= mul;
    if (arg0->unk15 == 0) {
        arg0->x_vel.val = -arg0->x_vel.val;
    }
    func_800179A4(arg0, 0);
    func_80016C48(1, 0x18, arg0);
    arg0->unk5 = 1;
    arg0->state++;
    func_8002CCB0(arg0, 0x40, 0x40);
}
#undef D_800970A0
#undef func_800179A4
#undef func_8002CCB0
