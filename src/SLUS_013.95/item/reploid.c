#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
s32 random_byte();
s32 func_8002DCF4(void*, void*);
void func_8004ED4C(u8* arg0, u8 arg1, u8 a2);
void set_reploid_status(u8, s32);
extern u8 D_80078BE8[];
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_RideArmorObj D_800CD340;

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))

// 0x8004EECC rescue_reploid: rescued reploid reward.
// basis: community tweaks-index.tsv:285
// callers: func_8004EA78
s32 rescue_reploid(void* arg0) {
    void* tgt;
    s32 r;

    tgt = &g_Player;
    if (S8(&g_Player, 0xD5) != 0) {
        tgt = &D_800CD340;
        if (D_800CD340.unk5 == 0) {
            tgt = (u8*)&D_800CD340 + 0xB0;
        }
    }
    if (!(F8(tgt, 0x5C) & 0x7F)) {
        return 0;
    }
    if (func_8002DCF4(arg0, tgt) != 0) {
        if (F8(arg0, 2) != 0x80) {
            set_reploid_status(F8(arg0, 2), 2);
        }
        {
            u8* e = (u8*)&g_playthrough_state;
            F8(arg0, 5) = 0;
            if ((s8)++e[0x39] >= 10) {
                e[0x39] = 9;
            } else {
                play_sound(0, 0x15, 0);
            }
        }
        r = random_byte() & 3;
        func_8004ED4C(arg0, D_80078BE8[r], r);
        return 1;
    }
    return 0;
}
