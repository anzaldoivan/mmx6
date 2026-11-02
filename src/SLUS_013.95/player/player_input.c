#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

u16 map_buttons(u16 arg0);
extern struct X4_PlayerObj g_Player;
extern u16 g_pad1_buttons[];

// 0x8003CD44 read_player_input: in-game input reading.
// basis: community tweaks-index.tsv:260
// callers: func_8001EC40, func_80020C40
M2C_UNK read_player_input(void) {
    struct X4_PlayerObj* pl = &g_Player;

    pl->input.buttons.held = map_buttons(g_pad1_buttons[0]);
    pl->input.buttons.previous = map_buttons(g_pad1_buttons[1]);
    pl->pressed_input = map_buttons(g_pad1_buttons[2]);
}
