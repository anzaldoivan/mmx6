#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;
extern s32 D_80097420;
extern struct X4_EngineObj D_800CCED0;

s32 func_80016C48(s32 a0, s32 a1, void* arg2);

void func_80034574(struct X4_PlayerObj* arg0) {
    s32 hp;
    s8 max;
    s8 v;

    if (!(D_80097420 & 1)) {
        struct X4_PlayerObj* pl = &D_800970A0;
        s8* e = (s8*)&D_800CCED0;
        max = ((s8*)&D_800CCED0 + pl->unk2)[0x5B];
        hp = pl->hp & 0x7F;
        if (hp != max) {
            v = hp + 1;
            if (max < v) {
                v = max;
            }
            pl->hp = v;
            if (!(D_80097420 & 3)) {
                func_80016C48(0, 0x17, 0);
            }
        } else {
            arg0->unk5 = 8;
            e[0x464] = 1;
        }
    }
}
