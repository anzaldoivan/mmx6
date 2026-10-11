#include "common.h"
#include "mmx6/x4.h"

extern s16 D_800E4192;
extern s16 D_800E4194;
extern s16 D_800E4196;
extern s16 D_800E4198;
extern s16 D_800E419A;
extern s16 D_800E419C;
extern s16 D_800E419E;
extern s16 D_800E41A0;
s32 func_800309F8(struct X4_PlayerObj* arg0, s16 arg1, s32 arg2);
s32 func_80030B80(struct X4_PlayerObj* arg0, s16 arg1);

void func_8002F418(struct X4_PlayerObj* arg0) {
    struct X4_Unk_unk68* box;
    u16 x;

    box = arg0->unk68;
    arg0->unk70 = 0;
    arg0->touching_spikes = 0;
    if (box != 0) {
        D_800E4196 = box->unk0;
        x = arg0->x_pos.u.hi;
        D_800E4198 = box->unk1;
        D_800E4192 = box->unk2;
        {
            register s32 h asm("$7") = box->unk3;
            D_800E4194 = h;
        }
        D_800E419A = x;
        D_800E419C = arg0->y_pos.i.hi;
        if (arg0->unk15 == 0) {
            D_800E419E = x + D_800E4196;
        } else {
            D_800E419E = x - D_800E4196;
        }
        D_800E41A0 = D_800E419C + D_800E4198;
        if (func_80030B80(arg0, D_800E419E - D_800E4192 - 1) != 0) {
            arg0->unk70 |= 2;
        }
        if (func_80030B80(arg0, D_800E419E + D_800E4192) != 0) {
            arg0->unk70 |= 1;
        }
        if (func_800309F8(arg0, D_800E4194 + (D_800E419C + D_800E4198), 1) !=
            0) {
            arg0->unk70 |= 8;
        }
        if (func_800309F8(arg0, D_800E419C + D_800E4198 - D_800E4194 - 1, 0) !=
            0) {
            arg0->unk70 |= 4;
        }
    }
}
