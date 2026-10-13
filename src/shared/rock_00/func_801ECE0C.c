#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D510(M2C_UNK, M2C_UNK, s8, M2C_UNK);
void func_801EEB7C(struct X4_WeaponObj* arg0);
extern u32* D_8007789C[];
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern s32 D_801F3790;
extern s32 D_801F37B0;

#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801ECE0C(struct X4_WeaponObj* arg0) {
    u8* sc;
    struct X4_PlayerObj* src;
    struct X4_PlayerObj* player;
    s16 h;
    s32 v;

    arg0->active = 0x21;
    arg0->on_screen = 1;
    arg0->unk68 = (struct X4_Unk_unk68*)&D_801F37B0;
    arg0->unk50 = &D_801F3790;
    sc = SCRATCH_1C;
    v = *(s32*)(sc + 4);
    src = arg0->owner;
    arg0->unk40 = 0;
    arg0->unk16 = 1;
    arg0->animation_table = D_8007789C;
    arg0->unk3C = sc + v;
    player = &D_800970A0;
    h = 0x7802;
    if (M2C_FIELD(player, s32*, 0xEC) & 0x180) {
        h = 0x7844;
    }
    arg0->unk42 = h;
    if (M2C_FIELD(player, s32*, 0xEC) & 0x40000) {
        arg0->unk42 = 0x7844;
    }
    arg0->unk15 = src->unk15;
    arg0->unk84.word = 0;
    func_801EEB7C(arg0);
    arg0->x_pos.i.lo = 0;
    arg0->y_pos.i.lo = 0;
    if (M2C_FIELD(src, s32*, 0xEC) & 0x100) {
        arg0->x_vel.val = 0x8C000;
    } else {
        arg0->x_vel.val = 0x6C000;
    }
    if (arg0->unk15 == 0) {
        arg0->x_vel.val = -arg0->x_vel.val;
    }
    arg0->unk28.val = 0;
    arg0->y_vel.val = 0;
    arg0->unk2C = 0;
    func_800179A4(arg0, 0x15);
    arg0->state++;
    func_8002CCB0(arg0, 0xC, 8);
    func_8003D510(0x21, 2, 0, 0);
}
#undef D_800970A0
