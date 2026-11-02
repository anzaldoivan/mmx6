#include "common.h"
#include "mmx6/x4.h"

void pump_file_loads(void);
void read_dat_file(s32 arg0, s32* arg1, u8* arg2);
#include "psyq/libsnd.h"
extern u8 D_8006E35C[];
extern s8 D_80090D50[6];
extern s8 D_80090D64[];
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800E2600;
extern s32 D_800E2604;

// 0x8001731C load_player_sound_seqs: closes open SEP handles, reads the controlled player's sound data file and opens its two SEP sets at full volume.
// basis: xref load_player_files (docs/leads/derived.tsv:9)
// callers: load_player_files
void load_player_sound_seqs(void) {
    u8 i;
    u8* p;

    for (i = 0; i < 6; i++) {
        if (D_80090D64[i] != -1) {
            SsSepClose(D_80090D64[i]);
            D_80090D64[i] = -1;
        }
    }
    {
        struct X4_EngineObj* e = &g_playthrough_state;
        p = &D_8006E35C[*(s8*)&e->controlled_player];
    }
    read_dat_file(*p, &D_800E2600, p);
    pump_file_loads();
    D_80090D64[0] = SsSepOpen((u8*)&D_800E2600 + D_800E2600, D_80090D50[0], 8);
    for (i = 0; i < 8; i++) {
        SsSepSetVol(D_80090D64[0], i, 0x7F, 0x7F);
    }
    D_80090D64[1] =
        SsSepOpen((u8*)&D_800E2604 - 4 + D_800E2604, D_80090D50[1], 2);
    for (i = 0; i < 2; i++) {
        SsSepSetVol(D_80090D64[1], i, 0x7F, 0x7F);
    }
}
