// prog SLUS_013.95 | system player | range 0x8003CD44-0x8003CD98
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#include "mmx6/system.h"
#include "mmx6/pilot_globals.h"

// 0x8003CD44 read_player_input: in-game input reading.
// basis: community tweaks-index.tsv:260
// callers: none known
// unnamed callers: func_8001EC40, func_80020C40
M2C_UNK read_player_input(void) {
    struct X4_PlayerObj* pl = &g_Player;

    pl->input.buttons.held = map_buttons(g_pad1_buttons[0]);
    pl->input.buttons.previous = map_buttons(g_pad1_buttons[1]);
    pl->pressed_input = map_buttons(g_pad1_buttons[2]);
}
