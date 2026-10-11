#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* func_8002C32C();
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)

#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_801EFFAC(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_WeaponObj* obj;
    s8 st;

    player = &D_800970A0;
    if (player->unk5 != F_U8(arg0, 0x8C) || player->unk5 == 0x11) {
        arg0->state = 3;
        return;
    }
    st = arg0->unk6;
    if (st == 0) {
        if (F_U8(player, 0x45) & 2) {
            obj = func_8002C32C();
            if (obj != 0) {
                obj->active = arg0->active;
                obj->id = arg0->id;
                obj->unk2 = 1;
                obj->bg_offset = arg0->bg_offset;
                obj->x_pos.u.hi = player->x_pos.u.hi - 0x20;
                obj->y_pos.u.hi = player->y_pos.u.hi;
                if (player->unk15 != 0) {
                    obj->x_pos.u.hi = player->x_pos.u.hi + 0x20;
                }
                F_U8(player, 0x98)++;
                F_U8(player, 0x99)++;
            }
            F_U8(arg0, 0x8E) = 8;
            F_U8(arg0, 0x8D) = 1;
            arg0->unk6++;
        }
    } else if (st == 1) {
        if (--F_U8(arg0, 0x8E) == 0) {
            obj = func_8002C32C();
            if (obj != 0) {
                obj->active = arg0->active;
                obj->id = arg0->id;
                obj->unk2 = st;
                obj->bg_offset = arg0->bg_offset;
                obj->x_pos.u.hi = player->x_pos.u.hi - 0x20;
                obj->y_pos.u.hi = player->y_pos.u.hi;
                if (player->unk15 != 0) {
                    obj->x_pos.u.hi = player->x_pos.u.hi + 0x20;
                }
                F_U8(player, 0x98)++;
                F_U8(player, 0x99)++;
            }
            arg0->unk6++;
            F_U8(arg0, 0x8D)++;
        }
    }
}
#undef D_800970A0
