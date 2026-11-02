#include "common.h"
#include "mmx6/x4.h"

extern u8 D_80075FE8[];
extern struct X4_EngineObj g_playthrough_state;

// 0x80042D3C register_orb: orb registered until Nightmare reset.
// basis: community tweaks-index.tsv:351
// callers: func_80040800, func_80040CB0, func_80040E3C
void register_orb(void* arg0) {
    u16 id;
    u8* p;

    id = *(u16*)((s8*)arg0 + 0x88);
    p = (id >> 3) +
        (D_80075FE8[g_playthrough_state.substage +
                    g_playthrough_state.stage * 2]
         << 5) +
        ((u8*)&g_playthrough_state + 0x178);
    *p |= 1 << (id & 7);
}
