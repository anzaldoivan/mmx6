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
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_801F0A40(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    u8* temp_v0;
    u8* temp_v1;
    s32 temp_a2;
    u8 b15;
    // !FAKE: depin: dropping it breaks the match (78/84)
    register s32 k asm("$7");

    player = &g_Player;
    if ((F_S32(player, 4) & 0xFFFF00) != 0x2C00) {
        arg0->state = 2;
        return;
    }
    F_U8(arg0, 0x14) = F_U8(player, 0x14);
    b15 = player->unk15;
    arg0->unk16 = 1;
    k = 0x7801;
    arg0->unk40 = 0x520;
    arg0->unk42 = k;
    arg0->unk15 = b15;
    temp_v0 = SCRATCH_14;
    arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x18);
    temp_v1 = SCRATCH_1C;
    temp_a2 = *(s32*)(temp_v1 + 0x38);
    arg0->animation_table = (u32**)&D_80077A20;
    arg0->unk64 = 1;
    arg0->unk3C = temp_v1 + temp_a2;
    func_800179A4(arg0, 0);
    func_801EE34C(arg0, player, arg0->id);
    F_S16(arg0, 0x8C) = arg0->x_pos.i.hi - player->x_pos.i.hi;
    F_S16(arg0, 0x8E) = arg0->y_pos.i.hi - player->y_pos.i.hi;
    F_U8(arg0, 0x48) = 0xFF;
    arg0->unk49 = 1;
    func_8003CF24(0x13, 1, 1);
    func_80017B04((s32*)arg0, 0x140, 0x20);
    arg0->state++;
    func_80016C48(1, 0x20, arg0);
    func_8002CCB0(arg0, 0x18, 0x18);
}
#undef g_Player
#undef func_800179A4
#undef func_8002CCB0
