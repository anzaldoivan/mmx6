#include "common.h"

s32 func_8003A33C(void*);
s32 func_8003A394(void*);
void player_enter_wall_cling(void* arg0);

// 0x8003A2CC try_enter_wall_cling: enters wall cling when not locked and touching a wall; returns 1 when taken.
// basis: xref player_enter_wall_cling (docs/leads/derived.tsv:17)
// callers: handle_jump_rise, func_800368FC, func_80036D4C, rock_00 func_801EAA38, rock_00 func_801EC020, rock_00 player_hover_hold, rock_00 player_hover_forward, rock_00 player_hover_forward_stop, rock_00 player_hover_back, rock_00 player_hover_back_stop, rock_01 func_801EB324, rock_01 func_801EB5F8, rock_01 func_801EBA7C
s32 try_enter_wall_cling(void* arg0) {
    if (*((s8*)arg0 + 0xD3) != 0) {
        return 0;
    }
    if (!(*((u8*)arg0 + 0x89) & 3)) {
        return 0;
    }
    if (func_8003A33C(arg0) != 0) {
        return 1;
    }
    if (func_8003A394(arg0) == 0) {
        return 0;
    }
    player_enter_wall_cling(arg0);
    return 1;
}
