#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 check_dash_input(struct X4_PlayerObj*);
M2C_UNK func_8003B298(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
void* player_spawn_weapon(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);

// 0x8003F28C start_falcon_dash: Falcon dash start.
// basis: community tweaks-index.tsv:246
// callers: none known
s32 start_falcon_dash(void* arg0) {
    s8* p = arg0;
    s32 r;

    if (!(*(u16*)(p + 0x80) & 0x80) && ((s32(*)())check_dash_input)() == 0) {
        r = 0;
    } else {
        func_8003B298(p);
        *(s32*)(p + 0x24) = 0;
        play_sound(1, 5, p);
        p[5] = 0x23;
        func_8003BA04(p, 0xA9);
        player_spawn_weapon(1, 0x17, 0, p);
        player_spawn_visual(1, 0x12, 0, 0);
        r = 1;
    }
    return r;
}
