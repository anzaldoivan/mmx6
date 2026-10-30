#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80025F34();
s32 func_800280F4();
void init_checkpoint_positions(void);
M2C_UNK reset_level();
void func_8002C2B8();
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800E3140;
extern u8 D_800E3141;
extern u8 D_800F366C[];

void func_800EEA1C(u8* arg0) {
    struct X4_EngineObj* e = &g_playthrough_state;
    u8 a = D_800E3141;
    u8 b = D_800E3140;

    e->character_state.bytes[0] = a;
    e->character_state.bytes[1] = b;
    *(u8*)(D_800F366C + 0x128A) = *(u8*)&e->controlled_player;
    do {
        reset_level(arg0, a, b);
    } while (0);
    func_8002C2B8();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    e->character_state.bytes[2] = 0;
    {
        struct X4_PlayerObj* pl = &g_Player;
        ((u8*)pl)[0xC9] = arg0[0x60];
        pl->unk2 = *(u8*)(D_800F366C + 0x128A);
    }
    arg0[2]++;
}
