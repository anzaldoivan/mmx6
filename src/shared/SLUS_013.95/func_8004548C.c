#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_80016C48(s32 a0, s32 a1, void* arg2);
#define func_80016C48 ((void (*)(s32, s32, void*))func_80016C48)
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
s8* func_8002BEC4(s8* p, s32 dir);
s32 func_8003EB0C(void* arg0, s32 arg1);
void func_8003F740(void*, s32);
extern s32 D_8007619C;
extern s32 D_800761A0;
extern struct X4_PlayerObj D_800970A0;

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_8004548C(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_WeaponObj* child;
    u8* parent;
    s8 kind;
    s32 hp;
    u16 y;
    s32 v;

    ((void (*)())func_80017A04)();
    if (--F_S8(arg0, 0x8E) == 0) {
        player = &D_800970A0;
        kind = 4;
        if (player->unk2 == 0) {
            kind = F_S8(player, 0x93);
        }
        hp = F_S16((u8*)&D_800970A0 + (kind << 1), 0xA8);
        if (hp >= func_8003EB0C(player, kind)) {
            if (player->unk2 != 0) {
                F_S8(player, 0x93) = 4;
                func_8003F740(player, 4);
            } else {
                func_8003F740(player, arg0->id);
            }
            parent = F_PTR(arg0, 0x7C);
            F_U8(arg0, 0x8F) = 0;
            child = (struct X4_WeaponObj*)func_8002BEC4((s8*)parent, 0);
            if (child != 0) {
                func_80016C48(1, 0x1F, arg0);
                {
                    register s32 one asm("$6") = 1;
                    child->active = one;
                    child->id = 0x35;
                    child->unk2 = 5;
                    F_PTR(child, 0x7C) = parent;
                    child->unk38 = arg0->unk38;
                    child->unk3C = arg0->unk3C;
                    child->animation_table = arg0->animation_table;
                    child->unk40 = arg0->unk40;
                    child->unk42 = arg0->unk42;
                    child->unk16 = arg0->unk16;
                    child->x_pos.i.hi = arg0->x_pos.i.hi;
                    y = arg0->y_pos.i.hi;
                    F_PTR(child, 0x68) = &D_800761A0;
                    F_PTR(child, 0x50) = &D_8007619C;
                    child->on_screen = one;
                    child->state = one;
                    child->unk5 = 4;
                    child->y_pos.i.hi = y;
                    ((void (*)(void*, s32, s32, u16))func_800179A4)(child, 6, 1,
                                                                    y);
                    if (arg0->unk2 == 1) {
                        v = 0x30000;
                        goto set;
                    }
                    if (arg0->unk2 == 2) {
                        v = -0x30000;
                    set:
                        child->x_vel.val = 0;
                        child->y_vel.val = v;
                    } else if (arg0->unk2 == 3) {
                        child->x_vel.val = -0x30000;
                        child->y_vel.val = 0;
                        goto neg;
                    } else {
                        child->x_vel.val = -0x30000;
                        child->y_vel.val = 0;
                    neg:
                        if (player->unk15 != 0) {
                            child->x_vel.val = -child->x_vel.val;
                        }
                    }
                }
                F_U8(parent, 0x8C)++;
            }
        }
        if (arg0->unk2 < 3) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 0);
        } else {
            ((void (*)(void*, s32))func_800179A4)(arg0, 1);
        }
        F_U8(arg0, 0x9C) &= 0xFD;
        arg0->unk5--;
    }
}
#undef func_80016C48
