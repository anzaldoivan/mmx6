#include "common.h"

extern s32 D_800E0398[][2];

s32 func_80016548(s32 arg0, s32* arg1) {
    s32* p = D_800E0398[arg0];
    *arg1 = p[1];
    return p[0];
}
