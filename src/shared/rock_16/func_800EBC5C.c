#include "common.h"
#include "mmx6/x4.h"

void func_80027BA0(s32, s32, s32, void*);
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCEF7;
extern u8 D_800F0BC4[][6][8];
extern s16 D_800F0DA4[][3];
extern s8 D_800F1CA0[];
extern s8 D_800F1CB8[];
extern u8 D_800F1CC4[];
extern u8 D_800F1CF9;

void func_800EBC5C(struct X4_EngineObj* arg0) {
    s16 idx;
    s32 sel;

    if (++arg0->unk8 >= 5) {
        sel = D_800CCEF7;
        idx = D_800F0DA4[sel][0];
        func_80027BA0(idx, D_800F0DA4[sel][1], D_800F0DA4[sel][2],
                      (u8*)D_800F0BC4 + D_800F1CA0[sel] * 0x30 +
                          (D_800F1CB8[sel] - 1) * 8);
        D_800971F8[idx].unk4C = 1;
        D_800F1CF9 = 1;
        arg0->unk8 = 0;
        arg0->unk2 = 0;
        D_800F1CC4[0] = 0;
        D_800F1CC4[1] = 0;
    }
}
