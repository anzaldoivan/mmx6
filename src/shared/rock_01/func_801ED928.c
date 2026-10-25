#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002C9B0();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
void set_velocity_from_angle(void*, s32);
M2C_UNK func_8002EE10(void*);
void func_8003CF24(s32, s32, s32);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
extern s32 D_8007798C;
extern struct X4_PlayerObj g_Player;
extern s32 D_801EE3E0;
extern s32 D_801EE3E4;
extern s32 D_801EE6F0;

#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801ED928(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    u8* t;
    s32 off;

    player = &g_Player;
    if (arg0->state == 0) {
        arg0->on_screen = 1;
        arg0->unk50 = &D_801EE3E0;
        arg0->unk68 = (struct X4_Unk_unk68*)&D_801EE3E4;
        t = SCRATCH_1C;
        off = *(s32*)(t + 0x34);
        arg0->animation_table = (u32**)&D_8007798C;
        arg0->unk40 = 0;
        arg0->unk42 = 0x7843;
        arg0->unk16 = 1;
        arg0->unk3C = t + off;
        func_8003CF24(6, 0x13, 1);
        arg0->x_pos.i.hi = player->x_pos.i.hi;
        arg0->y_pos.i.hi = player->y_pos.i.hi + 0x18;
        set_velocity_from_angle(arg0, ((arg0->unk2 * 2) + 0x16) & 0xFE);
        arg0->x_vel.val *= 5;
        arg0->y_vel.val *= 5;
        ((void (*)(void*, s32))func_800179A4)(arg0, 3);
        arg0->state++;
    } else if (arg0->state == 1 && func_8002CBFC(arg0, 0x20, 0x20) == 0 &&
               arg0->unk98 == 0) {
        func_80017A04(arg0);
        ((void (*)(void*))move_object)(arg0);
        arg0->unk64 = arg0->unk2 + 1;
        if (arg0->unk70 == 0) {
            func_8002EE10(arg0);
        }
        if (arg0->unk70 != 0) {
            func_80016C48(1, 0x15, player);
            func_800477E4(6, &D_801EE6F0, arg0);
            arg0->state++;
            return;
        }
    } else {
        func_8002C9B0(arg0);
        return;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
}
