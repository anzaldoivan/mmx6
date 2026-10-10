#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
M2C_UNK func_80017B04(M2C_UNK*, M2C_UNK, M2C_UNK);
#define func_80017B04 ((void (*)(void*, s32, s32))func_80017B04)
s8* func_8002BEC4(s8* p, s32 dir);
void func_8003CF24(s32, s32, s32);
s32 func_8003EB0C(void* arg0, s32 arg1);
void func_8003F740(void*, s32);
extern s32 D_800779C0[];
extern struct X4_PlayerObj D_800970A0;

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_80043638(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    s8* child;
    s32 i;
    s32 next;
    s32 hp;
    u8* q;

    player = &D_800970A0;
    if (arg0->unk2 == 0) {
        i = 0;
        F_S16(arg0, 0x94) = 0x1000;
        F_U8(arg0, 0x8D) = 1;
        F_U8(arg0, 0x8C) = 3;
        do {
            child = func_8002BEC4((s8*)arg0, 0);
            next = i + 1;
            if (child != 0) {
                child[0] = 1;
                child[1] = arg0->id;
                child[2] = next;
                F_PTR(child, 0x7C) = arg0;
            }
            if (i != 0) {
                if (arg0->id != 10) {
                    hp = F_S16((u8*)player + (F_S8(player, 0x93) << 1), 0xA8);
                    if (hp >= func_8003EB0C(player, F_S8(player, 0x93))) {
                        func_8003F740(player, arg0->id);
                    }
                }
                F_U8(arg0, 0x8D) |= 1 << i;
            }
            i = next;
        } while (i < 3);
        arg0->state++;
        if (player->unk2 != 0) {
            F_U8(arg0, 0x48) = 0xFF;
            F_S8(arg0, 0x47) = 0;
            arg0->unk49 = 1;
            q = SCRATCH_14;
            arg0->unk38 = q + *(s32*)(q + 0x10);
            func_80017B04(arg0, 0x140, 0x40);
            func_8003CF24(0x51, 0x19, 1);
        }
        return;
    }
    arg0->on_screen = 1;
    if (player->unk2 != 0) {
        u8* p = SCRATCH_14;
        u8* q;
        s32 off;
        arg0->unk38 = p + *(s32*)(p + 0x10);
        q = SCRATCH_1C;
        off = *(s32*)(q + 0x24);
        arg0->unk40 = 0x540;
        arg0->unk42 = 0x7849;
        arg0->unk3C = q + off;
    } else {
        u8* p = SCRATCH_14;
        u8* q;
        s32 off;
        arg0->unk38 = p + *(s32*)(p + 0x8);
        q = SCRATCH_1C;
        off = *(s32*)(q + 0x28);
        arg0->unk40 = 0x520;
        arg0->unk42 = 0x7801;
        arg0->unk3C = q + off;
    }
    arg0->animation_table = (u32**)D_800779C0;
    arg0->unk16 = 0;
    arg0->unk15 = player->unk15;
    arg0->unk64 = 1;
    arg0->x_pos.i.hi = player->x_pos.i.hi;
    arg0->y_pos.i.hi = player->y_pos.i.hi;
    func_800179A4(arg0, 0);
    arg0->unk5 = 1;
    arg0->state++;
}
#undef func_800179A4
#undef func_80017B04
