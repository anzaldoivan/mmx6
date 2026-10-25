#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* func_8002C32C();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_801EF410(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_WeaponObj* obj;
    s32 mode;
    s32 i;
    s32 d;

    player = &g_Player;
    mode = 0;
    if (player->unk5 != F_S8(arg0, 0x92)) {
        arg0->unk5--;
        return;
    }
    if (player->unk5 != 0x4A) {
        if (((player->x_pos.i.hi - F_U16(arg0, 0x8E)) >= 0
                 ? (player->x_pos.i.hi - F_U16(arg0, 0x8E))
                 : (F_U16(arg0, 0x8E) - player->x_pos.i.hi)) >= 0x20) {
            mode = 1;
        }
    } else {
        if (((player->x_pos.i.hi - F_U16(arg0, 0x8E)) >= 0
                 ? (player->x_pos.i.hi - F_U16(arg0, 0x8E))
                 : (F_U16(arg0, 0x8E) - player->x_pos.i.hi)) >= 0x20) {
            mode = 1;
        } else {
            if (((player->y_pos.i.hi - F_U16(arg0, 0x90)) >= 0
                     ? (player->y_pos.i.hi - F_U16(arg0, 0x90))
                     : (F_U16(arg0, 0x90) - player->y_pos.i.hi)) >= 0x20) {
                mode = 3;
            }
        }
    }
    if (mode != 0) {
        if (mode == 1) {
            if (F_U16(arg0, 0x8E) < player->x_pos.i.hi) {
                F_U16(arg0, 0x8E) = F_U16(arg0, 0x8E) + 0x20;
            } else {
                F_U16(arg0, 0x8E) = F_U16(arg0, 0x8E) - 0x20;
            }
            F_U16(arg0, 0x90) = player->y_pos.u.hi;
        } else {
            if (player->y_pos.i.hi > F_U16(arg0, 0x90)) {
                F_U16(arg0, 0x90) = F_U16(arg0, 0x90) + 0x20;
            } else {
                F_U16(arg0, 0x90) = F_U16(arg0, 0x90) - 0x20;
            }
            F_U16(arg0, 0x8E) = player->x_pos.u.hi;
        }
        i = 0;
        do {
            obj = func_8002C32C();
            if (obj != 0) {
                obj->active = arg0->active;
                obj->id = arg0->id;
                obj->unk2 = mode + i;
                obj->bg_offset = arg0->bg_offset;
                obj->x_pos.u.hi = F_U16(arg0, 0x8E);
                obj->y_pos.u.hi = F_U16(arg0, 0x90);
                F_PTR(obj, 0x7C) = arg0;
                arg0->unk6++;
            }
            i++;
        } while (i < 2);
    }
}
#undef g_Player
