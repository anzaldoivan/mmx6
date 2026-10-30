#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
struct X4_VisualObj* func_8002C398(void);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;

void func_80051C68(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_VisualObj* obj;

    if (arg0->unk72 & 8) {
        ((void (*)(void*, s32))set_animation)(arg0, 1);
        player = &g_Player;
        func_8003D308(0x18, player->unk15);
        obj = func_8002C398();
        if (obj != 0) {
            obj->active = 0x49;
            obj->id = 0x24;
            obj->unk2 = 0;
            obj->bg_offset = arg0->bg_offset;
            obj->unk50 = arg0;
        }
        {
            s32 x = arg0->x_pos.val;
            player->item_step = 1;
            g_playthrough_state.unk16 = 1;
            g_playthrough_state.unk12 = 1;
            g_playthrough_state.unk13 = 1;
            g_playthrough_state.unk17 = 1;
            player->x_pos.val = x;
        }
        arg0->unk5++;
    }
}
