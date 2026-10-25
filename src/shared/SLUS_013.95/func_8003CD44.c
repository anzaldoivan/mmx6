#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

u16 func_8003D7AC(u16 arg0);
extern struct X4_PlayerObj g_Player;
extern u16 D_800C456C[];

M2C_UNK func_8003CD44(void) {
    struct X4_PlayerObj* pl = &g_Player;

    pl->input.buttons.held = func_8003D7AC(D_800C456C[0]);
    pl->input.buttons.previous = func_8003D7AC(D_800C456C[1]);
    pl->pressed_input = func_8003D7AC(D_800C456C[2]);
}
