#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_80077A8C;
extern s32 D_801F37D0;
extern s32 D_801F37D4;
extern s32 D_801F4E28;
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s8* func_8002BEC4(s8* p, s32 dir);
s32 func_8002D2D4();
void set_velocity_from_angle(void*, s32);
M2C_UNK player_spawn_visual(M2C_UNK, M2C_UNK, s8, M2C_UNK);
s32 func_801EE34C();
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801ED524(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_WeaponObj* spawn;
    u8* temp_v0;
    u8* temp_a0;
    s32 var_s2;
    s32 var_s3;
    s32 one;
    u32 temp_v1;
    s32 var_a0;

    arg0->active = 1;
    arg0->on_screen = 1;
    temp_v0 = SCRATCH_14;
    arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 8);
    temp_a0 = SCRATCH_1C;
    var_a0 = *(s32*)(temp_a0 + 0x18);
    arg0->animation_table = (u32**)&D_80077A8C;
    arg0->unk40 = 0x520;
    arg0->unk42 = 0x7849;
    arg0->unk3C = temp_a0 + var_a0;
    player = &g_Player;
    if (M2C_FIELD(player, s32*, 0xEC) & 0x40180) {
        arg0->unk42 = 0x7844;
    }
    if (M2C_FIELD(player, s32*, 0xEC) & 0x100) {
        D_801F4E28 = 0xC;
    } else {
        D_801F4E28 = 8;
    }
    arg0->unk16 = 0;
    arg0->unk15 = player->unk15;
    arg0->unk68 = (struct X4_Unk_unk68*)&D_801F37D4;
    arg0->unk50 = &D_801F37D0;
    arg0->unk28.val = 0;
    arg0->unk2C = 0;
    func_800179A4(arg0, 0);
    arg0->state++;
    if (player->unk5 == 0x1F) {
        func_80016C48(1, 8, arg0);
        arg0->x_pos.u.hi = player->x_pos.u.hi;
        arg0->y_pos.u.hi = player->y_pos.u.hi + 0x18;
        set_velocity_from_angle(arg0, 0x18);
        arg0->x_vel.val *= D_801F4E28;
        arg0->y_vel.val *= D_801F4E28;
        one = 1;
        var_s3 = 0x16;
        for (var_s2 = 1; var_s2 >= 0; var_s2--) {
            spawn = (struct X4_WeaponObj*)func_8002BEC4((s8*)arg0, 0);
            if (spawn != 0) {
                spawn->id = arg0->id;
                spawn->active = arg0->active;
                spawn->on_screen = one;
                spawn->unk38 = arg0->unk38;
                spawn->unk3C = arg0->unk3C;
                spawn->animation_table = arg0->animation_table;
                spawn->unk40 = arg0->unk40;
                spawn->unk42 = arg0->unk42;
                spawn->unk16 = arg0->unk16;
                spawn->unk15 = arg0->unk15;
                spawn->unk68 = arg0->unk68;
                spawn->unk50 = arg0->unk50;
                spawn->x_pos.u.hi = arg0->x_pos.u.hi;
                spawn->y_pos.u.hi = arg0->y_pos.u.hi;
                spawn->unk28.val = 0;
                spawn->unk2C = 0;
                spawn->unk2 = one;
                set_velocity_from_angle(spawn, var_s3);
                spawn->x_vel.val *= D_801F4E28;
                spawn->y_vel.val *= D_801F4E28;
                func_800179A4(spawn, 0);
                spawn->state++;
            }
            var_s3 += 4;
        }
        return;
    }
    func_801EE34C(arg0, player, arg0->id);
    temp_v1 = func_8002D2D4() & 0xF;
    if (temp_v1 < 5) {
        set_velocity_from_angle(arg0, 1);
    } else if (temp_v1 < 0xB) {
        set_velocity_from_angle(arg0, 0);
    } else {
        set_velocity_from_angle(arg0, 0x1F);
    }
    arg0->x_vel.val *= D_801F4E28;
    arg0->y_vel.val *= D_801F4E28;
    if (arg0->unk15 == 0) {
        arg0->x_vel.val = -arg0->x_vel.val;
    }
    player_spawn_visual(0x21, 2, 0x2D, 0);
}
#undef g_Player
#undef func_800179A4
