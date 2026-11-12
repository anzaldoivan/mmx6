#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

extern s16 D_800E4192;
extern s16 D_800E4194;
extern s16 D_800E419E;
extern s16 D_800E41A0;
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
void func_800304D8();

#define CHECK(t, r)                                                            \
    switch (t) {                                                               \
    case 3:                                                                    \
    case 4:                                                                    \
    case 5:                                                                    \
    case 6:                                                                    \
    case 10:                                                                   \
    case 11:                                                                   \
    case 16:                                                                   \
    case 56:                                                                   \
    case 57:                                                                   \
    case 58:                                                                   \
    case 60:                                                                   \
    case 62:                                                                   \
    case 63:                                                                   \
        r = 1;                                                                 \
        break;                                                                 \
    default:                                                                   \
        r = 0;                                                                 \
        break;                                                                 \
    }

M2C_UNK func_8002EE10(struct X4_PlayerObj* arg0) {
    s32 r;

    if (arg0->collision_flags == 0 && arg0->terrain_box != 0) {
        func_800304D8();
        CHECK(func_80030234(arg0, D_800E419E - D_800E4192,
                            D_800E41A0 - D_800E4194),
              r);
        if (r) {
            arg0->collision_flags |= 6;
        } else {
            CHECK(func_80030234(arg0, D_800E419E - D_800E4192,
                                D_800E41A0 + D_800E4194),
                  r);
            if (r) {
                arg0->collision_flags |= 0xA;
            } else {
                CHECK(func_80030234(arg0, D_800E419E + D_800E4192,
                                    D_800E41A0 - D_800E4194),
                      r);
                if (r) {
                    arg0->collision_flags |= 5;
                } else {
                    CHECK(func_80030234(arg0, D_800E419E + D_800E4192,
                                        D_800E41A0 + D_800E4194),
                          r);
                    if (r) {
                        arg0->collision_flags |= 9;
                    }
                }
            }
        }
    }
}

#undef CHECK
