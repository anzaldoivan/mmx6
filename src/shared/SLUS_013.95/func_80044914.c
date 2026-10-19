#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
#define func_8002CCB0 func_8002CCB0
s32 func_8002D2D4();
void func_8003CF24(s32, s32, s32);
M2C_UNK func_8003D510(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3);
#define func_8003D510 func_8003D510
extern s32 D_8007616C[];
extern s32 D_80077A0C[];
extern struct X4_PlayerObj D_800970A0;
extern u8 D_800970B5;
extern struct X4_BackgroundObj D_800971F8[3];

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define BG (D_800971F8[player->bg_offset])

void func_80044914(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    s16 a;
    s16 b;
    u8* p;

    if (arg0->unk2 == 0) {
        F_S8(arg0, 0x8D) = 0;
        F_S8(arg0, 0x8C) = 0;
        arg0->unk15 = D_800970B5;
        arg0->state++;
        return;
    }
    player = &D_800970A0;
    a = player->x_pos.i.hi - BG.x_pos.i.hi;
    b = player->y_pos.i.hi - BG.y_pos.i.hi;
    if (func_8002D2D4() & 4) {
        if (arg0->unk15 != 0) {
            a = (a * (func_8002D2D4() % 11)) / 10;
        } else {
            a = 0x140 - ((0x140 - a) * (func_8002D2D4() % 11)) / 10;
        }
        arg0->x_pos.i.hi = a + BG.x_pos.i.hi;
        arg0->y_pos.i.hi = BG.y_pos.i.hi - 0x20;
    } else {
        if (arg0->unk15 != 0) {
            arg0->x_pos.i.hi = BG.x_pos.i.hi - 0x24;
        } else {
            arg0->x_pos.i.hi = BG.x_pos.i.hi + 0x164;
        }
        b = (b * (func_8002D2D4() % 11)) / 10;
        arg0->y_pos.i.hi = b + BG.y_pos.i.hi;
    }
    arg0->bg_offset = player->bg_offset;
    arg0->x_vel.val = 0x43E18;
    arg0->y_vel.val = -0x43E18;
    if (arg0->unk15 == 0) {
        arg0->x_vel.val = -0x43E18;
    }
    arg0->unk50 = D_8007616C;
    arg0->unk64 = 1;
    arg0->unk40 = 0x520;
    arg0->unk42 = 0x7801;
    arg0->unk16 = 0x12;
    arg0->unk38 = SCRATCH_14 + *(s32*)(SCRATCH_14 + 0x44);
    p = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x78);
    arg0->animation_table = (u32**)D_80077A0C;
    arg0->unk3C = p;
    func_800179A4(arg0, 4);
    func_8003D510(1, 0x1B, 3, 0);
    func_8003CF24(0x12, 1, 1);
    arg0->state++;
    func_8002CCB0(arg0, 0x30, 0x40);
}
#undef func_800179A4
#undef func_8002CCB0
#undef func_8003D510
