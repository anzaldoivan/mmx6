#include "common.h"
#include "mmx6/x4.h"

extern s16 D_800E4192;
extern s16 D_800E4194;
extern s16 D_800E419E;
extern s16 D_800E41A0;
extern s16 D_800E41A6;
extern s16 D_800E41B0[][4];
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
void func_800304D8();

static inline u8 tile_8002E974(struct X4_PlayerObj* p, s16 x, s16 y) {
    s32 i;

    for (i = 0; i < D_800E41A6; i++) {
        if (x >= D_800E41B0[i][0] && D_800E41B0[i][1] >= x &&
            y >= D_800E41B0[i][2] && D_800E41B0[i][3] >= y) {
            return 0x38;
        }
    }
    return func_80030234(p, x, y);
}

static inline s32 solid_8002E974(u8 t) {
    switch (t) {
    case 0x3:
    case 0x4:
    case 0x5:
    case 0x6:
    case 0xA:
    case 0xB:
    case 0x10:
    case 0x38:
    case 0x39:
    case 0x3A:
    case 0x3C:
    case 0x3E:
    case 0x3F:
        return 1;
    }
    return 0;
}

void func_8002E974(struct X4_PlayerObj* p) {
    if (p->collision_flags == 0 && p->terrain_box != 0) {
        func_800304D8();
        if (solid_8002E974(tile_8002E974(p, D_800E419E - D_800E4192,
                                         D_800E41A0 - D_800E4194))) {
            p->collision_flags |= 6;
        }
        if (solid_8002E974(tile_8002E974(p, D_800E419E - D_800E4192,
                                         D_800E41A0 + D_800E4194 - 1))) {
            p->collision_flags |= 0xA;
        }
        if (solid_8002E974(tile_8002E974(p, D_800E419E + D_800E4192 - 1,
                                         D_800E41A0 - D_800E4194))) {
            p->collision_flags |= 5;
        }
        {
            s16 x = D_800E419E + D_800E4192 - 1;
            s32 b = (u16)D_800E4194;
            if (solid_8002E974(tile_8002E974(p, x, D_800E41A0 + b - 1))) {
                p->collision_flags |= 9;
            }
        }
    }
}
