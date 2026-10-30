#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern s32 D_800779D8;
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3964;
extern s32 D_801F3968[];
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_8003CF24(s32, s32, s32);
M2C_UNK player_spawn_visual(M2C_UNK, M2C_UNK, s8, M2C_UNK);
s32 func_801EE34C();
#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801EEE40(struct X4_WeaponObj* arg0) {
    s8 temp_v1;
    u8* temp_a0;
    u8* temp_v0;
    s32 var_a0;

    temp_v0 = SCRATCH_14;
    arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x40);
    temp_a0 = SCRATCH_1C;
    var_a0 = *(s32*)(temp_a0 + 0x74);
    arg0->animation_table = (u32**)&D_800779D8;
    arg0->unk40 = 0x520;
    arg0->unk42 = 0x7801;
    arg0->unk16 = 1;
    arg0->unk3C = temp_a0 + var_a0;
    arg0->unk15 = g_Player.unk15;
    temp_v1 = arg0->id;
    arg0->unk67 = 1;
    arg0->unk64 = 0;
    if (temp_v1 == 2) {
        if (arg0->unk2 == 0) {
            arg0->unk50 = 0;
            arg0->unk68 = 0;
            M2C_FIELD(arg0, u8*, 0x9D) = 1;
            func_801EE34C(arg0, &g_Player, 2);
            set_animation(arg0, 0);
            play_sound(1, 0x14, arg0);
            M2C_FIELD(arg0, u8*, 0x8D) = 0;
            arg0->state = 1;
            arg0->unk5 = 0;
        } else {
            arg0->state = 3;
        }
        func_8002CCB0(arg0, 0x10, 0x10);
    } else if (temp_v1 == 0x34) {
        func_8002CCB0(arg0, 0x10, 0x10);
        set_animation(arg0, arg0->unk2 + 3);
        {
            // !FAKE: depin: dropping it breaks the match (91/96)
            register s32* t50 asm("$2") = &D_801F3964;
            // !FAKE: depin: dropping it breaks the match (92/96)
            register s32* t68 asm("$3") = D_801F3968;
            arg0->unk50 = t50;
            arg0->unk68 = (struct X4_Unk_unk68*)t68;
        }
        arg0->state = 2;
    }
    func_8003CF24(7, 1, 1);
    player_spawn_visual(1, 0x1B, 1, 0);
}
#undef g_Player
