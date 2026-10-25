#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
void func_800F0CF4(void* arg0);

#define ABS(x) ((x) >= 0 ? (x) : -(x))
#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

static inline u8 probe_tile(struct X4_PlayerObj* p, s16 x, s16 y) {
    if (p->unk68 == NULL) {
        return 0;
    }
    return func_80030234(p, x, y);
}

void func_800F0CF4(void* arg0) {
    s32 t;
    u8 tile;
    s32 c;

    if (g_Player.unk5 == 6) {
        goto set1;
    }
    if (g_Player.unk5 == 9 ||
        (g_Player.unk88.unsigned_bytes.collision_flags & 3) ||
        g_Player.nova_strike_active == 2) {
        goto set1;
    }
    if (FLD(arg0, u8, 0x1D) < 2) {
        FLD(arg0, s32, 0x8) = g_Player.x_pos.val + FLD(arg0, s32, 0x14);
        FLD(arg0, s32, 0x14) += FLD(arg0, s32, 0x18);
        tile = probe_tile(&g_Player, FLD(arg0, s16, 0xA),
                          g_Player.unk68->unk1 +
                              (g_Player.y_pos.i.hi + g_Player.unk68->unk3));
        if ((tile == 0 &&
             (g_Player.unk88.unsigned_bytes.collision_flags & 8)) ||
            tile == 0x3C || tile == 0 || tile == 0x18 || tile == 0x1C ||
            tile == 0x14 || tile == 0x1A) {
            g_Player.x_pos.val = FLD(arg0, s32, 0x8);
            if (FLD(arg0, u8, 0x1D) != 0) {
                if (FLD(arg0, s32, 0x14) < 0) {
                    FLD(arg0, s8, 0x4) = 1;
                }
            } else if (FLD(arg0, s32, 0x14) >= 0) {
                FLD(arg0, s8, 0x4) = 1;
            }
            goto tail;
        }
        goto miss;
    }
    if ((u8)--FLD(arg0, u8, 0x1F) != 0xFF) {
        FLD(arg0, s32, 0x8) = g_Player.x_pos.val + FLD(arg0, s32, 0x14);
        FLD(arg0, s32, 0x14) += FLD(arg0, s32, 0x18);
        tile = probe_tile(&g_Player, FLD(arg0, s16, 0xA),
                          g_Player.unk68->unk1 +
                              (g_Player.y_pos.i.hi + g_Player.unk68->unk3));
        if (!((tile == 0 &&
               (g_Player.unk88.unsigned_bytes.collision_flags & 8)) ||
              tile == 0x3C || tile == 0 || tile == 0x18 || tile == 0x1C ||
              tile == 0x14 || tile == 0x1A)) {
        miss:
            g_Player.x_pos.val = FLD(arg0, s32, 0x8);
            FLD(arg0, s8, 0x4) = 1;
            return;
        }
        t = FLD(arg0, s32, 0x8);
        g_Player.x_pos.val = t;
        if (g_Player.unk5 != 0xC && g_Player.unk6 != 2) {
            if (FLD(arg0, s32, 0x14) > 0) {
                c = FLD(arg0, s32, 0x14) < t - ((s32*)&g_Player)[0x13C / 4];
            } else {
                c = t - ((s32*)&g_Player)[0x13C / 4] < FLD(arg0, s32, 0x14);
            }
            if (c) {
                FLD(arg0, s8, 0x4) = 1;
            }
        }
        goto tail;
    }
    if (FLD(arg0, s32, 0x18) > 0) {
        FLD(arg0, s32, 0x18) = -0x600;
    } else {
        FLD(arg0, s32, 0x18) = 0x600;
    }
    FLD(arg0, u8, 0x1D) -= 2;
    func_800F0CF4(arg0);
tail:
    if (FLD(arg0, u8, 0x1D) & 1) {
        if (g_Player.x_pos.val < ((s32*)&g_Player)[0x13C / 4]) {
            if (ABS(((s16*)&g_Player)[0x13E / 2] - g_Player.x_pos.i.hi) <= 0) {
                FLD(arg0, s8, 0x4) = 1;
            }
        }
    } else if (g_Player.x_pos.val > ((s32*)&g_Player)[0x13C / 4]) {
        if (ABS(g_Player.x_pos.i.hi - ((s16*)&g_Player)[0x13E / 2]) != 1) {
            goto set1;
        }
    }
    return;
set1:
    FLD(arg0, s8, 0x4) = 1;
}
