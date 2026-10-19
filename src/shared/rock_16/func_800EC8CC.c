#include "common.h"
#include "mmx6/x4.h"

void func_80027C98(s32 arg0, s16 arg1, s16 arg2, u16* arg3);
extern struct X4_BackgroundObj D_800971F8[3];
extern u8 D_800F0BC4[][6][8];
// !FAKE: rect-row alias of the TU's u8 D_800F0BC4[][6][8]; a cast view folds +6 into the symbol
extern X4_RECT D_800F0BC4_r[][6];
#define D_800F0BC4 D_800F0BC4_r
extern s16 D_800F0DA4[][3];

void func_800EC8CC(s32 arg0) {
    X4_RECT rect;
    s16 idx;

    idx = D_800F0DA4[arg0][0];
    rect.w = D_800F0BC4[arg0][0].w;
    rect.h = D_800F0BC4[arg0][0].h;
    func_80027C98(idx, D_800F0DA4[arg0][1], D_800F0DA4[arg0][2], (u16*)&rect);
    D_800971F8[idx].unk4C = 1;
}
#undef D_800F0BC4
