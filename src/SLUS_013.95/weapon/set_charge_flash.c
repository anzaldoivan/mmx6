// prog SLUS_013.95 | system weapon | range 0x8003FF90-0x8003FFF0
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

// 0x8003FF90 player_set_charge_flash: sets flash_palette from charge slot arg1 level; returns 1 when that slot is charging.
// basis: code via=flash_palette; derived.tsv:140
// callers: update_player_charge
s32 player_set_charge_flash(struct X4_PlayerObj* arg0, s32 arg1) {
    s8 i = arg1;
    // !FAKE: first table byte held in the second return register, as the target allocates it
    register s32 v asm("$3");
    s8* p;
    s8 w;
    // !FAKE: result byte held in the first return register, as the target allocates it
    register s32 c asm("$2");
    // !FAKE: compare constant held in the second return register, as the target allocates it
    register s32 k asm("$3");

    p = (s8*)arg0 + i;
    v = p[0x9B];
    p = 0;
    if ((s8)v == 0) {
        return 0;
    }
    if (v == 1) {
        c = 0x26;
    shared:
        arg0->flash_palette = c;
        return 1;
    }
    k = 0x14;
    p = (s8*)arg0 + i;
    w = p[0x94];
    c = 0x29;
    if (w != k) {
        // !FAKE: shared store block placed after the v == 1 arm, as the target lays it out
        goto shared;
    }
    arg0->flash_palette = 0x2F;
    return 1;
}
