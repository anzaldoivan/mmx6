#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
extern M2C_UNK g_Player;
extern struct X4_EngineObj g_playthrough_state;
extern u8 boss_level_by_rank[];

// 0x80025FD8 set_boss_level: sets current boss level from rank.
// basis: community tweaks-index.tsv:173
// callers: func_800ED124, func_800ED610, func_800ED904, func_800EF400 and others
void set_boss_level(void) {
    s8* pl = (s8*)&g_Player;
    u8* e = (u8*)&g_playthrough_state;
    if (*(u16*)(e + 0xC) == 0xC) {
        e[0x8F] = 3;
        return;
    }
    {
        s32 i = pl[2];
        e[0x8F] = boss_level_by_rank[((s8*)(e - -i))[0x8D]];
    }
}
