#include "common.h"
#include "mmx6/x4.h"

extern s32 D_800741FC[];
extern s32 D_8007429C;
extern s8 D_800950A0[];
extern struct X4_EngineObj g_playthrough_state;

s32 check_attack_hit(void* arg0, void* arg1, s16* arg2, s16* arg3);
s32 func_800315CC(void* arg0, void* arg1);

// 0x80031474 check_enemy_hits: attack slots tested against enemies.
// basis: community tweaks-index.tsv:275
// callers: func_80040800, func_8004F624, func_8004FB60, func_800E98C0 and others
s32 check_enemy_hits(void* arg0) {
    u8* self = arg0;
    s8* p;
    s32 r;

    if (*(s8*)(self + 0x7A) != 0) {
        *(s8*)(self + 0x65) = 0;
        return 0;
    }
    p = D_800950A0;
    *(u16*)(self + 0x42) &= 0x7FFF;
    for (; p < D_800950A0 + 0x1400; p += 0xA0) {
        if (p[0] == 0) {
            continue;
        }
        if (*(void**)(self + 0x58) == &D_8007429C && p[0x9C] == 0) {
            continue;
        }
        if (check_attack_hit(p, self, (s16*)(p + 0x80), (s16*)(p + 0x82)) ==
            0) {
            continue;
        }
        r = func_800315CC(self, p);
        if (r == 0x7E) {
            return 0;
        }
        if (r < 0) {
            void* t = *(void**)(self + 0x58);
            if (t == D_800741FC || t == &D_8007429C) {
                if (p[0x9C] == 1) {
                    p[0x9C] |= 2;
                }
            } else {
                u8* e = (u8*)&g_playthrough_state;
                (*(s32*)(e + 0x94))++;
            }
        }
        if (r != 0) {
            return r;
        }
    }
    *(s8*)(self + 0x65) = 0;
    return 0;
}
