#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* func_8002C32C();
s32 func_8002D2D4();
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern struct X4_BackgroundObj D_800971F8[3];

#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_801F0410(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_WeaponObj* obj;
    s32 state;
    s32 r;

    state = arg0->unk6;
    player = &D_800970A0;
    if (state == 0) {
        if (player->unk5 != F_U8(arg0, 0x8C) || player->unk5 == 0x11) {
            goto end3;
        }
        if (!(F_S8(player, 0x45) & 0x80)) {
            return;
        }
        obj = func_8002C32C();
        if (obj != 0) {
            obj->active = arg0->active;
            obj->id = arg0->id;
            obj->unk2 = 1;
            obj->bg_offset = arg0->bg_offset;
            obj->x_pos.u.hi = player->x_pos.u.hi;
            obj->y_pos.u.hi = player->y_pos.u.hi;
            obj->unk15 = player->unk15;
            F_PTR(obj, 0x7C) = arg0;
            arg0->unk7++;
        }
        arg0->unk6++;
        player->unk6 = 1;
        F_U8(arg0, 0x8E) = 0x14;
        F_U8(arg0, 0x8D) = 1;
    } else if (state == 1) {
        if (--F_U8(arg0, 0x8E) != 0) {
            return;
        }
        obj = func_8002C32C();
        if (obj != 0) {
            obj->active = arg0->active;
            obj->id = arg0->id;
            obj->unk2 = state;
            obj->bg_offset = arg0->bg_offset;
            obj->unk15 = F_U8(arg0, 0x8F);
            if (obj->unk15 != 0) {
                obj->x_pos.u.hi = D_800971F8[arg0->bg_offset].x_pos.u.hi - 0x20;
            } else {
                obj->x_pos.u.hi =
                    D_800971F8[arg0->bg_offset].x_pos.u.hi + 0x160;
            }
            r = func_8002D2D4();
            obj->y_pos.u.hi = player->y_pos.u.hi + (r % 64) - 0x20;
            F_PTR(obj, 0x7C) = arg0;
            arg0->unk7++;
        }
        F_U8(arg0, 0x8E) = 0x14;
        if (++F_U8(arg0, 0x8D) >= 8) {
        end3:
            arg0->state = 3;
        }
    }
}
#undef D_800970A0
