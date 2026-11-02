#include "common.h"

s32 func_8002FD3C(void* arg0);
s32 func_80030068(void* arg0);
void func_8003B63C(void*);
void player_enter_ladder_climb_on_top(void*);

// 0x8003A3DC try_enter_ladder: grabs a ladder (input bit 4 over tile 0x20) or climbs on top (bit 8 over tile 0x21); returns 1 when taken.
// basis: xref player_enter_ladder_climb_on_top (docs/leads/derived.tsv:18)
// callers: func_80035274, func_800353C0, func_800354E8, func_80035A2C, func_80036800, func_80036A04, func_80037130, rock_00 func_801EB8B8, rock_01 func_801EBC60, rock_01 func_801ECE08
s32 try_enter_ladder(void* arg0) {
    u8* p = arg0;

    if (*(s8*)(p + 0xD3) != 0) {
        return 0;
    }
    if (p[0x92] != 0) {
        return 0;
    }
    if ((*(u16*)(p + 0x7C) & 4) && func_8002FD3C(p) == 0x20) {
        func_8003B63C(p);
        return 1;
    }
    if (!(*(u16*)(p + 0x7C) & 8)) {
        return 0;
    }
    if (func_80030068(p) != 0x21) {
        return 0;
    }
    player_enter_ladder_climb_on_top(p);
    return 1;
}
