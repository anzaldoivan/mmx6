#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_80077AD8;
extern s32 D_80097420;
extern s32 D_801F3B08[];
extern s16 D_801F3B40[];
M2C_UNK set_animation(void*, M2C_UNK);
void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_80017B04(M2C_UNK*, M2C_UNK, M2C_UNK);
M2C_UNK clear_object_slot();
void func_8003CF24(s32, s32, s32);
#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801F3200(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* player;
    u8* temp_v0;
    u8* temp_v1;
    s32 temp_a2;
    s8 idx;
    u8 dir;
    s32 t;

    player = &g_Player;
    t = player->unk5;
    if ((t ^ 0x4C) != 0) {
        clear_object_slot(arg0);
        return;
    }
    if (arg0->state != 0) {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            clear_object_slot(arg0);
            return;
        }
    } else {
        arg0->bg_offset = player->bg_offset;
        dir = player->unk15;
        arg0->unk16 = 1;
        arg0->unk40 = 0x540;
        arg0->unk42 = 0x784B;
        arg0->unk15 = dir;
        temp_v0 = SCRATCH_14;
        arg0->unk38 = temp_v0 + *(s32*)(temp_v0 + 0x3C);
        temp_v1 = SCRATCH_1C;
        temp_a2 = *(s32*)(temp_v1 + 0x80);
        arg0->animation_table = (u32**)&D_80077AD8;
        arg0->unk64 = 1;
        M2C_FIELD(arg0, s8*, 0x9C) = 1;
        arg0->unk3C = temp_v1 + temp_a2;
        set_animation(arg0, 0);
        arg0->previous_animation_index = 0xFF;
        arg0->unk49 = 1;
        func_8003CF24(0x55, 0x1B, 1);
        func_80017B04((s32*)arg0, 0x140, 0x40);
        {
            // !FAKE: depin: dropping it breaks the match (121/124)
            register s32 s asm("$2") = (u8)arg0->state + 1;
            arg0->state = s;
        }
    }
    idx = M2C_FIELD(arg0, s8*, 0x45);
    if (idx == 0) {
        arg0->unk50 = 0;
    } else {
        arg0->unk50 = &D_801F3B08[idx];
    }
    if (!(D_80097420 & 3)) {
        arg0->unk64++;
    }
    arg0->y_pos.u.hi = player->y_pos.u.hi;
    if (player->unk15 != 0) {
        arg0->x_pos.u.hi = player->x_pos.u.hi + D_801F3B40[player->unk7];
    } else {
        arg0->x_pos.u.hi = player->x_pos.u.hi - D_801F3B40[player->unk7];
    }
    arg0->on_screen = 1;
}
#undef g_Player
#undef SCRATCH_14
#undef SCRATCH_1C
