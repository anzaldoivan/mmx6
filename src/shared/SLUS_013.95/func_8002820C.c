#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern struct X4_EngineObj D_800CCED0;
extern s8 D_800CCEDF;

void func_8002820C(struct X4_BackgroundObj* arg0) {
    s16 lim;

    if (arg0->unk1C < arg0->x_pos.i.hi) {
        arg0->x_pos.i.hi = arg0->unk1C;
        lim = (s16)(arg0->x_pos.i.hi + 0x140);
        if (D_800970A0.x_pos.i.hi + 8 >= lim) {
            D_800970A0.x_pos.i.hi = arg0->x_pos.i.hi + 0x138;
        }
    }
    if (arg0->unk1E >= arg0->x_pos.i.hi) {
        arg0->x_pos.i.hi = arg0->unk1E;
        if (D_800970A0.x_pos.i.hi - 8 < arg0->x_pos.i.hi) {
            D_800970A0.x_pos.i.hi = arg0->x_pos.i.hi + 8;
        }
    }
    if (D_800970A0.y_pos.i.hi < 0 && D_800CCEDF == 0) {
        D_800970A0.y_pos.i.hi = 0;
    }
    if (arg0->unk20 < arg0->y_pos.i.hi) {
        arg0->y_pos.i.hi = arg0->unk20;
        lim = (s16)(arg0->y_pos.i.hi + 0x100);
        if (lim <= D_800970A0.y_pos.i.hi - 8) {
            u8 hp = D_800970A0.hp;
            u8* e = (u8*)&D_800CCED0;
            D_800970A0.hp = -0x80;
            *(s32*)(e + 0x98) += hp & 0x7F;
        }
    } else if (arg0->unk22 >= arg0->y_pos.i.hi) {
        arg0->y_pos.i.hi = arg0->unk22;
    }
}
#undef D_800970A0
