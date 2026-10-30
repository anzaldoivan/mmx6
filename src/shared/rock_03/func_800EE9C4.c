#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139A0(M2C_UNK);              /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
void func_80029F38();                        /* extern */
M2C_UNK func_8002B36C(M2C_UNK);              /* extern */
M2C_UNK func_8002B6B0();                     /* extern */
extern s8 D_8008EAB0;
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_ObjectHeader D_80097420;
extern u8 D_800C4560;
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800F782C[][16];

void func_800EE9C4(void* arg0) {
    s32 temp_a1;
    s32 temp_a0;
    s8 temp_a1_2;
    s16 temp_v1;
    s16 temp_y;
    s32 idx;

    temp_a1 = M2C_FIELD(arg0, u16*, 0x80) + 1;
    temp_a0 = M2C_FIELD(arg0, u16*, 0x82) - 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a1;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a0;
    if (!(*(s32*)&D_80097420 & 1)) {
        g_Player.x_pos.i.hi = temp_a1;
    } else {
        g_Player.x_pos.i.hi = temp_a0;
    }
    if (D_80097420.state == 0) {
        temp_a1_2 = M2C_FIELD(arg0, s8*, 2);
        switch (temp_a1_2) {
        case 2:
            if (g_Player.unk2 == 0) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0;
                g_playthrough_state.checkpoint = 1;
                D_8008EAB0 = 1;
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 1;
                g_playthrough_state.checkpoint = temp_a1_2;
                D_8008EAB0 = 1;
            }
            break;
        case 3:
            g_playthrough_state.checkpoint = 3;
            M2C_FIELD(arg0, s16*, 0x7E) = 2;
            break;
        case 4:
            g_playthrough_state.checkpoint = 3;
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
            break;
        }
        idx = M2C_FIELD(arg0, s16*, 0x7E);
        temp_v1 = D_800F782C[idx][0];
        temp_y = D_800F782C[idx][1];
        g_Player.x_pos.i.hi = temp_v1;
        g_Player.y_pos.i.hi = temp_y;
        M2C_FIELD(arg0, u16*, 0x80) = temp_v1 + 0x40;
        M2C_FIELD(arg0, u16*, 0x82) = temp_v1 - 0x40;
        if (g_Player.unk2 != 0) {
            g_Player.y_pos.i.hi--;
        }
        g_Player.spike_immune = 0;
        g_playthrough_state.gameplay_locked = 0;
        g_Player.nova_strike_active = 0;
        g_Player.unk18.val = g_Player.x_pos.val;
        g_Player.unk1C.val = g_Player.y_pos.val;
        func_8002B36C(0);
        D_800C4560 = 1;
        (&g_Player)[1].active = 0;
        background_objects[0].unk44 = 1;
        background_objects[1].unk44 = 1;
        background_objects[2].unk44 = 1;
        background_objects[0].x_pos.i.hi =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][2];
        background_objects[0].y_pos.i.hi =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][3];
        background_objects[1].x_pos.i.hi =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][4];
        background_objects[1].y_pos.i.hi =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][5];
        background_objects[2].x_pos.i.hi =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][6];
        background_objects[2].y_pos.i.hi =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][7];
        background_objects[0].unk1E =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][8];
        background_objects[0].unk1C =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][9];
        background_objects[0].unk22 =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][10];
        background_objects[0].unk20 =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][11];
        background_objects[0].unk26 =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][8];
        background_objects[0].unk24 =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][9];
        background_objects[0].unk2A =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][10];
        background_objects[0].unk28 =
            D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][11];
        background_objects[0].unk4C = 1;
        background_objects[1].unk4C = 1;
        background_objects[2].unk4C = 1;
        g_Player.air_state = 0;
        func_8002B6B0();
        (&g_Player)[1].active = 0;
        g_Player.hurt_phase = 0;
        g_Player.invincibility_timer = 0;
        func_80029F38(background_objects[0].x_pos.i.hi - 0x30,
                      background_objects[0].x_pos.i.hi + 0x170,
                      background_objects[0].y_pos.i.hi - 0x30,
                      background_objects[0].y_pos.i.hi + 0x120, 0);
        func_800139A0(8);
        background_objects[0].unk44 = 0;
        background_objects[1].unk44 = 0;
        background_objects[2].unk44 = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        play_sound(1, 1, arg0);
    }
}
