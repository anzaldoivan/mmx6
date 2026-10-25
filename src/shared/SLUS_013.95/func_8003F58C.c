#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8001750C(u8, u8);
void func_8003C4EC(struct X4_PlayerObj* self);
void func_8003CE30(void* arg0);
extern struct X4_PlayerObj g_Player;
extern u8 D_800CCF99;

M2C_UNK func_8003F58C(void) {
    struct X4_PlayerObj* pl = &g_Player;

    if (!(D_800CCF99 & 1) || (pl->weapon != 0)) {
        if (!(pl->input.buttons.held & 0x10)) {
            pl->charge_state[0] = 0;
            pl->charge_timer = 0;
        }
        if (!(pl->input.buttons.held & 0x20)) {
            pl->charge_state[1] = 0;
            pl->special_charge_timer = 0;
        }
        if (!(*(s32*)&pl->charge_state[1] & 0xFFFF00)) {
            func_8001750C(1, 7);
            func_8003CE30(pl);
            pl->charge_state[0] = 0;
            pl->charge_state[1] = 0;
            pl->charge_timer = 0;
            pl->special_charge_timer = 0;
            func_8003C4EC(pl);
        }
    }
}
