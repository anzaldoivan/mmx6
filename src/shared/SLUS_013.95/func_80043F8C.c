#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
M2C_UNK func_8002C9B0();

void func_80043F8C(s8* arg0) {
    struct X4_PlayerObj* parent;
    struct X4_PlayerObj* player;
    s8* p;
    s32 t;

    if (arg0[2] == 0) {
        if (arg0[0x8C] != 0) {
            return;
        }
        player = &g_Player;
        player->shot_count--;
        player->special_shot_count--;
        if (player->unk2 != 0 && player->stock_charge == 1) {
            player->stock_charge = 0;
        }
        p = (s8*)player;
    } else {
        parent = *(struct X4_PlayerObj**)(arg0 + 0x7C);
        parent->afterimage--;
        p = (s8*)(u8)arg0[2];
        if ((u32)((s32)p - 4) < 3) {
            t = (s8)(s32)p + (s32)parent;
            p = (s8*)t + 0x8C;
            t = 0;
            if (*p != 0) {
                (*p)--;
            }
        }
    }
    func_8002C9B0(arg0, p);
}
