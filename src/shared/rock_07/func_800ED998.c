#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK clear_object_slot();
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
void func_800ED4D0(void);
void func_800ED764(void);
void func_800ED8AC(void);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_80097420;
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800E3142;
extern u16 D_800F985C;

#define PL_14C (*(s16*)((u8*)&g_Player + 0x14C))

void func_800ED998(s8* arg0) {
    s8 temp_s1;

    if (arg0[4] == 0) {
        D_800F985C = D_800E3142;
        func_800ED4D0();
        func_800ED8AC();
        arg0[4]++;
    }
    if (g_Player.nova_strike_active != 2) {
        temp_s1 = g_Player.state;
        if (temp_s1 == 1 && g_Player.hp != 0) {
            if (g_Player.unk5 == 0x14) {
                if (arg0[0x14] != 0) {
                    play_sound(5, 3, 0);
                    arg0[0x14] = 0;
                }
            } else if (g_Player.unk5 != 0 && g_Player.unk5 != 0x14) {
                if (g_playthrough_state.checkpoint == 0) {
                    background_objects[0].unk26 =
                        background_objects[0].x_pos.i.hi;
                    background_objects[0].unk1E =
                        background_objects[0].x_pos.i.hi;
                }
                if (g_Player.unk68 != 0) {
                    if (g_playthrough_state.checkpoint >= 2) {
                        play_sound(5, 3, 0);
                        clear_object_slot(arg0);
                        return;
                    }
                    if (arg0[0x14] == 0 || PL_14C != 0) {
                        play_sound(5, 6, 0);
                        arg0[0x14] = temp_s1;
                    }
                    func_800ED764();
                    if ((u32)D_80097420 % 5 == 0) {
                        D_800F985C++;
                        func_800ED8AC();
                    }
                    if (func_80030234(&g_Player, g_Player.x_pos.i.hi,
                                      g_Player.unk68->unk1 +
                                          (g_Player.y_pos.i.hi +
                                           g_Player.unk68->unk3)) == 0x3A) {
                        g_Player.x_pos.i.hi--;
                    }
                }
            }
        }
    }
}
