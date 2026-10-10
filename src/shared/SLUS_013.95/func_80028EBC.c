#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)

void func_80028EBC(struct X4_BackgroundObj* arg0) {
    s32 spd1;
    s32 pos1;
    s32 spd2;
    s32 pos2;
    s32 spd3;
    s32 pos3;
    s32 pos4;
    s32 d;
    s16 t;
    s16 x;

    if (arg0->unk26 != arg0->unk1E) {
        d = arg0->unk26 - arg0->unk1E;
        if (d < 0) {
            d = arg0->unk1E - arg0->unk26;
        }
        spd1 = arg0->unk47;
        if (spd1 < d) {
            x = arg0->x_pos.i.hi;
            pos1 = (u16)arg0->x_pos.i.hi;
            if (arg0->unk26 >= x) {
                t = x + spd1;
                if (t >= arg0->unk26) {
                    arg0->unk1E = arg0->unk26;
                    goto block2;
                }
                arg0->unk1E = t;
                goto block2;
            } else {
                t = D_800970A0.x_pos.i.hi;
                t = t - pos1;
                if ((s16)(t - arg0->unk30) >= 0) {
                    t = D_800970A0.x_pos.i.hi - D_800970A0.unk18.i.hi;
                    if (t >= 0) {
                        t = 0;
                    }
                    t = t + pos1;
                    t = t - spd1;
                    if (t < arg0->unk26) {
                        arg0->unk1E = t;
                    } else {
                        arg0->unk1E = arg0->unk26;
                    }
                    goto block2;
                } else {
                    arg0->unk1E = arg0->unk26;
                    goto block2;
                }
            }
        }
        arg0->unk1E = arg0->unk26;
    }
block2:
    if (arg0->unk24 != arg0->unk1C) {
        d = arg0->unk24 - arg0->unk1C;
        if (d < 0) {
            d = arg0->unk1C - arg0->unk24;
        }
        spd2 = arg0->unk47;
        if (spd2 < d) {
            x = arg0->x_pos.i.hi;
            pos2 = (u16)arg0->x_pos.i.hi;
            if (arg0->unk24 < x) {
                t = x - spd2;
                if (t < arg0->unk24) {
                    arg0->unk1C = arg0->unk24;
                    goto block3;
                }
                goto store2;
            }
            t = D_800970A0.x_pos.i.hi;
            t = t - pos2;
            t = t - arg0->unk32;
            t = t + 2;
            if (t < 4) {
                t = D_800970A0.x_pos.i.hi - D_800970A0.unk18.i.hi;
                if (t < 0) {
                    t = 0;
                }
                t = t + pos2;
                t = t + spd2;
                if (arg0->unk24 < t) {
                store2:
                    arg0->unk1C = t;
                    goto block3;
                }
                arg0->unk1C = arg0->unk24;
                goto block3;
            }
        }

        arg0->unk1C = arg0->unk24;
    }
block3:
    if (arg0->unk2A != arg0->unk22) {
        d = arg0->unk2A - arg0->unk22;
        if (d < 0) {
            d = arg0->unk22 - arg0->unk2A;
        }
        spd3 = arg0->unk47;
        if (spd3 >= d) {
            arg0->unk22 = arg0->unk2A;
            goto block4;
        }
        x = arg0->y_pos.i.hi;
        pos3 = (u16)arg0->y_pos.i.hi;
        if (arg0->unk2A >= x) {
            t = x + spd3;
            if (t < arg0->unk2A) {
                arg0->unk22 = t;
            } else {
                arg0->unk22 = arg0->unk2A;
            }
            goto block4;
        }
        t = D_800970A0.y_pos.i.hi;
        t = t - pos3;
        t = t - arg0->unk2C;
        if (t < 0) {
            t = D_800970A0.y_pos.i.hi - D_800970A0.unk1C.i.hi;
            if (t >= 0) {
                t = 0;
            }
            t = t + pos3;
            t = t - spd3;
            if (t < arg0->unk2A) {
                t = arg0->unk2A;
            }
        }
        arg0->unk22 = t;
    }
block4:
    if (arg0->unk28 != arg0->unk20) {
        x = arg0->y_pos.i.hi;
        pos4 = (u16)arg0->y_pos.i.hi;
        if (arg0->unk28 < x) {
            t = x - arg0->unk47;
            if (t < arg0->unk28) {
                t = arg0->unk28;
            }
            arg0->unk20 = t;
            return;
        }
        t = D_800970A0.y_pos.i.hi;
        t = t - pos4;
        t = t - arg0->unk2E;
        t = t + 2;
        if (t < 4) {
            t = D_800970A0.y_pos.i.hi - D_800970A0.unk1C.i.hi;
            if (t < 0) {
                t = 0;
            }
            t = t + pos4;
            t = t + arg0->unk47;
            if (t >= arg0->unk28) {
                t = arg0->unk28;
            }
            arg0->unk20 = t;
            return;
        }
        arg0->unk20 = arg0->unk28;
    }
}
#undef D_800970A0
