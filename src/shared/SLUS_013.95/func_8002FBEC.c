#include "common.h"
#include "mmx6/x4.h"

extern u8 D_800E4191;
extern s16 D_800E4192;
extern s16 D_800E4196;
extern s16 D_800E419A;
extern s16 D_800E41A2;
s32 func_80030B80(struct X4_PlayerObj* arg0, s16 arg1);

s32 func_8002FBEC(struct X4_PlayerObj* arg0) {
    s16 x;

    if (D_800E4191 & 1) {
        if (arg0->unk15 != 0) {
            x = D_800E419A + D_800E41A2 + D_800E4196 + D_800E4192 - 1;
        } else {
            x = D_800E419A + D_800E41A2 - D_800E4196 + D_800E4192 - 1;
        }
    } else {
        if (arg0->unk15 != 0) {
            x = D_800E419A + D_800E41A2 + D_800E4196 - D_800E4192;
        } else {
            x = D_800E419A + D_800E41A2 - D_800E4196 - D_800E4192;
        }
    }
    if (func_80030B80(arg0, x) == 0) {
        arg0->x_pos.u.lo = 0;
        arg0->x_pos.u.hi += D_800E41A2;
        return 0;
    }
    return -1;
}
