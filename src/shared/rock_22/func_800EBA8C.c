#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_80097420;

void func_800EBA8C(struct X4_MainObj* arg0) {
    struct X4_PlayerObj* pl = &D_800970A0;
    struct X4_BackgroundObj* bg = D_800971F8;

    if (pl->y_pos.i.hi < bg[0].unk2A - 0x10) {
        pl->y_pos.i.hi = bg[0].unk2A - 0x10;
    }
    if (bg[0].unk2A >= 0x1B1) {
        if (!(D_80097420 & 1)) {
            bg[1].unk42++;
        }
        if (D_80097420 & 3) {
            goto end;
        }
    } else {
        if (D_80097420 & 3) {
            goto end;
        }
        if ((s16)bg[1].unk42 < 0x1E0) {
            bg[1].unk42++;
        }
    }
    bg[0].unk2A--;
    bg[0].unk28--;
end:
    if (--arg0->unk7E == 0) {
        func_8002943C(0xA, 2, 2);
        arg0->unk7E = 0xA;
    }
    if (D_800971F8[0].unk2A <= 0) {
        D_800971F8[0].unk2A = 0;
        D_800971F8[0].unk28 = 0;
        arg0->unk7C = 0;
        arg0->unk7E = 0xA;
        func_80016C48(5, 3, arg0);
        arg0->unk6++;
    }
}
