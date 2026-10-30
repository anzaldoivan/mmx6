#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

// 0x80030DC0 scale_damage: damage taken scaled by armor and difficulty.
// basis: community tweaks-index.tsv:204
// callers: func_8003D07C
s32 scale_damage(u8* arg0, s8 arg1) {
    s32 v = arg1;
    s32 flag;
    s32 t;

    if (v == 0) {
        return 0;
    }
    if (v == 0x7F) {
        return 0x7F;
    }
    {
        u8* e = (u8*)&g_playthrough_state;
        if (e[0x68] == 0) {
            v = (s8)((v * 3) / 4);
        } else if (e[0x68] >= 2) {
            t = (s16)((s8)(v / 4) + v);
            if (t >= 0x80) {
                t = 0x7F;
            }
            v = (s8)t;
        }
    }
    {
        u8 k = arg0[0xE7];
        u8* e;
        flag = 0;
        if ((u32)(k - 1) < 4 ||
            (k == 5 && (e = (u8*)&g_playthrough_state, e[0x5F] & 0x20)) ||
            (*(s32*)(arg0 + 0xEC) & 0x200)) {
            flag = 1;
        }
    }
    if (flag != 0) {
        v = v / 2;
    }
    if (v == 0) {
        v = 1;
    }
    return v;
}
