#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
#define func_80016C48 ((void (*)(s32, s32, void*))func_80016C48)
M2C_UNK func_800179A4(void*, M2C_UNK);
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
M2C_UNK func_80017B04(M2C_UNK*, M2C_UNK, M2C_UNK);
#define func_80017B04 ((void (*)(void*, s32, s32))func_80017B04)
s8* func_8002BEC4(s8* p, s32 dir);
void func_8003CF24(s32, s32, s32);
M2C_UNK func_8003D510(M2C_UNK, M2C_UNK, s8, M2C_UNK);
#define func_8003D510 ((void (*)(s32, s32, s8, s32))func_8003D510)
extern u8 D_80076194[][2];
extern s32 D_80077A40[];
extern struct X4_PlayerObj D_800970A0;

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_800451B8(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    s8 kind;
    s8* child;

    player = &D_800970A0;
    if (arg0->unk2 == 0) {
        func_80016C48(1, 0x1D, arg0);
        kind = 3;
        {
            register s32 t asm("$3") = player->unk2;
            if (t == 0) {
                kind = 1;
                if (!(player->input.buttons.held & 4)) {
                    kind = 3;
                    if (player->input.buttons.held & 8) {
                        kind = 2;
                    }
                }
            }
        }
        child = func_8002BEC4((s8*)arg0, 0);
        if (child != 0) {
            child[0] = 1;
            child[1] = arg0->id;
            child[2] = kind;
            F_PTR(child, 0x7C) = arg0;
            F_U8(arg0, 0x8C)++;
        }
        arg0->state++;
        if (player->unk2 != 0) {
            F_U8(arg0, 0x48) = 0xFF;
            F_S8(arg0, 0x47) = 0;
            arg0->unk49 = 1;
            {
                u8* q = SCRATCH_14;
                arg0->unk38 = q + *(s32*)(q + 0x14);
            }
            func_80017B04(arg0, 0x140, 0x40);
            func_8003CF24(0x52, 0x19, 1);
        }
        return;
    }
    if (player->unk2 != 0) {
        u8* a = SCRATCH_14;
        u8* b;
        arg0->unk38 = a + *(s32*)(a + 0x14);
        b = SCRATCH_1C;
        arg0->unk3C = b + *(s32*)(b + 0x28);
        arg0->unk40 = 0x540;
        arg0->unk42 = 0x7849;
    } else {
        u8* a = SCRATCH_14;
        u8* b;
        arg0->unk38 = a + *(s32*)(a + 0x20);
        b = SCRATCH_1C;
        arg0->unk3C = b + *(s32*)(b + 0x40);
        arg0->unk40 = 0x520;
        arg0->unk42 = 0x7801;
        func_8003D510(1, 0x1B, 4, 0);
        func_8003CF24(0x1B, 1, 1);
    }
    arg0->animation_table = (u32**)D_80077A40;
    arg0->unk16 = 1;
    F_S8(arg0, 0x9C) = 1;
    arg0->on_screen = 1;
    arg0->unk15 = 0;
    if (player->unk15 != 0) {
        arg0->x_pos.i.hi =
            player->x_pos.i.hi - (s8)D_80076194[arg0->unk2 - 1][0];
    } else {
        arg0->x_pos.i.hi =
            player->x_pos.i.hi + (s8)D_80076194[arg0->unk2 - 1][0];
    }
    arg0->y_pos.i.hi = player->y_pos.i.hi + (s8)D_80076194[arg0->unk2 - 1][1];
    if (arg0->unk2 < 3) {
        func_800179A4(arg0, 0);
    } else {
        func_800179A4(arg0, 1);
    }
    arg0->unk5 = 1;
    arg0->state++;
}
#undef func_80016C48
#undef func_800179A4
#undef func_80017B04
#undef func_8003D510
