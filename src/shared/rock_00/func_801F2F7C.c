#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
void func_8003CF24(s32, s32, s32);
s32 func_801EE34C();
extern s32 D_80077AC8;
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3B04;
extern s32 D_801F3B08[];

#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801F2F7C(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    u8* t;
    s32 o;
    u8 b;
    // !FAKE: depin: dropping it breaks the match (71/77)
    register s32 v asm("$2");

    player = &g_Player;
    b = player->unk15;
    arg0->active = 0x21;
    arg0->unk15 = b;
    t = SCRATCH_1C;
    o = *(s32*)(t + 0x1C);
    arg0->animation_table = (u32**)&D_80077AC8;
    arg0->unk40 = 0;
    arg0->unk42 = 0x784A;
    arg0->unk16 = 2;
    arg0->unk64 = 1;
    t = t + o;
    arg0->unk3C = t;
    ((void (*)(s32, s32, s32, void*))func_8003CF24)(0x54, 0x1A, 1, t);
    v = 0xA0000;
    if (*(s32*)((u8*)player + 0xEC) & 0x100) {
        v = 0xC0000;
        arg0->x_vel.val = v;
    } else {
        arg0->x_vel.val = v;
    }
    arg0->unk68 = (struct X4_Unk_unk68*)&D_801F3B04;
    arg0->unk50 = D_801F3B08;
    if (arg0->unk15 == 0) {
        arg0->x_vel.val = -arg0->x_vel.val;
    }
    arg0->unk28.val = 0;
    arg0->y_vel.val = 0;
    arg0->unk2C = 0;
    func_800179A4(arg0, 0);
    func_801EE34C(arg0, &g_Player, arg0->id);
    arg0->state++;
    func_8002CCB0(arg0, 0x20, 0x14);
    func_80016C48(1, 0xA, arg0);
}
#undef g_Player
#undef func_800179A4
#undef func_8002CCB0
