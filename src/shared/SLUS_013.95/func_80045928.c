#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
#define func_80016C48 ((void (*)(s32, s32, void*))func_80016C48)
M2C_UNK func_800179A4(void*, M2C_UNK);
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
void func_8003CF24(s32, s32, s32);
void* func_8003D480(M2C_UNK, s8, s8, void*);
M2C_UNK func_8003D510(M2C_UNK, M2C_UNK, s8, M2C_UNK);
#define func_8003D510 ((void (*)(s32, s32, s8, s32))func_8003D510)
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern s16 D_800761CC[][2];
extern s32 D_800761DC[][2];
extern s32 D_80077A5C[];
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_S16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_80045928(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    s32 i;
    s32 ang;
    s32 x;
    s32 y;
    u8* p;
    u8* q;

    player = &D_800970A0;
    if (arg0->unk2 == 0) {
        func_80016C48(1, 0x1E, arg0);
        if (func_8003D480(1, arg0->id, 1, arg0) != 0) {
            arg0->unk7++;
        }
        if (func_8003D480(1, arg0->id, 2, arg0) != 0) {
            arg0->unk7++;
        }
        if (func_8003D480(1, arg0->id, 3, arg0) != 0) {
            arg0->unk7++;
        }
        if (func_8003D480(1, arg0->id, 4, arg0) != 0) {
            arg0->unk7++;
        }
        func_8003D510(1, 0x1B, 0xB, 0);
        func_8003CF24(0x1E, 1, 1);
        {
            register s32 t asm("$3") = (u8)arg0->state + 1;
            arg0->state = t;
        }
        return;
    }
    p = SCRATCH_14;
    arg0->unk38 = p + *(s32*)(p + 0x2C);
    q = SCRATCH_1C;
    arg0->unk3C = q + *(s32*)(q + 0x60);
    arg0->animation_table = (u32**)D_80077A5C;
    arg0->unk40 = 0x520;
    arg0->unk42 = 0x7801;
    arg0->bg_offset = -1;
    if (arg0->unk2 < 5) {
        arg0->x_pos.i.hi =
            player->x_pos.i.hi - D_800971F8[player->bg_offset].x_pos.i.hi;
        arg0->y_pos.i.hi =
            player->y_pos.i.hi - D_800971F8[player->bg_offset].y_pos.i.hi;
        F_S16(arg0, 0x92) = arg0->x_pos.i.hi;
        arg0->unk16 = 0x11;
        F_S16(arg0, 0x94) = arg0->y_pos.i.hi;
        func_800179A4(arg0, 0);
        arg0->unk5 = 2;
    } else if (arg0->unk2 < 9) {
        if (arg0->unk2 == 8) {
            func_80016C48(1, 0x1F, arg0);
        }
        arg0->x_pos.i.hi = D_800761CC[arg0->unk2 - 5][0];
        arg0->y_pos.i.hi = D_800761CC[arg0->unk2 - 5][1];
        i = arg0->unk2 - 5;
        y = D_800761DC[i][1];
        ang = func_80065B74(arg0->y_pos.i.hi - y,
                            D_800761DC[i][0] - arg0->x_pos.i.hi);
        arg0->x_vel.val = func_80065A14(ang) << 6;
        arg0->y_vel.val = func_80065944(ang) << 6;
        arg0->unk16 = 0x10;
        arg0->unk64 = 1;
        func_800179A4(arg0, 1);
        arg0->unk5 = 5;
    }
    arg0->on_screen = 1;
    arg0->state++;
}
#undef func_80016C48
#undef func_800179A4
#undef func_8003D510
