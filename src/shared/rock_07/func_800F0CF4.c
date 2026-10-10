#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;
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

    if (D_800970A0.unk5 == 6) {
        goto set1;
    }
    if (D_800970A0.unk5 == 9 ||
        (D_800970A0.unk88.unsigned_bytes.collision_flags & 3) ||
        D_800970A0.nova_strike_active == 2) {
        goto set1;
    }
    if (FLD(arg0, u8, 0x1D) < 2) {
        FLD(arg0, s32, 0x8) = D_800970A0.x_pos.val + FLD(arg0, s32, 0x14);
        FLD(arg0, s32, 0x14) += FLD(arg0, s32, 0x18);
        tile = probe_tile(&D_800970A0, FLD(arg0, s16, 0xA),
                          D_800970A0.unk68->unk1 +
                              (D_800970A0.y_pos.i.hi + D_800970A0.unk68->unk3));
        if ((tile == 0 &&
             (D_800970A0.unk88.unsigned_bytes.collision_flags & 8)) ||
            tile == 0x3C || tile == 0 || tile == 0x18 || tile == 0x1C ||
            tile == 0x14 || tile == 0x1A) {
            D_800970A0.x_pos.val = FLD(arg0, s32, 0x8);
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
        FLD(arg0, s32, 0x8) = D_800970A0.x_pos.val + FLD(arg0, s32, 0x14);
        FLD(arg0, s32, 0x14) += FLD(arg0, s32, 0x18);
        tile = probe_tile(&D_800970A0, FLD(arg0, s16, 0xA),
                          D_800970A0.unk68->unk1 +
                              (D_800970A0.y_pos.i.hi + D_800970A0.unk68->unk3));
        if (!((tile == 0 &&
               (D_800970A0.unk88.unsigned_bytes.collision_flags & 8)) ||
              tile == 0x3C || tile == 0 || tile == 0x18 || tile == 0x1C ||
              tile == 0x14 || tile == 0x1A)) {
        miss:
            D_800970A0.x_pos.val = FLD(arg0, s32, 0x8);
            FLD(arg0, s8, 0x4) = 1;
            return;
        }
        t = FLD(arg0, s32, 0x8);
        D_800970A0.x_pos.val = t;
        if (D_800970A0.unk5 != 0xC && D_800970A0.unk6 != 2) {
            if (FLD(arg0, s32, 0x14) > 0) {
                c = FLD(arg0, s32, 0x14) < t - ((s32*)&D_800970A0)[0x13C / 4];
            } else {
                c = t - ((s32*)&D_800970A0)[0x13C / 4] < FLD(arg0, s32, 0x14);
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
        if (D_800970A0.x_pos.val < ((s32*)&D_800970A0)[0x13C / 4]) {
            if (ABS(((s16*)&D_800970A0)[0x13E / 2] - D_800970A0.x_pos.i.hi) <=
                0) {
                FLD(arg0, s8, 0x4) = 1;
            }
        }
    } else if (D_800970A0.x_pos.val > ((s32*)&D_800970A0)[0x13C / 4]) {
        if (ABS(D_800970A0.x_pos.i.hi - ((s16*)&D_800970A0)[0x13E / 2]) != 1) {
            goto set1;
        }
    }
    return;
set1:
    FLD(arg0, s8, 0x4) = 1;
}
