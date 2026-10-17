#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
M2C_UNK func_80017B04(M2C_UNK*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
void func_8003CF24(s32, s32, s32);
s32 func_801EE34C();
extern s32 D_80077A20;
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_801F0F98(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    u8* temp_v0;
    u8* temp_v1;
    s32 temp_a2;
    u8 b15;
    // !FAKE: depin: dropping it breaks the match (61/67)
    register s32 k asm("$7");

    player = &D_800970A0;
    F_U8(arg0, 0x14) = F_U8(player, 0x14);
    b15 = player->unk15;
    arg0->unk16 = 1;
    k = 0x7801;
    arg0->unk40 = 0x520;
    arg0->unk42 = k;
    arg0->unk15 = b15;
    temp_v0 = SCRATCH_14;
    arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x38);
    temp_v1 = SCRATCH_1C;
    temp_a2 = *(s32*)(temp_v1 + 0x6C);
    arg0->animation_table = (u32**)&D_80077A20;
    arg0->unk64 = 1;
    arg0->unk3C = temp_v1 + temp_a2;
    func_800179A4(arg0, 1);
    func_801EE34C(arg0, player, arg0->id);
    F_U8(arg0, 0x48) = 0xFF;
    arg0->unk49 = 1;
    func_8003CF24(0x16, 1, 1);
    func_80017B04((s32*)arg0, 0x140, 0x20);
    arg0->state++;
    func_80016C48(1, 0x21, arg0);
    func_8002CCB0(arg0, 0x28, 0x28);
}
#undef D_800970A0
#undef func_800179A4
#undef func_8002CCB0
